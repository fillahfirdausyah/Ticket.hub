#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


// Judul Program
void judul() {
	cout << "\t\t\t\t\t##############################" << endl;
	cout << "\t\t\t\t\t#                            #" << endl;
	cout << "\t\t\t\t\t#          Ticket.hub        #" << endl;
	cout << "\t\t\t\t\t#             V2.4           #" << endl;
	cout << "\t\t\t\t\t##############################" << endl;
	cout << "\t\t\t\t\t\t\t    19.11.3204" << endl;
}

// Animasi Loading
void loading() {
	char loading[100]= "Menghubungkan...../";
    for(int a = 0; a < 20; a++) {
         for(int b = 0; b < 100000000; b++) {}
       cout<<loading[a];
         }
}

void tema() {
	int tema;
	cout << endl;
	cout << "Tema" << endl;
	cout << "================" << endl;
	cout << "[1] Dark-Red"     << endl;
	cout << "[2] Dark-Green"   << endl;
	cout << "[3] Red-Yellow"   << endl;
	cout << "[4] Light-Green"  << endl;
	cout << "[5] Light-Blue"   << endl;
	cout << "================" << endl;
	cout << "Pilih Tema : ";
	cin >> tema;

	if (tema == 1) {
		system("color 0C");
	}else if (tema == 2){
		system("color 0A");
	}else if (tema == 3){
		system("color 4E");
	}else if (tema == 4){
		system("color 72");
	}else if (tema == 5){
		system("color 79");
	}
}

// Struktur Data
struct Tiket {
	string 	kode;
	string 	nama;
	int		harga;
	string 	jam;
	string 	tujuan;
};

Tiket batas[100];
int a,b,c,d;

//Prototype Fungsi
void menuUtama();
void login();
void mainAdmin();
void mainKasir();
void addData();
void lihatData();
void hapusData();
void editData();
void prosesTiket();
void cetakE();
void help();
void about();

//Main Program
main () {
	cout << "\n\n\n\n\n";
	cout<<"================================================TICKET.HUB V2.4====================================================";
	cout<<"===========================================PROGRAM MANAGEMEN & KASIR TICKET BUS==============================================";
 	cout<<"\n\n\n\t\t\t\t\t   PROGRAM BY FILLAH FIRDAUSYAH\n";
 	cout<<"\t\t\t\t\t\t    19.11.3204";
 	getch();
 	tema();
 	getch();
 	system("cls");

	judul();
	menuUtama();
	// mainAdmin();

getch();
}


// #########-Fungsi Program-####################

// Menu
void menuUtama() {

	int pilih;
	char is_continue;
	cout << "=======+Menu Utama+=========" << endl;
	cout << "[1] Login" << endl;
	cout << "[2] Lupa"  << endl;
	cout << "[3] Help"  << endl;
	cout << "[4] About" << endl;
	cout << "[5] Tema"  << endl;
	cout << "[6] exit"  << endl;
	cout << "============================" << endl;
	cout << "Pilih Menu [1-5]: ";
	cin >> pilih;


	switch (pilih) {
 		case 1:
 			login();
 		break;

 		case 2:
 			cout << "Anda lupa akun? silahkan hubungi super admin" << endl;
 			getch();
 			system("cls");
			judul();
			menuUtama();
 		break;

 		case 3:
 		system("cls");
			judul();
			help();
 		break;

 		case 4:
 		system("cls");
 			judul();
 			about();
 		break;

 		case 5:
 			system("cls");
 			judul();
 			tema();
 			system("cls");
 			judul();
 			menuUtama();
 		break;

 		case 6:
 			cout << "Terima Kasih " << endl;
 		break;
	}

}

// Proses Login
void login() {

	system("cls");
	judul();
	string user;
	string pass;
	cout << "Silahkan Login" << endl;
	cout << "============================" << endl;
	cout << "Username : ";
	cin >> user;
	cout << "Password : ";
	cin >> pass;
	cout << "============================" << endl;

		if (user == "admin" && pass == "admin123") {
			system("cls");
			judul();
			loading();
			mainAdmin();
		}else if (user == "kasir" && pass == "kasir123") {
			system("cls");
			judul();
			loading();
			mainKasir();
		}else {
			system("cls");
			judul();
			 cout << "Anda Karyawan? Jika lupa password hubungi Admin!" << endl;
			menuUtama();
		}
}

