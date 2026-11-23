#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    mvprintw(1, 2, "SNAKE ESCAPE: THE MAZE CHALLENGE");
    mvprintw(3, 2, "Project structure is ready!");
    mvprintw(5, 2, "Press any key to exit...");

    refresh();
    getch();

    endwin();
    return 0;
}
