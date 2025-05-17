#include <iostream>
#include <string>

using namespace std;

class Mahasiswa;

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string nim) : nama(n), NIM(nim), nilai(0) {}
    void tampilkanNilai()
    {
        cout << "Nilai " << nama << ": " << nilai << endl;
    }

    friend void beriNilai(Mahasiswa &m, float nilai);
};

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string n, string id, string p, float g) : nama(n), NIDN(id), pangkat(p), gaji(g) {}
    friend void beriNilai(Mahasiswa &m, float nilai);
    friend void ubahPangkat(Dosen *d, string pangkatBaru);
};

class Universitas
{
public:
    void lihatGajiDosen(Dosen *d)
    {
        cout << "Gaji Dosen " << d->nama << ": " << d->gaji << endl;
    }
};

void beriNilai(Mahasiswa &m, float n)
{
    m.nilai = n;
}

void ubahPangkat(Dosen *d, string pangkatBaru)
{
    d->pangkat = pangkatBaru;
}

int main() 
{
    Dosen dosen("Dr. Ali", "123456", "Lektor", 5000000);
    Mahasiswa mahasiswa("Budi", "A123");
    beriNilai(mahasiswa, 85.0);
    mahasiswa.tampilkanNilai();
    ubahPangkat(&dosen, "Profesor");
    Universitas univ;
    univ.lihatGajiDosen(&dosen);
    return 0;
}