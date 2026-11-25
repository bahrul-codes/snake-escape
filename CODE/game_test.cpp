#include <ncurses.h>
#include "game.h"

int main() {
    //Memulai ncurses
    initscr();

    // Mengaktifkan tombol panah
    keypad(stdscr, TRUE);

    // Menghilangkan tampilan kursor
    curs_set(0);

    // Memulai permainan
    mulaiGame();

    // Menjalankan gameplay
    jalankanGame();

    // Mengakhiri ncurses
    endwin();

    return 0;
}