#ifndef SNAKE_H
#define SNAKE_H

const int MAX_UL = 100;

// Posisi setiap bagian tubuh ular
extern int posisiX[MAX_UL];
extern int posisiY[MAX_UL];

// Panjang ular
extern int panjangUlar;

// Arah gerak ular
extern int arahX;
extern int arahY;

// Fungsi ular
void resetUlar();
void gerakUlar();
void tambahPanjangUlar();
bool cekTabrakanUlar();

#endif