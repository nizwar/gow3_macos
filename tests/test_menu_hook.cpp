// Runs the menu interpreter's builtin-call stub (src/menu_hook.h): any other function replays the
// replaced instructions and resumes; function 0xfff goes to quit.
#include <cassert>
#include <cstdint>
#include "../src/menu_hook.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif

// The stub ends with a jump to its resume address; here that is a `ret` back to the test.
extern "C" void menu_hook_return();
#ifdef __APPLE__
#define ASM_NAME(name) "_" #name /* Mach-O names carry a leading underscore */
#else
#define ASM_NAME(name) #name
#endif
asm(".globl " ASM_NAME(menu_hook_return) "\n" ASM_NAME(menu_hook_return) ":\n    ret\n");

static void* back[5];
static int quits;
static void quit() {
    ++quits;
    __builtin_longjmp(back, 1);  // no unwinding through the stub
}

// The interpreter frame: [rbp-0x2a0] is the provider table, rax the provider; rdi gets the entry.
alignas(16) static uint64_t frame[96];
static uint64_t providers[2] = {0x1111, 0x2222};

static uint64_t call(unsigned char* stub, uint32_t function, uint64_t provider) {
    uint64_t rdi;
    asm volatile("push %%rbp\n\tmov %%rbx, %%rbp\n\tcall *%%rcx\n\tpop %%rbp"
                 : "=D"(rdi), "+c"(stub), "+a"(provider), "+S"(function)
                 : "b"(frame + 96)
                 : "rdx", "r8", "r9", "r10", "r11", "memory", "cc");
    return rdi;
}

int main() {
    assert(spartanport_menu_signature_match(spartanport_menu_original, SPARTAN_MENU_HOOK_LENGTH));
    assert(!spartanport_menu_signature_match(spartanport_menu_original, SPARTAN_MENU_HOOK_LENGTH - 1));

#ifdef _WIN32
    auto* stub = static_cast<unsigned char*>(
        VirtualAlloc(nullptr, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));
    assert(stub);
#else
    void* page = mmap(nullptr, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    assert(page != MAP_FAILED);
    auto* stub = static_cast<unsigned char*>(page);
#endif
    assert(spartanport_menu_build_stub(stub, reinterpret_cast<uintptr_t>(&quit),
                                reinterpret_cast<uintptr_t>(&menu_hook_return)) < 256);
    frame[96 - 0x2a0 / 8] = reinterpret_cast<uint64_t>(providers);

    assert(call(stub, 0x5a, 1) == 0x2222);  // a game builtin: the original lookup
    assert(call(stub, 0xffe, 0) == 0x1111 && quits == 0);
    if (!__builtin_setjmp(back)) {
        call(stub, SPARTAN_MENU_EXIT_FUNCTION, 0);
        assert(!"quit returned");
    }
    assert(quits == 1);
    return 0;
}
