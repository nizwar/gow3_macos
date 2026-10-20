<p align="center">
  <img src="packaging/icon/monogram.png" alt="SP" width="160"><br>
  <img src="docs/images/spartanport-logo.png" alt="SpartanPort" width="600">
</p>

# SpartanPort

<div align="center">
  <a href="https://trendshift.io/repositories/299469?utm_source=trendshift-badge&amp;utm_medium=badge&amp;utm_campaign=badge-trendshift-299469" target="_blank" rel="noopener noreferrer"><img src="https://trendshift.io/api/badge/trendshift/repositories/299469/daily?language=C%2B%2B" alt="FelipePrado0%2FSpartanPort | Trendshift" width="250" height="55"/></a>
</div>

[English](README.md) | [Português (Brasil)](README.pt-BR.md) | [Español](README.es.md) | **Bahasa Indonesia**

**SpartanPort** adalah port PC tidak resmi dari **God of War III Remastered** (PlayStation 4) untuk
Windows 10/11, Linux (AppImage eksperimental), dan Mac dengan Apple Silicon
([eksperimental](#macos-apple-silicon-eksperimental)).

> **Tidak ada file game yang disertakan.** Anda perlu dump dari PS4 Anda sendiri (sudah diuji:
> CUSA01623 dan CUSA01715, versi 01.00 dan 01.02).
> Proyek ini tidak berafiliasi dengan maupun didukung oleh Sony Interactive Entertainment atau Santa Monica Studio.
> God of War adalah merek dagang Sony Interactive Entertainment.

> **Sebelumnya bernama gow3_pc.** Jika Anda memperbarui dari 2.5.0 lewat launcher, save dan pengaturan
> Anda tetap terjaga: saat pertama kali dijalankan, pengaturan game (`gow3.ini`), pengaturan launcher,
> dan, di Linux, folder data (`~/.local/share/gow3`) disalin ke nama barunya. File lama tetap di
> tempatnya, dan shortcut yang sudah ada tetap berfungsi. Di Linux, AppImage-nya sekarang bernama
> `spartanport-x86_64.AppImage`: perbarui launch options Steam yang memakai nama file lama.

## Daftar isi

- [SpartanPort](#spartanport)
  - [Daftar isi](#daftar-isi)
  - [Unduh dan main](#unduh-dan-main)
  - [Linux (AppImage, eksperimental)](#linux-appimage-eksperimental)
  - [macOS (Apple Silicon, eksperimental)](#macos-apple-silicon-eksperimental)
  - [Yang sudah berjalan](#yang-sudah-berjalan)
  - [Ketersediaan fitur](#ketersediaan-fitur)
  - [Pengaturan](#pengaturan)
  - [Kontrol keyboard](#kontrol-keyboard)
  - [Mengimpor save shadPS4](#mengimpor-save-shadps4)
  - [Overlay pihak ketiga (Windows)](#overlay-pihak-ketiga-windows)
  - [Overlay di Mac](#overlay-di-mac)
  - [Pemecahan masalah](#pemecahan-masalah)
  - [Performa dan kompatibilitas](#performa-dan-kompatibilitas)
  - [Build dari source](#build-dari-source)
    - [Windows](#windows)
    - [Linux (Ubuntu 24.04)](#linux-ubuntu-2404)
    - [macOS](#macos)
  - [Pengujian](#pengujian)
    - [Python](#python)
    - [Tes C++ di Windows (MSYS2 CLANG64)](#tes-c-di-windows-msys2-clang64)
    - [Tes C/C++ di Linux](#tes-cc-di-linux)
    - [Tes C/C++ di macOS](#tes-cc-di-macos)
    - [Pemeriksaan dengan game yang sudah disiapkan](#pemeriksaan-dengan-game-yang-sudah-disiapkan)
  - [Cara kerjanya](#cara-kerjanya)
  - [Kredit](#kredit)
  - [Lisensi](#lisensi)

## Unduh dan main

- Windows 10 (1903 atau lebih baru) atau Windows 11, 64-bit.
- Prosesor 64-bit dengan AVX: Intel Sandy Bridge (2011) atau lebih baru, AMD FX atau lebih baru. Di
  CPU tanpa MOVBE, BMI1, atau LZCNT (Sandy/Ivy Bridge, AMD FX), loader menulis ulang instruksi game
  yang memakainya menjadi stub yang diemulasikan dan mencatat baris `ISA:`; performa di CPU itu
  belum diukur. CPU yang lebih lama berhenti saat mulai dengan baris `STOP: this CPU lacks` di log.
- Kartu grafis dengan Vulkan 1.3 dan driver terbaru.
- Salinan game Anda (folder berisi `eboot.bin`, `sce_module`, dan `sce_sys`). Sudah diuji:
  CUSA01623 dan CUSA01715, versi 01.00 dan 01.02.

**Langkah-langkah**

1. Unduh `spartanport-windows.zip` dari
   [halaman Releases](https://github.com/FelipePrado0/SpartanPort/releases/latest).
2. Ekstrak ke folder pilihan Anda, misalnya `C:\Games\spartanport-windows`. Jangan menjalankannya dari
   dalam zip.
3. Buka **`SpartanPort.exe`**. Jika Windows menampilkan "Windows protected your PC", klik
   **More info**, lalu **Run anyway**: programnya tidak bertanda tangan digital.
4. Klik **Choose the game folder**. Anda akan dibawa ke halaman **Game**. Di sebelah **Game
   folder**, klik **Browse…** dan pilih folder yang berisi `eboot.bin`.
5. Kembali di **Home**, gambar sampul dan "CUSA01623 · version 01.02" akan muncul. Ubah **Quick
   settings** jika perlu: mode tampilan, batas frame rate, render resolution, dan frame rate
   engine.
6. Klik **Save** untuk menyimpan perubahan yang tertunda, lalu **PLAY**. Permainan pertama
   menyiapkan image game; kompilasi shader juga bisa memengaruhi waktu mulai dan performa di
   permainan berikutnya.

Patch dan perbaikan sudah disertakan dan diterapkan otomatis: perbaikan tekstur, lewati video
dengan X, dan 120 FPS aktif secara bawaan. Ubah resolusi dan frame rate di **Home** atau
**Performance**. Perbaikan layar hitam saat mulai selalu diminta, bahkan dengan pilihan patch lama
yang tersimpan; patch hanya diterapkan di lokasi yang signature-nya cocok. Patch resolusi
menggantikan perbaikan tekstur.

**Saat bermain**

- **Insert** di keyboard, atau **R3 + L2** di controller, membuka menu port: cheat, pengali,
  gambar, performa, dan overlay performa.
- Shader yang tersimpan dimuat di latar belakang. Catatan kecil "Loading shader cache" di pojok
  layar menunjukkan kemajuannya.

**Berikutnya**

- **`Play SpartanPort.exe`** langsung memulai game dengan pengaturan yang tersimpan. Anda bisa
  membuat shortcut desktop ke file itu, atau menambahkannya ke Steam lewat **Add a Non-Steam Game**.
- Save, cache shader, dan log Anda ada di folder `user` di sebelah `SpartanPort.exe`. Simpan
  folder itu saat memperbarui.
- **Advanced → Check for updates** mengunduh dan memasang versi baru. Save dan pengaturan Anda
  tetap aman.

## Linux (AppImage, eksperimental)

Versi Linux menjalankan runtime native dan launcher yang sama. Versi ini diuji di Arch Linux dengan
Radeon RX 7800 XT (RADV) di sesi Wayland.

**Yang Anda perlukan:** Linux x86-64 dengan glibc 2.39 atau lebih baru, CPU dengan AVX, driver
Vulkan 1.3, dan dump game milik Anda sendiri. Launcher sudah dicek bisa terbuka di Ubuntu 24.04,
Debian 13, Fedora 42, Arch, dan openSUSE Tumbleweed; ini tidak menjamin gameplay jalan di semua GPU.

**Unduh dan jalankan**

1. Unduh `spartanport-x86_64.AppImage` dari
   [halaman Releases](https://github.com/FelipePrado0/SpartanPort/releases/latest).
2. Di folder file itu, jalankan:
   ```bash
   chmod +x spartanport-x86_64.AppImage
   ./spartanport-x86_64.AppImage
   ```
3. Pilih folder game, simpan pengaturan, lalu tekan **PLAY**.

Jika unduhan lama menampilkan `GLIBC_2.44 not found`, unduh lagi AppImage yang sudah di-build ulang.
Pembaruan otomatis versi Windows tidak tersedia di Linux; unduh AppImage yang lebih baru untuk
memperbarui. Kerusakan gambar di Steam Deck/RADV adalah masalah yang sudah diketahui di AppImage
2.2.0 yang dipublikasikan.

- **File:** save, pengaturan, cache shader, dan log ada di `~/.local/share/spartanport`; pengaturan
  launcher sendiri di `~/.config/spartanport-launcher`.
- **Update folder:** jika update di-dump terpisah dari game, pilih di **Game → Update folder**.
  Folder itu ditumpuk di atas folder game tanpa mengubah keduanya.
- **Advanced → Linux:** sistem jendela (otomatis, Wayland, atau X11), GameMode, dan MangoHud. Hanya
  alat yang terpasang di sistem yang bisa dinyalakan.
- **Steam:** **Advanced → Add to Steam** menambahkan "SpartanPort" sebagai game non-Steam, lengkap
  dengan ikon, capsule vertikal dan horizontal, latar library, dan logo yang dibuat dari gambar di
  dump. Tutup Steam dulu (Steam menulis ulang shortcut-nya saat ditutup). Tombol ini juga ada di
  launcher Windows dan Mac (di sana belum diuji dengan Steam).
- **Steam Deck / SteamOS (Gaming Mode):** jika Steam mencoba menjalankan AppImage dengan Proton,
  buka **Properties → Compatibility** pada shortcut-nya dan pilih **Steam Linux Runtime**, bukan
  Proton. AppImage adalah aplikasi Linux native. Jika gagal dijalankan dengan **Steam Linux
  Runtime**, buka **Properties → Compatibility** pada shortcut-nya dan pilih **Default** untuk
  memakai library sistem host.
- **Entri menu:** AppImage menulis `~/.local/share/applications/spartanport.desktop` saat dijalankan,
  supaya launcher dan jendela game menampilkan ikonnya di dock; **Advanced → Linux** mematikannya
  dan menghapus entri itu. Jika alat lain (Gear Lever, AppImageLauncher…) sudah membuat entri yang
  menjalankan file yang sama, AppImage tidak membuat entri dan menghapus entrinya sendiri, jadi
  tidak ada duplikat.

## macOS (Apple Silicon, eksperimental)

Versi macOS menjalankan runtime native yang sama di bawah Rosetta 2, dengan grafik di driver Vulkan
KosmicKrisp dari Mesa (Vulkan di atas Metal). Sudah diuji di M4 Pro (macOS 27) pada pembukaan dan
pertarungan-pertarungan awal, tetapi belum dimainkan sampai tamat. Detail dan perbedaannya dengan
Linux: [packaging/macos/README.md](packaging/macos/README.md).

**Yang Anda perlukan:** Mac dengan Apple Silicon (M1 atau lebih baru), macOS 26 (Tahoe) atau lebih
baru, Rosetta 2, dan dump game milik Anda sendiri. Mac Intel tidak didukung. Jika Rosetta 2 belum
terpasang, halaman **Log** akan memberi tahu; pasang di Terminal dengan
`softwareupdate --install-rosetta --agree-to-license`. Python, library, dan driver Vulkan sudah ada
di dalam aplikasi.

**Unduh dan main**

1. Unduh `spartanport-macos.dmg` dari
   [halaman rilis macOS](https://github.com/nizwar/gow3_macos/releases/latest).
2. Buka file itu dan seret **SpartanPort** ke **Applications**.
3. Aplikasinya tidak ditandatangani dengan Apple Developer ID, jadi macOS memblokirnya. Izinkan
   sekali di Terminal:
   ```bash
   xattr -dr com.apple.quarantine "/Applications/SpartanPort.app"
   ```
4. Buka **SpartanPort** dan pilih folder game (update yang di-dump terpisah dari game masuk ke
   **Update folder**), klik **Save**, lalu **PLAY**. Permainan pertama lebih lama: Rosetta
   menerjemahkan kode game dan shader-nya dikompilasi.

Untuk FPS lebih tinggi di layar 1080p: **Performance → Render resolution → 720p** (atau 480p) dan
**Graphics → Upscaling → Upscale to the window** dengan **Upscaler → MetalFX (Apple)**. Setiap
render resolution yang lebih kecil dari jendela akan diperbesar, dan overlay performa lalu
menampilkan "MetalFX 720p->1080p". Di M4 Pro hasilnya sekitar 52 FPS di pertarungan pertama,
dibandingkan 32 FPS di 1080p native. Di 480p area terang menjadi terlalu silau (bug game yang sudah
diketahui di resolusi itu).

- **Tombol menu:** **`** (tombol di kiri angka 1) membuka menu port, karena keyboard Mac tidak punya
  tombol Insert; R3 + L2 berfungsi seperti di sistem lain.
- **Keyboard dan mouse:** secara bawaan R2 dan Dodge ada di tombol samping mouse, yang tidak dimiliki
  trackpad maupun Magic Mouse: beri keduanya tombol keyboard di halaman **Controls** launcher.
- **File:** save, pengaturan, cache shader, dan log ada di
  `~/Library/Application Support/spartanport` (**Advanced → Port folder** membukanya), begitu pula
  pengaturan launcher sendiri. Buka aplikasinya dari Applications, Launchpad, atau Dock.
- **Dari 2.4.0 (God of War III.app):** saat SpartanPort pertama kali dijalankan, save dan pengaturan
  disalin dari `~/Library/Application Support/gow3` dan `~/.config/gow3-launcher`, tanpa mengubah
  yang asli (cache shader dibangun ulang selagi Anda bermain). Setelah itu aplikasi lama boleh
  dihapus.
- **Pembaruan:** **Advanced → Check for updates** memeriksa rilis di repository ini (tag
  `macos-v<versi>` dengan `spartanport-macos.dmg`) dan mengunduh disk image yang lebih baru: seret
  aplikasi baru menimpa yang lama. Save dan pengaturan tetap aman.
- **Steam:** **Advanced → Add to Steam**, seperti di Linux (`~/Library/Application Support/Steam`),
  dengan Steam dalam keadaan tertutup; setelah itu Steam memulai game tanpa launcher.
- **Advanced → macOS → Metal performance HUD:** overlay dari Apple berisi frame rate, frame time,
  dan memori di jendela game, padanan MangoHud di Mac.
- **Graphics → Upscaling → Fewer GPU waits (experimental):** beban CPU lebih ringan saat pembacaan
  data GPU menahan proses menggambar; di M4 Pro FPS-nya tidak naik, karena yang membatasi adalah
  sisi GPU.
- **Overlay performa:** pemakaian GPU adalah pemakaian seluruh GPU (macOS tidak punya penghitung
  per proses), dan RAM adalah angka yang sama dengan Activity Monitor.
- **Performance → GPU data** tidak punya pilihan kartu grafis maupun memori stream buffer: Mac
  punya satu GPU yang berbagi memori dengan sistem.
- **Tanpa jendela launcher:**
  `"/Applications/SpartanPort.app/Contents/MacOS/SpartanPort" --play` memulai game dengan
  pengaturan tersimpan.

## Yang sudah berjalan

- Pembukaan, menu, cutscene video (H.264), dan gameplay.
- Audio: musik, suara, dan efek (ATRAC9 dan MP3).
- Controller (DualSense, Xbox, dan lainnya, lewat SDL3) dan keyboard sekaligus, dua-duanya bisa
  diatur ulang tombolnya.
- **Ikon tombol di dalam game** (opsional, mati secara bawaan): ikon tombol PlayStation di dalam
  game bisa diganti dengan ikon controller Anda, Xbox, atau Nintendo, atau dengan tombol keyboard
  yang Anda pakai untuk bermain (halaman Game, bagian Controls).
- Simpan dan muat: daftar save tampil di layar, seperti di PS4. Autosave juga berjalan. Launcher
  membuat cadangan save sebelum setiap permainan dimulai.
- Patch: render resolution 480p, 720p, 900p, 1440p, 1800p, atau 4K, perbaikan tekstur rusak, dan
  lewati video dengan tombol X (komunitas); frame rate engine 120 FPS (kvicken), 100 FPS (untuk
  layar 100 Hz), 144 FPS (untuk layar 144 Hz), atau 240 FPS (diadaptasi oleh Felipe Prado).
- **Ultrawide (beta):** render resolution 21:9, 32:9, dan 16:10 (3440x1440 sudah diuji) dengan
  bidang pandang yang lebih lebar, bukan gambar yang di-zoom, sudah bawaan: pilih di **Render
  resolution**, tempat setiap ukuran menampilkan resolusi persis dan rasio aspeknya. Cutscene tetap
  dengan bingkai 16:9 (lihat [docs/ultrawide.md](docs/ultrawide.md)). Mod juga bisa membawa patch
  game; [mod Ultrawide](extras/mods/Ultrawide) berisi ukuran yang sama untuk versi lama.
  **Cara memasang mod:** taruh file `.zip`-nya (jangan diekstrak) di folder `mods` di sebelah
  `SpartanPort.exe`; game mengekstraknya sendiri. Mod Ultrawide dan installer sekali klik untuk
  2.2.0 dijelaskan di [extras/mods/Ultrawide](extras/mods/Ultrawide/README.md).
- **Kompilasi shader di latar belakang:** pipeline yang tersimpan dimuat dan dikompilasi di latar
  belakang selagi Anda bermain. Patah-patah, efek yang belum muncul selama kompilasi, dan penurunan
  FPS sementara masih bisa terjadi; waktu mulai bergantung pada cache, driver grafis, dan CPU.
- **Launcher** dengan warna khas game, bahasa yang bisa dipilih dan bahasa Inggris sebagai
  cadangan: lima halaman (**Home, Graphics, Performance, Game, Advanced**) dan tombol **Save** untuk
  perubahan yang tertunda; pengaturan cepat di halaman awal, grafis, performa, folder game dan
  cadangan save, patch, mod (urutan, preset, dan bentrokan), kontrol dengan ikon tombol PlayStation
  atau Xbox, pembaruan, dan diagnosis.
- **Menu di dalam game** (Insert di keyboard, ` di Mac, R3+L2 di controller), dengan empat tab:
  - **Game:** cheat (darah, magic, item meter, dan Rage of Sparta tak terbatas, red orb maksimal,
    QTE otomatis: perintah tombol dan putaran stick terjawab sendiri);
    pengali 0,1x sampai 100x untuk red orb, green orb (darah), blue orb (magic), dan gold orb
    (Rage of Sparta), serta untuk damage yang diberikan dan diterima; bar darah musuh.
  - **Image:** mode tampilan (windowed, borderless, fullscreen), VSync, dan penajaman RCAS; di Mac
    juga upscaling ke jendela dengan FSR 1 atau MetalFX dari Apple.
  - **Performance:** batas frame rate (30 sampai tanpa batas), jumlah frame dalam antrean,
    kompilasi shader di latar belakang; render resolution, frame rate engine, dan opsi pembacaan
    data GPU diterapkan dengan satu tombol "Apply and restart".
  - **Overlay:** overlay performa berisi FPS, frametime, upscaler, GPU (nama dan pemakaian), CPU,
    RAM, dan VRAM, masing-masing opsional, dengan ukuran huruf, pojok layar, transparansi latar,
    dan tata letak yang bisa diatur. Angkanya adalah pemakaian game itu sendiri, bukan seluruh
    sistem (di Mac, pemakaian GPU-nya adalah pemakaian seluruh GPU). Item upscaler-nya menyebut
    apa yang memperbesar gambar, misalnya "MetalFX 720p->1080p".

## Ketersediaan fitur

Ketersediaan dicek terhadap [rilis 2.2.0](https://github.com/FelipePrado0/SpartanPort/releases/tag/windows-v2.2.0) dan source pada 14 Oktober 2026.

| Fitur | Paket 2.2.0 yang dipublikasikan | Source saat ini | macOS (repository ini) |
|---|---|---|---|
| ZIP Windows / AppImage Linux eksperimental | Tersedia | Script build tersedia | Aplikasi Mac dan `spartanport-macos.dmg` (`packaging/macos/package.sh`) |
| Patch layar hitam saat mulai / ikon tombol controller | Disertakan | Disertakan | Disertakan |
| Discord Rich Presence | Tidak disertakan | Opsional di Advanced, mati secara bawaan; nama game dan waktu bermain | Opsi yang sama (belum diuji di Mac) |
| Perbaikan antrean sparse RADV | Tidak disertakan | Sudah digabung ke `main` | Tidak berlaku (KosmicKrisp) |
| FSR 1, FSR 3.1, FSR 4, TAA, DLSS | Dimatikan | Dimatikan di alur pengaturan launcher/game | FSR 1 dan MetalFX dari Apple memperbesar ke jendela (Graphics → Upscaling); upscaler temporal tetap mati; tidak ada DLSS (NVIDIA) |
| Penajaman RCAS | Tersedia | Tersedia | Tersedia (dengan FSR 1; MetalFX menajamkan sendiri) |
| Check for updates / Add to Steam | Windows / keduanya | Windows / keduanya | Keduanya (disk image baru; folder Steam di Mac) |
| MangoHud / GameMode / pilihan Wayland-X11 | Linux | Linux | Metal performance HUD sebagai pengganti MangoHud |

AppImage Linux di-build ulang pada 14 Oktober untuk glibc 2.39 atau lebih baru. Paket Windows dan
Linux bisa memakai revisi source yang berbeda. Lihat catatan rilis untuk perubahan pada unduhan
berikutnya.

## Pengaturan

Pengaturan disimpan di `spartanport.ini` (game dan menu di dalam game) dan di
`settings.json` (launcher), di folder port. Save, cache shader, dan
`last_run.log` masuk ke folder `user` milik proyek.
Aplikasi Mac menyimpan semuanya di `~/Library/Application Support/spartanport`.

**GUI Scale:** pilih **Auto**, **1x**, atau **2x** di **Advanced → Launcher**,
lalu klik **Save**. Teks, kontrol, dan tata letak berubah ukuran bersamaan, tanpa
mengubah resolusi game. Auto mengikuti skala desktop yang dilaporkan Tk, dengan DPI
font X11/XWayland dan skala jendela sebagai cadangan di Linux. Di macOS, penskalaan
Retina tetap diurus sistem operasi. 1x/2x manual mengatur ukuran logis launcher,
termasuk teks, ikon, kontrol, scrollbar, dan jarak antarelemen. Resolusi layar saja
tidak menentukan skala. Pilihan ini disimpan di `settings.json`.

Di **Performance → GPU data → Stream buffer memory** (Windows dan Linux), pilih **System RAM
(cached, default)**, **System RAM (uncached)**, atau **GPU memory (previous behavior)**. RAM sistem
bisa menaikkan frame rate di laptop NVIDIA. Pilihan ini disimpan dan berlaku saat game berikutnya
dimulai, termasuk lewat `Play SpartanPort.exe` atau `--play`. Pilih GPU memory untuk kembali ke
cara alokasi sebelumnya. Untuk menjalankan langsung tanpa launcher, `SPARTAN_STREAM_MEMORY` menerima
`cached`, `host`, atau `device`; pilihan tersimpan di launcher lebih diutamakan saat launcher
dipakai.

Di **Performance → GPU data → Game multisampling**, **Automatic** membiarkan game memutuskan
berdasarkan kartu grafis yang dipakainya: gambar multisample milik game dibuat dengan satu sampel
di driver Windows AMD dan Intel, tempat membaca depth buffer 2 sampel sebagai tekstur menghasilkan
garis hitam di pencahayaan (keluarga Radeon RX 6600, Arc), dan tetap multisample di driver lain
(NVIDIA). Labelnya menyebut kartu dan keputusannya, misalnya "Automatic (Intel(R) Arc(TM) A750
Graphics: off)", dan mengikuti pilihan **Graphics card**. Aturan ini berlaku untuk semua GPU di dua
driver itu, termasuk yang terintegrasi; baris log game `GPU: guest multisampling off` atau `on`
menunjukkan apa yang diterapkan. Pilih **Off** jika garis muncul di kartu lain dan **On** untuk
tetap memakai multisampling. Off dan On mengatur `SPARTAN_NO_MSAA=1` atau `0`; Automatic meneruskan
`SPARTAN_NO_MSAA` yang diwarisi. Berlaku saat game berikutnya dimulai.

## Kontrol keyboard

Bawaan; ubah di halaman **Controls** di launcher, bagian **Keyboard & Mouse Mapping**.

| Tombol | Tombol PS4 |
|---|---|
| WASD | stick kiri |
| Panah | stick kanan (kamera) |
| Space | Cross |
| Shift kiri | Circle |
| Klik kiri | Square |
| Klik kanan | Triangle |
| Q dan E | L1 dan R1 |
| R dan tombol maju (forward) di mouse | L2 dan R2 |
| Z dan X | L3 dan R3 |
| Klik roda mouse | Rage of Sparta (L3 + R3) |
| C | Grab (L1 + Circle) |
| Tombol mundur (back) di mouse | Dodge |
| 1, 2, 3, 4 | d-pad atas, kanan, bawah, kiri (senjata) |
| Tab | Options |
| P | klik kiri touchpad (mode foto) |
| Esc | klik kanan touchpad (menu jeda) |
| Insert (` di Mac) | menu port (R3+L2 di controller) |

**Rage of Sparta on one input** (aktif secara bawaan) membuat Z dan X tidak terpakai. **Joystick
prompts** menjawab quick-time event putaran stick tanpa stick: ketik putarannya (setengah putaran
D S A, A S D, A W D, atau D W A; putaran penuh D S A W atau A S D W) atau, dengan *Adaptive mouse*,
gambar putarannya dengan mouse. Selagi Anda bermain, mouse tertahan di jendela game; menu di dalam
game, tombol jeda (Esc), dan jendela lain melepaskannya, lalu Esc sekali lagi atau klik di jendela
game menahannya kembali. Saat L2 ditahan (R), mouse membidik sebagai stick kanan, untuk Head of
Helios atau Bow of Apollo: *Relative* mengikuti gerakan, *Absolute* membidik dari posisi mouse saat
L2 ditekan, dan *Right stick sensitivity* mengatur seberapa jauh mouse perlu digerakkan. Tanpa
launcher, game memakai tombolnya sendiri: E dan Q untuk Square dan Triangle, 1 dan 3 untuk L1 dan
R1, F untuk R2, C untuk R3, I, K, J, L untuk d-pad, Enter untuk Options, Tab dan Backspace untuk
touchpad.

Di controller tanpa touchpad (Xbox dan lainnya), View membuka menu jeda (klik kanan touchpad) dan
L1 + View membuka mode foto (klik kiri). Di DualSense touchpad berfungsi seperti di PS4, dan
Share/Create berfungsi seperti View.

**Ikon tombol di dalam game** (mati secara bawaan) dipilih di halaman Controls launcher, pada
*In-game button icons*: *Match my controller*, *Xbox*, *Nintendo*, atau *Keyboard*. Ikon ini
menggantikan ikon PlayStation di tutorial, daftar jurus, dan perintah quick-time event; gambar
controller di menu jeda tetap DualShock 4. *Keyboard* menampilkan tombol keyboard yang menekan
setiap tombol controller, mengikuti pemetaan keyboard Anda (tombol yang diubah baru tampil saat game
dimulai berikutnya); *Match my controller* juga menampilkan tombol keyboard jika tidak ada gamepad
yang terhubung. Launcher menulis salinan dua file game yang sudah di-patch ke folder data port dan
tidak pernah mengubah folder game Anda. Controller baru dikenali setelah restart. Tanpa launcher,
atur `SPARTAN_GLYPH_STYLE` ke `auto`, `xbox`, `nintendo`, atau `keyboard` sebelum menjalankan
`run.py`.

Di menu: L1/R1 atau Q/E berpindah tab. Di daftar save: panah atau d-pad untuk memilih, Enter atau
Cross untuk konfirmasi, Esc atau Circle untuk batal. Keyboard Mac tidak punya tombol Insert: di
sana **`** (tombol di kiri angka 1) membuka menu, dan Insert tetap berfungsi di keyboard yang
memilikinya.

## Mengimpor save shadPS4

Hanya **save shadPS4 dari game ini** yang kompatibel. Save RPCS3 berasal dari game PS3 dan tidak
akan bisa dipakai. Gunakan title ID yang sama (contoh ini memakai `CUSA01623`).

1. Tutup game dan shadPS4. Cadangkan kedua folder save.
2. Cari sumbernya di folder data shadPS4: `user\savedata\1\CUSA01623\` di versi lama, atau
   `home\<user-id>\savedata\CUSA01623\` di versi baru. Di Mac, folder data shadPS4 biasanya
   `~/Library/Application Support/shadPS4`.
3. Tujuannya adalah **`user\savedata\1\CUSA01623\` di sebelah `SpartanPort.exe`**.
   Contoh: `C:\Games\spartanport-windows\user\savedata\1\CUSA01623\`. Dengan **Saves folder**
   khusus di launcher, pakai `<folder khusus>\savedata\1\CUSA01623\`. Di Mac (aplikasi):
   `~/Library/Application Support/spartanport/user/savedata/1/CUSA01623/`; dari build source,
   `user/savedata/1/CUSA01623/` di folder proyek.
4. Salin setiap folder slot ke sana, dengan nama dan file game-nya tetap. Jangan membuat folder
   `CUSA01623` lagi di dalamnya. Jangan ikutkan folder `sce_sys` internal slot ke data game.
5. Di samping setiap slot, buat `<nama slot>.sce_sys` jika belum ada. Anda bisa menyalin
   `sce_sys\icon0.png` dari shadPS4 ke sana. **Jangan mengganti nama `param.sfo` menjadi
   `param.bin`**: formatnya berbeda. Pertahankan `param.bin` milik port yang sudah ada. Tanpa file
   itu, slot tampil dengan nama foldernya; menyimpan lagi di port akan menulis metadatanya dan
   memperbarui informasi yang tampil.
6. Jalankan port dan pilih **Load Game**. Save yang sudah tamat juga bisa diimpor.

Dialog save di port menampilkan paling banyak **32 entri**. Jika slot yang diimpor tidak muncul di
daftar yang panjang, uji dengan **Saves folder** terpisah yang hanya berisi slot itu di bawah
`savedata\1\CUSA01623\`, beserta folder metadata di sampingnya. Simpan save aslinya dan kembalikan
pengaturan Saves folder sebelumnya setelah pengujian.

## Overlay pihak ketiga (Windows)

Proses game-nya adalah **`bin\spartanport-probe.exe`**, bukan `SpartanPort.exe` (build dari source
memakai `out\spartanport-probe.exe`). Tambahkan file itu ke RTSS dan aktifkan on-screen display
Afterburner. Di installer ReShade, pilih file yang sama dan API **Vulkan**.

Jika overlay tetap tidak muncul, laporkan versi port dan overlay, versi port terakhir yang masih
berfungsi, dan lampirkan `user\last_run.log`. Pemeriksaan ini tidak menjamin perbaikan untuk semua
konfigurasi overlay.

## Overlay di Mac

RTSS, Afterburner, dan ReShade tidak tersedia untuk macOS. Metal performance HUD dari Apple
menggantikannya: **Advanced → macOS → Metal performance HUD** di launcher, atau `MTL_HUD_ENABLED=1`
jika memulai tanpa launcher (Command-F9 menyalakan dan mematikannya). Proses game-nya adalah
`spartanport-probe` (di dalam aplikasi: `SpartanPort.app/Contents/Resources/bin/spartanport-probe`),
nama yang juga ditampilkan Activity Monitor.

## Pemecahan masalah

- Error format executable: build dari source menerima container PS4 SELF yang tidak terenkripsi
  (plaintext) serta executable dan modul ELF x86-64 little-endian yang sudah dibongkar (unpacked).
  ELF unpacked yang valid sebelumnya ditolak dengan `prepare failed: expected PS4 SELF`. File dalam
  format lain dan segmen SELF yang terenkripsi/terkompresi tetap membutuhkan dump game yang
  disiapkan dengan benar.
- Layar hitam saat mulai: pakai rilis terbaru, yang sudah berisi patch deadlock saat mulai. Jika
  masih terjadi, laporkan GPU, driver, build game, dan isi **Advanced → Log**. Menghapus cache
  shader bukan solusi umum dan membuatnya harus dibangun ulang saat game berikutnya dimulai.
- Game tertutup dengan "cannot create ... guest memory (error 1450)": Windows kehabisan memori
  virtual untuk mengalokasikan pool memori game. Perbesar page file: tekan **Win + R**, ketik
  `SystemPropertiesAdvanced`, buka pengaturan **Performance** → **Advanced** → **Virtual memory**
  Change, matikan pengelolaan otomatis, pilih drive **C:**, atur ukuran khusus (misalnya 16384 MB
  awal, 24576 MB maksimal), klik **Set**, **OK**, lalu restart PC.
- Game tidak mau terbuka: periksa **Advanced → Log**, atau kirim `user\last_run.log` bersama laporan
  Anda. Dengan **Saves folder** khusus, `last_run.log` ada di folder itu.
- Tekstur kuning/oranye/putih atau pencahayaan salah: coba matikan **Performance → GPU data →
  Deferred GPU readbacks**, lalu restart. Cara ini bisa membuat game patah-patah.
- Di Mac, "God of War III is damaged" atau "cannot be opened": jalankan lagi baris `xattr` di
  [langkah macOS](#macos-apple-silicon-eksperimental). "The game needs Rosetta 2": pasang dengan
  `softwareupdate --install-rosetta --agree-to-license`. `STOP: macOS 26 or newer is needed`: driver
  Vulkan (KosmicKrisp) butuh macOS 26 (Tahoe).
- Kegagalan rendering khusus GPU tertentu, crash, masalah audio, dan hambatan progres masih
  diselidiki. Periksa [catatan rilis](https://github.com/FelipePrado0/SpartanPort/releases/latest)
  dan [issues](https://github.com/FelipePrado0/SpartanPort/issues) sebelum melapor; jika relevan,
  sertakan save dari sebelum masalah terjadi.

## Performa dan kompatibilitas

Pengujian sebelumnya di AMD Radeon RX 6700 XT, Ryzen 5 5600X, dan 32 GB mencatat rata-rata 144 FPS
(55 sampai 240) di 1080p dengan frame rate engine 240 FPS. Ini hasil acuan, bukan benchmark setiap
rilis maupun jaminan untuk sistem lain.

**Sudah diuji dan bisa dimainkan dari awal sampai tamat** di 1080p native dengan frame rate engine
240 FPS di sistem uji. Tekstur rusak, crash, dan hambatan progres juga dilaporkan di konfigurasi
lain, termasuk di 1080p. Lihat masalah yang sudah diketahui di catatan rilis.

Di Mac mini dengan M4 Pro (macOS 27, VSync mati), pertarungan pertama berjalan sekitar 52 FPS di
720p dengan MetalFX dan sekitar 32 FPS di 1080p native; yang membatasi adalah sisi GPU
([pengukuran](packaging/macos/README.md#fewer-gpu-waits-experimental)). Mac lain belum diuji.

## Build dari source

### Windows

Pasang Python 3.10 atau lebih baru dari python.org, dengan dukungan Tk, lalu pasang dependensi
launcher dan penulisan ulang instruksi di PowerShell:

```powershell
python -m pip install pillow iced-x86==1.21.0
```

Perintah build berikut memakai MSYS2 CLANG64; perintah launcher yang ditandai PowerShell memakai
instalasi Python untuk Windows.

Pengembangan dilakukan di branch `spartanport`; `main` menerima penggabungan yang sudah diuji.

1. Pasang MSYS2 (`winget install MSYS2.MSYS2`) dan, di shell **MSYS2 CLANG64**, paket-paket yang
   tercantum di [packaging/windows/README.md](https://github.com/FelipePrado0/SpartanPort/blob/main/packaging/windows/README.md).
2. Clone repository beserta submodule-nya, lalu build:

   ```bash
   git clone --recursive https://github.com/FelipePrado0/SpartanPort
   cd SpartanPort
   git checkout spartanport   # branch pengembangan; lewati untuk build main
   bash build.sh
   ```

3. Jalankan launcher (di PowerShell, di folder proyek):

   ```powershell
   python launcher/spartanport_launcher_win.py
   ```

4. Di **Game**, pilih folder game dan patch. Ubah **Graphics** dan **Performance**, klik **Save**
   untuk perubahan yang tertunda, lalu **PLAY**.

Untuk bermain dengan pengaturan tersimpan tanpa membuka jendela launcher (untuk shortcut atau
Steam):

```powershell
python launcher/spartanport_launcher_win.py --play
```

Atau tanpa launcher sama sekali:

```powershell
$env:SPARTAN_GAME_DIR = 'D:\path\CUSA01623'
python run.py
```

### Linux (Ubuntu 24.04)

Untuk clone baru, jalankan perintah berikut di shell Linux. Script dependensinya memasang paket
sistem dengan sudo, memilih GCC 14 sebagai compiler bawaan, dan membuat `out/venv` berisi
PyInstaller, Pillow, dan iced-x86. Script ini ditujukan untuk Ubuntu 24.04; sesuaikan dependensinya
di distribusi lain. Jika sudah clone, mulai dari folder repository dan lewati dua perintah pertama.

```bash
git clone --recursive https://github.com/FelipePrado0/SpartanPort
cd SpartanPort
bash packaging/linux/ci-deps.sh
bash build.sh
out/venv/bin/python launcher/spartanport_launcher_win.py
```

Untuk membuat AppImage setelah build:

```bash
PATH="$PWD/out/venv/bin:$PATH" bash packaging/linux/build.sh
./dist/spartanport-x86_64.AppImage
```

Lingkungan build dibuat sebelum perintah packaging. Build di distribusi yang lebih baru bisa
membutuhkan glibc yang lebih baru; build rilis publik memakai Ubuntu 24.04. Dari repository, pakai
`out/venv/bin/python launcher/spartanport_launcher_win.py --play` untuk pengaturan launcher yang
tersimpan, atau `SPARTAN_GAME_DIR=/path/ke/CUSA01623 out/venv/bin/python run.py` untuk menjalankan
langsung.

### macOS

Anda perlu Xcode command line tools (`xcode-select --install`), `brew install cmake ninja pkg-config`
dari Homebrew, Rosetta 2, dan Python 3 dengan Tk dan Pillow untuk launcher
(`brew install python python-tk`, lalu `python3 -m pip install pillow`). Build pertama mengunduh dan
membangun library x86-64 yang dipakai game (sekitar 5 menit; `packaging/macos/deps.sh`).

```bash
git clone --recursive https://github.com/nizwar/gow3_macos && cd gow3_macos
git checkout macos-port            # pekerjaan macOS
./play-mac.sh                      # build, mencari dump di ~/Downloads, ~/Desktop, atau ~/Documents, lalu main
./play-mac.sh /path/ke/CUSA01623   # folder itu (eboot.bin, sce_module, sce_sys)
./play-mac.sh --launcher           # launcher: pengaturan, save, mod
bash packaging/macos/package.sh    # dist/spartanport-macos.dmg dan dist/SpartanPort.app: untuk rilis
```

Dari repository, save, `spartanport.ini`, cache shader, dan `user/last_run.log` ada di folder
proyek; `python3 launcher/spartanport_launcher_win.py --play` memulai dengan pengaturan launcher yang
tersimpan, dan `SPARTAN_GAME_DIR=/path/ke/CUSA01623 python3 run.py` tanpa launcher. Dari
repository, **Advanced → Desktop shortcut** menaruh aplikasi di desktop yang membuka launcher.

## Pengujian

Jalankan dari root repository setelah build. Tes C++ pertama di bawah ini tidak butuh dump game.

### Python

Di Windows, pakai PowerShell. Di Linux, ganti `python` dengan `out/venv/bin/python`.

```powershell
python -m unittest discover -s tests -p "test_*.py"
```

### Tes C++ di Windows (MSYS2 CLANG64)

```bash
source ./msys2-env.sh
ninja -C out/gpu perf-overlay-test warmup-inbox-test graphics-settings-test
out/gpu/perf-overlay-test.exe
out/gpu/warmup-inbox-test.exe
out/gpu/graphics-settings-test.exe
```

### Tes C/C++ di Linux

```bash
bash build.sh --test
ninja -C out/gpu perf-overlay-test warmup-inbox-test graphics-settings-test
out/gpu/perf-overlay-test
out/gpu/warmup-inbox-test
out/gpu/graphics-settings-test
```

`bash build.sh --test` menjalankan tes runtime C tambahan di Linux dan macOS. Di Windows, build
berhenti sebelum bagian itu; pakai target Ninja di atas.

### Tes C/C++ di macOS

```bash
bash build.sh --test
source packaging/macos/env.sh   # compiler dan library x86-64 untuk ninja
ninja -C out/gpu perf-overlay-test warmup-inbox-test graphics-settings-test
out/gpu/perf-overlay-test
out/gpu/warmup-inbox-test
out/gpu/graphics-settings-test
```

### Pemeriksaan dengan game yang sudah disiapkan

Setelah menyiapkan dump Anda sendiri, `out/eboot.elf` dan `out/boot-linked.bin` dibutuhkan untuk
pemeriksaan berikut. Di MSYS2 CLANG64 di Windows, ganti contoh path game dengan milik Anda:

```bash
ninja -C out/gpu stat-multipliers-test
out/gpu/stat-multipliers-test.exe out/eboot.elf
out/spartanport-probe.exe out/boot-linked.bin --app0 "D:/Games/CUSA01623" --check-imports
```

Di Linux dan macOS, pakai `out/gpu/stat-multipliers-test` dan `out/spartanport-probe` tanpa `.exe`,
dan path dari sistem itu. `--check-imports` memeriksa import sistem dan keluar tanpa memulai
gameplay.
Target tes lainnya tercantum di [gpu/CMakeLists.txt](https://github.com/FelipePrado0/SpartanPort/blob/main/gpu/CMakeLists.txt).

## Cara kerjanya

Sisi CPU-nya native: file eksekusi asli game berjalan langsung di prosesor PC (PS4 memakai
arsitektur x86-64 yang sama), dan runtime yang ditulis khusus untuk game ini menggantikan library
sistem PS4, tanpa emulasi CPU. Grafiknya diterjemahkan: berjalan di video core
[shadPS4](https://github.com/shadps4-emu/shadPS4), yang mengubah perintah GPU dan shader PS4 ke
Vulkan, dengan perbaikan rendering game ini dari
[branch `eltutz` milik cuesta4](https://github.com/cuesta4/shadPS4/tree/eltutz). Menjalankan kode
game langsung di CPU juga cara kerja shadPS4; yang diubah proyek ini adalah lapisan sistem dan
pekerjaan khusus game ini (patch, cache shader di latar belakang, launcher, dan menu di dalam
game). Di Mac, Rosetta 2 dari Apple menerjemahkan kode x86-64 itu untuk Apple Silicon, dan grafiknya
sampai ke Metal lewat driver Vulkan KosmicKrisp dari Mesa.
Proyek ini adalah fork dari [port Windows milik Supermedo](https://github.com/Supermedo/bloodborne_pc)
atas [bloodborne_pc milik deadinside28](https://github.com/deadinside28/bloodborne_pc) (lihat
[Kredit](#kredit)).

- Patch dan hook di dalam game (cheat, pengali, bar darah) menemukan lokasinya lewat signature:
  byte asli di sekitar masing-masing, di mana pun sebuah rilis menaruh kode itu
  (`tools/make_signatures.py`). Lokasi yang tidak ditemukan hanya mematikan patch atau hook itu;
  game tetap jalan tanpanya, dan log serta menu menyebutkan alasannya.

| Bagian | Lokasi | Fungsinya |
|---|---|---|
| Persiapan | `scripts/` | Membaca `eboot.bin`, menerapkan relokasinya, dan menggabungkan `libc` dan `libSceFios2` milik game menjadi satu image |
| Loader | `src/probe.c` | Memuat image, memasang hook yang sudah divalidasi (cheat, pengali, bar darah), dan memulai kode asli game |
| Runtime | `src/runtime_*.c` | Mengimplementasikan ulang fungsi sistem PS4: memori, thread, file, audio, video, controller, save, dan layanan |
| GPU | `gpu/shadps4/` | Video core shadPS4, yang menerjemahkan perintah GPU dan shader PS4 ke Vulkan, dengan perbaikan dari cuesta4 untuk game ini (branch `eltutz`) dan optimasi kecepatan dari port ini (cache shader di latar belakang, pembacaan data yang ditunda) |
| Menu di dalam game | `gpu/shim/spartanport_overlay.cpp` | Menu Dear ImGui dan overlay performa; pengaturan di `gpu/shim/spartanport_settings.cpp` |
| Patch | `patches/CUSA01623.xml`, `scripts/patches.py` | Diterapkan di memori saat mulai, tanpa mengubah file game |
| Launcher | `launcher/spartanport_launcher_win.py` | Pengaturan, patch, mod, kontrol, dan tombol main |
| macOS | `src/compat_mac.c`, `packaging/macos/` | Rosetta 2, tata letak memori dan state thread di Mac, KosmicKrisp; upscaling MetalFX (`host_passes/metalfx_pass.cpp`, `vk_metalfx.mm`); aplikasi dan disk image-nya |

Dokumentasi lain: [mod](https://github.com/FelipePrado0/SpartanPort/blob/main/docs/MODS.md), [patch](https://github.com/FelipePrado0/SpartanPort/blob/main/docs/PATCHES.md), [peta frame dan riwayat riset upscaler](https://github.com/FelipePrado0/SpartanPort/blob/main/docs/upscaler.md),
dan [pekerjaan GPU paralel](https://github.com/FelipePrado0/SpartanPort/blob/main/docs/parallel_gpu.md).

## Kredit

Proyek ini adalah fork dari port Windows milik Supermedo, yang dibangun di atas port asli milik
deadinside28:

- **deadinside28**: [bloodborne_pc](https://github.com/deadinside28/bloodborne_pc), port native
  aslinya.
- **Supermedo** (Mohammed Albarghouthi): [bloodborne_pc untuk Windows](https://github.com/Supermedo/bloodborne_pc),
  fork asal proyek ini.
- **cuesta4**: [fork shadPS4 yang berfokus pada game ini](https://github.com/cuesta4/shadPS4/tree/eltutz)
  (branch `eltutz`). Rendering game di port ini bergantung pada perbaikannya: penulisan ulang blend
  GNM, state depth/stencil, dan image aliasing. cuesta4 juga salah satu pembuat patch resolusi,
  perbaikan tekstur, 120 FPS, dan lewati video (di bawah). Jika Anda bermain di shadPS4, build
  inilah yang dianjurkan untuk game ini.
- **Tim shadPS4**: video core [shadPS4](https://github.com/shadps4-emu/shadPS4), yang melakukan
  seluruh penerjemahan GPU dan shader ke Vulkan di port ini.
- **[WilkPrintes](https://github.com/WilkPrintes)**: merancang dan membangun
  [situs web SpartanPort](https://spartanport.com/en). Terima kasih khusus karena telah memberi
  proyek ini rumahnya.

Patch: kvicken dan cuesta4 (resolusi, perbaikan tekstur, 120 FPS, dan lewati video, berdasarkan
patch PS3 dari illusion0001), dipublikasikan untuk shadPS4 di
[shadps4-emu/ps4_cheats#145](https://github.com/shadps4-emu/ps4_cheats/pull/145) dan diadaptasi
untuk executable ini. Patch 144 dan 240 FPS diadaptasi oleh Felipe Prado dari patch 120 FPS; patch
100 FPS adalah patch yang sama dengan nilai 100.
Cheat: diadaptasi dari [cheat GoldHEN](https://github.com/GoldHEN/GoldHEN_Cheat_Repository) milik
Celogamez.

Juga dipakai: [LibAtrac9](https://github.com/Thealexbarney/LibAtrac9), [FFmpeg](https://ffmpeg.org),
[SDL3](https://github.com/libsdl-org/SDL), [Dear ImGui](https://github.com/ocornut/imgui),
[sirit](https://github.com/shadps4-emu/sirit), [magic_enum](https://github.com/Neargye/magic_enum),
[miniz](https://github.com/richgel999/miniz), [xbyak](https://github.com/herumi/xbyak),
[Vulkan Memory Allocator](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator),
[FSR-Vulkan](https://github.com/FireBurn/FSR-Vulkan) dan AMD FidelityFX SDK,
[MSYS2](https://www.msys2.org), [LLVM](https://llvm.org), dan [Pillow](https://python-pillow.org).
Di macOS: driver Vulkan KosmicKrisp dari [Mesa](https://mesa3d.org) (dari rilis shadPS4 untuk
macOS), MetalFX dari Apple, [mimalloc](https://github.com/microsoft/mimalloc), dan
[PyInstaller](https://pyinstaller.org) untuk aplikasinya.

## Lisensi

GNU GPL v2 atau yang lebih baru ([LICENSE](https://github.com/FelipePrado0/SpartanPort/blob/main/LICENSE)).
Komponen pihak ketiga tetap memakai lisensinya masing-masing.
