#include <iostream>
using namespace std;

int main() {
    int bilanganpertama, bilangankedua;
    int opsi;
    
cout<<"Nama : Dafi Umar Faruq" << endl;
cout<<"NIM  : 32602400068" << endl;
cout << endl;

    // Meminta pengguna untuk memasukkan bilangan pertama
    cout << "Masukkan bilangan pertama: ";
    cin >> bilanganpertama;

    // Menampilkan menu pilihan
    cout << "\nPilih salah satu opsi berikut:\n";
    cout << "1. Masukkan bilangan kedua yang lebih kecil dari bilangan pertama\n";
    cout << "2. Masukkan bilangan kedua yang lebih besar dari bilangan pertama\n";
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> opsi;

    // Mengecek apakah pilihan valid
    if (opsi == 1 || opsi == 2) {
        // Meminta pengguna untuk memasukkan bilangan kedua
        cout << "Masukkan bilangan kedua: ";
        cin >> bilangankedua;

        if (opsi == 1) {
            // Memeriksa apakah bilangan kedua lebih kecil dari bilangan pertama
            if (bilangankedua < bilanganpertama) {
                cout << "Bilangan kedua adalah: " << bilangankedua << endl;
                cout << "Nilai sudah sesuai.\n";
            } else {
                cout << "Kesalahan: Bilangan kedua tidak lebih kecil dari bilangan pertama.\n";
            }
        } else if (opsi == 2) {
            // Memeriksa apakah bilangan kedua lebih besar dari bilangan pertama
            if (bilangankedua > bilanganpertama) {
                cout << "Bilangan kedua adalah: " << bilangankedua << endl;
                cout << "Nilai sudah sesuai.\n";
            } else {
                cout << "Kesalahan: Bilangan kedua tidak lebih besar dari bilangan pertama.\n";
            }
        }
    } else {
        // Jika pilihan menu tidak valid
        cout << "Kesalahan: Pilihan tidak valid. Silakan pilih 1 atau 2.\n";
    }

return 0;
}