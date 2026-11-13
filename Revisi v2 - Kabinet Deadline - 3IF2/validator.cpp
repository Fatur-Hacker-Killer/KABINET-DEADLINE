#include "data.hpp"
#include <cctype>

// Mengulang sampai pengguna mengetik angka dalam rentang yang benar.
int ValidasiAngka(const string& pesan, int minimum, int maksimum) {
    while (true) {
        cout << pesan;
        string teks;
        getline(cin, teks);

        bool bukanAngka = teks.empty() || teks.size() > 9 ||
                          teks.find_first_not_of("0123456789") != string::npos;
        if (bukanAngka) {
            cout << "Inputan harus berupa angka " << minimum 
                 << "-" << maksimum << " dan tidak boleh teks.\n";
            continue;}

        int nilai = stoi(teks);
        if (nilai < minimum || nilai > maksimum) {
            cout << "Inputan harus berupa angka "
                 << minimum << "-" << maksimum << ".\n";
            continue;}
        return nilai;}}

// Mengubah angka jenis (1-4) menjadi nama jenis.
string NamaJenis(int jenis) {
    const JenisLaporan daftar[JUMLAH_JENIS] = {
        {"Jalan rusak atau berlubang"},
        {"Drainase rusak atau tersumbat"},
        {"Lampu penerangan jalan mati"},
        {"Kerusakan fasilitas umum (jembatan/trotoar)"}
    };
    if (jenis < 1 || jenis > 4) return "";
    return daftar[jenis - 1].nama;}

string NamaStatus(const string& pilihan) {
    if (HurufKecil(pilihan) == "diproses") return "Diproses";
    if (HurufKecil(pilihan) == "selesai") return "Selesai";
    return "";}

// Mengubah seluruh teks menjadi huruf kecil.
string HurufKecil(string teks) {
    for (size_t i = 0; i < teks.size(); i++) {
        teks[i] = (char)tolower((unsigned char)teks[i]);}
    return teks;}
