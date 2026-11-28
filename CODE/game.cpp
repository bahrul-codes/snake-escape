#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "game.h"
#include "menu.h"
#include "snake.h"
#include "maze.h"

// Membuat posisi makanan secara acak
void buatMakanan(Maze maze, Ular ular, int &x, int &y) {

    do {
        x = rand() % MAZE_KOLOM;
        y = rand() % MAZE_BARIS;

    } while (
        posisiTembok(maze, x, y) ||
        posisiAdaUlar(ular, x, y) ||
        (x == 0 && y == 1) || (x == 29 && y == 13)
    );
}

// Menjalankan keseluruhan gameplay
void jalankanGame() {

    srand(time(0));

    //Menampilkan intro dan menu
    tampilkanIntro();
    tampilkanPlay();

    // Membuat data maze dan ular
    Maze maze;
    Ular ular;

    inisialisasiMaze(maze);
    inisialisasiUlar(ular);

    // Membuat window maze
    WINDOW* jendela = newwin(
        MAZE_BARIS + 2,
        MAZE_KOLOM + 2,
        4,
        5
    );

    keypad(jendela, TRUE);
    wtimeout(jendela, 120);

    int skor = 0;
    const int TARGET = 7;

    int makananX, makananY;

    buatMakanan(maze, ular, makananX, makananY);

    bool gameSelesai = false;
    bool menang = false;

    // Loop utama gameplay
    while (!gameSelesai) {

        // Menggambar tampilan permainan
        clear();

        mvprintw(1, 5, "SNAKE ESCAPE");
        mvprintw(2, 5, "Makanan: %d/%d", skor, TARGET);

        box(jendela, 0, 0);

        gambarMaze(jendela, maze);

        // Menggambar makanan
        if (skor < TARGET) {
            mvwaddch(
                jendela,
                makananY + 1,
                makananX + 1,
                '*'
            );
        }

        // Menggambar ular
        gambarUlar(jendela, ular);

        refresh();
        wrefresh(jendela);

        // Membaca tombo keyboard
        int tombol = wgetch(jendela);

        if (tombol != ERR) {
            ubahArahUlar(ular, tombol);
        }

        // Menghitung posisi ular memakan makanan
        bool makan = (
            skor < TARGET &&
            nextX == makananX &&
            nextY == makananY
        );

        // Menggerakkan ular
        gerakkanUlar(ular, makan);

        // Memeriksa tabrakan dengan dinding
        bool kenaTembok = posisiTembok (
            maze,
            ular.posisiX[0],
            ular.posisiY[0],
        );

        // Pintu keluar boleh dilewati setelah terbuka
        if (
            ular.posisiX[0] == 29 &&
            ular.posisiY[0] == 13 &&
            maze.pintuKeluarTerbuka
        ) {
            kenaTembok = false;
        }

        // Memeriksa tabrakan
        if (
            kenaTembok || tabrakanDenganDiriSendiri(ular)
        ) {
            gameSelesai = true;
            menang = false;
        }

        // Jika ular memakan makanan
        if (!gameSelesai && makan) {

            skor++;

            // Membuka pintu setelah 7 makanan
            if (skor == TARGET) {
                bukaPintuKeluar(maze);
            }
            else {
                // Membuat makanan baru
                buatMakanan(
                    maze,
                    ular,
                    makananX,
                    makananY
                );
            }
        }

        // Memeriksa apakah ular mencapai pintu keluar
        if (
            !gameSelesai &&
            maze.pintuKeluarTerbuka &&
            ular.posisiX[0] == 29 &&
            ular.posisiY[0] == 13
        ) {
            gameSelesai = true;
            menang = true;
        }
    }

    // Menghapus window permainan
    delwin(jendela);

    // Menampilkan hasil permainan
    clear();

    if (menang) {
        mvprintw(8, 20, "SELAMAT! KAMU MENANG YEY!");
    }
    else {
        mvprintw(8, 25, "YAHH GAME OVER!");
    }

    mvprintw(10, 25, "Skor: %d/%d", skor, TARGET);
    mvprintw(13, 18, "Press any key to exit...");

    refresh();
    timeout();
    getch();
}

