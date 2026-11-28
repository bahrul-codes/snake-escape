#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>

const int MAKS_PANJANG_ULAR = 450;

// Mengelompokkan seluruh data ular
struct Ular {

    int posisiX[MAKS_PANJANG_ULAR];
    int posisiY[MAKS_PANJANG_ULAR];
    int panjang;
    int arahX;
    int arahY;

};

// Mengatur posisi awal ular
void inisialisasiUlar(Ular &ular);

// Menggambar ular di layar
void gambarUlar(WINDOW* jendela, Ular ular);    

// Mengubah arah gerak ular
void ubahArahUlar(Ular &ular, int tombol);

//Menggerakkan ular
void gerakkanUlar(Ular &ular, bool tambahPanjang);

// Memeriksa tabrakan ular dengan tubuhnya sendiri
bool tabrakanDenganDiriSendiri(Ular ular);

// Memeriksa apakah suatu posisi ditempati ular
bool posisiAdaUlar(Ular ular, int x, int y);

#endif

