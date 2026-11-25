#include <ncurses.h>
#include "maze.h"

WINDOW *mywin;

// Ukuran labirin
const int BARIS = 15;
const int KOLOM = 30;

// Menyimpan peta labirin
char peta[15][30];

// Membuat peta labirin
void buatMaze() {

    // Mengaktifkan warna
    start_color();

    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    // Membuat peta dengan ruang kosong dan dinding
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {

            if (i == 0 || i == BARIS - 1 || j == 0 || j == KOLOM - 1) {
                peta[i][j] = '#'; // Dinding
            } else {
                peta[i][j] = ' '; // Ruang kosong
            }
        }
    }

    // Membuat beberapa rintangan
    for (int j = 5; j < 23; j++) {
        if (j != 14 ) {
            peta[4][j] = '#';
        }
    }

    for (int i = 6; i < 12; i++) {
        peta[i][10] = '#';
    }

    for (int j = 15; j < 27; j++) {
        peta[9][j] = '#';
    }

    // Membuat jendela labirin
    mywin = newwin(17, 32, 2, 5);

    // Memeriksa apakah jendela berhasil dibuat
    if (mywin == NULL) {
        return;
    }

    // Membuat bingkai jendela
    box(mywin, 0, 0);

    wrefresh(mywin);
}

// Menampilkan labirin dengan animasi
void tampilkanMaze() {

    // Warna dinding
    wattron(mywin, COLOR_PAIR(4));

    // Menampilkan dinding satu per satu 
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (peta[i][j] == '#') {
                mvwaddch(mywin, i + 1, j + 1, '#');
                wrefresh(mywin);
                napms(15); // Delay untuk animasi
            }
        }
    }

    wattroff(mywin, COLOR_PAIR(4));
    wrefresh(mywin);
}

// Menghapus jendela labirin
void hapusMaze() {

    if (mywin != NULL) {
        delwin(mywin);
        mywin = NULL;
    }
}   