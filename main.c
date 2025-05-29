#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void startup(); // Fungsi yang berperan dalam memulai program, kita akan menempatkan fungsi ini pada bagian-bagian penting dalam program seperti ketika program pertama kali dijalankan atau ketika program akan diulang kembali.
void surveiMandiri(); // Fungsi yang berperan untuk memulai antarmuka survei/asesmen terhadap kualitas air yang dimiliki oleh user dengan akurasi yang tergantung pada metode/alat yang digunakan user.
void kalkulatorAir(); // Fungsi yang berperan untuk memulai perhitungan terhadap penggunaan air oleh user.
void skalaASCII(char keyword[]); // Fungsi digunakan untuk melakukan generalisasi teks sehingga tidak perlu menulis fungsi puts/printf secara redundan.
void badgeBijakAir(); // Fungsi yang digunakan untuk melakukan generalisasi ASCII art ketika penggunaan air termasuk efisien/hemat atau ideal.
void tampilkanPertanyaan(const char* pertanyaan); 
int cekPenggunaanAir(const char* kegiatan, double nilai, double min, double maks);

typedef enum {
	KURANG, IDEAL, BOROS
}kategoriPenggunaanAir;

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
	startup(); // Fungsi main untuk memulai keseluruhan program.
	return 0;
}

int penilaianSurvei(dataAir data, int alat[]); // Fungsi digunakan untuk melakukan perhitungan pada skor.

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
		if (input < 1 || input > 3) puts ("Opsi tidak valid, masukkan ulang.");
	}
	
	switch (input) { // Switch case digunakan untuk memilih program mana yang akan dipakai atau keluar berdasarkan input user.
		case 1 :
			surveiMandiri();
			startup();
			break;
		case 2 :
			kalkulatorAir();
			startup();
			break;
		case 3 : // Ketika user menginput pilihan yang ketiga '3', maka program akan keluar.
			break;
	}
}

void surveiMandiri() { 
    int i, skor, alat[3];
    dataAir* data = (dataAir*) malloc (sizeof(dataAir));
    char input = 'a', temp[20];
    
    // Menampilkan header survei mandiri
    for (i = 0; i < 51; i++) printf ("-");
    printf ("\n|%18sBijak Air 1.0%18s|\n", "", "");
    printf ("|%18sSurvei Mandiri%17s|\n", "", "");
    for (i = 0; i < 51; i++) printf ("-");
    
    // Bagian survei fisik dan sensorik
    printf ("\n|I. Survei Fisik dan Sensorik%21s|","");
    printf("\n|Jawablah pertanyaan-pertanyaan berikut%11s|\n|%49s|", "", "");
    
    // Input skala bau air (1 = tidak bau, 5 = sangat bau)
    printf ("\n|1. Seberapa bau air Anda?%24s|", "");
    skalaASCII("Bau");
    data->bau = -1;
    while (data->bau < 1 || data->bau > 5) {
        printf ("|Jawaban Anda : ");
        scanf ("%s", &temp);
        data->bau = atoi(temp);
        if (data->bau < 1 || data->bau > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
    }
    
    // Pertanyaan tentang kepemilikan alat ukur kekeruhan
    printf ("|%49s|\n|2.a Apakah anda punya alat Nephelometer atau %4s|\n|    Spektrofotometer / kolorimeter?  (Y/N)%7s|", "", "", "");
    while(input != 'Y' && input != 'N') {
        printf ("\n|Jawaban Anda : ");
        scanf (" %c", &input);
        input = toupper(input);
        if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
    }
    
    // Input nilai kekeruhan berdasarkan alat atau persepsi
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
    
    // Pertanyaan tentang kepemilikan alat ukur pH
    printf ("|%49s|\n|3.a Apakah anda punya alat pH Meter atau kertas  |\n|    lakmus (Y/N)%33s|", "", "");
    input = 'a';
    while(input != 'Y' && input != 'N') {
        printf ("\n|Jawaban Anda : ");
        scanf (" %c", &input);
        input = toupper(input);
        if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
    }
    data->pH = -1;
    // Input nilai pH jika punya alat, jika tidak maka input rasa air
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
        	if (data->rasa < 1 || data->rasa > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
        }
    }
    
    // Input skala endapan air (1 = tidak ada endapan, 5 = sangat banyak)
    printf ("|%49s|\n|4. Seberapa banyak endapan air Anda?%13s|", "", "");
    skalaASCII("Banyak");
    data->endapan = 0;
    while (data->endapan < 1 || data->endapan > 5) {
        printf ("|Jawaban Anda : ");
        scanf("%s", &temp);
        data->endapan = atoi(temp);
        if (data->endapan < 1 || data->endapan > 5) printf ("|Jawaban tidak valid, coba lagi%19s|\n", "");
    }
    
    // Pertanyaan tentang kepemilikan alat tes Coliform
    printf ("|%49s|\n|5.a Apakah anda punya alat tes Coliform? (Y/N)   |", "");
    input = 'a';
    while(input != 'Y' && input != 'N') {
        printf ("\n|Jawaban Anda : ");
        scanf (" %c", &input);
        input = toupper(input);
        if (input != 'Y' && input != 'N') printf ("|Jawaban tidak valid, hanya menerima 'Y' dan 'N'  |");
    }
    
    // Input nilai eColi jika punya alat, jika tidak maka input skala sering diare
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
    
    // Hitung skor kelayakan air berdasarkan input survei
    skor = penilaianSurvei(*data, alat);

    // Menampilkan hasil penilaian dan kategori kelayakan air
    for (i = 0; i < 51; i++) printf ("-");
    printf("\n|%18sHasil Penilaian%16s|\n", "", "");
    sprintf (temp, "%d", skor);
    printf("|Skor Kelayakan Air: %-29s|\n|", temp);
    
    printf ("Tingkat Kelayakan Air : ");
    if (skor < 50) printf("Tidak Layak%14s|\n","");
	else if (skor < 70) printf("Hati-hati%16s|\n", "");
	else if (skor < 85) printf("Layak%20s|\n", "");
    else printf("Sangat Layak%13s|\n","");
    
    // Menampilkan kategori akurasi berdasarkan jumlah alat yang digunakan
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
            printf ("|Kategori : Sangat Akurat%25s|\n", "");
            printf ("|Akurasi: 90 - 100%%%31s|\n", "");
            break;
    }
    for (i = 0; i < 51; i++) printf ("-");
    puts ("\n");
    free(data);
}

