Kelompok 7

file admin.c
	File ini berisi tentang cara bagi admin dalam memanajemenkan daftar buku, dimana 
	admin bisa manambahkan, menghapus, mengedit, serta menyimpan buku  tersebut ke dalam 
	file tesk. Di dalam file ini pertama berisi struktur buku yang digunakan untuk menunjukkan 
	buku, seperti ID, judul, penulis, penerbit, jumlah buku, jumlah halaman, tahun terbit,
	dan jumlah yang tersedia. Kedua ada fungsi tentang tambahan buku yang digunakan untuk
	memasukkan informasi tentang buku baru, seperti ID, judul, penulis, penerbit, jumlah buku,
	jumlah halaman, tahun terbit,dan jumlah yang tersedia, dimana nanti akan disimpan dalam 
	array daftar buku. ketiga ada fungsi untuk menghapus buku yang digunakan penguna untuk
	menghpaus buku yang ingin dihapus dari daftar buku. keempat ada fungsi edit buku yang 
	digunakan pengguna untuk mengedit ID buku yang ingin di edit, misal pengguna ingin mencari 
	buku dengan judul atau ID yang berbeda. kelima ada fungsi simpan ke file teks yang digunakan 
	untuk menyimpan data buku yang telah dimasukkan ke dalam file teks dengan format yang sesuai.

file user.c
	File  ini berisi tentang cara bagi pengguna atau user untuk membuka sebuah menu sederhana yang 
	akan digunakan untuk berinteraksi dengan sistem manajemen dari sebuah perpustakaan, contohnya 
	jika ingin melihat daftar buku yang tersedia, meminjam buku, melihat daftar buku yang sudah dipinjam,
	serta bisa untuk mengembalikan buku yang sudah di pinjam. dan juga pengguna ingin keluar dari sistem
	tersebut. Di dalam file ini pertama ada cara untuk melihat buku yang tersedia (di dalam file books.txt),
	kedua ada fungsi untuk meminjam buku, dimana pengguna akan memasukkan judul buku yang ingin dipinjam,
	lalu akan diperiksa apakah buku tersebut ada atau tidak ada, kalau ada maka buku tersebut akan 
	ditambahkan ke dalam file borrowed_books.txt. ketiga ada fungsi untuk melihat buku yang dipinjam 
	di file borrowed_books.txt. keempat ada fungsi untuk mengembalikan buku, dimana pengguna akan memasukkan
	judul buku yang akan dikembalikan.maka buku yang sudah dikembalikan akan dihapus di file borrowed_books.
	txt dan akan ditambah lagi ke file books.txt.kemudian yang keenam ada fungsi main yang digunakan oleh
	pengguna untuk memilih apa pun yang ingin mereka lakukan, misalya seperti memilih untuk melihat buku, 
	meminjam buku, melihat buku yang ingin dipinjam, mengembalikan buku, serta keluar dari sistem tersebut.

file main.c 
	Di dalam file ini digunakan sebagai program utama yang memungkinkan admin untuk login dan mengelola 
	daftar buku,serta memungkinkan pengguna atau user untuk login dan melakukan operasi terkait buku 
	sesuai yang ingin di akses.Di dalam file ini berisi 3 blok kode program yang bertugas menangani 
	berbagai fungsi, seperti blok pertama berisi Login untuk admin, disini pengguna harus menggunakan 
	akun admin dengan memasukkan username dan password. Program kemudian memeriksa apakah username dan 
	password yang dimasukkan cocok dengan yang ada dalam file "admin.txt" atau "user.txt". jika login 
	berhasil maka program akan menampilkan pesan berhasil, begitu juga kalau login gagal.Pada blok kedua 
	berisi login untuk user, dimana login ini sama saja seperti login terhadap admin yaitu menggunakan
	username dan juga password. hanya saja ada ketentuan yang berbeda antara admin dan user. di bagian 
	user, user dapat melihat buku yang tersedia, meminjam buku, mengembalikan buku, atau keluar dari 
	program login tersebut. kemudian yang blok yang ketiga ada Operasi Admin, dimana berisi tentang cara 
	menjalan kan operasi admin tentang menajemen buku yang mencakup beberapa pilihan seperti menambah, 
	menghapus, atau mengedit buku dalam daftar. dimana saat setiap operasi yang dilakukan bersarkan input 
	pengguna dan diulang hingga pengguna memilih untuk keluar dari program login ini.

file login.c
	login.c adalah sebuah file yang berisi untuk menentukan berhasil atau tidaknya saat login.login ini 
	terbagi menjadi dua yitu memilih menggunakan akun sebagain user atau akun sebagai admin. Kemudian 
	pengguna akan diperintahkan untuk mengisi username dan password. Apabila akun yang dipilih adalah 
	akun user maka file yang digunakan adalah user.txt dan apabila akun yang dipilih adalah akun admin, 
	file yang digunakan adalah admin.txt. Kedua file txt tersebut berisi username dan password yang 
	sudah terdaftar sehingga apabila username dan password benar sesuai dengan txt tersebut maka login 
	berhasil. Namun, apabila username atau password salah atau tidak terdaftar maka login akan gagal.

