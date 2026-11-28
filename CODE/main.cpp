#include <ncurses.h>
#include "game.h"

int main() {

    // Mengaktifkan mode ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Menjalankan gameplay
    jalankanGame();

    // Mengakhiri ncurses
    endwin();

    return 0;
}