// Fungsi digunakan untuk melakukan perhitungan pada skor survei air
int penilaianSurvei(dataAir data, int alat[]) {

    float skor = 0, alatTerpakai = 0;
    
    // Skala 1 (baik) - 5 (buruk), skor optimal jika nilai 1
    // Penilaian bau air
    skor += ((5 - data.bau) / 4.0) * 20;
    
    // Penilaian kekeruhan air
    if (alat[0] == 1) {
        alatTerpakai++;
        // Jika menggunakan alat ukur, gunakan nilai decimal dan TCU
        if (data.kekeruhan.decimal > 5) skor += (1 - (data.kekeruhan.decimal / 5.0)) * 15;
        else skor += 15;
        if (data.TCU > 50) skor += (1 - (data.TCU / 50.0)) * 10;
        else skor += 10;
    }
    else {
        // Jika tidak menggunakan alat, gunakan persepsi integer
        skor += ((5 - data.kekeruhan.integer) / 4.0) * 25;
    }
    
    // Penilaian pH atau rasa air
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
    
    // Penilaian endapan air
    skor += ((5 - data.endapan) / 4.0) * 15;
    
    // Penilaian eColi atau sering diare
    if (alat[2] == 1) {
        alatTerpakai++;
        if (data.eColi > 50) skor += (1 - (data.eColi / 50.0)) * 20;
        else skor += 20;
    }
    else {
        skor += ((5 - data.diare) / 4.0) * 20;
    }
    // Skor akhir dikembalikan untuk ditampilkan pada surveiMandiri
    return skor;
}

