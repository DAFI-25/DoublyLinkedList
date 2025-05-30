#include <iostream>
using namespace std;


int main(){

    int BilanganPertama, BilanganKedua, opsi;

    cout <<"Pre Test Dasar Pemograman dan Algoritma" << endl;
    cout << "Masukan Bilangan Awal\t: ";
    cin >> BilanganPertama;
    cout << "Bilangan Awal Adalah\t: " << BilanganPertama << "\n\n\n";

    cout << "Masukan Pilihan Menu\n";
    cout << "1. Masukan Bilangan Lebih Kecil\n";
    cout << "2. Masukan Bilangan Lebih Besar\n";
    cout << "Masukan pilihan anda\t:" ;
    cin >> opsi;

    if (opsi == 1){
        cout << "Anda memilih menu '1. Masukan Bilangan Lebih Kecil'" << endl;
        cout << "Masukan Bilangan Kedua\t: ";
        cin >> BilanganKedua;

        cout << "Bilangan awal adalah\t: " << BilanganPertama << endl;
        cout << "Bilangan akhir adalah\t:" << BilanganKedua << endl;
        if (BilanganPertama > BilanganKedua){
            cout << "Bilangan sudah sesuai" << endl;
        } else cout << "Bilangan tidak sesuai" << endl;

    } else  if (opsi == 2){
        cout << "Anda memilih menu '2. Masukan Bilangan Lebih Besar'" << endl;
        cout << "Masukan bilangan kedua : ";
        cin >> BilanganKedua ;

        cout << "Bilangan awal adalah\t: " << BilanganPertama << endl;
        cout << "Bilangan akhir adalah\t: " << BilanganKedua << endl;
        if (BilanganKedua > BilanganPertama){
            cout << "Bilangan sudah sesuai" << endl;
        } else cout << "Bilangan tidak sesuai" << endl;

    } else cout << "Pilihan anda tidak ada dimenu" << endl;

    return 0;
}