// Halaman Admin
void mainAdmin() {
	lanjut:
	system("cls");
	judul();

	char is_continue;
	int pilih;
	cout << endl;
	cout << endl;
	cout << "Selamat Datang Admin"         << endl;
	cout << "=======+Menu Admin+=========" << endl;
	cout << "[1] Tambah Data"              << endl;
	cout << "[2] Lihat  Data"              << endl;
	cout << "[3] Hapus   Data"             << endl;
	cout << "[4] Edit  Data"               << endl;
	cout << "[5] Masuk Sebagai Kasir"      << endl;
	cout << "[6] Logout"                   << endl;
	cout << "============================" << endl;
	cout << "Pilih Menu [1-6]: ";
	cin >> pilih;

	enum option {TAMBAH = 1, LIHAT, HAPUS, EDIT, KASIR, LOGOUT};
	switch (pilih) {

		case TAMBAH:
			system("cls");
			judul();
			addData();
		break;

		case LIHAT:
			system("cls");
			judul();
			lihatData();
		break;

		case HAPUS:
			hapusData();
		break;

		case EDIT:
			system("cls");
			judul();
			editData();
			break;
		case KASIR:
			mainKasir();
			break;
		case LOGOUT:
			system("cls");
			judul();
			cout << "Anda telah logout!" << endl;
			menuUtama();
			break;
	}

	label_continue:
	cout << endl;
	cout << "Lanjutkan?(Y/N) : ";
	cin >> is_continue;

	if (is_continue == 'y' || is_continue == 'Y') {
		goto lanjut;
	}else if (is_continue == 'n' || is_continue == 'N') {
		system("cls");
		judul();
		cout << "Anda telah logout!" << endl;
		menuUtama();
	}else {
		goto label_continue;
	}

}

// Halaman Kasir
void mainKasir() {
	lanjut:

	system("cls");
	judul();
	char is_continue;
	int pilih;
	cout << endl;
	cout << endl;
	cout << "Selamat Datang Kasir"         << endl;
	cout << "=======+Menu Kasir+=========" << endl;
	cout << "[1] Lihat  Tiket"             << endl;
	cout << "[2] Proses Tiket"             << endl;
	cout << "[3] Cetak  E-Tiket"           << endl;
	cout << "[4] Logout"                   << endl;
	cout << "============================" << endl;
	cout << "Pilih Menu [1-4]: ";
	cin >> pilih;

	enum option {LIHAT = 1, PROSES, CETAK, KELUAR, FINISH};
	switch (pilih) {

		case LIHAT:
			system("cls");
			judul();
			lihatData();
		break;

		case PROSES:
			system("cls");
			judul();
			prosesTiket();
		break;

		case CETAK:
			cetakE();
		break;

		case KELUAR:
			system("cls");
			judul();
			cout << "Anda telah logout!" << endl;
			menuUtama();
	
		break;


	}

	label_continue:
	cout << endl;
	cout << "Lanjutkan?(Y/N) : ";
	cin >> is_continue;

	if (is_continue == 'y' || is_continue == 'Y') {
		goto lanjut;
	}else if (is_continue == 'n' || is_continue == 'N') {
		system("cls");
		judul();
		cout << "Anda telah logout!" << endl;
		menuUtama();
	}else {
		goto label_continue;
	}
}

// Tambah Data (Admin)
void addData() {
	cout << "Tambah Tiket"                 << endl;
	cout << "============================" << endl;
	cout << "\nBerapa Tiket? : ";
	cin >> b;

   	d = 0;
   for (c = 0; c < b; c++) {
   		d=d+1;
   		cout << "\nTiket ke-" << d << endl;
   		cout << "Kode Tiket\t: ";
   		cin  >> batas[a].kode;
   		cout << "Nama Bus\t: ";
   		cin  >> batas[a].nama;
   		cout << "Harga Tiket\t: ";
   		cin  >> batas[a].harga;
   		cout << "Jam Berangkat\t: ";
   		cin  >> batas[a].jam;
   		cout << "Tujuan\t\t: ";
   		cin  >> batas[a].tujuan;
   		a++;
   	}
   	cout << endl;
   	cout << "Data berhasil di tambahkan" << endl;
}

