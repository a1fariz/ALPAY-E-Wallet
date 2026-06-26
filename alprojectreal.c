#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

/////////////////////////// WARNA
////////////////////////////////////////////////////////
#define handle GetStdHandle(STD_OUTPUT_HANDLE)
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define SILVER 3
#define RED 4
#define COKLAT 5
#define GREY 6
#define WHITE 7
#define DARKGREY 8
#define BLUE 9
#define LIGHTGREEN 10
#define CYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define LIGHTCYAN 14
#define LIGHTWHITE 15
/////////////////////////////  VARIABLE GLOBAL
/////////////////////////////////////////////
char tam[100] = {};
char input;
char idx;
char ch;
int choice;
int i = 0;
int test = 0;
int a = 0;
int salah = 0;
int betul = 0;
int posisi = 1;
int dex = 0, sama = 0;
int tams = 0;
int indeks;
int jumlah;
int ids[10] = {0};
char usernames[10][50] = {0};
char passwords[10][50] = {0};
int pins[10] = {0};
double saldos[10] = {0.0};

/////////////////////////////////////////////////////////////////

//////////////////////// FUNGSI ////////////////////////////////////////
// Forward declarations
void al();
void all();
void registasi_logo();
void logo_login();
void top_up_logo();
void logo_admin();
void settingtext();
void alpay();
void menu_admin();
int menu_utama();
int userMenu(int idx);

//////////////////////// FUNGSI STRUCT
//////////////////////////////////////////////////////

void gotoxy(int x, int y) {
  COORD position = {x, y};
  SetConsoleCursorPosition(handle, position);
}
void setColor(int text, int background) {
  SetConsoleTextAttribute(handle, background * 16 + text);
}

void clearScreen() { system("cls"); }

void drawBox(int x, int y, int panjang, int lebar, int text, int background) {
  for (int i = 0; i <= panjang; i++) {
    for (int j = 0; j <= lebar; j++) {
      if (i == 0 || j == 0 || i == panjang || j == lebar) {
        gotoxy(x + i, y + j);
        setColor(text, text);
        printf("%c", 219);
        Sleep(0);
      } else {
        gotoxy(x + i, y + j);
        setColor(background, background);
        printf(" ");
      }
    }
  }
}

void bingkai_tombol(int x, int y, int a, int b) {
  for (int i = 0; i < b; i++) {
    gotoxy(x, y + i);
    for (int j = 0; j < a; j++) {
      if (i == 0 && j >= 1 && j < a - 1) {
        printf("%c", 223);
      } else if (j == 0 || j == a - 1)
        printf("%c", 219);
      else if (i == b - 1)
        printf("%c", 220);
      else if (i == 0 && j == 0 || i == 0 && j == a - 1)
        printf("%c", 219);
      else
        printf(" ");
    }
  }
}
///////////////////////////////////////////////////////////////////// VALIDASI
///////////////////////////////////

void validasi_pin(char *temp) {
  int index = 0;
  char input;
  while (1) {
    input = getch();
    if (index < 4 && input >= '0' && input <= '9') {
      printf("%c", input);
      temp[index] = input;
      index++;
    } else if (input == 8 && index > 0) { // Backspace
      printf("\b \b");
      index--;
      temp[index] = '\0';
    } else if (input == 13) { // Enter
      temp[index] = '\0';
      break;
    }
  }
  // printf("%s",temp);
  // strcpy(pin, temp);
}

int val_saldo() {
  int index = 0;
  char input;
  char temp[100] = {};
  while (1) {
    input = getch();
    if (index < 10 && (input >= '0' && input <= '9')) {
      printf("%c", input);
      temp[index] = input;
      index++;
    } else if (input == 8 && index > 0) { // Backspace
      printf("\b \b");
      index--;
      temp[index] = '\0';
    } else if (input == 13 && index >= 6) { // Ente
      break;
    }
  }
  temp[index] = '\0';
  return atoi(temp);
}

char *val_user(char *username) {
  int index = 0;
  char input;
  char temp[100] = {};
  while (1) {
    input = getch();
    if (index < 50 &&
        ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') ||
         (input >= '0' && input <= '9'))) {
      printf("%c", input);
      temp[index] = input;
      index++;
    } else if (input == 8 && index > 0) { // Backspace
      printf("\b \b");
      index--;
      temp[index] = '\0';
    } else if (input == 13 && index >= 4) { // Enter
      break;
    }
  }
  temp[index] = '\0';
  return strcpy(username, temp);
}

char *val_pas_user(char *password) {
  char input;
  char temp[100] = {};
  int index = 0;
  while (1) {
    input = getch();
    if (index < 50 &&
        ((input >= 'a' && input <= 'z') || (input >= '0' && input <= '9'))) {
      printf("*");
      temp[index] = input;
      index++;
    } else if (input == 8 && index > 0) { // Backspace
      printf("\b \b");
      index--;
      temp[index] = '\0';
    } else if (input == 13 && index >= 4) { // Enter
      break;
    }
  }
  temp[index] = '\0';
  return strcpy(password, temp);
}

char *valus_admin(char *user) {
  i = 0;
  while ((idx = getch()) != 13 || i < 6) {
    if (i < 30 && (idx >= 'A' && idx <= 'Z' || idx >= 'a' && idx <= 'z' ||
                   idx >= '1' && idx <= '9' && i != 0 && tams != tam[i - 1])) {
      if (idx == 32) {
        printf("%c", idx);
        user[i] = idx;
        tams++;
        i++;
      } else {
        user[i] = idx;
        printf("%c", idx);
        i++;
      }
    } else if (idx == 8 && i > 0) {
      if (user[i - 1] == ' ') {
        printf("\b \b");
        user[i] = '\0';
        i--;
        tams--;
      } else {
        // tam[i]='j';
        printf("\b \b");
        user[i] = '\0';
        i--;
      }
    }
  }
  user[i] = '\0';
  return user;
}

char *val_pas_admin(char *pas) {
  char tamp[100] = {};
  int index = 0;
  while ((input = getch()) != 13 || index < 4) {
    if (index < 20 &&
        (((input >= '0' && input <= '9') &&
          (tamp[index - 1] != input || tamp[index - 2] != input)) ||
         ((input >= 'a' && input <= 'z') &&
          (tamp[index - 1] != input || tamp[index - 2] != input)) ||
         ((input >= 'a' && input <= 'z')))) {
      printf("*", input);
      tamp[index] = input;
      index++;
    } else if (input == 8 && index != 0) {
      index--;
      printf("\b \b");
      tamp[index] = '\0';
    }
  }
  tamp[index] = '\0';
  strcpy(pas, tamp);
  return pas;
}

////////////////////////////////////////////////////////////// VALIDASI
////////////////////////////////////

///////////////////////////////////////////////////////////////// FILE
///////////////////////////////////////////////////
void tulisAkun(char usernames[10][50], char passwords[10][50], int pins[10],
               double saldos[10], int jumlah_akun) {
  FILE *file = fopen("user.txt", "w");
  if (!file) {
    printf("Gagal membuka file untuk menulis.\n");
    return;
  }

  for (int i = 0; i < jumlah_akun; i++) {

    if (strlen(usernames[i]) > 0 && strlen(passwords[i]) > 0) {
      fprintf(file, "%s$%s$%d$%.2lf\n", usernames[i], passwords[i], pins[i],
              saldos[i]);
    }
  }

  fclose(file);
}

int bacaAkun(char usernames[10][50], char passwords[10][50], int pins[10],
             double saldos[10]) {
  FILE *file = fopen("user.txt", "r");
  if (!file) {
    return 0;
  }

  int i = 0;
  while (fscanf(file, "%[^$]$%[^$]$%d$%lf\n", usernames[i], passwords[i],
                &pins[i], &saldos[i]) == 4) {
    i++;
    if (i >= 10) {
      break;
    }
  }
  fclose(file);
  return i;
}

