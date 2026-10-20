// Runs the damage-hook stub (src/actor_hook.h) on fake actors and checks what it records, then
// the overlay's validity rules (gpu/shim/spartanport_actors.h).
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif
#include "../src/actor_hook.h"
#include "spartanport_actors.h"

// The stub ends with a jump to its resume address; here that is a `ret` back to the test.
extern "C" void actor_hook_return();
#ifdef __APPLE__
#define ACTOR_HOOK_RETURN "_actor_hook_return" /* Mach-O names carry a leading underscore */
#else
#define ACTOR_HOOK_RETURN "actor_hook_return"
#endif
asm(".globl " ACTOR_HOOK_RETURN "\n" ACTOR_HOOK_RETURN ":\n    ret\n");

alignas(64) static SpartanActorSlot slots[2];

static void hit(unsigned char* stub, unsigned char* actor) {
    asm volatile("mov %0, %%r13\n\tcall *%1\n\t"
                 :
                 : "r"(actor), "r"(stub)
                 : "rax", "rdi", "r13", "memory", "cc");
}

static void set_health(unsigned char* actor, float health, float max_health, bool player) {
    std::memcpy(actor + 0x1cc, &health, 4);
    std::memcpy(actor + 0x1d0, &max_health, 4);
    actor[0x298] = player ? 0 : 1;  // the infinite-health cheat writes the maximum only when 0
}

int main() {
    assert(spartanport_actor_signature_match(spartanport_actor_original, SPARTAN_ACTOR_HOOK_LENGTH));
    const unsigned char other[] = {0x49, 0x8b, 0x45, 0x00, 0x4c, 0x89, 0xee};
    assert(!spartanport_actor_signature_match(other, sizeof(other)));
    assert(!spartanport_actor_signature_match(spartanport_actor_original, SPARTAN_ACTOR_HOOK_LENGTH - 1));

#ifdef _WIN32
    auto* stub = static_cast<unsigned char*>(
        VirtualAlloc(nullptr, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));
    assert(stub);
#else
    void* page = mmap(nullptr, 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    assert(page != MAP_FAILED);
    auto* stub = static_cast<unsigned char*>(page);
#endif
    const unsigned n = spartanport_actor_build_stub(stub, reinterpret_cast<uintptr_t>(slots),
                                             reinterpret_cast<uintptr_t>(&actor_hook_return));
    assert(n < 256);

    alignas(16) static unsigned char player[0x300], enemy[0x300];
    set_health(player, 80.0f, 400.0f, true);
    set_health(enemy, 250.0f, 1000.0f, false);
    hit(stub, enemy);
    assert(slots[1].actor == reinterpret_cast<uint64_t>(enemy));
    assert(slots[1].health == 250.0f && slots[1].max_health == 1000.0f && slots[1].seq == 1);
    assert(slots[0].seq == 0);
    hit(stub, player);
    assert(slots[0].actor == reinterpret_cast<uint64_t>(player) && slots[0].health == 80.0f);
    set_health(enemy, 0.0f, 1000.0f, false);
    hit(stub, enemy);
    assert(slots[1].health == 0.0f && slots[1].seq == 2 && slots[0].seq == 1);

    assert(SpartanActors::Valid(250.0f, 1000.0f) && SpartanActors::Fraction(250.0f, 1000.0f) == 0.25f);
    assert(!SpartanActors::Valid(NAN, 100.0f) && !SpartanActors::Valid(10.0f, 0.0f));
    assert(!SpartanActors::Valid(-1.0f, 100.0f) && !SpartanActors::Valid(200.0f, 100.0f));
    assert(!SpartanActors::Valid(1.0f, 1e9f) && SpartanActors::Fraction(NAN, 1.0f) == 0.0f);
#ifdef _WIN32
    VirtualFree(stub, 0, MEM_RELEASE);
#else
    munmap(stub, 4096);
#endif
}
