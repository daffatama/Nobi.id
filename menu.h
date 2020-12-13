#include "style.h"

using namespace std;

void header(){
	gline(90);
	tab(5); nout("NOBI.ID V1.0.1");
	gline(90);
	tab(4); nout("Nikamati Box Office Favorit Mu");
	gline(90);
	endln(2);
}

void menu(){
	tab(5); nout("1. Pesan Tiket");
	tab(5); nout("2. Tentang Kami");
	tab(5); nout("3. Riwayat");
	tab(5); nout("4. Keluar");
	endln(1);
}

void mnPayment(){
	tab(4); nout("Pilih metode Pembayaran");
	gline(90);
	endln(1);
	tab(3); nout("1. Tunai");
	tab(3); nout("2. Debit");
	endln(1);
}

void about(){
	tab(3); nout("APA ITU NOBI.ID ?");
	endln(1);
	tab(3); nout("NOBI.ID adalah aplikasi layanan hiburan terdepan");
	tab(3); nout("di Indonesia yang memberikan pengalaman baru");
	tab(3); nout("dalam pembelian tiket film dan hiburan lainnya.");
	tab(3); nout("dengan NOBI.ID, pengguna dapat mengetahui informasi");
	tab(3); nout("tentang film terkini serta melakukan pemesanan");
	tab(3); nout("tiket dengan mudah, cepat, dan aman.");
	endln(1);
	tab(3); nout("Salam hormat dari developer,");
	endln(1);
	tab(7); nout("Daffa Tama Ramadani");
	tab(7); nout("1910631170013 (2-C)");
}