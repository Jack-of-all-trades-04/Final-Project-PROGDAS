# Final-Project-PROGDAS
Program yang akan dibuat adalah program yang terdiri dari 2 fitur yaitu Kalkulator Penggunaan Air dan Survei/Kuesioner Mandiri untuk menguji kelayakan air hal ini sejalan
dengan SDG nomor 6 "Sanitasi dan air bersih".

## Rubrik Penilaian
![Page 1](https://github.com/user-attachments/assets/7b519984-ff03-4bb7-b787-620388d206c6)
![Page 2](https://github.com/user-attachments/assets/4d19a2ce-37da-424b-84b0-35daa9526348)

## Ketentuan
Submission is through EMAS with the following file:
1. Final Program with a .c extension. If separate header files exist, all programs must be
zipped into one file.
2. Program executable file (.exe).
3. A Github link (URL is written inside the report). It should be clear who did what
4. Video presentation in Youtube, unlisted. The explation should follow the order of the rubric
(see Section III). Duration: 5 – 8 minutes (URL is written inside the report).
5. A report in PDF format. Generally, the report should use font Arial 11 pt, single space, no
space before & after paragraph, except the flowchart and source code. The report should
include all of this elements:
- Pg 1: Cover
- Pg 2: Video presentation URL & Github URL
- Pg 3: Task division for each group member written in detail & the username in github.
Everyone should have clear contribution in making the program, i.e. which block, shich
function.
- Pg 4: A brief explanation of the program's theme (no more than 1 page)
- Pg 5 etc: List of variables, arrays, structs, etc., and their uses.
- List of functions and their uses.
- Main program Flowchart. Arial narrow, 9 pt
- Each function flowchart. Arial narrow, 9 pt
- A copy of the source code with the following specifications: font: Lucida Console, 10pt,
single space, no space before or after paragraphs, etc.
- Screen capture of the running program (not the code), for all cases.

## Ringkasan Data Variabel
![Survei Kelayakan Air](https://github.com/user-attachments/assets/6c3d8239-fabd-4d31-8a90-6c6a69a9b877)
![Penggunaan Air](https://github.com/user-attachments/assets/3040daf2-322d-42d4-a197-4cd64ba2fbe6)

## Job Desc
- Novan : Kumpulin Data Referensi, Membuat framework template
- Nabil : 
- Ferdy : Menambahkan fitur pada program, debugging code, masukkan pada framework template
- Alam  : 

## Workflow Program
![Flowchart Program](https://github.com/user-attachments/assets/35a26297-1d09-40ec-9795-56559d85fd75)

## Penjelasan Workflow program
1. Program menghitung penggunaan air dalam kehidupan sehari-hari meliputi kegiatan berikut ini:
- minum
- mandi
- mencuci piring
- mencuci baju
- ibadah
- menyiram tanaman
- dan kegiatan lainnya

2.Program menentukan kelayakan air meliput beberapa indeks sebagai berikut:
- PH air
- Warna air
- kekeruhan air
- Bau air
- Rasa air
- Jumlah coliform
- Nilai endapan

Flow program untuk kelayakan air
- Tanya User untuk memilih di antara 2 opsi yaitu kelayakan air atau penggunaan air
- Pilihan pertama akan bertanya tentang kelayakan air
- Apabila user memilih pilihan 1, maka mendapat pertanyaan tentang PH air berupa kadar PH kurang dari 6.5 atau lebih dari 8.5
- Bila memenuhi salah satu maka skor kelayakan air bertambah 5
- Lalu, user akan mendapatkan pertanyaan tentang nilai kekeruhan air, bila lebih dari 5 maka skor kelayakan air bertambah 5
- Kemudian, user akan mendapatkan pertanyaan tentang skor bau dari air, nilai skor kelayakan air akan bertambah sesuai dengan nilai bau    dari air
- Selanjutnya, user akan mendapatkan pertanyaan tentang rasa dari air, nilai skor kelayakan air akan bertambah sesuai dengan nilai rasa   dari air
- Setelah itu, user akan mendapatkan pertanyaan tentang skor endapan air, nilai skor kelayakan air akan bertambah sesuai dengan nilai endapan dari air
- Terakhir, user akan mendapatkan pertanyaan tentang jumlah bakteri, bila jumlah bakteri lebih dari 50 maka skor kelayakan air akan bertambah 5

flow program untuk penggunaan air
- Tanya user konsumsi air minum untuk satu hari lalu total penggunaan air akan bertambah
- Lalu user akan ditanya tentang konsumsi air untuk mandi kemudian akan membuat total penggunaan air ditambah sebelumnya
- Kemudian user akan mendapat pertanyaan penggunaan air untuk mencuci piring lalu membuat total penggunaan air ditambah sebelumnya
- Selanjutnya user akan ditanya tentang penggunaan air untuk mencuci baju kemudian akan ditambah total penggunaan air sebelumnya
- Setelah itu user juga mendapat pertanyaan penggunaan air untuk ibadah dan menyiram tanaman hingga mendapat total penggunaan air satu hari
