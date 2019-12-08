#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

void judul() {
	cout << "\t\t\t\t          ##############################" << endl;
	cout << "\t\t\t\t          #                            #" << endl;
	cout << "\t\t\t\t          #          Ticket.hub        #" << endl;
	cout << "\t\t\t\t          #             V2.4           #" << endl;
	cout << "\t\t\t\t          ##############################" << endl;
}

void bersih() {
	system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ProtoType Function
void menuUtama();
void login();
void lupa();
void help();
void about();
void mainAdmin();

//Main Program
main () {

	judul();
	menuUtama();

	getch();
}

/////////////////////////
//	Inti Program		/
//	Function			/
//						/
/////////////////////////

//Tampilkan Menu
void menuUtama() {
	int pilih;
	cout << "\tMenu Utama" << endl;
	cout << "\t====================================" << endl;
	cout << "\t1.Login" << endl;
	cout << "\t2.Lupa" << endl;
	cout << "\t3.Help" << endl;
	cout << "\t4.About" << endl;
	cout << "\t====================================" << endl;
	cout << "\tPilih Menu : ";
	cin >> pilih;


	switch (pilih) {
 		case 1:
 			login();
 		break;

 		case 2:
 			lupa();
 		break;

 		case 3:
 			help();
 		break;

 		case 4:
 			about();
 		break;

	};
}

//Proses Login
void login() {

	bersih();
	judul();
	string user;
	string pass;
	cout << "\tSilahkan Login" << endl;
	cout << "\t====================================" << endl;
	cout << "\tUsername : ";
	cin >> user;
	cout << "\t====================================" << endl;
	cout << "\tPassword : ";
	cin >> pass;
	cout << "\t====================================" << endl;

		if (user == "admin" && pass == "admin123") {
			bersih();
			judul();
			mainAdmin();
		}else if (user == "kasir" && pass == "kasir123") {
			bersih();
			judul();
			cout << "\tWelcome " << user << endl;
		}else {
			cout << "\tAnda Karyawan? Jika lupa password hubungi Admin!";
		}
}

//Jika User memilih Lupa
void lupa() {

}

//Jika User memilih Help
void help() {
	bersih ();
	judul  ();

	cout << "\t\t\t\t   Selamat Datang di pusat bantuan Tickte.hub";

}

//Jika User memilih About
void about() {

}

void mainAdmin() {
	bersih();
	judul();

	int pAdmin;
	cout << "\tSelamat Datang admin"  << endl;
	cout << "\t====================================" << endl;
	cout << "\t1. Tambah Data Ticket" << endl;
	cout << "\t2. Lihat Data Ticket"  << endl;
	cout << "\t3. Edit Data Ticket"   << endl;
	cout << "\t4. Hapus Data Ticket"  << endl;
	cout << "\t5. Logout"  << endl;
	cout << "\t====================================" << endl;
	cout << "\tPilih Menu : ";
	cin >> pAdmin;

	enum option {CREATE = 1, READ, UPDATE, DELETE, FINISH};
	switch (pAdmin) {
		case CREATE:
			cout << "\tTambah Data Ticket : ";
			break;
		case READ:
			cout << "\tLihat Data Ticket : ";
			break;
		case UPDATE:
			cout << "\tEdit Data Ticket : ";
			break;
		case DELETE:
			cout << "\tHapus Data Ticket : ";
			break;
		case FINISH:
			bersih();
			judul();
			menuUtama();
			break;

	}
}