// Lihat Data (Admin)
void lihatData() {
	int i,j;
 	cout << "Tiket" << endl;
 	cout << "============" << endl;
 	cout << endl;
 	cout << "No. \tKode Tiket. \tNama Bus. \tHarga Tiket. \tJam Berangkat. \tTujuan" << endl;
 	cout << "==============================================================================" << endl;
 	j=0;
 	for (i = 0; i < a; i++) {
 	j+=1;
  	cout << j << "\t";
  	cout << batas[i].kode   << "\t\t";
  	cout << batas[i].nama   << "\t\t";
  	cout << batas[i].harga  << "\t\t";
  	cout << batas[i].jam    << "\t\t";
  	cout << batas[i].tujuan << "\t\t";
  	cout << endl;
  }
  cout << "==============================================================================" << endl;

}

// Hapus Data (Admin)
void hapusData() {
	awal:
	system("cls");
	judul();
	int x,y;
	char z;

	lihatData();
  	cout << "Hapus Tiket No : ";
  	cin  >> x;	
  	cout << endl;
  	cout << "Yakin Ingin Hapus? (y/n) : ";
  	cin  >> z;

  		yakin:
  		if (z == 'y' || z == 'Y') {
  			y = x-1;
 			a--;
 		for (int i = y; i < a; i++){
 			batas[i]=batas[i+1];
 		}
 			cout<<"Tiket Berhasil Di Hapus" << endl;;
 			cout << "======================" << endl;
  		}else if (z == 'n' || z == 'N') {
  			goto awal;
  		}else {
  			goto yakin;
  		}
 	
}

// Edit Data (Admin)
void editData() {
	int i,k,l,m;
	lihatData();
	cout << "Edit Tiket No : ";
	cin >> k;
	system("cls");
	judul();
	l = k-1;
	cout << endl;
	cout << "Tiket yang akan diedit" << endl;
	cout << "========================" << endl;
	cout << "Kode Tiket    : " << batas[l].kode << endl;
	cout << "Nama Bus      : " << batas[l].nama << endl;
	cout << "Harga Tiket   : " << batas[l].harga << endl;
	cout << "Jam Berangkat : " << batas[l].jam << endl;
	cout << "Tujuan        : " << batas[l].tujuan << endl;
	cout << "========================" << endl;
		cout << endl;
		cout << "Edit Data" << endl;
		cout << "============================" << endl;
   		cout << "Kode Tiket\t: ";
   		cin  >> batas[l].kode;
   		cout << "Nama Bus\t: ";
   		cin  >> batas[l].nama;
   		cout << "Harga Tiket\t: ";
   		cin  >> batas[l].harga;
   		cout << "Jam Berangkat\t: ";
   		cin  >> batas[l].jam;
   		cout << "Tujuan\t\t: ";
   		cin  >> batas[l].tujuan;
   	system("cls");
   	judul();
   	lihatData();
   		cout << "Data berhasil di simpan" << endl;
}

