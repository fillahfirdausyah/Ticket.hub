#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


// Judul Program
void judul() {
	system("color 0C");
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

// Struktur Data
struct Tiket {
	string 	kode;
	string 	nama;
	string	harga;
	string 	jam;
	string 	tujuan;
};

Tiket batas[100];
int a,b,c,d;

//Prototype Fungsi
void menuUtama();
void login();
void mainAdmin();
void addData();
void lihatData();
void hapusData();
void editData();


//Main Program
main () {
	cout<<"\n\n\n\n\n=============================PROGRAM Pesan Ticket Bus=============================";
 	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t     PROGRAM Fillah Firdausyah\n\n";
 	cout<<"\t\t\t        ASSALAMU'ALAIKUM";
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
	cout << "[2] Lupa" << endl;
	cout << "[3] Help" << endl;
	cout << "[4] About" << endl;
	cout << "[5] exit" << endl;
	cout << "============================" << endl;
	cout << "Pilih Menu [1-5]: ";
	cin >> pilih;


	switch (pilih) {
 		case 1:
 			login();
 		break;

 		case 2:
 			cout << "lupa" << endl;
 		break;

 		case 3:
 		system("cls");
			judul();
			cout << "\t\t\t\t   Selamat Datang di pusat bantuan Tickte.hub";
 		break;

 		case 4:
 			cout << "About " << endl;
 		break;

 		case 5:
 		cout << "Terima Kasih " << endl;

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
		}else {
			system("cls");
			judul();
			 cout << "Anda Karyawan? Jika lupa password hubungi Admin!" << endl;
			menuUtama();
		}
}

// Halaman Admin
void mainAdmin(){
	lanjut:
	system("cls");
	judul();


	char is_continue;
	int pilih;
	cout << endl;
	cout << endl;
	cout << "Selamat Datang Admin" << endl;
	cout << "=======+Menu Admin+=========" << endl;
	cout << "[1] Tambah Data" << endl;
	cout << "[2] Lihat  Data" << endl;
	cout << "[3] Hapus   Data" << endl;
	cout << "[4] Edit  Data" << endl;
	cout << "[5] Masuk Sebagai Kasir" << endl;
	cout << "[6] Logout" << endl;
	cout << "============================" << endl;
	cout << "Pilih Menu [1-6]: ";
	cin >> pilih;

	enum option {TAMBAH = 1, LIHAT, HAPUS, EDIT, KASIR, FINISH};
	switch (pilih) {

		case TAMBAH:
			system("cls");
			judul();
			addData();
		break;

		case LIHAT:
			lihatData();
		break;

		case HAPUS:
			hapusData();
		break;

		case EDIT:
			editData();
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

// Tambah Data
void addData() {
	cout << "Tambah Tiket" << endl;
	cout << "============================" << endl;
	cout << "\nBerapa Tiket? : ";
	cin >> b;
   	d = 0;
   for (c = 0; c < b; c++) {
   		d=d+1;
   		cout << "\nTiket ke-" << d << endl;
   		cout << "Kode Tiket\t: ";
   		cin >> batas[a].kode;
   		cout << "Nama Bus\t: ";
   		cin >> batas[a].nama;
   		cout << "Harga Tiket\t: ";
   		cin >> batas[a].harga;
   		cout << "Jam Berangkat\t: ";
   		cin >> batas[a].jam;
   		cout << "Tujuan\t\t: ";
   		cin >> batas[a].tujuan;
   		a++;
   	}
   	cout << endl;
   	cout << "Data berhasil di tambahkan" << endl;
}

void lihatData() {
	system("cls");
	judul();
	int i,j;
 	cout << "Data Tiket" << endl;
 	cout << "============================" << endl;
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

void hapusData() {
	system("cls");
	judul();
	int x,y;
	lihatData();
  	cout << "Hapus Tiket No : ";
  	cin >> x;
 	y = x-1;
 	a--;
 		for (int i = y; i < a; i++){
 			batas[i]=batas[i+1];
 		}
 cout<<"Tiket Berhasil Di Hapus";
 cout << "============================" << endl;
}

void editData() {
	int k,l;
	cout << "Edit Data" << endl;
	cout << "============================" << endl;
	lihatData();
	cout << "Edit Tiket No : ";
	cin >> k;
	l=k-1;
   		cout << "Kode Tiket\t: ";
   		cin >> batas[l].kode;
   		cout << "Nama Bus\t: ";
   		cin >> batas[l].nama;
   		cout << "Harga Tiket\t: ";
   		cin >> batas[l].harga;
   		cout << "Jam Berangkat\t: ";
   		cin >> batas[l].jam;
   		cout << "Tujuan\t\t: ";
   		cin >> batas[l].tujuan;
   	lihatData();
}
