#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <limits>

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

struct Tiket {
	int pk;
	string kode;
	string nama;
	string jam;
	string teater;
	string harga;
};

//ProtoType Function
void menuUtama();
void login();
void mainAdmin();
void cekDatabase(fstream &data);
void writeData(fstream &data, int posisi, Tiket &inputTiket);
void addDataTiket(fstream &data);
int getDataSize(fstream &data);
Tiket readData(fstream &data, int posisi);
void displayDataTiket(fstream &data);
void updateRecord(fstream &data);
void deleteRecord(fstream &data);

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
	cout << "Menu Utama" << endl;
	cout << "====================================" << endl;
	cout << "1.Login" << endl;
	cout << "2.Lupa" << endl;
	cout << "3.Help" << endl;
	cout << "4.About" << endl;
	cout << "====================================" << endl;
	cout << "Pilih Menu : ";
	cin >> pilih;


	switch (pilih) {
 		case 1:
 			login();
 		break;

 		case 2:
 			cout << "lupa" << endl;
 		break;

 		case 3:
 		bersih ();
		judul  ();
			cout << "\t\t\t\t   Selamat Datang di pusat bantuan Tickte.hub";
 		break;

 		case 4:
 			cout << "About " << endl;
 		break;

	};
}

//Proses Login
void login() {

	bersih();
	judul();
	string user;
	string pass;
	cout << "Silahkan Login" << endl;
	cout << "====================================" << endl;
	cout << "Username : ";
	cin >> user;
	cout << "====================================" << endl;
	cout << "Password : ";
	cin >> pass;
	cout << "====================================" << endl;

		if (user == "admin" && pass == "*****") {
			bersih();
			judul();
			mainAdmin();
		}else if (user == "kasir" && pass == "*****") {
			bersih();
			judul();
			cout << "Welcome " << user << endl;
		}else {
			bersih();
			judul();
			 cout << "Anda Karyawan? Jika lupa password hubungi Admin!" << endl;
			menuUtama();
		}
}


//Halaman Admin
void mainAdmin() {
	lanjut:
	bersih();
	judul();

	fstream data;
	cekDatabase(data);

	int pAdmin;
	char is_continue;
	cout << "Selamat Datang admin"  << endl;
	cout << "====================================" << endl;
	cout << "1. Tambah Data Ticket" << endl;
	cout << "2. Lihat Data Ticket"  << endl;
	cout << "3. Edit Data Ticket"   << endl;
	cout << "4. Hapus Data Ticket"  << endl;
	cout << "5. Logout"  << endl;
	cout << "====================================" << endl;
	cout << "Pilih Menu : ";
	cin >> pAdmin;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');


	enum option {CREATE = 1, READ, UPDATE, DELETE, FINISH};
	switch (pAdmin) {
		case CREATE:
			cout << "Tambah Data Ticket" << endl;
			cout << "====================================" << endl;
			addDataTiket(data);
			break;
		case READ:
			cout << "Lihat Data Ticket" << endl;
			cout << "====================================" << endl;
			displayDataTiket(data);
			break;
		case UPDATE:
			bersih();
			judul();
			cout << "Edit Data Ticket" << endl;
			cout << "====================================" << endl;
			displayDataTiket(data);
			cout << "====================================" << endl;
			updateRecord(data);
			displayDataTiket(data);
			break;
		case DELETE:
			cout << "Hapus Data Ticket" << endl;
			cout << "====================================" << endl;
			displayDataTiket(data);
			deleteRecord(data);
			displayDataTiket(data);
			break;
		case FINISH:
			bersih();
			judul();
			menuUtama();
			break;

	}
label_continue:

	cout << "Lanjutkan?(Y/N) : ";
	cin >> is_continue;

	if (is_continue == 'y' || is_continue == 'Y') {
		goto lanjut;
	}else if (is_continue == 'n' || is_continue == 'N') {
		bersih();
		judul();
		cout << "Anda telah logout!" << endl;
		menuUtama();
	}else {
		goto label_continue;
	}

}

//Cek Database
void cekDatabase(fstream &data) {
	data.open("data.bin", ios::out | ios::in | ios::binary);
	//chech database ada atau tidak
	if (data.is_open()) {
		cout << "database di temukan " << endl;
	}else {
		cout << "database tidak di temukan. Sudah di buatkan database baru" << endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

//Write Data
void writeData(fstream &data, int posisi, Tiket &inputTiket){
	data.seekp((posisi - 1)*sizeof(Tiket), ios::beg);
	data.write(reinterpret_cast<char*>(&inputTiket),sizeof(Tiket));
}

//Mengambil Ukuran Data
int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0,ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Tiket);
}