// Proses Tiket (Kasir)
void prosesTiket(){
	int i,j,k;
	int org,total,diskon,pm,kbl;
	int bus;
	
	lihatData();
	cout << "Pilih Bus : ";
	cin >> k;
	j = k-1;
	cout << endl;
	cout << "Tiket yang dipilih" << endl;
	cout << "========================" << endl;
	cout << "Kode Tiket    : " << batas[j].kode << endl;
	cout << "Nama Bus      : " << batas[j].nama << endl;
	cout << "Harga Tiket   : " << batas[j].harga << endl;
	cout << "Jam Berangkat : " << batas[j].jam << endl;
	cout << "Tujuan        : " << batas[j].tujuan << endl;
	cout << "========================" << endl;
		cout << "Berapa orang ? : ";
		cin >> org;
		total = org * batas[j].harga;
		cout << "Total nya adalah : " << total << endl;
			if (total >= 300000 && total <= 500000) {
				diskon = total - 25000;
				cout << "Dapat potongan sebesar 25.000" << endl;
				cout << "Total yang harus dibayar : " << diskon << endl;
				cout << "Uang pembeli sebesar     : ";
				cin  >> pm;
				kbl = diskon - pm;
				cout << "Kembalian sebesar        : " << kbl << endl;
			}else if (total <= 100000 && total <= 250000 ) {
				diskon = total - 15000;
				cout << "Dapat potongan sebesar 15.000" << endl;
				cout << "Total yang harus dibayar : " << diskon << endl;
				cout << "Uang pembeli sebesar     : ";
				cin  >> pm;
				kbl = pm - diskon;
				cout << "Kembalian sebesar        : " << kbl << endl;
			}else {
				cout << "Total yang harus dibayar : " << total << endl;
				cout << "Uang pembeli sebesar     : ";
				cin  >> pm;
				kbl = total - pm;
				cout << "Kembalian sebesar        : " << kbl << endl;
			}
		
		
	
}

// Cetak E-TIket (kasir)
void cetakE() {
	cout << "Cetak E-Tiket" << endl;
	cout << "==================" << endl;
	cout << "Mohon maaf cetak E-Tiket masih dalam proses perbaikan" << endl;
}

// Help
void help() {
	int bantu;
	char kbl;
	awal:
	cout << "Selamat Datang di pusat bantuan Ticket.hub" << endl;
	cout << "====================================================" << endl;
	cout << endl;
	cout << "Ada yang bisa kami bantu?"    << endl;
	cout << "============================" << endl;
	cout << "[1] Admin "  << endl;
	cout << "[2] Kasir "  << endl;
	cout << "[0] Kembali" << endl;
	cout << "============================" << endl;
	cout << "Bantuan tentang : ";
	cin  >> bantu;

		if (bantu == 1) {
			system("cls");
			judul();
			cout << "Pusat bantuan tentang admin" << endl;
			cout << "================================" << endl;
			cout << "Jika ingin masuk sebagai admin pada menu utama pilih menu 1 (login)." << endl;
			cout << "Pada kolom username ketikan 'admin' dan password 'admin123'" << endl;
			cout << endl;
			cout << "[1] Tambah Data " << endl;
			cout << "Menu tambah data untuk menambahkan data tiket yang nanti akan diproses oleh kasir" << endl;
			cout << "Format pengisian data yang benar sebagai berikut :" << endl;
			// cout << endl;
			cout << "	- Pilih berapa tiket yang akan dimasukan" << endl; 
			cout << "	- Kode tiket berisi 4 huruf kapital dan diikuti 2 angka" << endl;
			cout << " 		 Kode Tiket    : AXOW-51" << endl;
			cout << "	- Nama bus diisi oleh nama bunga" << endl;
			cout << "  		Nama Bus      : Melati" << endl;
			cout << "	- Harga tiket diisi tanpa menggunakan titik(.) atau koma(,)" << endl;
			cout << "  		Harga Tiket   : 45000" << endl;
			cout << "	- Jam keberangatan dipisahkan oleh titik dua(:)" << endl;
			cout << "  		Jam Berangkat : 10:00" << endl;
			cout << "	- Tujuan bus diisi dengan nama kota" << endl;
			cout << "  		Tujuan        : Solo" << endl;
			// cout << endl;
			cout << "[2] Lihat Data " << endl;
			cout << "  	Pada menu ini kita bisa melihat data tiket yang sudah di inputkan." << endl;
			// cout << endl;
			cout << "[3] Hapus Data " << endl;
			cout << "  	Untuk menghapus data tiket kita cukup memilih nomor berapa tiket yang akan di hapus." << endl;
			// cout << endl;
			cout << "[4] Edit Data " << endl;
			cout << "  	Ketika kita ingin mengedit tiket kita cukup memilih tiket yang akan diedit berdasarkan nomor tiket tersebut." << endl;
			cout << endl;
			lan:
			cout << "[y/n] Kembali : ";
			cin  >> kbl;
					if (kbl == 'y' || kbl == 'Y') {
					system("cls");
					judul();
					goto awal;
				}else {
					goto lan;
				}
		}else if (bantu == 2) {
			system("cls");
			judul();
			cout << "Pusat bantuan tentang kasir" << endl;
			cout << "================================" << endl;
			cout << "Jika ingin masuk sebagai kasir pada menu utama pilih menu 1 (login)." << endl;
			cout << "Pada kolom username ketikan 'kasir' dan password 'kasir123'" << endl;
			cout << endl;
			cout << "[1] Lihat Tiket" << endl;
			cout << "	Untuk melihat tiket yang sudah dimasukan oleh admin." << endl;
			cout << "[2] Proses Tiket" << endl;
			cout << "	Dimenu ini kasir akan memproses pesanan dari penumpang yang ingin membeli tiket" << endl;
			cout << "  	kasir memilih bus yang dipesan penumpang berdasarkan nomor tiket" << endl; 
			cout << "  	kasir akan menanyakan berapa orang dan akan memproses pembayaran." << endl;
			cout << "[3] Cetak  E-Tiket" << endl;
			cout << "	Dimenu ini kasir bisa mencetak E-Tiket penumpang yang sudah di pesan online" << endl;
			cout << "  	kasir hanya menanyakan kode penumpang dan bisa langsung di proses" << endl;
			cout << endl;
			jut:
			cout << "[y/n] Kembali : ";
			cin  >> kbl;
				if (kbl == 'y' || kbl == 'Y') {
					system("cls");
					judul();
					goto awal;
				}else {
					goto jut;
				}
		}else if (bantu == 0) {
			system("cls");
			judul();
			menuUtama();
		}
}

