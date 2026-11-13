#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Laporan {
    int jenis;
    string kelurahan;
    string alamat;
    string deskripsi;
    string status;
};

extern vector<Laporan>database;

struct JenisLaporan{
    string nama;
};

//login petugas
const int MAKS_LOGIN = 3; 
const string USERNAME_PETUGAS = "Admin";
const string PASSWORD_PETUGAS = "ABC123";

const int JUMLAH_JENIS = 4;
const JenisLaporan Daftar_JENIS[JUMLAH_JENIS] = {
    {"Jalan Rusak atau Berlubang"},
    {"Drainase Rusak atau Tersumbat"},
    {"Lampu Penerangan Jalan Mati"},
    {"Kerusakan Fasilitas Umum (Jembatan / trotoar)"}
};

//validasi
int ValidasiAngka(const string& pesan, int minimum, int maksimum);
string NamaJenis(int jenis);
string NamaStatus(const string& pilihan);   
string HurufKecil(string teks);

//Masyarakat
void BuatLaporan(vector<Laporan>& database);
void TampilkanSemuaLaporan(const vector<Laporan>& database); //berlaku petugas dan masyarakat
void CekLaporanSpesifik(const vector<Laporan>& database);
void MenuMasyarakat(vector<Laporan>& database);

//petugas
bool LoginPetugas();
void UbahStatus(vector<Laporan>& database);
void RekapStatus(const vector<Laporan>& database);
void MenuPetugas(vector<Laporan>& database);

//entry point
void MenuUtama(vector<Laporan>& database);

#endif