//Membaca Data Didatabase
Tiket readData(fstream &data, int posisi) {
	Tiket readTiket;
	data.seekg((posisi - 1)*sizeof(Tiket),ios::beg);
	data.read(reinterpret_cast<char*>(&readTiket),sizeof(Tiket));

	return readTiket;
}

//tambah data tiket
void addDataTiket(fstream &data){
	
	Tiket inputTiket, lastTiket;

	int size = getDataSize(data);
	cout << "Data Didatabase : " << size << endl;

	if (size == 0) {
		inputTiket.pk = 1;
	}else {
		lastTiket = readData(data,size);
		inputTiket.pk = lastTiket.pk + 1;
		cout << "pk = " << inputTiket.pk << endl;
	}


	cout << "Kode Tiket 	: ";
	getline(cin, inputTiket.kode);
	cout << "Nama Film 	: ";
	getline(cin, inputTiket.nama);
	cout << "Jam Tayang 	: ";
	getline(cin, inputTiket.jam);
	cout << "Theater 	: ";
	getline(cin, inputTiket.teater);
	cout << "Harga Tiket 	: ";
	getline(cin, inputTiket.harga);

	writeData(data,size+1,inputTiket);
}

//Tampilkan Data
void displayDataTiket(fstream &data) {
	int size = getDataSize(data);
	Tiket showTiket;
	cout << "No.  \tKode Tiket.  \tNama Film.  \t\tJam Tayang.  \tTheater.  \tHarga Tiket." << endl;
		for (int i = 1; i <= size; i++) {
			showTiket = readData(data,i);
			cout << i << "\t";
			cout << showTiket.kode << "\t\t";
			cout << showTiket.nama << "\t\t";
			cout << showTiket.jam << "\t\t";
			cout << showTiket.teater << "\t\t";
			cout << showTiket.harga << endl;		
		}
}

//Mengupdate Data
void updateRecord(fstream &data) {
	int nomor;
	Tiket updateTiket;

	cout << "Pilih data yang ingin di rubah (berdasarkan Nomor) : ";
	cin >> nomor;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "====================================" << endl;

	updateTiket = readData(data,nomor);

	cout << "Data yang di pilih : " << endl;
	cout << "Kode Tiket 	: " << updateTiket.kode << endl;
	cout << "Nama Film 	: " << updateTiket.nama << endl;
	cout << "Jam Tayang 	: " << updateTiket.jam << endl;
	cout << "Theater 	: " << updateTiket.teater << endl;
	cout << "Harga Tiket 	: " << updateTiket.harga << endl;
	cout << "====================================" << endl;

	cout << "Merubah data tiket" << endl;
	cout << "====================================" << endl;

	cout << "Kode Tiket 	: ";
	getline(cin,updateTiket.kode);
	cout << "Nama Film 	: ";
	getline(cin,updateTiket.nama);
	cout << "Jam Tayang 	: ";
	getline(cin,updateTiket.jam);
	cout << "Theater 	: ";
	getline(cin,updateTiket.teater);
	cout << "Harga Tiket 	: ";
	getline(cin,updateTiket.harga);

	writeData(data,nomor,updateTiket);

}

//Menghapus Data
void deleteRecord(fstream &data) {
	int nomor,size,offset;
	Tiket blankTiket, tempTiket;

	fstream dataSementara;

	size = getDataSize(data);

	cout << "Pilih data yang akan dihapus(berdasarkan nomor) : ";
	cin >> nomor;

	writeData(data,nomor,blankTiket);

	dataSementara.open("temp.dat", ios::trunc | ios::out | ios::in | ios::binary);

	offset = 0;
	for (int i = 1; i <= size; i++) {
		tempTiket = readData(data,i);
			if (!tempTiket.kode.empty()) {
				writeData(dataSementara,i - offset,tempTiket);
			}else {
				offset++;
				cout << "Deleted Tiket" << endl;
			}

	}

	size = getDataSize(dataSementara);
	data.close();
	data.open("data.bin", ios::trunc | ios::out | ios::binary);
	data.close();
	data.open("data.bin", ios::out | ios::in | ios::binary);

	for (int i = 1; i <= size; i++) {
		tempTiket = readData(dataSementara,i);
		writeData(data,i,tempTiket);
	}
}

