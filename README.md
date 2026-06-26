# ALPAY E-Wallet 💳

Aplikasi E-Wallet interaktif berbasis antarmuka baris perintah (CLI/Console) yang ditulis dalam bahasa **C**. Proyek ini dibuat selama **10 hari** sebagai proyek pemrograman pertama sekaligus tugas akhir Ujian Akhir Semester (UAS).

Aplikasi ini dirancang dengan antarmuka yang dinamis memanfaatkan Windows Console API (`windows.h` dan `conio.h`) untuk memberikan pengalaman pengguna yang lebih hidup melalui pewarnaan teks, navigasi posisi (`gotoxy`), dan pergerakan bingkai menu.

---

## 🚀 Fitur Utama

### 👤 Menu Pengguna (User)
- **Registrasi Akun Baru**: Pendaftaran akun pengguna dengan validasi format masukan secara real-time.
- **Login Akun**: Keamanan login menggunakan enkripsi visual (masking sandi dengan bintang `*`).
- **Top-Up Saldo**: Penambahan saldo akun secara mandiri.
- **Transfer Saldo**: Mengirimkan dana ke pengguna lain dengan verifikasi PIN transaksi.
- **Lihat Profil**: Menampilkan data detail akun (username, kata sandi, PIN, dan sisa saldo).
- **Mutasi Transaksi**: Riwayat lengkap transaksi keluar dan masuk khusus untuk akun pengguna bersangkutan.

### 🔑 Menu Admin
- **Login Khusus Admin**: Masuk ke panel kontrol admin menggunakan kredensial khusus.
- **Top-Up Admin**: Menambahkan saldo langsung ke akun pengguna tertentu.
- **Transfer Admin**: Melakukan pemindahan saldo dari pengirim ke penerima tertentu atas nama sistem.
- **Daftar Akun**: Menampilkan list seluruh akun pengguna yang terdaftar di dalam database sistem.
- **Cari Akun**: Mempermudah pencarian profil dan data detail milik pengguna tertentu.
- **Lihat Riwayat Transaksi**: Laporan transaksi menyeluruh (log global) yang terjadi pada sistem ALPAY.

---

## 🛠️ Teknologi & API yang Digunakan

1. **Bahasa Pemrograman**: C (Standar C99/C11/C17).
2. **Windows Console API**:
   - `windows.h`: Digunakan untuk manipulasi penempatan kursor (`COORD` dan `SetConsoleCursorPosition`), pengaturan warna teks/latar (`SetConsoleTextAttribute`), serta efek transisi jeda (`Sleep`).
   - `conio.h`: Digunakan untuk menangkap input karakter keyboard secara langsung tanpa menekan enter (`getch`) untuk navigasi menu dan masking password.
3. **Penyimpanan Data Sederhana**:
   - Berbasis file teks (`user.txt` dan `histori.txt`) untuk menyimpan data pengguna terdaftar dan rekaman mutasi secara presisten.

---

## 💻 Cara Kompilasi dan Menjalankan

### Persyaratan Sistem
- Sistem Operasi **Windows** (karena menggunakan API Windows).
- **GCC Compiler** (MinGW).

### Langkah-Langkah
1. Buka Command Prompt (CMD) atau PowerShell di direktori proyek.
2. Kompilasi program menggunakan perintah berikut:
   ```bash
   gcc alprojectreal.c -o alprojectreal.exe
   ```
3. Jalankan aplikasi hasil kompilasi:
   ```bash
   alprojectreal.exe
   ```

---

## 📂 Struktur Proyek
- `alprojectreal.c`: Source code utama program C.
- `ALFARIZI FLOWCHART UAS.png` / `drawio`: Diagram alur sistem aplikasi ALPAY.
- `user.txt` *(auto-generated)*: File penyimpanan data akun pengguna (`username$password$pin$saldo`).
- `histori.txt` *(auto-generated)*: File penyimpanan log transaksi (`pengirim$penerima$nominal$tipe`).

---

*Proyek ini diarsipkan untuk kenangan masa-masa awal belajar pemrograman C. Dikembangkan dengan sepenuh hati dalam waktu 10 hari.* ✨
