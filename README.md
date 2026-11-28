# Final Project Snake Escape - Ncurses Implementation

## 📑 Daftar Isi
1. [Tentang Projek](#tentang-projek)
2. [Fitur Utama](fitur-utama)
3. [Struktur Projek](struktur-projek)
4. [Persyaratan Instalasi](persyaratan-instalasi)
5. [Cara Instalasi dan Menjalankan Program](cara-instalasi-dan-menjalankan-program)
6. [Kontrol Permainan](kontrol-permainan)
7. [Cara Bermain](cara-bermain)
8. [Credits](credits)

## 📖 Tentang Projek
Snake Escape merupakan permainan berbasis konsol yang dikembangkan menggunakan bahasa pemrograman C++ dengan bantuan library NCurses. Permainan ini menggabungkan konsep permainan ular klasik dengan petualangan menjelajahi labirin.
Dalam permainan ini, pemain bertugas mengendalikan ular untuk mengumpulkan makanan pada setiap level yang telah ditentukan, lalu menjelajahi jalur labirin, serta menemukan jalan keluar untuk menyelesaikan permainan dan melanjutkan ke level berikutnya.
Snake Escape dilengkapi dengan beberapa fitur yang mendukung pengalaman bermain, mulai dari menu utama, gameplay, sistem labirin, hingga pengelolaan statistik dan leaderboard pemain.
Projek ini dikembangkan sebagai bentuk penerapan konsep pemrograman C++, khusunya dalam penggunaan fungsi, perulangan, percabangan, array, Ncurses, bubble sort, searching, text file, dan animasi file.

## 🎮 Fitur Utama
Snake Escape memiliki empat fitur utama yang saling terhubung untuk mendukung jalannya permainan.
## 1. Menu Utama : 
Menampilkan tampilan awal yang berfungsi sebagai pusat navigasi permainan. Pemain dapat memilih berbagai opsi sebelum memulai permainan seperti start game, leaderboard, how to play, dan statistic.
## 2. Gameplay :
Bagian inti permainan untuk melakukan beberapa aktivitas dan menjalankan misi permainan yang meliputi mengendalikan pergerakan ular, mengumpulkan makanan untuk memperoleh skor, menjelajahi labirin, mencari jalan keluar dari labirin, dan menyelesaikan permainan.
## 3. Maze (Labirin) :
Area permainan berbentuk labirin yang menjadi tantangan utama bagi pemain. Pemain harus menjelajahi jalur yang tersedia dan menentukan arah untuk menemukan jalan keluar.
## 4. Data dan Leaderboard
Fitur data berfungsi untuk mengelola dan menyimpan informasi hasil permainan lalu data yang tersimpan digunakan untuk mencatat statistik permainan serta mendukung sistem leaderboard. Melalui fitur ini, pemain dapat melihat informasi mengenai hasil permainan dan membandingkan pencapaian dengan pemain lainnya.

## 📂 Struktur Projek
snake-escape/
│
├── CODE/
│   ├── game.cpp
│   ├── game.h
│   ├── leaderboard.cpp
│   ├── leaderboard.h
│   ├── main.cpp
│   ├── maze.cpp
│   ├── maze.h
│   ├── menu.cpp
│   ├── menu.h
│   ├── snake.cpp
│   ├── snake.h
│   ├── sound.cpp
│   ├── sound.h
│   ├── statistics.cpp
│   └── statistics.h
│
├── data/
│   ├── leaderboard.txt
│   └── statistic.txt
├── .gitignore
└── README.md

## ⚙️ Persyaratan Instalasi
Sebelum menjalankan Snake Escape, pastikan perangkat telah memiliki beberapa kebutuhan berikut:
- Bahasa pemrograman : C++
- Compiler : G++
- Library : NCurses
- Lingkungan Pengembangan : Visual Studio Code
- Sistem Operasi : Linux/Ubuntu (WSL)

  ## Cara Instalasi dan Menjalankan Program
  Buka terminal lalu jalankan perintah berikut :
  [GitHub Snake Escape](https://github.com/bahrul-codes/snake-escape)
  
  






