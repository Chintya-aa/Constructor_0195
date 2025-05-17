#include <iostream>
#include <string>
using namespace std;

class Dosen;
class Staff;
class Universitas;

class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;
    
public:
    Mahasiswa(string nama, string NIM) {
        this->nama = nama;
        this->NIM = NIM;
        this->nilai = 0.0;
    }
    
    void tampilInfo() {
        cout << "Mahasiswa: " << nama << " (NIM: " << NIM << "), Nilai: " << nilai << endl;
    }
    
    friend class Dosen;
};

class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;
    
public:
    Dosen(string nama, string NIDN, string pangkat, float gaji) 
    {
        this->nama = nama;
        this->NIDN = NIDN;
        this->pangkat = pangkat;
        this->gaji = gaji;
    }
};

