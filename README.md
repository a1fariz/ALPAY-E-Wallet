# 💳 ALPAY E-Wallet — Console-Based E-Wallet System

<p align="center">
  <img src="https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language C"/>
  <img src="https://img.shields.io/badge/Platform-Windows%20Console%20API-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows Platform"/>
  <img src="https://img.shields.io/badge/Compiler-GCC%20%2F%20MinGW-brightgreen?style=for-the-badge" alt="GCC MinGW"/>
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" alt="MIT License"/>
</p>

Aplikasi simulasi dompet digital (**E-Wallet**) interaktif berbasis antarmuka baris perintah (*Console / CLI*) yang ditulis murni dalam bahasa pemrograman **C**. Proyek ini dirancang memanfaatkan **Windows Console API** (`windows.h` & `conio.h`) untuk menghadirkan pengalaman antarmuka yang dinamis melalui pewarnaan teks, navigasi kursor kustom `gotoxy`, masking sandi visual `*`, dan pergerakan bingkai menu responsif.

---

## 📑 Daftar Isi
- [Fitur Utama](#-fitur-utama)
- [Arsitektur & Penyimpanan Data](#-arsitektur--penyimpanan-data)
- [Diagram Alur Sistem](#-diagram-alur-sistem)
- [Teknologi & API](#-teknologi--api)
- [Cara Kompilasi & Menjalankan](#-cara-kompilasi--menjalankan)
- [Struktur Direktori](#-struktur-direktori)
- [Author & Catatan](#-author--catatan)

---

## ✨ Fitur Utama

### 👤 Menu Pengguna (User)
- **Registrasi Akun Baru**: Pendaftaran akun pengguna dengan validasi format masukan secara real-time.
- **Login Akun Terproteksi**: Keamanan otentikasi login menggunakan masking karakter kata sandi (`*`).
- **Cek Saldo & Profil**: Menampilkan ringkasan detail akun (Username, Kata Sandi, PIN, dan Sisa Saldo).
- **Top-Up Saldo Mandiri**: Pengisian saldo akun secara mandiri.
- **Transfer Antar Pengguna**: Pengiriman dana instan ke sesama pengguna dengan verifikasi keamanan PIN 6 digit.
- **Tarik Tunai**: Simulasi penarikan saldo dengan validasi batas saldo minimum.
- **Pembayaran Tagihan**: Pembayaran tagihan utilitas (Listrik PLN, Pulsa/Paket Data, PDAM, Internet).
- **Mutasi Transaksi**: Riwayat mutasi transaksi keluar dan masuk khusus untuk akun pengguna bersangkutan.

### 🛡️ Panel Administrator (Admin)
- **Login Khusus Admin**: Masuk ke panel kontrol admin menggunakan kredensial khusus.
- **Top-Up Admin**: Menambahkan saldo langsung ke akun pengguna tertentu dalam sistem.
- **Transfer Admin**: Melakukan pemindahan saldo antar pengguna atas nama sistem.
- **Daftar Seluruh Akun**: Menampilkan tabel seluruh data akun yang terdaftar dalam database sistem.
- **Pencarian Akun**: Mempermudah pencarian profil dan data detail milik akun pengguna tertentu.
- **Laporan Transaksi Global**: Audit log dan rekap riwayat seluruh transaksi yang terjadi di sistem ALPAY.

---

## 🗄️ Arsitektur & Penyimpanan Data

Sistem menggunakan penyimpanan berbasis berkas flat (*flat-file database*) yang persisten:
- **`user.txt`**: Menyimpan rekaman pengguna terdaftar dengan format delimitasi string:
  ```text
  username$password$pin$saldo
  ```
- **`histori.txt`**: Menyimpan rekaman log transaksi global:
  ```text
  pengirim$penerima$nominal$jenis_transaksi
  ```

---

## 📊 Diagram Alur Sistem

Alur kerja dan logika percabangan aplikasi didokumentasikan lengkap pada diagram alur:
- Diagram Gambar: `ALFARIZI FLOWCHART UAS.png`
- Format Sumber Editable: `ALFARIZI FLOWCHART UAS.drawio`

---

## 🛠️ Teknologi & API

1. **Bahasa Pemrograman**: C (Standar C99 / C11 / C17).
2. **Windows Console API**:
   - `windows.h`: Manipulasi posisi kursor (`COORD`, `SetConsoleCursorPosition`), warna teks/background (`SetConsoleTextAttribute`), dan delay efek transisi (`Sleep`).
   - `conio.h`: Menangkap masukan karakter keyboard secara instan (`getch`) untuk masking sandi dan navigasi menu interaktif.
3. **Standar I/O & File Operations**: `stdio.h`, `stdlib.h`, `string.h`, `unistd.h`.

---

## 🚀 Cara Kompilasi & Menjalankan

### Prasyarat
- Sistem Operasi **Windows** (karena menggunakan dependensi Windows Console API).
- Compiler **GCC / MinGW**.

### Langkah-langkah
1. **Clone repositori**:
   ```bash
   git clone https://github.com/a1fariz/ALPAY-E-Wallet.git
   cd ALPAY-E-Wallet
   ```
2. **Kompilasi program**:
   ```bash
   gcc alprojectreal.c -o alprojectreal.exe
   ```
3. **Jalankan aplikasi**:
   ```bash
   alprojectreal.exe
   ```

---

## 📁 Struktur Direktori

```text
alfariz_projectkan/
├── alprojectreal.c             # Source code utama program C
├── alprojectreal.exe           # Executable biner hasil kompilasi
├── ALFARIZI FLOWCHART UAS.png  # Diagram alur sistem alpay
├── ALFARIZI FLOWCHART UAS.drawio
├── user.txt                    # Penyimpanan data pengguna (auto-generated)
├── histori.txt                 # Penyimpanan riwayat transaksi (auto-generated)
└── README.md                   # Dokumentasi proyek
```

---

## 👨‍💻 Author

Dikembangkan oleh **Muhammad Hafiz Alfarizi** ([@a1fariz](https://github.com/a1fariz)).  
*Proyek ini diarsipkan sebagai tonggak awal pembelajaran algoritma pemrograman dan manipulasi sistem I/O tingkat rendah dalam bahasa C.*