// Fungsi untuk menghitung penggunaan air
// Penerapan modul 5 praktikum yaitu modul function
void kalkulatorAir() {
    int i, j, jumlahAnggota = 0, nilaiIdeal = 0;
    char temp[20];
	double* total_air = (double*) malloc(sizeof(double));
	double* penggunaanAir = (double*) malloc(6*sizeof(double));
    *total_air = 0;
    double nilai;
	const char* listPertanyaan[] = {
        "1. Berapa banyak air yang digunakan untuk minum? ",
        "2. Berapa banyak air yang digunakan untuk mandi? ",
        "3. Berapa banyak air yang digunakan untuk mencuci baju? ",
        "4. Berapa banyak air yang digunakan untuk mencuci piring? ",
        "5. Berapa banyak air yang digunakan untuk wudhu? ",
        "6. Berapa banyak air yang digunakan untuk siram   tanaman? "
    };

    const char* kegiatan[] = {
        "Minum", "Mandi", "Mencuci Baju", "Mencuci Piring", "Wudhu", "Siram Tanaman"
    };

    double penggunaanMinimal[] = {2, 30, 10, 5, 1.5*5.0, 5};
    double penggunaanMaksimal[] = {3, 60, 20, 10, 3*5.0, 20};

    for (i = 0; i < 51; i++) printf("-");
    printf("\n|%18sBijak Air 1.0%18s|\n", "", "");
    printf("|%18sKalkulator Air%17s|\n", "", "");
    for (i = 0; i < 51; i++) printf("-");

    while (jumlahAnggota <= 0) {
    	printf("\n|Masukkan jumlah anggota keluarga anda: ");
    	scanf(" %s", &temp);
    	jumlahAnggota = atoi(temp);
    	if (jumlahAnggota <= 0) printf ("|Jawaban tidak valid, coba lagi%19s|", "");
	}
	
	//Set array penggunaan air ke 0 semua
	for (i = 0; i < 6; i++) penggunaanAir[i] = 0;
	
    for (i = 0; i < jumlahAnggota; i++) {
    	double totalAirAnggota = 0;
        for (j = 0; j < 51; j++) printf("-");
        printf("\n|%14sAnggota keluarga ke-%d%14s|\n", "", i+1, "");
        for (j = 0; j < 51; j++) printf("-");
		printf("\n|%8sMasukkan angka dalam satuan liter%8s|", "", "");
		
        for (j = 0; j < 6; j++) {
            tampilkanPertanyaan(listPertanyaan[j]);
            do {
                printf ("|Jawab: ");
                scanf (" %s", &temp);
                nilai = atof(temp);
                if (nilai <= 0) printf("|Input tidak valid. Coba lagi.%20s|\n","");
            } while (nilai <= 0);
            printf ("|%49s|", "");
            penggunaanAir[j] += nilai;
            totalAirAnggota += nilai;
        }
        
        sprintf (temp, "%.2lf", totalAirAnggota);
        printf("\n|Total penggunaan anggota ke-%d: %-10s liter%2s|\n", i+1, temp, "");
        for (j = 0; j < 51; j++) printf("-");
        puts ("\n");
        *total_air += totalAirAnggota;
    }

    for (j = 0; j < 51; j++) printf("-");
    printf("\n|%17sHasil Kalkulator%16s|\n", "", "");
    for (j = 0; j < 51; j++) printf("-");
    sprintf (temp, "%.2lf", *total_air);
    printf("\n|Penggunaan air sebanyak: %-18s liter|\n", temp);
    printf("|Detail rata-rata penggunaan setiap kegiatan :%4s|\n","");

    // Tampilkan kategori per kegiatan
    for (i = 0; i < 6; i++) {
        nilaiIdeal += cekPenggunaanAir(kegiatan[i], (penggunaanAir[i]/jumlahAnggota), penggunaanMinimal[i], penggunaanMaksimal[i]);
    }

    // Kategori total
    kategoriPenggunaanAir kategori;
    if (*total_air < 50 * jumlahAnggota && nilaiIdeal <= 3) kategori = KURANG;
    else if (*total_air <= 100 * jumlahAnggota && nilaiIdeal >= 4) kategori = IDEAL;
    else if (*total_air <= 100 * jumlahAnggota && nilaiIdeal <= 3) kategori = KURANG;
	else kategori = BOROS;
    

    for (j = 0; j < 51; j++) printf("-");
    printf("\n|Kategori penggunaan air: ");
    switch (kategori) {
        case KURANG:
            printf("KURANG%18s|\n","");
            printf("|Ideal adalah 50-100 liter per orang%14s|\n", "");
            printf ("|Dan setidaknya ada 4 penggunaan secara ideal%5s|\n", "");
            break;
        case IDEAL:
            printf("IDEAL%19s|\n", "");
            printf("|Ideal diantara 50-100 liter per orang%12s|\n","");
            badgeBijakAir();
            break;
        case BOROS:
            printf("BOROS%19s|\n","");
            printf("|Penggunaan melebihi 100 liter per orang%10s|\n","");
            printf("|Apakah Anda butuh saran?%25s|\n","");

            do {
                printf("|Ketik IYA atau TIDAK: ");
                scanf("%s", temp);
                for (i = 0; temp[i]; i++) temp[i] = tolower(temp[i]);

                if (strcmp(temp, "iya") == 0) {
                    printf ("|Saran:%43s|\n", "");
                    printf ("|1. Matikan keran air bila tidak digunakan%8s|\n", "");
                    printf ("|2. Mengecek pipa secara berkala%18s|\n", "");
                    printf ("|3. Menampung air hujan%27s|\n", "");
                } 
				else if (strcmp(temp, "tidak") == 0) printf ("|Baik. Semoga penggunaan air mu bisa lebih hemat%2s|\n","");
				else printf("|Input tidak valid. Coba lagi.%20s|\n","");
				
            } while (strcmp(temp, "iya") != 0 && strcmp(temp, "tidak") != 0);
            break;
    }
    for (i = 0; i < 51; i++) printf("-");
    puts ("\n");

    free(total_air);
    free(penggunaanAir);
}

//mengatur spacing untuk bisa rapi dan sejajar dengan survey
int cekPenggunaanAir(const char* kegiatan, double nilai, double minimal, double maksimal) {
	char temp1[20], temp2[20];
	sprintf (temp1, "%.2lf", nilai);
	printf ("|%-20s : %-19s  liter|\n", kegiatan, temp1);
	sprintf (temp1, "%.2lf", minimal);
	sprintf (temp2, "%.2lf", maksimal);
	if (nilai < minimal) printf ("|Kurang dari ideal (%-7s sampai %-7s  liter)|\n", temp1, temp2);
	else if (nilai > maksimal) printf ("|Boros, angka ideal(%-7s sampai %-7s  liter)|\n", temp1, temp2);
	else {
		printf ("|Sudah Ideal (%-7s sampai %-7s        liter)|\n", temp1, temp2);
		return 1;
	}
	return 0;
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
		if (i == 49) printf ("|  %-47s|\n", pertanyaan + i);
		else printf ("\n|%.49s|\n", pertanyaan + i);
		i += 49;
	}
} 

//Penghargaan untuk user yang bisa mengkonsumsi air secara ideal dalam satu hari
//Implementasi penggunaan ASCII ART dari modul 4 dengan topik do,while,for,switch
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
