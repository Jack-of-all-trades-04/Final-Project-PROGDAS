#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void startup();
void surveiMandiri();
void kalkulatorAir();
void skalaASCII(char keyword[]);
void badgeBijakAir();
void cekPenggunaanAir(const char* kegiatan, double nilai, double minimal, double maksimal);
void tampilkanPertanyaan(const char* pertanyaan);

typedef enum {
	KURANG, IDEAL, BOROS
}penggunaanAir;

typedef struct {
	float pH, eColi, TCU;
	int bau, rasa, endapan, diare;
	
	union {
		float decimal;
		int integer;
	}kekeruhan;
	
}dataAir;

typedef enum {
	TIDAKAKURAT, CUKUPAKURAT, AKURAT, SANGATAKURAT
}sistemPenilaian;

int main() {
	startup();
	return 0;
}

int penilaianSurvei(dataAir data, int alat[]);

void startup() {
	int i, input = 0;
	char temp[20];
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|Silahkan pilih opsi yang tersedia :%14s|", "");
	printf ("\n|1. Survei Mandiri Kelayakan Air%18s|", "");
	printf ("\n|2. Kalkulator Penggunaan Air%21s|", "");
	printf ("\n|3. Keluar%40s|\n", "");
	for (i = 0; i < 51; i++) printf ("-");
	
	while (input < 1 || input > 3) {
		printf ("\nOpsi Yang Anda Pilih : ");
		scanf ("%s", &temp);
		input = atoi(temp);
		if (input < 1 || input > 3) {
			puts ("Opsi tidak valid, masukkan ulang.");
		}
	}
	
	switch (input) {
		case 1 :
			surveiMandiri();
			startup();
			break;
		case 2 :
			kalkulatorAir();
			startup();
			break;
		case 3 :
			break;
	}
}

