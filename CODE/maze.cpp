#include <ncurses.h>
#include "maze.h"

// Mengatur bentuk awal maze
void inisialisasiMaze(Maze &maze) {

    const char* layout[MAZE_BARIS] = {
        "##############################",
        "        #              #     #",
        "#               #      #     #",
        "#       #       #            #",
        "###   ####    #####   ###   ##",
        "#       #              #     #",
        "#               #      #     #",
        "#       #       #            #",
        "##     ###   #####   ####   ##",
        "#       #              #     #",
        "#               #      #     #",
        "#       #       #            #",
        "###     ####   ####     ######",
        "#                            #",
        "##############################"
    };

    // Menyalin bentuk maze ke dalam array
    for (int y = 0; y < MAZE_BARIS; y++) {
        for (int x = 0; x < MAZE_KOLOM; x++) {
            maze.peta[y][x] = layout[y][x];
        }
    }

    // Pintu keluar awalnya tertutup
    maze.pintuKeluarTerbuka = false;
}
 

// Menggambar maze ke layar
void gambarMaze(WINDOW* jendela, Maze maze) {

    for (int y = 0; y < MAZE_BARIS; y++) {
        for (int x = 0; x < MAZE_KOLOM; x++) {

            char karakter = maze.peta[y][x];

            // Menampilkan pintu masuk
            if (x == 0 && y == 1) {
                karakter = 'S';
            }

            // Menampilkan pintu keluar
            else if (x == 29 && y == 13) {

                if (maze.pintuKeluarTerbuka) {
                    karakter = 'E';
                }
                else {
                    karakter = 'X';
                }
            }

            // Menggambar karakter ke dalam jendela
            mvwaddch(jendela, y + 1, x + 1, karakter);
        }
    }
}


// Memeriksa apakah posisi merupakan dinding
bool posisiTembok(Maze maze, int x, int y) {

    // Posisi di luar maze di anggap dinding
    if (x < 0 || x >= MAZE_KOLOM || y < 0 || y >= MAZE_BARIS) {
        return true;
    }

    // Memeriksa pintu keluat
    if (x == 29 && y == 13) {
        return !maze.pintuKeluarTerbuka;
    }

    // Memeriksa apakah isi peta adalah dinding
    if (maze.peta[y][x] == '#') {
        return true;
    }

    return false;
}


// Membuka pintu keluar
void bukaPintuKeluar(Maze &maze) {
    maze.pintuKeluarTerbuka = true;
}