void tulisRiwayat(char *dari, char *ke, double jumlah, char *jenis) {
  FILE *file = fopen("histori.txt", "a");
  if (!file) {
    printf("Gagal membuka file riwayat.\n");
    return;
  }

  fprintf(file, "%s$%s$%.2lf$%s\n", dari, ke, jumlah, jenis);
  fclose(file);
}

void bacaRiwayat() {
  FILE *file = fopen("histori.txt", "r");
  if (!file) {
    printf("Tidak ada riwayat transaksi.\n");
    return;
  }

  char buffer[200];
  while (fgets(buffer, sizeof(buffer), file)) {
    printf("%s", buffer);
  }
  fclose(file);
}
//////////////////////////////////// FILE TXT
//////////////////////////////////////////////////////////////
void userRegister() {
  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  registasi_logo();

  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);

  char username[50];
  char password[50];
  char tamp[10];
  int pin;

  if (jumlah_akun >= 10) {
    printf("Batas akun telah tercapai. Tidak dapat mendaftarkan akun baru.\n");
    getchar();
    return;
  }

  all();
  gotoxy(36, 15);
  printf("Masukkan Username: ");
  gotoxy(56, 15);
  val_user(username);

  gotoxy(36, 22);
  printf("Masukkan Password: ");
  gotoxy(56, 22);
  val_pas_user(password);

  al();
  gotoxy(36, 28);
  printf("Masukkan PIN (4 digit): ");
  gotoxy(60, 28);
  validasi_pin(tamp);
  pin = atoi(tamp);

  strcpy(usernames[jumlah_akun], username);
  strcpy(passwords[jumlah_akun], password);
  pins[jumlah_akun] = pin;
  saldos[jumlah_akun] = 0.0;

  tulisAkun(usernames, passwords, pins, saldos, jumlah_akun + 1);

  gotoxy(60, 40);
  printf("Pendaftaran berhasil");
  getchar();
}

void userLogin() {
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  char username[50], password[50];

  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  logo_login();
  setColor(5, 7);
  all();
  gotoxy(36, 15);
  printf("Masukkan Username: ");
  gotoxy(56, 15);
  val_user(username);
  gotoxy(36, 22);
  printf("Masukkan Password: ");
  gotoxy(56, 22);
  val_pas_user(password);

  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], username) == 0 &&
        strcmp(passwords[i], password) == 0) {
      printf("Login berhasil! Selamat datang, %s.\n", username);
      getchar();
      getchar();
      userMenu(i);
      return;
    }
  }

  printf("Username atau Password salah.\n");
  getchar();
  getchar();
}

void userTopUp(int index) {
  char usernames[10][50], passwords[10][50];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  double jumlah;

  // Validasi jika index tidak valid
  if (index < 0 || index >= jumlah_akun) {
    printf("Index akun tidak valid.\n");
    getchar();
    return;
  }

  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  al();
  gotoxy(36, 22);
  top_up_logo();

  gotoxy(36, 28);
  printf("Masukkan jumlah top-up: ");
  gotoxy(66, 28);
  jumlah = val_saldo();

  if (jumlah <= 0) {
    gotoxy(36, 30);
    printf("Jumlah top-up tidak valid.\n");
    getchar();
    return;
  }

  saldos[index] += jumlah;

  tulisAkun(usernames, passwords, pins, saldos, jumlah_akun);

  tulisRiwayat(usernames[index], usernames[index], jumlah, "topup");

  gotoxy(36, 32);
  printf("Top-up berhasil! Saldo baru: %.2f\n", saldos[index]);

  getchar();
}

void userTransfer(int index) {
  char usernames[10][50], passwords[10][50], ids[10][10];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  char target[50];
  double jumlah;

  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  printf("=== TRANSFER SALDO ===\n");
  all();
  gotoxy(36, 15);
  printf("Masukkan username penerima: ");
  gotoxy(66, 15);
  val_user(target);
  gotoxy(36, 22);
  printf("Masukkan jumlah transfer: ");
  gotoxy(66, 22);
  jumlah = val_saldo();

  if (jumlah <= 0 || saldos[index] < jumlah) {
    printf("Transfer gagal. Jumlah tidak valid atau saldo tidak cukup.\n");
    getchar();
    getchar();
    return;
  }

  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], target) == 0) {
      saldos[index] -= jumlah;
      saldos[i] += jumlah;
      tulisAkun(usernames, passwords, pins, saldos, jumlah_akun);
      tulisRiwayat(usernames[index], usernames[i], jumlah, "transfer");
      printf("Transfer berhasil! Saldo baru: %.2f\n", saldos[index]);
      getchar();
      getchar();
      return;
    }
  }

  printf("Username penerima tidak ditemukan.\n");
  getchar();
  getchar();
}

void adminTopUp() {
  clearScreen();
  char usernames[10][50], passwords[10][50];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  double jumlah;
  int index = -1;
  char user[50];

  drawBox(0, 0, 144, 34, 5, 7);
  top_up_logo();
  gotoxy(100, 7);
  printf("Daftar akun terdaftar ( Username):\n");
  for (int i = 0; i < jumlah_akun; i++) {
    gotoxy(100, 8 + i);
    printf("username : %s", usernames[i]);
  }

  all();
  gotoxy(36, 15);
  printf("Masukkan username: ");
  gotoxy(66, 15);
  val_user(user);

  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], user) == 0) {
      index = i;
      break;
    }
  }

  gotoxy(36, 22);
  printf("Masukkan jumlah top-up: ");
  gotoxy(66, 22);
  jumlah = val_saldo();

  if (jumlah <= 0) {
    printf("Jumlah top-up tidak valid.\n");
  } else {
    saldos[index] += jumlah;
    tulisAkun(usernames, passwords, pins, saldos, jumlah_akun);
    tulisRiwayat("Admin", usernames[index], jumlah, "topup");
    printf("Top-up berhasil! Saldo baru %s: %.2f\n", usernames[index],
           saldos[index]);
  }

  while (input = getch()) {

    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }

  getchar();
  getchar();
}

void adminTransfer() {

  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  char user_pengirim[50], user_penerima[50];
  double jumlah;
  int index_pengirim = -1, index_penerima = -1;

  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  logo_admin();
  printf("=== ADMIN TRANSFER SALDO ===\n");
  printf("Daftar akun terdaftar (Username):");
  for (int i = 0; i < jumlah_akun; i++) {
    setColor(5, 7);
    gotoxy(45, 6 + i);
    printf("username : %s\n", usernames[i]);
  }
  all();
  gotoxy(36, 15);
  printf("Masukkan username akun pengirim: ");
  gotoxy(66, 15);
  val_user(user_pengirim);
  gotoxy(36, 22);
  printf("Masukkan username akun penerima: ");
  gotoxy(66, 22);
  val_user(user_penerima);

  // Cari akun pengirim
  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], user_pengirim) == 0) {
      index_pengirim = i;
    }
    if (strcmp(usernames[i], user_penerima) == 0) {
      index_penerima = i;
    }
  }

  if (index_pengirim == -1 || index_penerima == -1) {
    printf("username akun tidak valid.\n");
    getchar();
    getchar();
    return;
  }
  al();
  gotoxy(36, 28);
  printf("Masukkan jumlah transfer: ");
  gotoxy(66, 28);
  jumlah = val_saldo();

  if (jumlah <= 0 || saldos[index_pengirim] < jumlah) {
    printf("Transfer gagal. Jumlah tidak valid atau saldo tidak cukup.\n");
  } else {
    saldos[index_pengirim] -= jumlah;
    saldos[index_penerima] += jumlah;
    tulisAkun(usernames, passwords, pins, saldos, jumlah_akun);
    tulisRiwayat(usernames[index_pengirim], usernames[index_penerima], jumlah,
                 "transfer");
    printf("Transfer berhasil! Saldo baru %s: %.2f\n",
           usernames[index_pengirim], saldos[index_pengirim]);
  }
  while (input = getch()) {

    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }

  getchar();
  getchar();
}

