#include "data.hpp"

void MenuMasyarakat(vector<Laporan>& database) {
    int pilihan;
    do {cout << "\nMenu Masyarakat:\n"
             << "1. Buat Laporan\n"
             << "2. Lihat Laporan\n"
             << "3. Kembali\n";
        pilihan = ValidasiAngka("Input Pilihan: ", 1, 3);
        cout << string(50, '=') << "\n";

        switch (pilihan) {
            case 1:
                BuatLaporan(database);
                break;
            case 2: {
                if (database.size() == 0) {
                    cout << "Belum ada data laporan\n";
                    cout << string(50, '=');
                    break;}
                TampilkanSemuaLaporan(database);

                int cari = ValidasiAngka(
                    "\nCari laporan secara spesifik? (1. Ya, 2. Tidak): ", 1, 2);
                if (cari == 1) {
                    CekLaporanSpesifik(database);
                }
                break;}
            case 3:
                break;
            }} while (pilihan != 3);}

void BuatLaporan(vector<Laporan>& database) {
    cout << "Jenis kerusakan:\n";
    for (int i = 1; i <= JUMLAH_JENIS; i++) {
        cout << i << ". " << NamaJenis(i) << "\n";}
        
    int jenis = ValidasiAngka("Input jenis (1-4): ", 1, 4);

    string kelurahan, alamat, deskripsi;
    while (true) {
        cout << "Input kelurahan: ";
        getline(cin, kelurahan);
        cout << "Input alamat: ";
        getline(cin, alamat);
        cout << "Input deskripsi singkat: ";
        getline(cin, deskripsi);
        if (kelurahan.empty() || alamat.empty()
            || deskripsi.empty()) {
            cout << "Inputan tidak boleh kosong\n";
            continue;}
        break;}

    Laporan baru;
    baru.jenis = jenis;
    baru.kelurahan = kelurahan;
    baru.alamat = alamat;
    baru.deskripsi = deskripsi;
    baru.status = "Baru";
    database.push_back(baru);

    cout << "Laporan berhasil ditambahkan\n";
    cout << string(50, '=');
}

void CekLaporanSpesifik(const vector<Laporan>& database) {
    string kelurahan, status;
    while (true) {
        cout << "Input kelurahan: ";
        getline(cin, kelurahan);
        cout << "Input status kerusakan (Baru/Diproses/Selesai): ";
        getline(cin, status);
        if (kelurahan.empty() || status.empty()) {
            cout << "Inputan tidak boleh kosong\n";
            continue;}
        break;}

    bool ditemukan = false;
    for (size_t i = 0; i < database.size(); i++) {
        if (HurufKecil(database[i].kelurahan) == HurufKecil(kelurahan) &&
            HurufKecil(database[i].status) == HurufKecil(status)) {
            cout << string(50, '=') 
                 << "\nJenis     : " << NamaJenis(database[i].jenis) << "\n"
                 << "Kelurahan : " << database[i].kelurahan << "\n"
                 << "Alamat    : " << database[i].alamat << "\n"
                 << "Deskripsi : " << database[i].deskripsi << "\n"
                 << "Status    : " << database[i].status << "\n"
                 << string(50, '=') << "\n";
            ditemukan = true;
        }}
    if (!ditemukan) {
        cout << "Laporan tidak ditemukan\n";
        cout << string(50, '=');
}}

void TampilkanSemuaLaporan(const vector<Laporan>& database) {
    if (database.size() == 0) {
        cout << "\nBelum ada data laporan\n";
        cout << string(50, '=');
        return;}

    for (size_t i = 0; i < database.size(); i++) {
        cout << "\nLaporan " << i + 1 << "\n"
             << "Jenis     : " << NamaJenis(database[i].jenis) << "\n"
             << "Kelurahan : " << database[i].kelurahan << "\n"
             << "Alamat    : " << database[i].alamat << "\n"
             << "Deskripsi : " << database[i].deskripsi << "\n"
             << "Status    : " << database[i].status << "\n"
             << string(50, '=');}
    RekapStatus(database);}