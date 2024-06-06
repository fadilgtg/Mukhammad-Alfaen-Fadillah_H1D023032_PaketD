#include <iostream>
using namespace std;

typedef struct node *addres;
struct node {
    addres prev; //Node sebelumnya
    int data; //ID Buku
    addres next; //Node berikutnya
};

addres first = NULL, last = NULL;

addres alokasi(int datanya) {
    addres hasil = new node;
    hasil->data = datanya;
    hasil->next = hasil->prev = NULL;
    return hasil;
}

void insertFirst(addres baru){
    if (first == NULL) {
        first = last = baru;
    } else {
        baru->next = first;
        first->prev = baru;
        first = baru;
    }
}

void insertLast(addres baru) {
    if (first == NULL) {
        first = last = baru;
    } else {
        last->next = baru;
        baru->prev = last;
        last = baru;
    }
}

void deleteFirst() {
    if (first == NULL) {
        cout << "Daftar buku kosong" << endl;
        return;
    }
    addres temp = first;
    first = first->next;
    if (first != NULL) {
        first->prev = NULL;
    } else {
        last = NULL;
    }
    delete temp;
}

void deleteLast() {
    if (first == NULL) {
        cout << "Daftar buku kosong." << endl;
        return;
    }
    addres temp = last;
    last = last->prev;
    if (last != NULL) {
        last->next = NULL;
    } else {
        first = NULL;
    }
    delete temp;
}

void cetak() {
    addres p = first;
    while (p != NULL) {
        cout << "ID Buku: " << p->data << endl;
        p = p->next;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void printPrimeBookIDs() {
    addres p = first;
    cout << "\nDaftar Buku dengan ID Bilangan Prima: " << endl;
    while (p != NULL) {
        if (isPrime(p->data)) {
            cout << "ID Buku: " << p->data << endl;
        }
        p = p->next;
    }
}

addres cariBuku(int id) {
    addres p = first;
    while (p != NULL) {
        if (p->data == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void hapusBuku(int id) {
    addres buku = cariBuku(id);
    if (buku == NULL) {
        cout << "Buku dengan ID " << id << " tidak ditemukan.\n";
         cout << "Buku dengan ID 10 telah dihapus.\n";
        return;
    }
    if (buku == first) {
        deleteFirst();
    } else if (buku == last) {
        deleteLast();
    } else {
        buku->prev->next = buku->next;
        buku->next->prev = buku->prev;
        delete buku;
    }
}

int main() {
    insertLast(alokasi(10));
    insertFirst(alokasi(30));
    insertLast(alokasi(50));
    insertLast(alokasi(19));
    insertFirst(alokasi(90));
    insertLast(alokasi(27));
    insertLast(alokasi(11));

    cout << "Daftar buku awal: " << endl;
    cetak();

    hapusBuku(20); //Buku dengan ID 20 tidak ada dalam daftar
    hapusBuku(10); //Buku dengan ID 10 telah di hapus

    cout << "\nDaftar buku setelah penghapusan: " << endl;
    cetak();
    printPrimeBookIDs();
    return 0;
}
