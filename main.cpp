#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

//deklarasi function
void judul() {
	cout << "\t\t\t\t          ##############################" << endl;
	cout << "\t\t\t\t          #                            #" << endl;
	cout << "\t\t\t\t          #          Ticket.hub        #" << endl;
	cout << "\t\t\t\t          #                            #" << endl;
	cout << "\t\t\t\t          ##############################" << endl;
}
void login();
void daftar();
void lupa();
void help();
void about();

main () {
	judul();

	int pilih;
	cout << "\t1.Login" << endl;
	cout << "\t2.Daftar" << endl;
	cout << "\t3.Lupa" << endl;
	cout << "\t4.Help" << endl;
	cout << "\t5.About" << endl;
	cout << "\tPilih Menu : ";
	cin >> pilih;

	switch (pilih) {
 		case 1:
 			login();
 		break;

 		case 2:
 			daftar();
 		break;

 		case 3:
 			lupa();
 		break;

 		case 4:
 			help();
 		break;

 		case 5:
 			about();
 		break;
	};

getch();
}

void login() {
	string user;
	string pass;

	cout << "\tUsername : ";
	cin >> user;
	cout << "\tPassword : ";
	cin >> pass;

		if (user == "admin" && pass == "admin123") {
			system("cls");
			judul();
			cout << "\tWelcome " << user << endl;
		}else if (user == "user" && pass == "user123") {
			system("cls");
			judul();
			cout << "\tWelcome " << user << endl;
		}else {
			cout << "Anda belum terdaftar!";
		}
}

void daftar() {

}

void lupa() {

}

void help() {

}

void about() {

}