void adminHapusAkun() {
  char usernames[10][50], passwords[10][50];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  char target[50];

  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  logo_admin();
  gotoxy(100, 5);
  printf("Daftar akun terdaftar (Username):");
  for (int i = 0; i < jumlah_akun; i++) {
    setColor(5, 7);
    gotoxy(100, 6 + i);
    printf("username : %s\n", usernames[i]);
  }
  printf("=== ADMIN HAPUS AKUN ===\n");
  al();
  gotoxy(36, 28);
  printf("Masukkan username yg akan dihapus: ");
  gotoxy(66, 28);
  val_user(target);

  int found = 0;
  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], target) == 0) {
      found = 1;
      for (int j = i; j < jumlah_akun - 1; j++) {
        strcpy(usernames[j], usernames[j + 1]);
        strcpy(passwords[j], passwords[j + 1]);
        pins[j] = pins[j + 1];
        saldos[j] = saldos[j + 1];
      }
      jumlah_akun--;
      break;
    }
  }

  if (found) {
    tulisAkun(usernames, passwords, pins, saldos, jumlah_akun);
    printf("Akun berhasil dihapus.\n");
  } else {
    printf("Username tidak ditemukan.\n");
  }
  gotoxy(45, 40);
  printf("tekan esc untuk kembali");
  while (input = getch()) {

    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }

  getchar();
  getchar();
}

void adminEditAkun() {
  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  logo_admin();

  char usernames[10][50], passwords[10][50];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);

  if (jumlah_akun == 0) {
    gotoxy(45, 18);
    printf("Tidak ada akun yang terdaftar.\n");
    getchar();
    return;
  }

  char inputUsername[50];
  int index = -1;

  gotoxy(100, 16);
  printf("Daftar akun terdaftar (Username):\n");
  for (int i = 0; i < jumlah_akun; i++) {
    gotoxy(100, 17 + i);
    printf("%d. %s", i + 1, usernames[i]);
  }

  gotoxy(36, 15);
  printf("Masukkan username ingin diedit: ");
  gotoxy(68, 15);
  val_user(inputUsername);

  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], inputUsername) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    gotoxy(36, 18);
    printf("Username tidak ditemukan.\n");
    getchar();
    return;
  }

  gotoxy(100, 20);
  printf("=== DATA SEBELUM EDIT ===");
  gotoxy(100, 21);
  printf("Username: %s", usernames[index]);
  gotoxy(100, 22);
  printf("Password: %s", passwords[index]);
  gotoxy(100, 23);
  printf("PIN: %d", pins[index]);
  gotoxy(100, 24);
  printf("Saldo: %.2lf", saldos[index]);

  char newUsername[50], newPassword[50];
  int newPin;
  char tempPin[10];

  gotoxy(36, 24);
  printf("Masukkan username ( Enter tidak mengubah): ");
  gotoxy(85, 24);
  val_user(newUsername);
  if (strlen(newUsername) > 0) {
    strcpy(usernames[index], newUsername);
  }

  gotoxy(36, 26);
  printf("Masukkan password (enter tidak mengubah): ");
  gotoxy(85, 26);
  val_pas_user(newPassword);
  if (strlen(newPassword) > 0) {
    strcpy(passwords[index], newPassword);
  }

  gotoxy(36, 28);
  printf("Masukkan PIN baru (4 digit): ");
  gotoxy(70, 28);
  validasi_pin(tempPin);
  if (strlen(tempPin) > 0) {
    newPin = atoi(tempPin);
    pins[index] = newPin;
  }

  FILE *file = fopen("user.txt", "w");
  if (!file) {
    printf("Gagal membuka file untuk menulis.\n");
    return;
  }

  for (int i = 0; i < jumlah_akun; i++) {
    fprintf(file, "%s$%s$%d$%.2lf\n", usernames[i], passwords[i], pins[i],
            saldos[i]);
  }
  fclose(file);

  gotoxy(36, 30);
  printf("\n=== DATA SETELAH EDIT ===");
  gotoxy(36, 31);
  printf("Username: %s", usernames[index]);
  gotoxy(36, 32);
  printf("Password: %s", passwords[index]);
  gotoxy(36, 33);
  printf("PIN: %d", pins[index]);
  gotoxy(36, 34);
  printf("Saldo: %.2lf", saldos[index]);

  while (input = getch()) {
    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }
}

void adminLihatProfil() {
  char usernames[10][50], passwords[10][50];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);
  char user[50];
  int index = -1;

  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  gotoxy(45, 2);
  settingtext();
  gotoxy(45, 6);
  printf("Daftar akun terdaftar (ID - Username):\n");
  for (int i = 0; i < jumlah_akun; i++) {
    gotoxy(45, 18 + i);
    printf("username : %s", usernames[i]);
  }
  gotoxy(45, 26);
  printf("Masukkan username akun: ");
  val_user(user);

  for (int i = 0; i < jumlah_akun; i++) {
    if (strcmp(usernames[i], user) == 0) {
      index = i;
      break;
    }
  }

  for (int i = 0; i < jumlah_akun; i++) {

    gotoxy(100, 16 + i * 5);
    printf("Username: %s", usernames[i]);
    gotoxy(100, 17 + i * 5);
    printf("Password: %s", passwords[i]);
    gotoxy(100, 18 + i * 5);
    printf("PIN: %d", pins[i]);
    gotoxy(100, 19 + i * 5);
    printf("Saldo: %.2f", saldos[i]);
  }
  gotoxy(45, 48);
  printf("tekan esc untuk kembali");
  while (input = getch()) {

    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }

  getchar();
}

void adminLihatSaldo() {
  char usernames[10][50], passwords[10][50];
  int pins[10];
  double saldos[10];
  int jumlah_akun = bacaAkun(usernames, passwords, pins, saldos);

  clearScreen();
  gotoxy(45, 8);
  printf("=== ADMIN LIHAT SALDO ===");
  for (int i = 0; i < jumlah_akun; i++) {
    gotoxy(45, 10 + i);
    printf("Username: %s, Saldo: %.2f", usernames[i], saldos[i]);
  }

  while (input = getch()) {

    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }

  getchar();
  getchar();
}
void al() {
  setColor(5, 7);
  gotoxy(28, 26);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
  gotoxy(28, 27);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 28);
  printf("  %c%c                                                    %c%c", 219,
         219, 219, 219);
  gotoxy(28, 29);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 30);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
}

void adminRiwayatTransaksi() {
  clearScreen();
  gotoxy(45, 8);
  printf("=== ADMIN RIWAYAT TRANSAKSI ===\n");
  gotoxy(45, 12);
  bacaRiwayat();
  while (input = getch()) {

    if (input == 27) {
      menu_admin();
      break;
    } else {
      printf("\a");
    }
  }

  getchar();
  getchar();
}
void settingtext() {
  setColor(5, 7);
  gotoxy(35, 2);
  printf(".d88888b             dP     dP   oo                   \n");
  gotoxy(35, 3);
  printf("88.    \"'            88     88                        \n");
  gotoxy(35, 4);
  printf("`Y88888b. .d8888b. d8888P d8888P dP 88d888b. .d8888b. \n");
  gotoxy(35, 5);
  printf("      `8b 88ooood8   88     88   88 88'  `88 88'  `88 \n");
  gotoxy(35, 6);
  printf("d8'   .8P 88.  ...   88     88   88 88    88 88.  .88 \n");
  gotoxy(35, 7);
  printf(" Y88888P  `88888P'   dP     dP   dP dP    dP `8888P88 \n");
  gotoxy(35, 8);
  printf("oooooooooooooooooooooooooooooooooooooooooooooo~.88\n");
  gotoxy(35, 9);
  printf("                                              d8888P  \n");
}
void all() {
  setColor(5, 7);
  gotoxy(28, 13);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
  gotoxy(28, 14);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 15);
  printf("  %c%c                                                    %c%c", 219,
         219, 219, 219);
  gotoxy(28, 16);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 17);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);

  gotoxy(28, 20);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
  gotoxy(28, 21);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 22);
  printf("  %c%c                                                    %c%c", 219,
         219, 219, 219);
  gotoxy(28, 23);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 24);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
}

