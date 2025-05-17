#include <iostream>
#include <string>

using namespace std;

class Mahasiswa; // Kedekatan dengan class Dosen

class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai; // Attribut bersifat privat

public:
    Mahasiswa(string n, string nim) : nama(n), NIM(nim), nilai(0) {}

    // Method untuk menampilkan nilai
    void tampilkanNilai() {
        cout << "Nilai " << nama << ": " << nilai << endl;
    }

    // Access value using friend function
    friend void beriNilai(Mahasiswa& m, float nilai);
};