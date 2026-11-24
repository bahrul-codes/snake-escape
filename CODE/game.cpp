<<<<<<< Updated upstream
// Modul gameplay Snake Escape.
// Implementasi akan ditambahkan secara bertahap.
=======
#include <ncurses.h>

int main() {
    // 1. Mulai mode NCurses
    initscr();

    // 2. Pengaturan dasar layar & input
    cbreak();               // Baca input per karakter langsung tanpa tunggu Enter
    noecho();               // Jangan tampilkan karakter tombol yang ditekan ke layar
    keypad(stdscr, TRUE);   // Aktifkan tombol khusus seperti Arrow keys, F1, dll.
    curs_set(0);            // Sembunyikan kursor (0 = hilang, 1 = normal, 2 = blok)

    // Opsional: aktifkan warna jika ingin memakai warna teks
    // if (has_colors()) {
    //     start_color(); 
    // }

    // --- Tulis kode game atau tampilan NCurses Anda di sini ---
    mvprintw(1, 2, "Template kosong NCurses siap digunakan.");
    mvprintw(3, 2, "Tekan tombol apa saja untuk keluar...");
    refresh();

    // Tunggu satu input tombol sebelum keluar
    getch();

    // 3. Kembalikan terminal ke mode normal sebelum program selesai
    endwin();
    return 0;
}
>>>>>>> Stashed changes
