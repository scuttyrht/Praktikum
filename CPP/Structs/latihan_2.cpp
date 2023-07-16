#include <iostream>
using namespace std;

struct pegawai
{
    string nama;
    int jam_kerja;
    int gaji_harian;
};

int getGajiHarian(int jam_kerja) {
    int gaji_perjam = 6000, gaji_harian;
    if (jam_kerja > 40) {
        gaji_harian = 40 * gaji_perjam + (jam_kerja - 40) * 3 * gaji_perjam;
        return gaji_harian;
    } else {
        gaji_harian = jam_kerja * gaji_perjam;
        return gaji_harian;
    }
}

int main(int argc, char const *argv[])
{
    pegawai peg;

    cout << "Masukkan nama pegawai\t: "; cin >> peg.nama;
    cout << "Masukkan jmlh jam kerja\t: "; cin >> peg.jam_kerja;
    peg.gaji_harian = getGajiHarian(peg.jam_kerja);
    cout << "Gaji harian " << peg.nama << ": " << peg.gaji_harian << endl;
    system("PAUSE");
    return 0;
}