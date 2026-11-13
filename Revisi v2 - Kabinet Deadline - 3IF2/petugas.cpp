#include "data.hpp"

bool LoginPetugas() {
    int percobaan = 0;
    while (percobaan < MAKS_LOGIN) {
        string username, password;
        cout << "\nInput username: ";
        getline(cin, username);
        cout << "Input password: ";
        getline(cin, password);

        if (username == USERNAME_PETUGAS && password == PASSWORD_PETUGAS) {
            cout << "Login berhasil\n";
            cout << string(50, '=');
            return true;}

        cout << "Username atau password salah\n";
        percobaan++;}

    cout << "Login gagal 3 kali, akses ditolak\n";
    cout << string(50, '=');
    return false;}

void UbahStatus(vector<Laporan>& database) {
    if (database.size() == 0) {
        cout << "\nBelum ada data laporan\n";
        cout << string(50, '=');
        return;}

    TampilkanSemuaLaporan(database);

    int jenis = ValidasiAngka("\nInput jenis (1-4): ", 1, 4);

    string kelurahan, alamat;
    while (true) {
        cout << "Input kelurahan: ";
        getline(cin, kelurahan);
        cout << "Input alamat: ";
        getline(cin, alamat);
        if (kelurahan.empty() || alamat.empty()) {
            cout << "Inputan tidak boleh kosong\n";
            cout << string(50, '=');
            continue;}
        break;}

    for (size_t i = 0; i < database.size(); i++) {
        if (database[i].jenis == jenis &&
            HurufKecil(database[i].kelurahan) == HurufKecil(kelurahan) &&
            HurufKecil(database[i].alamat) == HurufKecil(alamat)) {

            string pilihan;
            while (true) {
                cout << "Input status (Diproses/Selesai): ";
                getline(cin, pilihan);

                pilihan = NamaStatus(pilihan);
                if (pilihan != "") break;

                cout << "Inputan harus Diproses atau Selesai\n";}

            database[i].status = pilihan;
            cout << "Status berhasil diubah\n";
            cout << string(50, '=');
            return;
        }}
    cout << "Laporan tidak ditemukan\n";
    cout << string(50, '=');}

void RekapStatus(const vector<Laporan>& database) {
    int baru = 0, diproses = 0, selesai = 0;
    for (size_t i = 0; i < database.size(); i++) {
        if (database[i].status == "Baru") baru++;
        else if (database[i].status == "Diproses") diproses++;
        else if (database[i].status == "Selesai") selesai++;}
        
    cout << "\nRekapitulasi Status Laporan\n"
         << "Baru     : " << baru << "\n"
         << "Diproses : " << diproses << "\n"
         << "Selesai  : " << selesai << "\n"
         << string(50, '=');}

void MenuPetugas(vector<Laporan>& database) {
    int pilihan;
    do {
        cout << "\nMenu Petugas:\n"
             << "1. Melihat Laporan Warga\n"
             << "2. Memperbarui Status Laporan\n"
             << "3. Kembali\n";
        pilihan = ValidasiAngka("Input Pilihan: ", 1, 3);
        cout << string(50, '=');

        switch (pilihan) {
            case 1:
                TampilkanSemuaLaporan(database);
                break;
            case 2:
                UbahStatus(database);
                break;
            case 3:
                break;
        }} while (pilihan != 3);}