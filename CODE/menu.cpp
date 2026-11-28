#include <ncurses.h>
#include <unistd.h>
#include "menu.h"

// menampilkan intro game
void tampilkanIntro (){
    clear();

    // mengaktifkan warna 
    start_color();

    // membuat kombinasi teks magenta dan bg hitam
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);

    // mengatur background layar
    bkgd(COLOR_PAIR(1));
    erase();

    // mengaktifkan warna magenta
    attron(COLOR_PAIR(1));
    const char* judul = "SNAKE ESCAPE";
    const char* subjudul = "THE MAZE CHALLENGE";

    // garis pembatas atas
    mvprintw(4, 24, "================================");

    // animasi judul game
    for(int i = 0; judul[i] != '\0'; i++){
        mvprintw(6, 34 + i, "%c", judul[i]);
        refresh();
        usleep(150000); 
    }

    // animasi subjudul
    for(int i = 0; subjudul[i] != '\0'; i ++){
        mvprintw(8, 31 + i, "%c", subjudul[i]);
        refresh();
        usleep(100000); 
    }

    // garis pembatas bawah
    mvprintw(10, 24, "================================");

    // pesan untuk melanjutkan
    mvprintw(13, 26, "Press any key to continue...");
    attroff(COLOR_PAIR(1));
    refresh();

    // menunggu tombol ditekan
    getch();

}

// menampilkan layar PLAY
void tampilkanPlay(){
    clear();

    // menggunakan warna magenta
    attron(COLOR_PAIR(1));
    mvprintw(4, 24, "================================");
    mvprintw(6, 34, "SNAKE ESCAPE");
    mvprintw(8, 31, "THE MAZE CHALLENGE");
    mvprintw(11, 36, "[ PLAY ]");
    mvprintw(14, 25, "Press ENTER to start the game");
    mvprintw(16, 24, "================================");

    attroff(COLOR_PAIR(1));
    refresh();

    // menunggu tombol ENTER
    int tombol;
    while (true){
        tombol = getch();
            if(tombol == 10 || tombol == KEY_ENTER){
            break;
        }
    }
}