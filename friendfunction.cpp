#include <iostream>
#include <string>
using namespace std;

class Dosen;
class Staff;
class Universitas;

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string nama, string NIM)
    {
        this->nama = nama;
        this->NIM = NIM;
        this->nilai = 0.0;
    }

    void tampilInfo()
    {
        cout << "Mahasiswa: " << nama << " (NIM: " << NIM << "), Nilai: " << nilai << endl;
    }

    friend class Dosen;
};

class Dosen
{
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

    void beriNilai(Mahasiswa *m, float nilai)
    {
        m->nilai = nilai;
    }

    void tampilInfo()
    {
        cout << "Dosen: " << nama << " (NIDN: " << NIDN << "), Pangkat: " << pangkat << ", Gaji: " << gaji << endl;
    }

    friend class Staff;
    friend void lihatGajiDosen(Dosen *d);
};

class Staff
{
private:
    string nama;
    string id;
    float gaji;

public:
    Staff(string nama, string id, float gaji)
    {
        this->nama = nama;
        this->id = id;
        this->gaji = gaji;
    }

    void ubahPangkat(Dosen *d, string pangkatBaru)
    {
        d->pangkat = pangkatBaru;
        cout << "Pangkat Dosen " << d->nama << " telah diubah menjadi " << pangkatBaru << endl;
    }

    void tampilInfo()
    {
        cout << "Staff: " << nama << " (ID: " << id << "), Gaji: " << gaji << endl;
    }

    friend void lihatGajiStaff(Staff *s);

    
