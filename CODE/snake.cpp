#include <ncurses.h>
#include "snake.h"

// Mengatur posisi awal ular
void inisialisasiUlar(Ular &ular) {

    ular.panjang = 3;

    // Posisi kepala
    ular.posisiX[0] = 3;
    ular.posisiY[0] = 2;

    // Posisi badan
    ular.posisiX[1] = 2;
    ular.posisiY[1] = 2;
    
    // Posisi ekor
    ular.posisiX[2] = 1;
    ular.posisiY[2] = 2;

    // Arah awal: ke kanan
    ular.arahX = 1;
    ular.arahY = 0;

}

// Menggambar ular di dalam jendela maze
void gambarUlar(WINDOW* jendela, Ular ular) {

    for (int i = 0; i < ular.panjang; i++) {
        
        int x = ular.posisiX[i] + 1;
        int y = ular.posisiY[i] + 1;
        
        if (i == 0) {
            mvwaddch(jendela, y, x, 'O');
        } else {
            mvwaddch(jendela, y, x, 'o');
        }
    }
}

// Mengubah arah gerak ular
void ubahArahUlar(Ular &ular, int tombol) {
    int arahBaruX = 0;
    int arahBaruY = 0;

    switch (tombol) {
        case KEY_UP:
            arahBaruY = -1;
            break;

        case KEY_DOWN:
            arahBaruY = 1;
            break;

        case KEY_LEFT:
            arahBaruX = -1;
            break;

        case KEY_RIGHT:
            arahBaruX = 1;
            break;

            default:
            return;


    }

    // Mencegah ular berbalik langsung ke arah berlawanan
    if (
        arahBaruX == -ular.arahX &&
        arahBaruY == -ular.arahY
    ) {
        return;

    }

    ular.arahX = arahBaruX;
    ular.arahY = arahBaruY;
}

// Menggerakkan ular
void gerakkanUlar(Ular &ular, bool tambahPanjang) {

    // Menambah panjang ular jika memakan makanan
    if (tambahPanjang && ular.panjang < MAKS_PANJANG_ULAR) {
        ular.panjang++;
    }

    // Menggeser posisi tubuh mengikuti kepala
    for (int i = ular.panjang - 1; i > 0; i--) {

        ular.posisiX[i] = ular.posisiX[i - 1];
        ular.posisiY[i] = ular.posisiY[i - 1];
    }

    // Menggerakkan kepala sesuai arah 
    ular.posisiX[0] += ular.arahX;
    ular.posisiY[0] += ular.arahY;
}

// Memeriksa tabrakan ular dengan tubuhnya sendiri
bool tabrakanDenganDiriSendiri(Ular ular) {

    for (int i = 1; i < ular.panjang; i++) {

        if (ular.posisiX[0] == ular.posisiX[i] &&
            ular.posisiY[0] == ular.posisiY[i]) {

                return true;
            }
    }

    return false;
}

// Memeriksa apakah posisi ditempati ular
bool posisiAdaUlar(Ular ular, int x, int y) {

    for (int i =0; i < ular.panjang; i++) {

        if (ular.posisiX[i] == x && 
            ular.posisiY[i] == y) {

                return true;

         }
    }

    return false;
}
