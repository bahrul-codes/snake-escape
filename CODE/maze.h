#ifndef MAZE_H
#define MAZE_H

#include <ncurses.h>

const int MAZE_BARIS = 15;
const int MAZE_KOLOM = 30;

// Mengelompokkan data maze
struct Maze {
    char peta[MAZE_BARIS][MAZE_KOLOM];
    bool pintuKeluarTerbuka;
};

// Mengatur bentuk dan kondisi awal maze
void inisialisasiMaze(Maze &maze);

// Menggambar maze ke layar
void gambarMaze(WINDOW* jendela, Maze maze);

// Memeriksa apakah posisi merupakan dinding
bool posisiTembok(Maze maze, int x, int y);

// Membuka pintu keluar
void bukaPintuKeluar(Maze &maze);

#endif