void registasi_logo() {
  setColor(5, 7);
  gotoxy(30, 5);
  Sleep(40);
  printf("%c%c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c  %c%c %c%c%c%c%c%c%c "
         "%c%c%c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c%c%c %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(30, 6);
  Sleep(40);
  printf("%c%c   %c%c %c%c      %c%c       %c%c %c%c         %c%c    %c%c   "
         "%c%c %c%c      %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(30, 7);
  Sleep(40);
  printf("%c%c%c%c%c%c  %c%c%c%c%c   %c%c   %c%c%c %c%c %c%c%c%c%c%c%c    %c%c "
         "   %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
  gotoxy(30, 8);
  Sleep(40);
  printf("%c%c   %c%c %c%c      %c%c    %c%c %c%c      %c%c    %c%c    %c%c   "
         "%c%c      %c%c %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(30, 9);
  Sleep(40);
  printf("%c%c   %c%c %c%c%c%c%c%c%c  %c%c%c%c%c%c  %c%c %c%c%c%c%c%c%c    "
         "%c%c    %c%c   %c%c %c%c%c%c%c%c%c %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
}

int adminLogin() {
  char username[50], password[50];
  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  // logo_login();
  logo_admin();
  char pil;
  setColor(5, 7);
  gotoxy(32, 5);
  printf("%c%c%c%c%c%c   %c%c   %c%c%c%c%c%c   %c%c%c    %c%c      %c%c   "
         "%c%c%c    %c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(32, 6);
  printf("%c%c       %c%c   %c%c       %c%c%c%c   %c%c      %c%c   %c%c%c%c   "
         "%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(32, 7);
  printf("%c%c%c%c%c%c   %c%c   %c%c  %c%c   %c%c  %c%c %c%c      %c%c   %c%c  "
         "%c%c %c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(32, 8);
  printf("    %c%c   %c%c   %c%c   %c%c  %c%c   %c%c%c%c      %c%c   %c%c   "
         "%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(32, 9);
  printf("%c%c%c%c%c%c   %c%c   %c%c%c%c%c%c%c  %c%c    %c%c%c      %c%c   "
         "%c%c    %c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);

  setColor(5, 7);
  gotoxy(28, 13);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
  gotoxy(28, 14);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 15);
  printf("  %c%c                                                    %c%c", 219,
         219, 219, 219);
  gotoxy(28, 16);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 17);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);

  gotoxy(28, 20);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);
  gotoxy(28, 21);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 22);
  printf("  %c%c                                                    %c%c", 219,
         219, 219, 219);
  gotoxy(28, 23);
  printf("    %c%c                                                %c%c", 219,
         219, 219, 219);
  gotoxy(28, 24);
  printf("      "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219);

  setColor(5, 7);
  gotoxy(36, 15);
  printf("USERNAME  :");
  gotoxy(36, 22);
  printf("PASSWORD  :");

  gotoxy(50, 15);
  valus_admin(username);
  gotoxy(50, 22);
  val_pas_admin(password);

  if (strcmp(username, "alfariz") == 0 && strcmp(password, "admin1234") == 0) {
    menu_admin();
  } else {
    gotoxy(50, 40);
    printf("PASSWORD ATAU USERNAME SALAH");
    Sleep(250);
    adminLogin();
  }
}

void displayLoginBanner() {
  gotoxy(50, 7);
  Sleep(40);
  printf("%c%c%c    %c%c%c     %c%c%c%c%c%c%c     %c%c%c    %c%c     %c%c    "
         "%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 8);
  Sleep(40);
  printf("%c%c%c%c  %c%c%c%c     %c%c          %c%c%c%c   %c%c     %c%c    "
         "%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(50, 9);
  Sleep(40);
  printf("%c%c %c%c%c%c %c%c     %c%c%c%c%c       %c%c %c%c  %c%c     %c%c    "
         "%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 10);
  Sleep(40);
  printf(
      "%c%c  %c%c  %c%c     %c%c          %c%c  %c%c %c%c     %c%c    %c%c \n",
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219);
  gotoxy(50, 11);
  Sleep(40);
  printf("%c%c      %c%c     %c%c%c%c%c%c%c     %c%c   %c%c%c%c      "
         "%c%c%c%c%c%c  \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219);
}

void logo_user() {
  char a = 219;
  gotoxy(40, 1);
  setColor(5, 7);
  printf("%c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ", a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(40, 2);
  setColor(5, 7);
  printf("%c%c    %c%c %c%c      %c%c      %c%c   %c%c ", a, a, a, a, a, a, a,
         a, a, a, a, a);
  gotoxy(40, 3);
  setColor(5, 7);
  printf("%c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ", a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(40, 4);
  setColor(5, 7);
  printf("%c%c    %c%c      %c%c %c%c      %c%c   %c%c ", a, a, a, a, a, a, a,
         a, a, a, a, a);
  gotoxy(40, 5);
  setColor(5, 7);
  printf(" %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ", a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
}
void info() {
  clearScreen();
  drawBox(0, 0, 144, 34, 5, 7);
  setColor(5, 7);
  gotoxy(63, 3);
  printf("%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c", 219, 219,
         187, 219, 219, 219, 187, 219, 219, 187, 219, 219, 219, 219, 219, 219,
         219, 187, 219, 219, 219, 219, 219, 219, 187);
  gotoxy(63, 4);
  printf("%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219,
         186, 219, 219, 219, 219, 187, 219, 219, 186, 219, 219, 201, 205, 205,
         205, 205, 188, 219, 219, 201, 205, 205, 205, 219, 219, 187);
  gotoxy(63, 5);
  printf("%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c", 219, 219,
         186, 219, 219, 201, 219, 219, 187, 219, 219, 186, 219, 219, 219, 219,
         219, 187, 219, 219, 186, 219, 219, 186);
  gotoxy(63, 6);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c", 219, 219,
         186, 219, 219, 186, 200, 219, 219, 187, 219, 219, 186, 219, 219, 201,
         205, 205, 188, 219, 219, 186, 219, 219, 186);
  gotoxy(63, 7);
  printf("%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c", 219, 219,
         186, 219, 219, 186, 200, 219, 219, 219, 219, 186, 219, 219, 186, 200,
         219, 219, 219, 219, 219, 219, 201, 188);
  gotoxy(63, 8);
  printf("%c%c%c%c%c%c  %c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c", 200, 205, 188,
         200, 205, 188, 200, 205, 205, 205, 188, 200, 205, 188, 200, 205, 205,
         205, 205, 205, 188);

  drawBox(50, 15, 53, 15, 5, 7);
  for (int a = 0; a < 1; a++) {
    setColor(5, 7);
    gotoxy(62, 17);
    printf("TITLE      : ALPAY (E-WALLET)");
    Sleep(300);
    gotoxy(62, 19);
    printf("DEV        : ALFA RIZI");
    Sleep(300);
    gotoxy(62, 21);
    printf("RELEASE    : JANUARI, 2024");
    Sleep(300);
    gotoxy(62, 23);
    printf("RANK       : IMMORTAL");
    Sleep(300);
    gotoxy(62, 25);
    printf("WHATSAPP   : +62 838 3081 3177");
    Sleep(300);
    gotoxy(62, 27);
    printf("VERSION    : BETA 0.1");
    Sleep(10000);
    menu_admin();
  }
}
void logo_login() {
  gotoxy(50, 4);
  Sleep(40);
  printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c%c    %c%c \n", 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(50, 5);
  Sleep(40);
  printf("%c%c      %c%c    %c%c %c%c       %c%c %c%c%c%c   %c%c \n", 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 6);
  Sleep(40);
  printf("%c%c      %c%c    %c%c %c%c   %c%c%c %c%c %c%c %c%c  %c%c \n", 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219);
  gotoxy(50, 7);
  Sleep(40);
  printf("%c%c      %c%c    %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c \n", 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219);
  gotoxy(50, 8);
  Sleep(40);
  printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c   %c%c%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
}

void erase1() {
  setColor(5, 7);
  gotoxy(50, 10);
  printf("                                        ");
  gotoxy(50, 11);
  printf("                                        ");
  gotoxy(50, 12);
  printf("                                        ");
  gotoxy(50, 13);
  printf("                                        ");
  gotoxy(50, 14);
  printf("                                        ");
  gotoxy(50, 15);
  printf("                                        ");
  gotoxy(50, 16);
  printf("                                        ");
  gotoxy(50, 17);
  printf("                                        ");
  gotoxy(50, 18);
  printf("                                        ");
  gotoxy(50, 19);
  printf("                                        ");
  gotoxy(50, 20);
  printf("                                        ");
  gotoxy(50, 21);
  printf("                                        ");
  gotoxy(50, 22);
  printf("                                        ");
  gotoxy(50, 23);
  printf("                                        ");
  gotoxy(50, 24);
  printf("                                        ");
  gotoxy(50, 25);
  printf("                                        ");
  gotoxy(50, 26);
  printf("                                        ");
  gotoxy(50, 27);
  printf("                                        ");
  gotoxy(50, 28);
  printf("                                        ");
  gotoxy(50, 29);
  printf("                                        ");
}
void loading1() {
  for (int a = 1; a < 3; a++) {
    for (int x = 1; x < 9; x++) {
      // erase1();
      // system("cls");
      for (int i = 1; i <= 18; i++) {
        gotoxy(105, i + 8);
        for (int j = 1; j <= 14; j++) {
          if (i == j + 2 && i < 9 && j > 1 || i + j == 17 && j > 8 ||
              j == 6 && i > 8 && i < 11 || i + j == 17 && j < 7 ||
              i == j + 2 && j >= 9 || j == 9 && i > 8 && i < 11 ||
              j == 1 && i < 4 && i >= 1 || j == 1 && i > 15 && i < 19 ||
              j == 14 && i < 4 && i > 0 || j == 14 && i > 15 && i < 19 ||
              i == 1 && j > 1 && j < 14 || i == 18 && j > 1 && j < 14) {
            printf("%c%c", 219, 219);
            if (x == 1 && a == 1)
              Sleep(100);
          } else if (i == 2 && j >= 1 && j <= 14 && x < 2)

            printf("%c%c", 176, 176);
          else if (i == 3 && j >= 2 && j <= 13 && x < 3)
            printf("%c%c", 176, 176);
          else if (i == 4 && j >= 3 && j <= 12 && x < 4)
            printf("%c%c", 176, 176);
          else if (i == 5 && j >= 4 && j <= 11 && x < 5)
            printf("%c%c", 176, 176);
          else if (i == 6 && j >= 5 && j <= 10 && x < 6)
            printf("%c%c", 176, 176);
          else if (i == 7 && j >= 6 && j <= 9 && x < 7)
            printf("%c%c", 176, 176);
          else if (i >= 8 && i <= 18 && j > 6 && j <= 8 && x > 1 && x < 8)
            printf("%c%c", 176, 176);
          else if (i == 12 && j > 4 && j < 11 && x > 7)
            printf("%c%c", 176, 176);
          else if (i == 13 && j > 3 && j < 12 && x > 6)
            printf("%c%c", 176, 176);
          else if (i == 14 && j > 2 && j < 13 && x > 5)
            printf("%c%c", 176, 176);
          else if (i == 15 && j > 1 && j < 14 && x > 4)
            printf("%c%c", 176, 176);
          else if (i == 16 && x > 3)
            printf("%c%c", 176, 176);
          else if (i == 17 && x > 2)
            printf("%c%c", 176, 176);
          else
            printf("  ");
        }
        printf("\n");
      }
    }
  }
}
//         Sleep(100);
//         if (a < 3)
//         {
//             // erase1();
//             system("cls");
//             gotoxy(50, 6);
//             printf("%c%c%c%c%c%c                        %c%c%c%c%c%c\n", 219,
//             219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
//             Sleep(100);
//             gotoxy(50, 7);
//             printf("%c%c    %c%c                    %c%c%c%c%c%c%c%c\n", 219,
//             219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219);
//             Sleep(100);
//             gotoxy(50, 8);
//             printf("%c%c      %c%c                %c%c%c%c%c%c%c%c%c%c\n",
//             219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 219,
//             219); Sleep(100); gotoxy(50, 9); printf("%c%c        %c%c
//             %c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 176,
//             176, 176, 176, 176, 176, 176, 176, 219, 219); Sleep(100);
//             gotoxy(50, 10);
//             printf("%c%c          %c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219,
//             219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176,
//             176, 176, 219, 219); Sleep(100); gotoxy(50, 11); printf("%c%c
//             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219,
//             219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176,
//             176, 176, 176, 176, 176, 176, 219, 219); Sleep(100); gotoxy(50,
//             12); printf("%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176,
//             176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219);
//             Sleep(100);
//             gotoxy(50, 13);
//             printf("%c%c                    %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
//             219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,
//             176, 219, 219); Sleep(100); gotoxy(50, 14); printf("%c%c
//             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219,
//             219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176,
//             176, 176, 176, 176, 176, 176, 219, 219); Sleep(100); gotoxy(50,
//             15); printf("%c%c          %c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
//             219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176,
//             176, 176, 176, 219, 219); Sleep(100); gotoxy(50, 16);
//             printf("%c%c        %c%c            %c%c%c%c%c%c%c%c%c%c%c%c\n",
//             219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176,
//             176, 219, 219); Sleep(100); gotoxy(50, 17); printf("%c%c %c%c
//             %c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 176, 176,
//             176, 176, 176, 176, 219, 219); Sleep(100); gotoxy(50, 18);
//             printf("%c%c    %c%c                    %c%c%c%c%c%c%c%c\n", 219,
//             219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219);
//             Sleep(100);
//             gotoxy(50, 18);
//             printf("%c%c%c%c%c%c                        %c%c%c%c%c%c\n", 219,
//             219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
//             Sleep(100);

void loading2() {
  for (int z = 1; z <= 3; z++) {
    int b = 3;
    int a = 54;
    int c = 18;
    system("cls");
    for (int x = 1; x <= 6; x++) {
      for (int i = 1; i <= b * 4; i++) {
        gotoxy(a, i + c);
        for (int j = 1; j <= b * 4; j++) {
          if (i == 1 && j <= b || i == 1 && j > b * 3 || i == b * 4 && j <= b ||
              i == b * 4 && j > b * 3 || j == 1 && i <= b ||
              j == 1 && i > b * 3 || j == b * 4 && i <= b ||
              j == b * 4 && i > b * 3) {
            printf("%c%c", 219, 219);
          } else {
            printf("  ");
          }
        }
        // printf("\n");
      }
      b++;
      a -= 4;
      c -= 2;
      Sleep(20);
    }
  }
}

void welcome() {
  setColor(5, 7);
  gotoxy(35, 8);
  printf("%c%c       %c%c %c%c%c%c%c%c%c %c%c       %c%c%c%c%c   %c%c%c%c%c  "
         "%c%c    %c%c %c%c%c%c%c%c%c    %c%c%c%c%c%c%c  %c%c%c%c%c\n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219);
  Sleep(40);
  setColor(5, 7);
  gotoxy(35, 9);
  printf("%c%c       %c%c %c%c      %c%c      %c%c    %c %c%c   %c%c %c%c%c  "
         "%c%c%c %c%c           %c%c%c   %c%c   %c%c\n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219);
  Sleep(40);
  setColor(5, 7);
  gotoxy(35, 10);
  printf("%c%c   %c   %c%c %c%c%c%c%c   %c%c      %c%c      %c%c   %c%c %c%c "
         "%c%c %c%c %c%c%c%c%c        %c%c%c   %c%c   %c%c\n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
  Sleep(40);
  setColor(5, 7);
  gotoxy(35, 11);
  printf(" %c%c %c%c%c %c%c  %c%c      %c%c      %c%c    %c %c%c   %c%c %c%c   "
         " %c%c %c%c           %c%c%c   %c%c   %c%c\n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219);
  Sleep(40);
  setColor(5, 7);
  gotoxy(35, 12);
  printf("  %c%c   %c%c   %c%c%c%c%c%c%c %c%c%c%c%c%c%c  %c%c%c%c%c   "
         "%c%c%c%c%c  %c%c    %c%c %c%c%c%c%c%c%c      %c%c%c    %c%c%c%c%c\n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219);
  Sleep(40);
  setColor(5, 7);
  alpay();
  Sleep(40);
  for (int a = 1, b = 1; a <= 100; a++) {
    setColor(5, 7);
    gotoxy(67, 30);
    printf("Loading %d%%", a);
    Sleep(15);
    if (a % 2 == 0) {
      setColor(5, 7);
      gotoxy(b + 47, 32);
      printf("%c", 177);
      Sleep(20);
      b++;
    }
  }
}
void alpay() {

  gotoxy(45, 15);
  setColor(5, 7);
  Sleep(40);
  printf(" %c%c%c%c%c%c     %c%c%c         %c%c%c%c%c%c%c      %c%c%c%c%c%c    "
         " %c%c%c   %c%c%c\n",
         219, 219, 219, 219, 219, 187, 219, 219, 187, 219, 219, 219, 219, 219,
         219, 187, 219, 219, 219, 219, 219, 187, 219, 219, 187, 219, 219, 187);
  gotoxy(45, 16);
  setColor(5, 7);
  Sleep(40);
  printf("%c%c%c%c%c%c%c%c    %c%c%c         %c%c%c%c%c%c%c%c    "
         "%c%c%c%c%c%c%c%c    %c%c%c%c %c%c%c%c\n",
         219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 186, 219, 219, 201,
         205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 187, 200,
         219, 219, 187, 219, 219, 201, 188);
  gotoxy(45, 17);
  setColor(5, 7);
  Sleep(40);
  printf("%c%c%c%c%c%c%c%c    %c%c%c         %c%c%c%c%c%c%c%c    "
         "%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 186, 219, 219, 186, 219, 219, 219,
         219, 219, 219, 201, 188, 219, 219, 219, 219, 219, 219, 219, 186, 200,
         219, 219, 219, 219, 201, 188);
  gotoxy(45, 18);
  setColor(5, 7);
  Sleep(40);
  printf("%c%c%c%c%c%c%c%c    %c%c%c         %c%c%c%c%c%c%c     "
         "%c%c%c%c%c%c%c%c      %c%c%c%c%c  \n",
         219, 219, 201, 205, 205, 219, 219, 186, 219, 219, 186, 219, 219, 201,
         205, 205, 205, 188, 219, 219, 201, 205, 205, 219, 219, 186, 200, 219,
         219, 201, 188);
  gotoxy(45, 19);
  setColor(5, 7);
  Sleep(40);
  printf("%c%c%c  %c%c%c    %c%c%c%c%c%c%c%c    %c%c%c         %c%c%c  %c%c%c  "
         "     %c%c%c   \n",
         219, 219, 186, 219, 219, 186, 219, 219, 219, 219, 219, 219, 219, 187,
         219, 219, 186, 219, 219, 186, 219, 219, 186, 219, 219, 186);
  gotoxy(45, 20);
  setColor(5, 7);
  Sleep(40);
  printf("%c%c%c  %c%c%c    %c%c%c%c%c%c%c%c    %c%c%c         %c%c%c  %c%c%c  "
         "     %c%c%c   \n",
         200, 205, 188, 200, 205, 188, 200, 205, 205, 205, 205, 205, 205, 188,
         200, 205, 188, 200, 205, 188, 200, 205, 188, 200, 205, 188);
}

void logo_loading() {
  gotoxy(90, 3);
  setColor(5, 7);
  printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c  %c%c%c%c%c%c  %c%c %c%c%c    "
         "%c%c  %c%c%c%c%c%c  \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219);
  gotoxy(90, 4);
  setColor(5, 7);
  printf("%c%c      %c%c    %c%c %c%c   %c%c %c%c   %c%c %c%c %c%c%c%c   %c%c "
         "%c%c       \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(90, 5);
  setColor(5, 7);
  printf("%c%c      %c%c    %c%c %c%c%c%c%c%c%c %c%c   %c%c %c%c %c%c %c%c  "
         "%c%c %c%c   %c%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219);
  gotoxy(90, 6);
  setColor(5, 7);
  printf("%c%c      %c%c    %c%c %c%c   %c%c %c%c   %c%c %c%c %c%c  %c%c %c%c "
         "%c%c    %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(90, 7);
  setColor(5, 7);
  printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c  %c%c   %c%c %c%c%c%c%c%c  %c%c %c%c   "
         "%c%c%c%c  %c%c%c%c%c%c  \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219);
}

void logo_admin() {
  setColor(5, 7);
  gotoxy(90, 5);
  printf(" %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c    %c%c%c %c%c %c%c%c    %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(90, 6);
  printf("%c%c   %c%c %c%c   %c%c %c%c%c%c  %c%c%c%c %c%c %c%c%c%c   %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(90, 7);
  printf(
      "%c%c%c%c%c%c%c %c%c   %c%c %c%c %c%c%c%c %c%c %c%c %c%c %c%c  %c%c \n",
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(90, 8);
  printf("%c%c   %c%c %c%c   %c%c %c%c  %c%c  %c%c %c%c %c%c  %c%c %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(90, 9);
  printf("%c%c   %c%c %c%c%c%c%c%c  %c%c      %c%c %c%c %c%c   %c%c%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
}

void menu_tamp() {
  gotoxy(50, 9);
  Sleep(40);
  printf("%c%c%c    %c%c%c     %c%c%c%c%c%c%c     %c%c%c    %c%c     %c%c    "
         "%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 10);
  Sleep(40);
  printf("%c%c%c%c  %c%c%c%c     %c%c          %c%c%c%c   %c%c     %c%c    "
         "%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219);
  gotoxy(50, 11);
  Sleep(40);
  printf("%c%c %c%c%c%c %c%c     %c%c%c%c%c       %c%c %c%c  %c%c     %c%c    "
         "%c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 12);
  Sleep(40);
  printf(
      "%c%c  %c%c  %c%c     %c%c          %c%c  %c%c %c%c     %c%c    %c%c \n",
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219);
  gotoxy(50, 13);
  Sleep(40);
  printf("%c%c      %c%c     %c%c%c%c%c%c%c     %c%c   %c%c%c%c      "
         "%c%c%c%c%c%c  \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219);
}

void top_up_logo() {
  setColor(5, 7);
  gotoxy(50, 1);
  Sleep(40);
  printf("%c%c%c%c%c%c%c%c  %c%c%c%c%c%c  %c%c%c%c%c%c      %c%c    %c%c "
         "%c%c%c%c%c%c  \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219);
  gotoxy(50, 2);
  Sleep(40);
  printf("   %c%c    %c%c    %c%c %c%c   %c%c     %c%c    %c%c %c%c   %c%c \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219);
  gotoxy(50, 3);
  Sleep(40);
  printf(
      "   %c%c    %c%c    %c%c %c%c%c%c%c%c      %c%c    %c%c %c%c%c%c%c%c  \n",
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 4);
  Sleep(40);
  printf("   %c%c    %c%c    %c%c %c%c          %c%c    %c%c %c%c      \n", 219,
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
  gotoxy(50, 5);
  Sleep(40);
  printf("   %c%c     %c%c%c%c%c%c  %c%c           %c%c%c%c%c%c  %c%c      \n",
         219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
         219, 219, 219, 219);
}

void logo_login_user() {
  char a = 219;
  gotoxy(8, 3);
  setColor(5, 11);
  printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c%c    %c%c     %c%c "
         "   %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(8, 4);
  setColor(5, 11);
  printf("%c%c      %c%c    %c%c %c%c       %c%c %c%c%c%c   %c%c     %c%c    "
         "%c%c %c%c      %c%c      %c%c   %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a);
  gotoxy(8, 5);
  setColor(5, 11);
  printf("%c%c      %c%c    %c%c %c%c   %c%c%c %c%c %c%c %c%c  %c%c     %c%c   "
         " %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(8, 6);
  setColor(5, 11);
  printf("%c%c      %c%c    %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c     %c%c    "
         "%c%c      %c%c %c%c      %c%c   %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a);
  gotoxy(8, 7);
  setColor(5, 11);
  printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c   %c%c%c%c    "
         "  %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a);
}

int adminmenu() {
  clearScreen();
  int posisi = 1;
  input = 0;
  char klik;
  char a = 219;
  drawBox(0, 0, 144, 34, 5, 7);
  gotoxy(3, 3);
  setColor(5, 7);
  printf("%c%c%c    %c%c%c %c%c%c%c%c%c%c %c%c%c    %c%c %c%c    %c%c      "
         "%c%c%c%c%c  %c%c%c%c%c%c  %c%c%c    %c%c%c %c%c %c%c%c    %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(3, 4);
  setColor(5, 7);
  printf("%c%c%c%c  %c%c%c%c %c%c      %c%c%c%c   %c%c %c%c    %c%c     %c%c   "
         "%c%c %c%c   %c%c %c%c%c%c  %c%c%c%c %c%c %c%c%c%c   %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(3, 5);
  setColor(5, 7);
  printf("%c%c %c%c%c%c %c%c %c%c%c%c%c   %c%c %c%c  %c%c %c%c    %c%c     "
         "%c%c%c%c%c%c%c %c%c   %c%c %c%c %c%c%c%c %c%c %c%c %c%c %c%c  %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a);
  gotoxy(3, 6);
  setColor(5, 7);
  printf("%c%c  %c%c  %c%c %c%c      %c%c  %c%c %c%c %c%c    %c%c     %c%c   "
         "%c%c %c%c   %c%c %c%c  %c%c  %c%c %c%c %c%c  %c%c %c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(3, 7);
  setColor(5, 7);
  printf("%c%c      %c%c %c%c%c%c%c%c%c %c%c   %c%c%c%c  %c%c%c%c%c%c      "
         "%c%c   %c%c %c%c%c%c%c%c  %c%c      %c%c %c%c %c%c   %c%c%c%c ",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  bingkai_tombol(12, 12, 20, 3);
  gotoxy(19, 13);
  setColor(15, 11);
  printf("TOP UP"); ///// 1
  bingkai_tombol(12, 20, 20, 3);
  gotoxy(19, 21);
  setColor(15, 11);
  printf("TRANSFER"); //////
  bingkai_tombol(12, 29, 20, 3);
  gotoxy(20, 30);
  setColor(15, 11);
  printf("LIAT AKUN"); //////////////3
  bingkai_tombol(69, 12, 20, 3);
  gotoxy(74, 13);
  setColor(15, 11);
  printf("BANED AKUN"); ////////////////6
  bingkai_tombol(69, 20, 20, 3);
  gotoxy(74, 21);
  setColor(15, 11);
  printf("EDIT PROFILE"); ///////7
  bingkai_tombol(70, 29, 20, 3);
  gotoxy(76, 30);
  setColor(15, 11);
  printf("HISTORY"); ////////////8
  bingkai_tombol(42, 12, 20, 3);
  gotoxy(47, 13);
  setColor(15, 11);
  printf("INFO DEVELOPER"); /////////////4
  bingkai_tombol(42, 29, 20, 3);
  gotoxy(47, 30);
  setColor(15, 11);
  printf("LOG OUT"); /////////5
  logo_loading();
  loading1();
  while ((klik = getch()) != 13) {
    if (klik == 80) {
      if (posisi == 1) {
        posisi = 2;
        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 11);
        printf("TOP UP");
        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 1);
        printf("TRANSFER");
      } else if (posisi == 2) {
        posisi = 3;

        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 11);
        printf("TRANSFER");
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 1);
        printf("LIAT AKUN");
      } else if (posisi == 3) {
        posisi = 4;
        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 1);
        printf("INFO DEVELOPER");
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 11);
        printf("LIAT AKUN");
      } else if (posisi == 4) {
        posisi = 5;

        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 11);
        printf("INFO DEVELOPER");
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 1);
        printf("LOG OUT");
      } else if (posisi == 5) {
        posisi = 6;
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 11);
        printf("LOG OUT");
        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 1);
        printf("BANED AKUN");
      } else if (posisi == 6) {
        posisi = 7;

        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 11);
        printf("BANED AKUN");
        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 1);
        printf("EDIT PROFILE");
      } else if (posisi == 7) {
        posisi = 8;

        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 11);
        printf("EDIT PROFILE");
        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 1);
        printf("HISTORY");
      } else if (posisi == 8) {
        posisi = 1;

        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 1);
        printf("TOP UP");

        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 11);
        printf("HISTORY");
      }
    } else if (klik == 72) {
      if (posisi == 1) {
        posisi = 8;
        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 1);
        printf("HISTORY");
        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 11);
        printf("TOP UP");
      } else if (posisi == 2) {
        posisi = 1;

        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 1);
        printf("TOP UP");

        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 11);
        printf("TRANSFER");
      } else if (posisi == 3) {
        posisi = 2;
        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 1);
        printf("TRANSFER");
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 11);
        printf("LIAT AKUN");
      } else if (posisi == 4) {
        posisi = 3;
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 1);
        printf("LIAT AKUN");

        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 11);
        printf("INFO DEVELOPER");
      } else if (posisi == 5) {
        posisi = 4;
        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 1);
        printf("INFO DEVELOPER");
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 11);
        printf("LOG OUT");
      } else if (posisi == 6) {
        posisi = 5;
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 1);
        printf("LOG OUT");

        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 11);
        printf("BANED AKUN");
      } else if (posisi == 7) {
        posisi = 6;
        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 1);
        printf("BANED AKUN");

        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 11);
        printf("EDIT PROFILE");
      } else if (posisi == 8) {
        posisi = 7;
        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 1);
        printf("EDIT PROFILE");

        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 11);
        printf("HISTORY");
      }
    } else if (klik == 77) {
      if (posisi == 1) {
        posisi = 4;
        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 1);
        printf("INFO DEVELOPER");
        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 11);
        printf("TOP UP");
      } else if (posisi == 2) {
        posisi = 7;
        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 1);
        printf("EDIT PROFILE");

        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 11);
        printf("TRANSFER");
      } else if (posisi == 3) {
        posisi = 5;
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 1);
        printf("LOG OUT");
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 11);
        printf("LIAT AKUN");
      } else if (posisi == 4) {
        posisi = 6;
        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 1);
        printf("BANED AKUN");

        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 11);
        printf("INFO DEVELOPER");
      } else if (posisi == 5) {
        posisi = 8;
        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 1);
        printf("HISTORY");
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 11);
        printf("LOG OUT");
      } else if (posisi == 6) {
        posisi = 1;

        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 1);
        printf("TOP UP");

        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 11);
        printf("BANED AKUN");
      } else if (posisi == 7) {
        posisi = 2;
        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 1);
        printf("TRANSFER");

        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 11);
        printf("EDIT PROFILE");
      } else if (posisi == 8) {
        posisi = 3;
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 1);
        printf("LIAT AKUN");

        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 11);
        printf("HISTORY");
      }
    } else if (klik == 75) {
      if (posisi == 1) {
        posisi = 6;
        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 1);
        printf("BANED AKUN");
        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 11);
        printf("TOP UP");
      } else if (posisi == 2) {
        posisi = 7;
        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 1);
        printf("EDIT PROFILE");

        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 11);
        printf("TRANSFER");
      } else if (posisi == 3) {
        posisi = 8;
        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 1);
        printf("HISTORY");
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 11);
        printf("LIAT AKUN");
      } else if (posisi == 4) {
        posisi = 1;

        bingkai_tombol(12, 12, 20, 3);
        gotoxy(19, 13);
        setColor(15, 1);
        printf("TOP UP");

        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 11);
        printf("INFO DEVELOPER");
      } else if (posisi == 5) {
        posisi = 3;
        bingkai_tombol(12, 29, 20, 3);
        gotoxy(20, 30);
        setColor(15, 1);
        printf("LIAT AKUN");
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 11);
        printf("LOG OUT");
      } else if (posisi == 6) {
        posisi = 4;
        bingkai_tombol(42, 12, 20, 3);
        gotoxy(47, 13);
        setColor(15, 1);
        printf("INFO DEVELOPER");

        bingkai_tombol(69, 12, 20, 3);
        gotoxy(74, 13);
        setColor(15, 11);
        printf("BANED AKUN");
      } else if (posisi == 7) {
        posisi = 2;

        bingkai_tombol(69, 20, 20, 3);
        gotoxy(74, 21);
        setColor(15, 11);
        printf("EDIT PROFILE");
        bingkai_tombol(12, 20, 20, 3);
        gotoxy(19, 21);
        setColor(15, 1);
        printf("TRANSFER");
      } else if (posisi == 8) {
        posisi = 5;
        bingkai_tombol(42, 29, 20, 3);
        gotoxy(47, 30);
        setColor(15, 1);
        printf("LOG OUT");

        bingkai_tombol(70, 29, 20, 3);
        gotoxy(76, 30);
        setColor(15, 11);
        printf("HISTORY");
      }
    }
  }
  return posisi;
}

