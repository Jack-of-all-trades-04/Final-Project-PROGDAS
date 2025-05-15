#include <stdio.h>
#include <stdlib.h>

void membuatBox(char teks);
void startup();
void surveiMandiri();
void kalkulatorAir();

int main() {
	startup();
	return 0;
}

void startup() {
	int i, input = 0;
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|Silahkan pilih opsi yang tersedia :%14s|", "");
	printf ("\n|1. Survei Mandiri Kelayakan Air%18s|", "");
	printf ("\n|2. Kalkulator Penggunaan Air%21s|\n", "");
	for (i = 0; i < 51; i++) printf ("-");
	while (input < 1 || input > 2) {
		printf ("\nOpsi Yang Anda Pilih : ");
		scanf ("%d", &input);
		if (input < 1 || input > 2) {
			puts ("Opsi tidak valid, masukkan ulang.");
		}
	}
	switch (input) {
		case 1 :
			surveiMandiri();
			break;
		case 2 :
			kalkulatorAir();
			break;
	}
}

void surveiMandiri() {
	int i, input = 0;
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	printf ("|%18sSurvei Mandiri%17s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
}

void kalkulatorAir() {
	int i, input = 0;
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	printf ("|%18sKalkulator Air%17s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
}
