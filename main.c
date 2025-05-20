#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void membuatBox(char teks);
void startup();
void surveiMandiri();
void kalkulatorAir();
void skalaASCII(char keyword[]);

typedef enum {
	KURANG, IDEAL, BOROS
}penggunaanAir;

typedef struct {
	float pH, TCU, TDS, eColi;
	int bau, rasa, endapan, diare;
	union {
		float decimal;
		int integer;
	}kekeruhan;
	union {
		float decimal;
		int integer;
	}warnaAir;
	
}dataAir;

typedef enum {
	TIDAKAKURAT, CUKUPAKURAT, AKURAT
}sistemPenilaian;

int main() {
	startup();
	return 0;
}

void startup() {
	int i, input = 0;
	char temp[20];
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|Silahkan pilih opsi yang tersedia :%14s|", "");
	printf ("\n|1. Survei Mandiri Kelayakan Air%18s|", "");
	printf ("\n|2. Kalkulator Penggunaan Air%21s|\n", "");
	for (i = 0; i < 51; i++) printf ("-");
	
	while (input < 1 || input > 2) {
		printf ("\nOpsi Yang Anda Pilih : ");
		scanf ("%s", &temp);
		input = atoi(temp);
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
    int bau, rasa, endapan, coliform, skor = 0, i;
	dataAir data;
	char input = 'a', temp[20];
    for (i = 0; i < 51; i++) printf ("-");
    printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
    printf ("|%18sSurvei Mandiri%17s|\n", "", "");
    for (i = 0; i < 51; i++) printf ("-");
	
	printf ("\n|I. Survei Fisik dan Sensorik%21s|","");
    printf("\n|Jawablah pertanyaan-pertanyaan berikut%11s|\n|%49s|", "", "");
    
    printf ("\n|1. Seberapa bau air Anda?%24s|", "");
    skalaASCII("Bau");
    data.bau = 0;
    while (data.bau < 1 || data.bau > 5) {
    	printf ("|Jawaban Anda : ");
    	scanf ("%s", &temp);
    	data.bau = atoi(temp);
    	if (data.bau < 1 || data.bau > 5) {
    		printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	printf ("|%49s|\n|2.a Apakah anda punya alat Nephelometer atau %4s|\n|    Spektrofotometer / kolorimeter?  (Y/N)%7s|", "", "", "");
	
	while(input != 'Y' && input != 'N') {
		printf ("\n|Jawaban Anda : ");
		scanf (" %c", &input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	
	switch(input) {
		case 'Y' :
			printf ("|2.b Berapa NTU yang muncul?%22s|\n", "");
    		data.kekeruhan.decimal = -1;
    		while (data.kekeruhan.decimal <= 0) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data.kekeruhan.decimal = atof(temp);
    			if (data.kekeruhan.decimal <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			printf ("|2.c Berapa TCU yang muncul?%22s|\n", "");
    		data.warnaAir.decimal = -1;
    		while (data.warnaAir.decimal <= 0) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data.warnaAir.decimal = atof(temp);
    			if (data.warnaAir.decimal <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			break;
		case 'N' :
			printf ("|2.b Seberapa kotor air Anda?%21s|", "");
    		skalaASCII("Kotor");
    		data.bau = 0;
    		while (data.kekeruhan.integer < 1 || data.kekeruhan.integer > 5) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data.kekeruhan.integer = atoi(temp);
    			if (data.kekeruhan.integer < 1 || data.kekeruhan.integer > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			break;
	}
    
    printf ("|%49s|\n|3.a Apakah anda punya alat pH Meter atau kertas  |\n|    lakmus (Y/N)%33s|", "", "");
    input = 'a';
    while(input != 'Y' && input != 'N') {
		printf ("\n|Jawaban Anda : ");
		scanf (" %c", &input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	data.pH = -1;
	if (input == 'Y') {
		printf ("|3.b Masukkan pH yang terukur%21s|\n", "");
		while (data.pH <= 0 || data.pH > 14) {
    		printf ("|Jawaban Anda : ");
    		scanf("%s", &temp);
    		data.pH = atoi(temp);
    		if (data.pH <= 0 || data.pH > 14) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	else {
		printf ("|3.b Seberapa berasa air Anda?%20s|", "");
	    skalaASCII("Berasa");
	    data.rasa = 0;
	    while (data.rasa < 1 || data.rasa > 5) {
	    	printf ("|Jawaban Anda : ");
	    	scanf("%s", &temp);
	    	data.rasa = atoi(temp);
	    	if (data.rasa < 1 || data.rasa > 5) {
	    		printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
		}
	}
    
    printf ("|%49s|\n|4. Seberapa banyak endapan air Anda?%13s|", "", "");
    skalaASCII("Banyak");
    data.endapan = 0;
    while (data.endapan < 1 || data.endapan > 5) {
    	printf ("|Jawaban Anda : ");
    	scanf("%s", &temp);
    	data.endapan = atoi(temp);
    	if (data.endapan < 1 || data.endapan > 5) {
    		printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
    
    printf ("|%49s|\n|5.a Apakah anda punya alat tes Coliform? (Y/N)   |", "");
    input = 'a';
    while(input != 'Y' && input != 'N') {
		printf ("\n|Jawaban Anda : ");
		scanf (" %c", &input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	
	if (input == 'Y') {
		printf ("|5.b Masukkan angka CFU/100mL%21s|\n", "");
		data.eColi = -1;
    	while (data.eColi <= 0) {
	    	printf ("|Jawaban Anda : ");
	    	scanf ("%s", &temp);
	    	data.eColi = atof(temp);
	    	if (data.eColi <= 0 ) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	else {
		printf ("|5.b Apakah anda sering diare?%20s|", "");
		skalaASCII("Sering");
		data.diare = -1;
    	while (data.diare < 1 || data.diare > 5) {
	    	printf ("|Jawaban Anda : ");
	    	scanf("%s", temp);
	    	data.diare = atoi(temp);
	    	if (data.diare < 1 || data.diare > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
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

void skalaASCII(char keyword[]) {
	int panjang = 15 - (strlen(keyword)*2), i;
	printf ("\n| o--------o--------o--------o-------o %11s|", "");
	printf ("\n| 1 %32s 5%12s|", "", "");
	printf ("\n|Tidak %s %20s Sangat %s", keyword, "", keyword);
	for (i = 1; i < panjang; i++) printf (" ");
	printf ("|\n");
}

//AsCII ART
printf("                 /\   ");
printf("                /  \");
printf("               /    \");
printf("              /      \");
printf("             /        \");
printf("            /          \");
printf("           /            \");
printf("          /              \n");
    printf("     ;                ;\n");
    printf("     \                /\n");
    printf("      `-.__..__..__..`      '\n");
