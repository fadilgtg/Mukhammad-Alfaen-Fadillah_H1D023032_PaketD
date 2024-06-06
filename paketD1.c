#include <stdio.h>

//Deklarasi struktur khs
typedef struct {
    int nim;
    float ip;
} khs;

//Buat fungsi update IP Mahasiswa
void updateIP(khs *data, float newIP) {
    data->ip = newIP;
}

//Buat fungsi cetak KHS
void printKHS(khs *data) {
    printf("NIM: %d\n", data->nim);
    printf("IP: %.2f\n", data->ip);
}

//Buat main program 
int main() {
    khs mahasiswa = { 24052, 3.85};

    //Cetak KHS sebelum perubahan
    printf("Sebelum IP diperbarui:\n");
    printKHS(&mahasiswa);
    printf("\n");

    //Ubah IP Mahasiswa
    updateIP(&mahasiswa, 4.00);

    //Cetak KHS setelah perubahan
    printf("Setelah IP diperbarui:\n");
    printKHS(&mahasiswa);

    return 0;
}