void menu_admin() {
  clearScreen();
  char input;
  int pilih;
  pilih = adminmenu();
  switch (pilih) {

  case 1:
    adminTopUp();
    Sleep(5000);
    break;

  case 2:
    adminTransfer();
    Sleep(5000);
    break;

  case 3:
    adminLihatProfil();
    Sleep(5000);
    break;

  case 4:
    info();
    break;

  case 5:
    printf("anda kembali ke menu utama");
    menu_utama();
    break;

  case 6:
    adminHapusAkun();

    break;

  case 7:
    adminEditAkun();
    break;

  case 8:
    adminRiwayatTransaksi();
    break;
  }
}

void menu_user_daftar_login() {
  do {
    posisi = 1;
    input = 0;

    clearScreen();
    // drawBox(0, 0, 173, 39, 11, 15);
    drawBox(0, 0, 144, 34, 5, 7);
    gotoxy(35, 12);
    setColor(5, 7);
    displayLoginBanner();
    gotoxy(35, 18);
    setColor(5, 7);
    logo_user();
    bingkai_tombol(42, 26, 20, 3);
    gotoxy(47, 27);
    setColor(5, 7);
    printf("DAFTAR ");
    bingkai_tombol(82, 26, 20, 3);
    gotoxy(87, 27);
    setColor(5, 7);
    printf("LOGIN ");
    gotoxy(58, 32);
    setColor(5, 13);
    printf("Tekan >> Esc 2X << Untuk Keluar");
    while ((input = getch()) != 13) {
      if (input == 77) {
        if (posisi == 1) {
          posisi = 2;
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("LOGIN ");
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("DAFTAR ");
        } else if (posisi == 2) {
          posisi = 1;
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("DAFTAR ");
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("LOGIN ");
        }
      } else if (input == 75) {
        if (posisi == 1) {
          posisi = 2;
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("LOGIN ");
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("DAFTAR ");
        } else if (posisi == 2) {
          posisi = 1;
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("DAFTAR ");
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("LOGIN ");
        }
      } else if (input == 27) {
        posisi = 3;
        break;
      }
    }
    if (posisi == 1) {
      userLogin();
    }

    else if (posisi == 2) {
      userRegister();
    } else if (posisi == 3) {
      menu_utama();
      break;
    }
  } while (posisi != '4');
}
int userMenu(int index) {
  do {
    input = 0;
    posisi = 1;
    clearScreen();
    // drawBox(0, 0, 173, 39, 11, 15);
    drawBox(0, 0, 144, 34, 5, 7);
    gotoxy(35, 12);
    setColor(5, 7);
    displayLoginBanner();
    gotoxy(35, 18);
    setColor(5, 7);
    logo_user();
    bingkai_tombol(42, 26, 20, 3);
    gotoxy(47, 27);
    setColor(5, 7);
    printf("TOP UP ");
    bingkai_tombol(82, 26, 20, 3);
    gotoxy(87, 27);
    setColor(5, 7);
    printf("TRANSFER ");
    gotoxy(58, 32);
    setColor(5, 13);
    printf("Tekan >> Esc 2X << Untuk Keluar");
    while ((input = getch()) != 13) {
      if (input == 77) {
        if (posisi == 1) {
          posisi = 2;
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("TRANSFER ");
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("TOP UP ");
        } else if (posisi == 2) {
          posisi = 1;
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("TOP UP ");
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("TRANSFER ");
        }
      } else if (input == 75) {
        if (posisi == 1) {
          posisi = 2;
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("TRANSFER ");
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("TOP UP ");
        } else if (posisi == 2) {
          posisi = 1;
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("TOP UP ");
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("TRANSFER ");
        }
      } else if (input == 27) {
        posisi = 3;
        break;
      }
    }
    if (posisi == 1) {
      userTransfer(index);
    } else if (posisi == 2) {

      userTopUp(index);
    } else if (posisi == 3)

    {
      menu_user_daftar_login();
      break;
    }
  } while (posisi != '4');
  return 0;
}