// About
void about() {
	int about;
	char kbl;
	con:
	cout << "About" << endl;
	cout << "========================" << endl;
	cout << endl;
	cout << "[1] About Me" << endl;
	cout << "[2] About Ticket.hub" << endl;
	cout << "[0] Kembali" << endl;
	cout << "========================" << endl;
	cout << "About : ";
	cin >> about;

		if (about == 1) {
			system("cls");
			judul();
			cout << "Programmer" << endl;
			cout << "======================" << endl;
			cout << "Nama saya adalah Fillah Akbar Firdausyah saya lahir dikota Bitung,Sulawesi Utara pada tahun 2000, saya merupakan" << endl;;
			cout << "anak yang suka tentang teknologi terlebih pada bidang IT sampai-sampai waktu SMK dulu saya sering dipanngil IT Guy" << endl;; 
			cout << "Karena ketertarikan saya akan dunia IT saya waktu lulus SMP memutuskan untuk masuk SMK Jurusan Teknik Komputer dan Jaringan (TKJ)," << endl; 
			cout << "dan setelah saya lulu dari SMK saya masuk ke Universitas AMIKOM Yogyakarta mengambil Jurusan S1-Informatika" << endl;
			ti:
			cout << "[y/n] Kembali : ";
			cin  >> kbl;
			if (kbl == 'y' || kbl == 'Y') {
					system("cls");
					judul();
					goto con;
				}else {
					goto ti;
				}
		}else if (about == 2) {
			system("cls");
			judul();
			cout << "Ticket.hub V2.4" << endl;
			cout << "======================" << endl;
			cout << " Ticket.hub adalah aplikasi Management dan Sistem Kasir untuk tiket bus yang multi platform kedepanya," << endl; 
			cout << "Ticket.hub pertama dibuat dalam bentuk Website App(V1.3) dan sekarang Ticket.hub dalam proses pengembangan dan berharap lebih baik kedepannya" << endl;
			nue:
			cout << "[y/n] Kembali : ";
			cin  >> kbl;
			if (kbl == 'y' || kbl == 'Y') {
					system("cls");
					judul();
					goto con;
				}else {
					goto nue;
				}
		}else if (about == 0) {
			system("cls");
			judul();
			menuUtama();
		}
}
