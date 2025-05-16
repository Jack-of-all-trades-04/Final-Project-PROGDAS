#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk pertanyaan survei mandiri
typedef struct{
	char teks[100];
	int bobotRisiko;
	int jawaban;
} pertanyaan;


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
	pertanyaan pertanyaanSurvei[] = { // Daftar pertanyaan
		{"Apakah air terlihat keruh?", 5, 0},
		{"Apakah air berbau tidak sedap?", 4, 0},
		{"Apakah air berasa aneh ketika diminum (misal asin/pahit)?", 3, 0},
		{"Apakah anda menggunakan filter air?", -1, 0},
		{"Apakah anda pernah mengalami gatal/iritasi setelah menggunakan air ini?", 3, 0},
		{"Apakah anda pernah menemu hal tidak wajar dalam air (Misal kotoran atau serangga)?", 2, 0},
	};
	int i, input = 0, skor = 0;
	int n = sizeof(pertanyaanSurvei) / sizeof(pertanyaan); // Menghitung jumlah pertanyaan

	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	printf ("|%18sSurvei Mandiri%17s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");

	// Menampilkan pertanyaan survei
	printf("\nJawab pertanyaan berikut dengan 1 (Ya) atau 0 (Tidak)\n");

    for (int i = 0; i < n; i++) {
        printf("%d. %s ", i + 1, pertanyaanSurvei[i].teks);
        scanf("%d", &pertanyaanSurvei[i].jawaban);
        if (pertanyaanSurvei[i].jawaban == 1) {
            skor += pertanyaanSurvei[i].bobotRisiko;
        }
    }
	// Mendisplay hasil survei
    printf("\nHasil Penilaian:\n");
	printf("Skor Kelayakan Air: %d\n", skor);
    if (skor >= 5){
		printf("Air tidak layak digunakan. \n");
	} else {
		printf("Air layak digunakan.\n");
	}
}


void kalkulatorAir() {
	int i, input = 0;
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	printf ("|%18sKalkulator Air%17s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
}
