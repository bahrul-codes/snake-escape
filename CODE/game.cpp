#include <ncurses.h>
#include <unistd.h>
#include "game.h"
#include "snake.h"

bool gameOver = false;
int skor = 0;

// Menampilkan Game Over
void tampilkanGameOver() {
    clear();

    mvprintw(10, 15, "GAME OVER! ");
    mvprintw(12, 15, "Skor: %d", skor);
    mvprintw(14,15, "Tekan tombol apa saja untuk keluar");

    refresh();
    getch();
}

// Jeda permainan
void jedaGame() {
    mvprintw(0, 0, "PAUSE - Tekan SPACE untuk lanjut");
    refresh();

    while (getch() != ' ') {

    }
}

// Memulai permainan 
void mulaiGame() {
    resetUlar();
    skor = 0;
    gameOver = false;

}

// Menjalankan permainan
void jalankanGame() {
    int lebar = 40;
    int tinggi = 20;

    while (!gameOver) {
        clear();

        // Membaca tombol keyboard
        timeout(150);
        int tombol = getch();

        switch (tombol) {
            case KEY_UP:
            if (arahY != 1) {
                arahX = 0;
                arahY = -1;

            }
            break;

            case KEY_DOWN:
            if (arahY != -1) {
                arahX = 0;
                arahY = 1;

            }
            break;

            case KEY_LEFT:
            if (arahX != 1) {
                arahX = -1;
                arahY = 0;
            }
            break;

            case KEY_RIGHT:
            if (arahX != -1) {
                arahX = 1;
                arahY = 0;
            }
            break;

            case ' ':
            jedaGame();
            break;

        }

        // Menggerakan ular
        gerakUlar();

        // Memeriksa tabrakan dengan dinding 
        if (posisiX[0] <= 0 || posisiX[0] >= lebar -1 || 
            posisiY[0] <= 0 || posisiY[0] >= tinggi -1) {
            gameOver = true;

         }

         // Memeriksa tabrakan dengan tubuh ular sendiri
         if (cekTabrakanUlar()) {
            gameOver = true;
         }

         // Menggambar arena
         for (int x = 0; x < lebar; x++) {
             mvaddch(0, x, '#');
             mvaddch(tinggi - 1, x, '#');

         }

         for (int y = 0; y < tinggi; y++) {
             mvaddch(y, 0, '#');
             mvaddch(y, lebar - 1, '#');

             }
         // Menggambar ular
         for (int i = 0; i < panjangUlar; i++) {
             mvaddch(posisiY[i], posisiX[i], 'O');
         }

         mvprintw(tinggi + 1, 0, "Sko: %d", skor);

         refresh();
    }

    tampilkanGameOver();
}