file user.txt
	User.txt adalah sebuah file berbentuk txt yang berisi tentang username dan password dari akun
	user yang akan dipilih oleh pengguna pada saat login. Username dari User berada pada sebelah kiri
	sebelum tanda koma dan password dari akun user berada di sebelah kanan atau setelah koma karena
	kode yang dibuat berupa syntax yang dapat memisahkan sebuah baris menjadi dua bagian diantara
	tanda koma.

file bacaData.c
	Fungsi `bacaDataBuku` dalam kode C ini bertujuan untuk membaca data buku dari sebuah file teks
	dan menyimpannya dalam array struktur buku hingga mencapai akhir file atau jumlah buku yang dibaca
	mencapai batas maksimum (`MAX_BUKU`). Fungsi ini membuka file yang ditentukan, membaca informasi
	tiap buku (ID Buku, Judul, Penulis, Penerbit, Jumlah Halaman, Tahun Terbit, dan Jumlah Tersedia)
	menggunakan `fscanf` dan `fgets`, menghilangkan karakter newline dengan `strtok`, dan meningkatkan
	penghitung jumlah buku setiap kali data baru ditambahkan. Jika file tidak dapat dibuka, fungsi
	mencetak pesan kesalahan dan berhenti, kemudian menutup file setelah selesai membaca semua data.

file clearBuffer.c
	Fungsi `clearBuffer` dalam kode C ini berfungsi untuk membersihkan buffer input dengan cara membaca
	dan membuang semua karakter yang tersisa dalam buffer hingga mencapai karakter newline (`\n`) atau
	end-of-file (`EOF`). Fungsi ini berguna untuk memastikan tidak ada data residual yang mengganggu
	input berikutnya, terutama setelah menggunakan fungsi input seperti `scanf` yang tidak menghapus
	karakter newline dari buffer. Hal ini membantu mencegah masalah dalam pengambilan input berikutnya
	dan memastikan bahwa program dapat menerima input baru dengan benar.

file simpanData.c
	Fungsi `simpanDataBuku` dalam kode C ini bertujuan untuk menyimpan data buku yang ada dalam array
	struktur buku ke dalam sebuah file teks, menggantikan konten file yang ada dengan data terbaru. 
	Fungsi ini membuka file yang ditentukan oleh makro `FILENAME` dalam mode tulis ("w") dan memeriksa
	keberhasilannya; jika gagal, fungsi mencetak pesan kesalahan dan berhenti. Kemudian, fungsi menggunakan
	`fprintf` untuk menulis detail setiap buku (ID Buku, Judul, Penulis, Penerbit, Jumlah Halaman, Tahun
	Terbit, dan Jumlah Tersedia) ke dalam file dalam format yang telah ditentukan. Setelah semua data buku
	ditulis, file ditutup dengan `fclose` untuk memastikan data tersimpan dengan benar.

file header.h
	header.h adalah sebuah file header yang berisi deklarasi untuk fungsi-fungsi dan tipe data 
	yang akan digunakan di dalah program. Dengan menyertakan header.h dalam file,
	Kita dapat menggunakan tipe data User dan memanggil fungsi-fungsi yang telah dideklarasikan
	di dalamnya. Ini membantu dalam memisahkan deklarasi dari implementasi dan memungkinkan untuk
	penggunaan kembali kode. Fungsi #ifndef LIBRARY_H dan #define LIBRARY_H juga berfungsi pada header
	untuk menghindari pengulangan definisi jika file header.h disertakan lebih dari satu kali dalam
	satu unit kompilasi.

file books.txt
	File books.txt adalah sebuah file teks yang berisi daftar buku-buku beserta detailnya, seperti
	ID Buku, Judul, Penulis, Penerbit, Jumlah Halaman, Tahun Terbit, dan Jumlah Tersedia. Setiap buku
	memiliki entri yang terdiri dari beberapa baris dengan format yang telah ditentukan, yaitu tiap
	baris mewakili satu detail buku. Dengan menggunakan format ini, file books.txt menjadi sebuah
	struktur data yang terorganisir dan dapat dibaca dengan mudah baik oleh manusia maupun oleh
	program komputer. File ini bisa digunakan sebagai basis data sederhana untuk mengelola informasi
	tentang koleksi buku dalam sebuah perpustakaan atau toko buku.

file makefile 
	Makefile adalah sebuah file teks khusus yang digunakan dalam pengembangan perangkat lunak untuk
	mengotomatisasi proses kompilasi dan pembangunan program. Dengan menggunakan Makefile, pengembang
	dapat menentukan aturan-aturan untuk mengkompilasi setiap bagian dari proyek perangkat lunak mereka,
	serta mendefinisikan dependensi antar berkas. Hal ini memungkinkan pengembang untuk mengelola proyek
	dengan lebih efisien, menghindari kompilasi berulang kali dari berkas yang sama, dan memastikan bahwa
	hanya bagian-bagian tertentu yang diperlukan yang dikompilasi ulang saat ada perubahan. Makefile juga
	memungkinkan pengembang untuk menjalankan tugas tambahan, seperti membersihkan file sementara atau
	menjalankan pengujian otomatis, dengan mudah melalui perintah make. Dengan demikian, Makefile menjadi
	alat yang sangat berharga dalam mengelola kompleksitas pengembangan perangkat lunak dengan cara yang
	terstruktur dan terotomatisasi.
