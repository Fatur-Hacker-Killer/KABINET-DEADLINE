#include "data.hpp"

//Menu pilih role
void MenuUtama(vector<Laporan>& database) {
    int pilihan;
    do {cout << "\nPilih Role\n"
             << "1. Masyarakat\n"
             << "2. Petugas\n"
             << "3. Keluar\n";
        pilihan = ValidasiAngka("Input Pilihan: ", 1, 3);
        cout << string(50, '=');

        switch (pilihan) {
            case 1:
                MenuMasyarakat(database);
                break;
            case 2:
                if (LoginPetugas()) {
                    MenuPetugas(database);}
                break;
            case 3:
                cout << "\nProgram selesai.";
                break;
        }} while (pilihan != 3);}

int main() {
    vector<Laporan> database;
    MenuUtama(database);
    return 0;}