int menu_utama() {
  do {
    clearScreen();
    input = 0;
    posisi = 1;
    // drawBox(0, 0, 173, 39, 11, 15);
    drawBox(0, 0, 144, 34, 5, 7);
    gotoxy(35, 12);
    setColor(5, 7);
    // displayLoginBanner();
    menu_tamp();
    bingkai_tombol(42, 26, 20, 3);
    gotoxy(47, 27);
    setColor(5, 7);
    printf("USER MENU");
    bingkai_tombol(82, 26, 20, 3);
    gotoxy(87, 27);
    setColor(5, 7);
    printf("ADMIN MENU");
    gotoxy(58, 32);
    setColor(5, 7);
    printf("Tekan >> Esc 2X << Untuk Keluar");
    while ((input = getch()) != 13) {
      if (input == 77) {
        if (posisi == 1) {
          posisi = 2;
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("ADMIN MENU");
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("USER MENU");
        } else if (posisi == 2) {
          posisi = 1;
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("USER MENU");
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("ADMIN MENU");
        }
      } else if (input == 75) {
        if (posisi == 1) {
          posisi = 2;
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("ADMIN MENU");
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("USER MENU");
        } else if (posisi == 2) {
          posisi = 1;
          bingkai_tombol(42, 26, 20, 3);
          gotoxy(47, 27);
          setColor(5, 7);
          printf("USER MENU");
          bingkai_tombol(82, 26, 20, 3);
          gotoxy(87, 27);
          setColor(5, 7);
          printf("ADMIN MENU");
        }
      } else if (input == 27) {
        posisi = 3;
        break;
      }
    }
    if (posisi == 1) {
      adminLogin();
    } else if (posisi == 2) {
      menu_user_daftar_login();
    } else if (posisi == 3) {
      exit(0);
      break;
    }
  } while (choice != '4');

  return 0;
}
int main() {
  system("COLOR F7");
  setColor(5, 7);
  gotoxy(0, 0);
  system("pause");
  clearScreen();
  drawBox(0, 0, 144, 34, 7, 7);
  // loading1();
  welcome();
  clearScreen();
  drawBox(0, 0, 144, 34, 7, 7);
  menu_utama();
  return 0;
}