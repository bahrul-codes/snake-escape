#include "snake.h"

// Variabel ular
int posisiX[MAX_UL];
int posisiY[MAX_UL];

int panjangUlar;
int arahX;
int arahY;

// Mengatur ulang ular
void resetUlar() {
    panjangUlar = 3;

    arahX = 1;
    arahY = 0;
    
    posisiX[0] = 20;
    posisiY[0] = 12;

    posisiX[1] = 19;
    posisiY[1] = 12;

    posisiX[2] = 18;
    posisiY[2] = 12;

}

// Menggerakkan ular
void gerakUlar() {
    for (int i = panjangUlar - 1; i > 0; i--) {
        posisiX[i] = posisiX[i - 1];
        posisiY[i] = posisiY[i - 1];
    }

    posisiX[0] += arahX;
    posisiY[0] += arahY;
}

// Menambah panjang ular
void tambahPanjangUlar() {
    if (panjangUlar < MAX_UL) {
        posisiX[panjangUlar] = posisiX[panjangUlar - 1];
        posisiY[panjangUlar] = posisiY[panjangUlar - 1];

        panjangUlar++;
    }
}

// Memeriksa tabrakan ular dengan tubuhnya sendiri
bool cekTabrakanUlar() {
    for (int i = 1; i < panjangUlar; i++) {
        if (posisiX[0] == posisiX[i] && 
        posisiY[0] == posisiY[i]) {
            return true;
            
        }
    }
    
    return false;
}