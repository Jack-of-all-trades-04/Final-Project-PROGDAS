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
    data.bau = -1;
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
		scanf (" %s", &input);
		input = toupper(input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	
	switch(input) {
		case 'Y' :
			alat[0] = 1;
			printf ("|2.b Berapa NTU yang muncul?%22s|\n", "");
    		data.kekeruhan.decimal = -1;
    		while (data.kekeruhan.decimal <= 0) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data.kekeruhan.decimal = atof(temp);
    			if (data.kekeruhan.decimal <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			printf ("|2.c Berapa TCU yang muncul?%22s|\n", "");
    		data.TCU = -1;
    		while (data.TCU <= 0) {
    			printf ("|Jawaban Anda : ");
    			scanf ("%s", &temp);
    			data.TCU = atof(temp);
    			if (data.TCU <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
			}
			break;
		case 'N' :
			alat[0] = 0;
			printf ("|2.b Seberapa kotor air Anda?%21s|", "");
    		skalaASCII("Kotor");
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
		scanf (" %s", &input);
		input = toupper(input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	data.pH = -1;
	if (input == 'Y') {
		alat[1] = 1;
		printf ("|3.b Masukkan pH yang terukur%21s|\n", "");
		while (data.pH <= 0 || data.pH > 14) {
    		printf ("|Jawaban Anda : ");
    		scanf("%s", &temp);
    		data.pH = atoi(temp);
    		if (data.pH <= 0 || data.pH > 14) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
		}
	}
	else {
		alat[1] = 0;
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
		scanf (" %s", &input);
		input = toupper(input);
		if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
	}
	
	if (input == 'Y') {
		alat[2] = 1;
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
		alat[2] = 0;
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
	
	skor = penilaianSurvei(data, alat);
	
	for (i = 0; i < 51; i++) printf ("-");
    printf("\n|%18sHasil Penilaian%16s|\n", "", "");
    sprintf (temp, "%d", skor);
    printf("|Skor Kelayakan Air: %-29s|\n|", temp);
	printf ("Tingkat Kelayakan Air : ");
	if (skor < 50) {
		printf("Tidak Layak%26s|\n","");
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
			printf ("|Akurasi: 60 - 80%%%32s|\n", "");
			break;
		case CUKUPAKURAT :
			printf ("|Kategori : Cukup Akurat%26s|\n", "");
			printf ("|Akurasi: 60 - 80%%%32s|\n", "");
			break;
		case AKURAT :
			printf ("|Kategori : Akurat%32s|\n", "");
			printf ("|Akurasi: 80 - 100%%%31s|\n", "");
			break;
		case SANGATAKURAT : 
			printf ("|Kategori : Sangat Akurat%28s|\n", "");
			printf ("|Akurasi: 80 - 100%%%31s|\n", "");
			break;
	}
	for (i = 0; i < 51; i++) printf ("-");
	puts ("\n");
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
    /* Jika skor < 50 = Tidak layak, 50 - 69 = Hati-hati
    70 - 84 = Layak, 85 - 100 = Sangat Layak 
    Jika alat terpakai = 0 maka pakai enum TIDAKAKURAT
    jika alat terpakai = 1 maka pakai enum CUKUPAKURAT
    jika alat terpakai = 2 maka pakai enum AKURAT
    jika alat terpakai = 3 maka pakai enum SANGATAKURAT
    Kemudian dibuat Akurasi berdasarkan enumnya, Alat terpakai => 2 maka
    tampilkan Akurasi : 80 - 100%
    sisanya Akurasi : 60 - 80%
    */
    return skor;

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

    penggunaanAir kategori;
	if(total_air < 50){
		kategori = KURANG;
	} else if (total_air >= 50 && total_air <= 100) {
		kategori = IDEAL;
	} else {
		kategori = BOROS;
	}

	printf("Penggunaan air selama satu hari sebanyak: %d liter\n",total_air);
	printf("kategori penggunaan air: ");
	switch (kategori) {
		case KURANG:
			printf("KURANG\n");
			break;
		case IDEAL:
			printf("IDEAL\n");
			break;
		case BOROS:
			printf("BOROS\n");
			break;
	}
	if (kategori == BOROS) {
        char pilihan[50];
        printf("\nApakah anda butuh saran untuk bisa mengurangi penggunaan air?\n");
        printf("Ketik IYA atau TIDAK: ");
        scanf("%s", pilihan);

        // Normalisasi ke huruf kecil
        for (i = 0; pilihan[i]; i++) {
            pilihan[i] = tolower(pilihan[i]);
        }

        if (strcmp(pilihan, "iya") == 0) {
            printf("\nBerikut ini saran untuk anda bisa menghemat air:\n");
            printf("1. Matikan keran air bila tidak digunakan\n");
            printf("2. Mengecek pipa secara berkala\n");
            printf("3. Menampung air hujan\n");
        } else if (strcmp(pilihan, "tidak") == 0) {
            printf("Baik, semoga penggunaan air anda bisa lebih hemat ke depannya.\n");
        } else {
            printf("Input tidak dikenali. Silakan ketik IYA atau TIDAK.\n");
        }
    }

}

void skalaASCII(char keyword[]) {
	int panjang = 15 - (strlen(keyword)*2), i;
	printf ("\n| o--------o--------o--------o-------o %11s|", "");
	printf ("\n| 1 %32s 5%12s|", "", "");
	printf ("\n|Tidak %s %20s Sangat %s", keyword, "", keyword);
	for (i = 1; i < panjang; i++) printf (" ");
	printf ("|\n");
}

void badgeBijakAir() {
	printf("                 /\\    \n");
	printf("                /  \\    \n");
	printf("               /    \\    \n");
	printf("              /      \\    \n");
	printf("             /        \\    \n");
	printf("            /          \\    \n ");
	printf("          /            \\    \n");
	printf("          /              \\     \n");
	printf("         ;                ;     \n");
	printf("         \\                /      \n");
	printf("          `-.__..__..__..`      \n");
}