void surveiMandiri() {
    int i, skor, alat[3];
	dataAir* data = (dataAir*) malloc (sizeof(dataAir));
	char input = 'a', temp[20];
	
    for (i = 0; i < 51; i++) printf ("-");
    printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
    printf ("|%18sSurvei Mandiri%17s|\n", "", "");
    for (i = 0; i < 51; i++) printf ("-");
	
	printf ("\n|I. Survei Fisik dan Sensorik%21s|","");
    printf("\n|Jawablah pertanyaan-pertanyaan berikut%11s|\n|%49s|", "", "");
    
    printf ("\n|1. Seberapa bau air Anda?%24s|", "");
    skalaASCII("Bau");
    data->bau = -1;
    while (data->bau < 1 || data->bau > 5) {
    	printf ("|Jawaban Anda : ");
    	scanf ("%s", &temp);
    	data->bau = atoi(temp);
    	if (data->bau < 1 || data->bau > 5) {
    		printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	printf ("|%49s|\n|2.a Apakah anda punya alat Nephelometer atau %4s|\n|    Spektrofotometer / kolorimeter?  (Y/N)%7s|", "", "", "");
	
	while(input != 'Y' && input != 'N') {
		printf ("\n|Jawaban Anda : ");
		scanf (" %s", &input);
		input = toupper(input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	
	switch(input) {
		case 'Y' :
			alat[0] = 1;
			printf ("|2.b Berapa NTU yang muncul?%22s|\n", "");
    		data->kekeruhan.decimal = -1;
    		while (data->kekeruhan.decimal <= 0) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data->kekeruhan.decimal = atof(temp);
    			if (data->kekeruhan.decimal <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			printf ("|2.c Berapa TCU yang muncul?%22s|\n", "");
    		data->TCU = -1;
    		while (data->TCU <= 0) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data->TCU = atof(temp);
    			if (data->TCU <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			break;
		case 'N' :
			alat[0] = 0;
			printf ("|2.b Seberapa kotor air Anda?%21s|", "");
    		skalaASCII("Kotor");
    		while (data->kekeruhan.integer < 1 || data->kekeruhan.integer > 5) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data->kekeruhan.integer = atoi(temp);
    			if (data->kekeruhan.integer < 1 || data->kekeruhan.integer > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			break;
	}
    
    printf ("|%49s|\n|3.a Apakah anda punya alat pH Meter atau kertas  |\n|    lakmus (Y/N)%33s|", "", "");
    input = 'a';
    while(input != 'Y' && input != 'N') {
		printf ("\n|Jawaban Anda : ");
		scanf (" %s", &input);
		input = toupper(input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	data->pH = -1;
	if (input == 'Y') {
		alat[1] = 1;
		printf ("|3.b Masukkan pH yang terukur%21s|\n", "");
		while (data->pH <= 0 || data->pH > 14) {
    		printf ("|Jawaban Anda : ");
    		scanf("%s", &temp);
    		data->pH = atoi(temp);
    		if (data->pH <= 0 || data->pH > 14) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	else {
		alat[1] = 0;
		printf ("|3.b Seberapa berasa air Anda?%20s|", "");
	    skalaASCII("Berasa");
	    data->rasa = 0;
	    while (data->rasa < 1 || data->rasa > 5) {
	    	printf ("|Jawaban Anda : ");
	    	scanf("%s", &temp);
	    	data->rasa = atoi(temp);
	    	if (data->rasa < 1 || data->rasa > 5) {
	    		printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
		}
	}
    
    printf ("|%49s|\n|4. Seberapa banyak endapan air Anda?%13s|", "", "");
    skalaASCII("Banyak");
    data->endapan = 0;
    while (data->endapan < 1 || data->endapan > 5) {
    	printf ("|Jawaban Anda : ");
    	scanf("%s", &temp);
    	data->endapan = atoi(temp);
    	if (data->endapan < 1 || data->endapan > 5) {
    		printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
    
    printf ("|%49s|\n|5.a Apakah anda punya alat tes Coliform? (Y/N)   |", "");
    input = 'a';
    while(input != 'Y' && input != 'N') {
		printf ("\n|Jawaban Anda : ");
		scanf (" %s", &input);
		input = toupper(input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	
	if (input == 'Y') {
		alat[2] = 1;
		printf ("|5.b Masukkan angka CFU/100mL%21s|\n", "");
		data->eColi = -1;
    	while (data->eColi <= 0) {
	    	printf ("|Jawaban Anda : ");
	    	scanf ("%s", &temp);
	    	data->eColi = atof(temp);
	    	if (data->eColi <= 0 ) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	else {
		alat[2] = 0;
		printf ("|5.b Apakah anda sering diare?%20s|", "");
		skalaASCII("Sering");
		data->diare = -1;
    	while (data->diare < 1 || data->diare > 5) {
	    	printf ("|Jawaban Anda : ");
	    	scanf("%s", temp);
	    	data->diare = atoi(temp);
	    	if (data->diare < 1 || data->diare > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	
<<<<<<< HEAD
	skor = penilaianSurvei(*data, alat);
=======
	skor = penilaianSurvei(data, alat);
>>>>>>> e2d13b0b052913ff55686649986fa4e96af897e5

	for (i = 0; i < 51; i++) printf ("-");
    printf("\n|%18sHasil Penilaian%16s|\n", "", "");
    sprintf (temp, "%d", skor);
    printf("|Skor Kelayakan Air: %-29s|\n|", temp);
	printf ("Tingkat Kelayakan Air : ");
	if (skor < 50) {
		printf("Tidak Layak%14s|\n","");
	} else if (skor < 70) {
		printf("Hati-hati%16s|\n", "");
	} else if (skor < 85) {
		printf("Layak%20s|\n", "");
	} else {
		printf("Sangat Layak%13s|\n","");
	}
	
	int alatTerpakai = alat[0] + alat[1] + alat[2];
	switch (alatTerpakai) {
		case TIDAKAKURAT :
			printf ("|Kategori : Tidak Akurat%26s|\n", "");
			printf ("|Akurasi: 60 - 70%%%32s|\n", "");
			break;
		case CUKUPAKURAT :
			printf ("|Kategori : Cukup Akurat%26s|\n", "");
			printf ("|Akurasi: 70 - 80%%%32s|\n", "");
			break;
		case AKURAT :
			printf ("|Kategori : Akurat%32s|\n", "");
			printf ("|Akurasi: 80 - 90%%%32s|\n", "");
			break;
		case SANGATAKURAT : 
			printf ("|Kategori : Sangat Akurat%28s|\n", "");
			printf ("|Akurasi: 90 - 100%%%31s|\n", "");
			break;
	}
	for (i = 0; i < 51; i++) printf ("-");
	puts ("\n");
	free(data);
}

int penilaianSurvei(dataAir data, int alat[]) {

    float skor = 0, alatTerpakai = 0;
    
    // Skala 1 (baik) - 5 (buruk), skor optimal jika nilai 1
    skor += ((5 - data.bau) / 4.0) * 20;
    
    if (alat[0] == 1) {
        alatTerpakai++;
        if (data.kekeruhan.decimal > 5) skor += (1 - (data.kekeruhan.decimal / 5.0)) * 15;
        else skor += 15;
        if (data.TCU > 50) skor += (1 - (data.TCU / 50.0)) * 10;
        else skor += 10;
    }
    else {
        skor += ((5 - data.kekeruhan.integer) / 4.0) * 25;
    }
    
    if (alat[1] == 1) {
        alatTerpakai++;
        float range = 0;
        if (data.pH < 6.5) range = fabs(data.pH - 6.5);
        else if (data.pH > 8.5) range = fabs(data.pH - 8.5);
        else if (data.pH >= 6.5 && data.pH <= 8.5) skor += 20;
        if (range != 0) skor += (1 - (range / 3.0)) * 20;
    }
    else {
        skor += ((5 - data.rasa) / 4.0) * 20;
    }
    
    skor += ((5 - data.endapan) / 4.0) * 15;
    
    if (alat[2] == 1) {
        alatTerpakai++;
        if (data.eColi > 50) skor += (1 - (data.eColi / 50.0)) * 20;
        else skor += 20;
    }
    else {
        skor += ((5 - data.diare) / 4.0) * 20;
    }
    return skor;

}

void kalkulatorAir() {
	int i, input = 0;
	char temp[20];
	
	for (i = 0; i < 51; i++) printf ("-");
	printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
	printf ("|%18sKalkulator Air%17s|\n", "", "");
	for (i = 0; i < 51; i++) printf ("-");
	
    double* total_air = (double*) malloc (sizeof(double));
    double* penggunaan = (double*) malloc (6 * sizeof(double));// Dynamic Array dengan dengan ukuran 6
    const char* listPertanyaan[] = {
	"1. Berapa banyak air yang digunakan untuk minum?  (dalam liter)",
	"2. Berapa banyak air yang digunakan untuk mandi?  (dalam liter)",
	"3. Berapa banyak air yang digunakan untuk mencuci baju? (dalam liter)",
	"4. Berapa banyak air yang digunakan untuk mencuci piring? (dalam liter)",
	"5. Berapa banyak air yang digunakan untuk wudhu?  (dalam liter)",
	"6. Berapa banyak air yang digunakan untuk siram   tanaman? (dalam liter)",
	};
	const char *kegiatan[] = {"Minum", "Mandi", "Mencuci Baju", "Mencuci Piring", "Wudhu", "Siram Tanaman"};
	double penggunaanMinimal[] = {2,30,10,50,1.5*5.0,5};
	double penggunaanMaksimal[] = {3,60,20,100,3*5.0,20};
    printf("\n|Jawablah pertanyaan-pertanyaan berikut%11s|\n|%49s|", "", "");
    *total_air = 0;
	for (i = 0; i < 6; i++) {
    	tampilkanPertanyaan(listPertanyaan[i]);
    	do {
    		printf ("\n|Jawaban Anda : ");
    		scanf (" %s", &temp);
    		penggunaan[i] = atof(temp);
    		if (penggunaan[i] <= 0) printf ("|Jawaban tidak valid, coba lagi.%18s|", "");
		} 
		while (penggunaan[i] <= 0);
		printf ("|%49s|", "");
		*total_air += penggunaan[i];
	}
	
	puts ("");
	for (i = 0; i < 51; i++) printf ("-");
    printf ("\n|%16sHasil Kalkulator%17s|", "", "");
    sprintf (temp, "%.2lf", *total_air);
	printf ("\n|Penggunaan air sebanyak: %-18s liter|\n", temp);
	printf ("|Detail : %40s|\n", "");
	
	for (i = 0; i < 6; i++) {
		int j;
		cekPenggunaanAir(kegiatan[i], penggunaan[i], penggunaanMinimal[i], penggunaanMaksimal[i]);
		printf ("|");
		for (j = 0; j < 49; j++) printf ("-");
		printf ("|\n");
	}
	
	penggunaanAir kategori;
	if(*total_air < 50){
		kategori = KURANG;
	} else if (*total_air >= 50 && *total_air <= 100) {
		kategori = IDEAL;
	} else {
		kategori = BOROS;
	}

	printf ("|Kategori penggunaan air: ");
	switch (kategori) {
		case KURANG:
			printf ("KURANG%18s|\n|Ideal adalah 50 sampai 100 liter%17s|\n", "", "");
			break;
		case IDEAL:
			printf ("IDEAL%19s|\n|Ideal diantara 50 sampai 100 liter%15s|\n", "", "");
			badgeBijakAir();
			break;
		case BOROS:
			printf ("BOROS%19s|\n|Penggunaan melebihi 100 liter%20s|\n", "", "");
			printf ("|Apakah Anda butuh saran untuk bisa mengurangi    |\n|penggunaan air?%34s|\n", "");
			do {
				printf ("|Ketik IYA atau TIDAK: ");
				scanf ("%s", &temp);
				for (i = 0; i < strlen(temp); i++) temp[i] = tolower(temp[i]);
				if (strcmp(temp, "iya") == 0) {
		            printf("|Berikut ini saran untuk Anda bisa menghemat air  |\n","");// Sarannya kalau mau dynamic?
		            printf("|1. Matikan keran air bila tidak digunakan%8s|\n","");
		            printf("|2. Mengecek pipa secara berkala%18s|\n","");
		            printf("|3. Menampung air hujan%27s|\n","");
		    	}
				else if (strcmp(temp, "tidak") == 0) printf ("|Baik, semoga penggunaan air Anda bisa lebih hemat|\n|ke depannya%38s|\n","");
				else printf ("|Input tidak valid, silakan ketik IYA atau TIDAK%2s|\n","");
			}
			while (strcmp(temp, "iya") != 0 && strcmp(temp, "tidak") != 0);
			break;
	}
	for (i = 0; i < 51; i++) printf ("-");
	free(total_air);
	free(penggunaan);
	puts ("\n");
}

void cekPenggunaanAir(const char* kegiatan, double nilai, double minimal, double maksimal) {
	char temp1[20], temp2[20];
	sprintf (temp1, "%.2lf", nilai);
	printf ("|%-20s : %-19s  liter|\n", kegiatan, temp1);
	sprintf (temp1, "%.2lf", minimal);
	sprintf (temp2, "%.2lf", maksimal);
	if (nilai < minimal) printf ("|Kurang dari ideal (%-7s sampai %-7s  liter)|\n", temp1, temp2);
	else if (nilai > maksimal) printf ("|Boros, angka ideal(%-7s sampai %-7s  liter)|\n", temp1, temp2);
	else printf ("|Sudah Ideal (%-7s sampai %-7s        liter)|\n", temp1, temp2);
}

void skalaASCII(char keyword[]) {
	int panjang = 15 - (strlen(keyword)*2), i;
	printf ("\n| o--------o--------o--------o-------o %11s|", "");
	printf ("\n| 1 %32s 5%12s|", "", "");
	printf ("\n|Tidak %s %20s Sangat %s", keyword, "", keyword);
	for (i = 1; i < panjang; i++) printf (" ");
	printf ("|\n");
}

void tampilkanPertanyaan(const char* pertanyaan) {
	int panjang = strlen(pertanyaan), i = 0;
	while (i < panjang) {
		if (i == 49) printf ("|  %-47s|", pertanyaan + i);
		else printf ("\n|%.49s|\n", pertanyaan + i);
		i += 49;
	}
}

void badgeBijakAir() {
	printf("|Selamat, Anda mendapatkan Badge Bijak Air!!%6s|\n", "");
	printf("|                       /\\ %23s|\n", "");
	printf("|                      /  \\ %22s|\n", "");
	printf("|                     /    \\    %18s|\n", "");
	printf("|                    /      \\    %17s|\n", "");
	printf("|                   /        \\    %16s|\n", "");
	printf("|                  /          \\    %15s|\n", "");
	printf("|                 /            \\    %14s|\n", "");
	printf("|                /              \\     %12s|\n", "");
	printf("|               ;                ;     %11s|\n", "");
	printf("|               \\                /     %11s|\n", "");
	printf("|                `-.__..__..__..`      %11s|\n", "");
}

