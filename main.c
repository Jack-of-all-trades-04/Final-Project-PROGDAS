#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    float ph, kekeruhan, warna; 
    int bau, rasa, endapan, coliform, skor = 0;

    for (int i = 0; i < 51; i++) printf ("-");
    printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
    printf ("|%18sSurvei Mandiri%17s|\n", "", "");
    for (int i = 0; i < 51; i++) printf ("-");

    printf("\nJawablah pertanyaan-pertanyaan berikut\n");
    printf("1. Berapa nilai pH air?: "); 
    scanf("%f", &ph);
    if (ph < 6.5 || ph > 8.5){
		skor += 5;
	} 
    printf("2. Berapa nilai kekeruhan air dalam NTU?: ");
    scanf("%f", &kekeruhan);
    if (kekeruhan > 5) {
		skor += 5;
	}
    printf("3. Berapa skala warna air dalam TCU?: ");
    scanf("%f", &warna);
    if (warna > 50){
		skor += 5;
	}
    printf("4. Berapa skor kebauan air? (0–5): ");
    scanf("%d", &bau);
    if (bau >= 0 && bau <= 5){
		skor += bau;
	}
    printf("5. Berapa rasa tidak sedap air? (0–5): ");
    scanf("%d", &rasa);
    if (rasa >= 0 && rasa <= 5) {
		skor += rasa;
	}
    printf("6. Berapa skor endapan dalam air? (0–5): ");
    scanf("%d", &endapan);
    if (endapan >= 0 && endapan <= 5){
		skor += endapan;
	}
    printf("7. Berapa jumlah bakteri coliform (dalam CFU): ");
    scanf("%d", &coliform);
    if (coliform > 50) {
		skor += 5;
	}

    // Tampilkan hasil dan kembali ke menu startup
    printf("\nHasil Penilaian:\n");
    printf("Skor Kelayakan Air: %d\n", skor);
    startup();
}



void kalkulatorAir() {
	int i, input = 0;
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	printf ("|%18sKalkulator Air%17s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");

        int total_air = 0;
        int minum, mandi, mencuci_piring, mencuci_baju, ibadah, menyiram_tanaman;  

        printf("\nJawablah pertanyaan-pertanyaan berikut\n");
        printf("1. Berapa nilai konsumsi air untuk minum hari ini (dalam liter)?: ");
        scanf("%d", &minum);
        total_air += minum;

    
        printf("2. Berapa nilai konsumsi air untuk mandi hari ini (dalam liter)?: ");
	scanf("%d", &mandi);
        total_air += mandi;

        printf("3. Berapa nilai konsumsi air untuk mencuci piring hari ini (dalam liter)?: ");
        scanf("%d", &mencuci_piring);
        total_air += mencuci_piring;

    
        printf("4. Berapa nilai konsumsi air untuk mencuci baju hari ini (dalam liter)?: ");
	scanf("%d", &mencuci_baju);
        total_air += mencuci_baju;

    
        printf("5. Berapa nilai konsumsi air untuk ibadah (misalnya wudhu) hari ini (dalam liter)?: ");
        scanf("%d", &ibadah);
        total_air += ibadah;

    	printf("6. Berapa nilai konsumsi air untuk menyiram tanaman hari ini (dalam liter)?: ");
    	scanf("%d", &menyiram_tanaman);
   	total_air += menyiram_tanaman;

	
	

	
	
}
