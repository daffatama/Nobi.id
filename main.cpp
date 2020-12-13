/*
NPM		: 1910631170013
Nama 	: DAFFA TAMA RAMADANI
Kelas	: 2C
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include <sstream>
#include <string.h>
#include <ctype.h>

//memanggil file menu.h
#include "menu.h"

using namespace std;

//var global
string kodeStruk, tglStruk, msg, pilihan, kursi, jamTayang;
int id, idRiw, harga, cWaktu, idOrder, jamNow, jamMulai, jamHabis, bayar, kembali;

//var waktu
int day, tgl, bln, thn, jam, mnt, dtk;

//var simpan order sementara
string order_kodeOrder, order_kodeFilm, order_tglOrder, order_kursi;
int order_harga;

//prototype prosedure dan fungsi
void payment(int, string);
void timeNow();
void switchHarga();
void makeStruk();
void addRiw();
void saveOrder(string, string, string, string, int);
void msgAlert(string);
void msgSuccess(string);
void convertJam(int, int);

//data waktu awal tayang
struct wktAwal
{
	int jam;
	int menit;
};

//data waktu akhir tayang
struct wktAkhir
{
	int jam;
	int menit;
};

//data film
struct film
	{
		string kodeFilm;
		string judulFilm;
		int tahunTerbit;
		string genre;
		string sutradara;
		wktAwal wktMulai;
		wktAkhir wktHabis;
		string rate;
		string bahasa;
		int teater;
	};

	//mengisi data film
	film newFilm[]={
		{"MV001", "JOKER", 2019, "Crime", "Todd Phillips", 17, 10, 19, 43, "D18+", "Inggris", 1},
		{"MV002", "PARASITE", 2019, "Crime", "Boong Joon Ho", 12, 20, 14, 30, "D18+", "Korea", 2},
		{"MV003", "Interstellar", 2014, "Sci-fi", "Chirtopher Nolan", 15, 20, 17, 3, "R13+", "Inggris", 3},
		{"MV004", "Avengers: Endgame", 2019, "Action", "Anthony Russo", 19, 0, 22, 5, "R13+", "Inggris", 2},
		{"MV005", "Star Wars: IX", 2019, "Fantasy", "J.J. Abrams", 13, 30, 15, 35, "R13+", "Inggris", 1},
		{"MV006", "Your Name", 2016, "Animation", "Makoto Shinkai", 19, 15, 21, 30, "SU", "Jepang", 3}
	};

//inisialisasi jumlah data film
int newFilm_size = sizeof(newFilm)/sizeof(*newFilm);

//data order
struct order
	{
		string kodeOrder;
		string kodeFilm;
		string tglOrder;
		string kursi;
		int harga;
	};

	order newOrder[100];

//inisialisasi jumlah data order
int newOrder_size = sizeof(newOrder)/sizeof(*newOrder);

//prosedur cetak kode struk
void makeStruk(){
	string newThn, newTgl, newBln, newId;
	idOrder = idRiw;
	timeNow();

	//konversi data thn dari int ke string
	stringstream a;
	a<<thn;
	newThn = a.str();

	//konversi data bln dari int ke string
	stringstream b;
	b<<bln;
	newBln = b.str();

	//konversi data tgl dari int ke string
	stringstream c;
	c<<tgl;
	newTgl = c.str();

	//konversi data idOrder dari int ke string
	stringstream d;
	d<<idOrder;
	newId = d.str();

	kodeStruk = "NOBI"+newThn+newBln+newTgl+newId;
	tglStruk = newTgl+"-"+newBln+"-"+newThn;
}

//tambah data order
void addRiw(){
	idRiw += 1;
}

//prosedur simpan data order
void saveOrder(string a, string b, string c, string d, int e){
	newOrder[idRiw].kodeOrder = a;
	newOrder[idRiw].kodeFilm = b;
	newOrder[idRiw].tglOrder = c;
	newOrder[idRiw].kursi = d;
	newOrder[idRiw].harga = e;

	addRiw();
}

//prosedur hapus
void clear(){
	system("cls");
	header();
}

//prosedur menentukan harga berdasarkan hari
void switchHarga(){
	timeNow();

	if(day == 6 || day == 7){
		//harga sabtu-minggu
		harga = 70000;
	}else{
		//harga hari biasa
		harga = 50000;
	}
}

//warna teks merah
void msgAlert(string a){
	string color = "\033[1;31m";
	string normal = "\033[0m";
	msg = color+a+normal;
}

//warna teks hijau
void msgSuccess(string a){
	string color = "\033[1;32m";
	string normal = "\033[0m";
	msg = color+a+normal;
}

//prosedure get local time
void timeNow(){
	time_t now = time(0);
	struct tm *ltm = localtime(&now);

	thn = 1900+ltm -> tm_year;
	bln = 1+ltm -> tm_mon;
	tgl = ltm -> tm_mday;
	jam = ltm -> tm_hour;
	mnt = ltm -> tm_min;
	dtk = ltm -> tm_sec;
	day = ltm -> tm_wday;
}

//konversi jam kebentuk bilangan agar mudah dilakukan operasi(contoh: 11:20 menjadi 1120)
void convertJam(int j, int m){
	if(m == 0 || m == 1 || m == 2 || m == 3 || m == 4 || m == 5 || m == 6 || m == 7 || m == 8 || m == 9){
		stringstream a;
		a<<m;
		string strMenit = "0"+a.str();

		stringstream b;
		b<<j;
		string strJam = b.str();

		string jam = strJam+strMenit;

		stringstream ss(jam);
		ss>>cWaktu;
	}else{
		stringstream a;
		a<<m;
		string strMenit = a.str();

		stringstream b;
		b<<j;
		string strJam = b.str();

		string jam = strJam+strMenit;

		stringstream ss(jam);
		ss>>cWaktu;
	}
}

main(){
	//halaman menu
	showMenu:
	clear();

	menu();
	tab(4); out("Pilih Menu : "); 
	pilihan = getche();
	endln(1);

	if(pilihan == "1"){
		goto showFilm;
	}else if(pilihan == "2"){
		goto showAbout;
	}else if(pilihan == "3"){
		goto riwayat;
	}else if(pilihan == "4"){
		goto keluar;
	}else{
		endln(1);
		msgAlert("Pilihan tidak tersedia. Tekan apa saja untuk lanjut");
		tab(3); out(msg); 
		getch();
		goto showMenu;
	}

	//halaman riwayat
	riwayat:
	clear();

	tab(5); nout("Riwayat Transaksi");
	gline(90);
	cout<<setiosflags(ios::left)<<setw(5)<<"No";
	cout<<setiosflags(ios::left)<<setw(20)<<"Kode Order";
	cout<<setiosflags(ios::left)<<setw(25)<<"Kode Film";
	cout<<setiosflags(ios::left)<<setw(15)<<"Tanggal";
	cout<<setiosflags(ios::left)<<setw(10)<<"Kursi";
	cout<<setiosflags(ios::left)<<setw(15)<<"Harga"<<endl;
	gline(90);

	for(int i = 0; i<newOrder_size; i++){
		if(newOrder[i].kodeOrder != ""){
			cout<<setiosflags(ios::left)<<setw(5)<<i+1;
			cout<<setiosflags(ios::left)<<setw(20)<<newOrder[i].kodeOrder;
			cout<<setiosflags(ios::left)<<setw(25)<<newOrder[i].kodeFilm;
			cout<<setiosflags(ios::left)<<setw(15)<<newOrder[i].tglOrder;
			cout<<setiosflags(ios::left)<<setw(10)<<newOrder[i].kursi;
			cout<<setiosflags(ios::left)<<setw(15)<<newOrder[i].harga<<endl;
		}
	}

	endln(2);
	out("Tekan apa saja untuk kembali"); 
	pilihan = getche();
	goto showMenu;

	//halaman keluar
	keluar:
	endln(1);
	tab(4); out("Anda yakin ingin keluar[y/n] ? ");
	pilihan = getche();

	if(pilihan == "y" || pilihan == "Y"){
		endln(1);
		gline(90);
		msgAlert("PROGRAM BERAKHIR"); 
		tab(5); nout(msg);
		gline(90);
		exit(0);
	}else{
		goto showMenu;
	}

	//halaman about
	showAbout:
	clear();

	about();
	endln(2);
	tab(3); out("Tekan apa saja untuk kembali"); 
	pilihan = getche();
	goto showMenu;

	//halaman daftar film
	showFilm:
	clear();

	//membuat header tabel data film
	tab(5); nout("Daftar Film");
	gline(90);
	cout<<setiosflags(ios::left)<<setw(5)<<"No";
	cout<<setiosflags(ios::left)<<setw(25)<<"Judul Film";
	cout<<setiosflags(ios::left)<<setw(25)<<"Jam Tayang";
	cout<<setiosflags(ios::left)<<setw(10)<<"Rate";
	cout<<setiosflags(ios::left)<<setw(10)<<"Teater";
	cout<<setiosflags(ios::left)<<setw(30)<<"Status"<<endl;
	gline(90);

	for(int i=0; i<newFilm_size; i++){
		//mengubah tipe data waktu tayang menjadi string
		stringstream ss;
		ss<<newFilm[i].wktMulai.jam<<"."<<newFilm[i].wktMulai.menit<<" - "<<newFilm[i].wktHabis.jam<<"."<<newFilm[i].wktHabis.menit;
		jamTayang = ss.str();

		//membuat isi tabel daftar film
		cout<<setiosflags(ios::left)<<setw(5)<<i+1;
		cout<<setiosflags(ios::left)<<setw(25)<<newFilm[i].judulFilm;
		cout<<setiosflags(ios::left)<<setw(25)<<jamTayang;
		cout<<setiosflags(ios::left)<<setw(10)<<newFilm[i].rate;
		cout<<setiosflags(ios::left)<<setw(10)<<newFilm[i].teater;

		//get local time dan mengkonversinya menjadi bilangan
		timeNow();
		convertJam(jam,mnt);
		jamNow = cWaktu;
		convertJam(newFilm[i].wktMulai.jam, newFilm[i].wktMulai.menit);
		jamMulai = cWaktu;
		convertJam(newFilm[i].wktHabis.jam, newFilm[i].wktHabis.menit);
		jamHabis = cWaktu;

		/*
			membagi tayangan dalam 3 kondisi waktu
			1. sedang tayang(on screen)
			2. akan tayang(coming soon)
			3. selesai tayang(out of time)
			berdasarkan jam tayang film
		*/
		if((jamNow>= jamMulai) && (jamNow <= jamHabis)){
			msgSuccess("On Screen");
			cout<<setiosflags(ios::left)<<setw(30)<<msg;
		}else if(jamNow <= jamMulai){
			cout<<setiosflags(ios::left)<<setw(30)<<"Coming Soon";
		}else if(jamNow >= jamHabis){
			msgAlert("Out Of Time");
			cout<<setiosflags(ios::left)<<setw(30)<<msg;
		}
		endln(1);
	}

	gline(90);
	timeNow();
	switchHarga();

	//menampilkan harga harian
	if(day == 1){
		cout<<"Harga tiket hari Senin : "<<harga<<endl;
	}else if(day == 2){
		cout<<"Harga tiket hari Selasa : "<<harga<<endl;
	}else if(day == 3){
		cout<<"Harga tiket hari Rabu : "<<harga<<endl;
	}else if(day == 4){
		cout<<"Harga tiket hari Kamis : "<<harga<<endl;
	}else if(day == 5){
		cout<<"Harga tiket hari Jumat : "<<harga<<endl;
	}else if(day == 6){
		cout<<"Harga tiket hari Sabtu : "<<harga<<endl;
	}else{
		cout<<"Harga tiket hari Minggu : "<<harga<<endl;
	}
	
	gline(90);	
	endln(1);
	nout("Tekan 'ESC' untuk kembali");
	endln(1);
	out("Pilih Film : "); 
	pilihan = getche();

	//mengubah tipe data pilihan menjadi integer dan menyimpanan nya pada variabel id
	stringstream ss(pilihan);
	ss>>id;
	id = id-1;

	if(pilihan=="\e"){
		goto showMenu;
	}else if(id>=0 && id<newFilm_size){
		goto showDetailFilm;
	}else{
		endln(1);
		msgAlert("Pilihan tidak tersedia. Tekan apa saja untuk lanjut");
		out(msg); 
		getch();
		goto showFilm;
	}

	//halaman detail film
	showDetailFilm:
	clear();

	//menampilkan data detail dari film yang dipilih
	tab(5); nout("Detail Film");
	gline(90);
	tab(4); cout<<""<<newFilm[id].judulFilm<<"("<<newFilm[id].tahunTerbit<<")";
	endln(2);
	tab(4); cout<<"Judul \t\t: "<<newFilm[id].judulFilm<<endl;
	tab(4); cout<<"Tahun Rilis \t: "<<newFilm[id].tahunTerbit<<endl;
	tab(4); cout<<"Genre \t\t: "<<newFilm[id].genre<<endl;
	tab(4); cout<<"Sutradara \t: "<<newFilm[id].sutradara<<endl;
	tab(4); cout<<"Rate \t\t: "<<newFilm[id].rate<<endl;
	tab(4); cout<<"Bahasa \t\t: "<<newFilm[id].bahasa<<endl;
	
	//get local time dan mengkonversinya menjadi bilangan
	timeNow();
	convertJam(jam,mnt);
	jamNow = cWaktu;
	convertJam(newFilm[id].wktMulai.jam, newFilm[id].wktMulai.menit);
	jamMulai = cWaktu;
	convertJam(newFilm[id].wktHabis.jam, newFilm[id].wktHabis.menit);
	jamHabis = cWaktu;

	if((jamNow>= jamMulai) && (jamNow <= jamHabis)){
		msgSuccess("On Screen");
		tab(4); cout<<"Status \t\t: "<<msg<<endl;
		endln(2);
		tab(4); out("Pesan Tiket[y/n] ? "); 
		pilihan = getch();

		if(pilihan=="y"||pilihan=="Y"){
			goto showKursi;
		}else if(pilihan=="n"||pilihan=="N"){
			goto showFilm;
		}else{
			goto showDetailFilm;
		}
	}else if(jamNow <= jamMulai){
		tab(4); cout<<"Status \t\t: Coming Soon"<<endl;
		endln(2);
		tab(4); out("Preorder[y/n] ? "); 
		pilihan = getch();

		if(pilihan=="y"||pilihan=="Y"){
			goto showKursi;
		}else if(pilihan=="n"||pilihan=="N"){
			goto showFilm;
		}else{
			goto showDetailFilm;
		}
	}else if(jamNow >= jamHabis){
		msgAlert("Out Of Time");
		tab(4); cout<<"Status \t\t: "<<msg<<endl;
		endln(1);
		msgAlert("Tidak bisa memesan tiket untuk film ini");
		tab(4); nout(msg);
		tab(4); out("Tekan apa saja untuk kembali"); 
		getch();
		goto showFilm;
	}

	//halaman booking/pilih kursi
	showKursi:
	string row, seat, full;
	clear();

	tab(5); nout("Pilih Kursi");
	gline(90);
	tab(3); cout<<""<<newFilm[id].judulFilm<<"("<<newFilm[id].tahunTerbit<<")"<<"\t\t Teater "<<newFilm[id].teater;
	endln(2);
	tab(3);

	//menampilkan kursi row A dengan seat 1-9
	for(int a=1; a<=9; a++){
		stringstream sa;
		sa<<a;
		string newA = "A"+sa.str();

		for(int x=0; x<newOrder_size; x++){

			if(newA == newOrder[x].kursi && newFilm[id].kodeFilm == newOrder[x].kodeFilm){
				full = "["+newA+"] ";
			}
		}
		if(full == "["+newA+"] "){
			msgAlert("["+newA+"] ");
			cout<<msg;
		}else{
			cout<<"[A"<<a<<"] ";
		}		
	}

	endln(1);
	tab(3);

	//menampilkan kursi row B dengan seat 1-9
	for(int b=1; b<=9; b++){
		stringstream sb;
		sb<<b;
		string newB = "B"+sb.str();

		for(int x=0; x<newOrder_size; x++){
			if(newB == newOrder[x].kursi && newFilm[id].kodeFilm == newOrder[x].kodeFilm){
				full = "["+newB+"] ";
			}
		}
		if(full == "["+newB+"] "){
			msgAlert("["+newB+"] ");
			cout<<msg;
		}else{
			cout<<"[B"<<b<<"] ";
		}	
	}

	endln(1);
	tab(3);

	//menampilkan kursi row C dengan seat 1-9
	for(int c=1; c<=9; c++){
		stringstream sc;
		sc<<c;
		string newC = "C"+sc.str();

		for(int x=0; x<newOrder_size; x++){

			if(newC == newOrder[x].kursi && newFilm[id].kodeFilm == newOrder[x].kodeFilm){
				full = "["+newC+"] ";
			}
		}
		//out(msg);
		if(full == "["+newC+"] "){
			msgAlert("["+newC+"] ");
			cout<<msg;
		}else{
			cout<<"[C"<<c<<"] ";
		}	
	}

	endln(1);
	tab(3);

	//menampilkan kursi row D dengan seat 1-9
	for(int d=1; d<=9; d++){
		stringstream sd;
		sd<<d;
		string newD = "D"+sd.str();

		for(int x=0; x<newOrder_size; x++){

			if(newD == newOrder[x].kursi && newFilm[id].kodeFilm == newOrder[x].kodeFilm){
				full = "["+newD+"] ";
			}
		}
		if(full == "["+newD+"] "){
			msgAlert("["+newD+"] ");
			cout<<msg;
		}else{
			cout<<"[D"<<d<<"] ";
		}	
	}

	endln(2);
	msgAlert("*Kursi dengan warna merah berarti sudah terisi");
	tab(2); cout<<msg<<endl;
	endln(1);
	tab(2); cout<<"Tekan 'ESC' untuk kembali"<<endl;
	endln(1);
	tab(2); out("Pilih kode kursi[A-D] : "); 
	row = getch();

	//validasi kursi terisi
	if(row=="\e"){
		goto showFilm;
	}else if(row=="A" || row=="B" || row=="C" || row=="D" || row=="a" || row=="b" || row=="c" || row=="d"){
		char s[row.length()];
		
		for(int i=0; i<sizeof(s); i++){
			s[i] = row[i];
			row=toupper(s[i]);
		}

		out(row);
		tab(1); out("Pilih nomer kursi[1-9] : "); 
		seat = getche();

		if(seat=="\e"){
			goto showKursi;
		}else if(seat=="1" || seat=="2" || seat=="3" || seat=="4" || seat=="5" || seat=="6" || seat=="7" || seat=="8" || seat=="9"){
			kursi = row+seat;

			for(int m=0; m<newOrder_size; m++){
				if(kursi == newOrder[m].kursi && newFilm[id].kodeFilm == newOrder[m].kodeFilm){
					full = kursi;
				}
			}

			if(kursi == full){
				endln(1);
				msgAlert("Kursi "+kursi+" tidak tersedia. Tekan apa saja untuk lanjut");
				tab(2); out(msg); 
				getch();
				goto showKursi;
			}else{
				goto konfirmPay;
			}
		}else{
			endln(1);
			msgAlert("Kursi tidak tersedia. Tekan apa saja untuk lanjut");
			tab(2); out(msg);
			getch();
			goto showKursi;
		}
	}else{
		endln(1);
		msgAlert("Kursi tidak tersedia. Tekan apa saja untuk lanjut");
		tab(2); out(msg);
		getch();
		goto showKursi;
	}

	//halaman konfirmasi pembayaran
	konfirmPay:
	clear();

	switchHarga();
	makeStruk();

	tab(5); nout("Konfirmasi");
	tab(3); gline(45);
	tab(4); nout("Anda akan memesan tiket, ");
	endln(1);
	tab(3); cout<<newFilm[id].judulFilm;
	endln(2);
	tab(3); cout<<"Date = "<<tglStruk<<endl;
	tab(3); cout<<"Time = "<<newFilm[id].wktMulai.jam<<":"<<newFilm[id].wktMulai.menit<<endl;
	tab(3); cout<<"Row/Seat = "<<kursi<<endl;
	tab(3); cout<<"Price = \033[1;31m"<<harga<<"\033[0m"<<endl;
	endln(1);
	tab(3); gline(45);
	tab(3); cout<<"Lanjut untuk memilih metode pembayaran[y/n]? "; 
	pilihan = getch();

	if(pilihan == "Y" || pilihan == "y"){
		goto showPayment;
	}else if(pilihan == "N" || pilihan == "n"){
		goto showKursi;
	}else{
		goto konfirmPay;
	}

	//halaman menu pembayaran
	showPayment:
	clear();

	mnPayment();
	tab(3); nout("Tekan 'ESC' untuk membatalkan transaksi");
	endln(1);
	tab(3); out("Pilih metode pembayaran : ");
	pilihan = getch();

	if(pilihan == "1"){
		goto tunai;
	}else if(pilihan == "2"){
		goto debit;
	}else if(pilihan == "\e"){
		goto cancelTagihan;
	}else{
		endln(1);
		msgAlert("Metode pembayaran tidak tersedia. Tekan apa saja untuk lanjut");
		tab(2); out(msg);
		getch();
		goto showPayment;
	}

	//halaman pembayaran tunai
	tunai:
	clear();

	switchHarga();
	makeStruk();

	tab(5); nout("Pembayaran Tunai");
	tab(3); gline(45);
	tab(3); cout<<newFilm[id].judulFilm;
	endln(2);
	tab(3); cout<<"Date = "<<tglStruk<<endl;
	tab(3); cout<<"Time = "<<newFilm[id].wktMulai.jam<<":"<<newFilm[id].wktMulai.menit<<endl;
	tab(3); cout<<"Row/Seat = "<<kursi<<endl;
	tab(3); cout<<"Price = \033[1;31m"<<harga<<"\033[0m"<<endl;
	endln(1);
	tab(3); gline(45);
	tab(3); out("Masukan nominal yang dibayarkan : ");
	cin>>bayar;

	//validasi uang yang dibayarkan
	if(bayar<harga){
		endln(1);
		msgAlert("Nominal yang dimasukan kurang");
		tab(3); nout(msg);
		msgAlert("Tekan apa saja untuk lanjut");
		tab(3); out(msg);
		getch();
		goto tunai;
	}else{
		kembali = bayar-harga;
		tab(3); cout<<"Kembali : "<<kembali;
		endln(1);
		goto success;
	}

	//halaman pembayaran debit
	debit:
	clear();

	switchHarga();
	makeStruk();

	tab(5); nout("Pembayaran Debit");
	tab(3); gline(45);
	tab(3); cout<<newFilm[id].judulFilm;
	endln(2);
	tab(3); cout<<"Date = "<<tglStruk<<endl;
	tab(3); cout<<"Time = "<<newFilm[id].wktMulai.jam<<":"<<newFilm[id].wktMulai.menit<<endl;
	tab(3); cout<<"Row/Seat = "<<kursi<<endl;
	tab(3); cout<<"Price = \033[1;31m"<<harga<<"\033[0m"<<endl;
	endln(1);
	tab(3); gline(45);
	tab(3); out("Masukan nominal yang dibayarkan : ");
	cin>>bayar;

	//validasi uang yang dibayarkan
	if(bayar<harga){
		endln(1);
		msgAlert("Nominal yang dimasukan kurang");
		tab(3); nout(msg);
		msgAlert("Tekan apa saja untuk lanjut");
		tab(3); out(msg);
		getch();
		goto debit;
	}else if(bayar>harga){
		endln(1);
		msgAlert("Nominal yang dimasukan berlebih");
		tab(3); nout(msg);
		msgAlert("Tekan apa saja untuk lanjut");
		tab(3); out(msg);
		getch();
		goto debit;
	}else{
		tab(3); cout<<"Gesek kartu untuk menyelesaikan transaksi..";
		Sleep(5000);
		endln(1);
		goto success;
	}

	//halaman order sukses
	success:
	makeStruk();
	timeNow();

	//mengisi data order sementara
	order_kodeOrder = kodeStruk;
	order_kodeFilm = newFilm[id].kodeFilm;
	order_tglOrder = tglStruk;
	order_kursi = kursi;
	order_harga = harga;

	//menyimpan data order sebagai riwayat
	saveOrder(order_kodeOrder, order_kodeFilm, order_tglOrder, order_kursi, order_harga);

	endln(1);
	msgSuccess("Pembelian tiket berhasil. Tekan apa saja untuk cetak tiket");
	tab(2); out(msg);
	getch();
	goto cetakTiket;

	//halaman pembatalan transaksi
	cancelTagihan:
	clear();

	cout<<"\033[1;31mAnda akan membatalkan pesanan kursi "<<kursi<<" teater "<<newFilm[id].teater<<" untuk film "<<newFilm[id].judulFilm<<"[y/n] ? \033[0m";
	pilihan = getche();

	if(pilihan == "Y" || pilihan == "y"){
		endln(2);
		tab(1); cout<<"\033[1;31mPesanan dibatalkan. Tekan apa saja untuk kembali ke main menu\033[0m";
		getch();
		goto showMenu;
	}else if(pilihan == "N" || pilihan == "n"){
		goto showPayment;
	}else{
		goto cancelTagihan;
	}

	//halaman cetak tiket
	cetakTiket:
	clear();

	tab(5); nout("TIKET NOBI.ID");
	tab(4); gline(30);
	tab(4); cout<<newFilm[id].judulFilm;
	endln(2);
	tab(4); cout<<"Date = "<<tglStruk<<endl;
	tab(4); cout<<"Time = "<<newFilm[id].wktMulai.jam<<":"<<newFilm[id].wktMulai.menit<<endl;
	tab(4); cout<<"Row/Seat = "<<kursi<<endl;
	tab(4); cout<<"Price = "<<harga<<endl;
	endln(1);
	tab(4); gline(30);
	tab(4); cout<<kodeStruk;
	endln(3);
	tab(3); out("Tekan apa saja untuk kembali ke menu utama");
	getch();
	goto showMenu;
}