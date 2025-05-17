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

    void lihatGajiDosen(Dosen *d)
    {
        cout << "Gaji Dosen " << d->nama << ": Rp " << d->gaji << endl;
    }

    void lihatGajiStaff(Staff *s)
    {
        cout << "Gaji Staff " << s->nama << ": Rp " << s->gaji << endl;
    }

    class Universitas
    {
    private:
        string nama;

    public:
        Universitas(string nama)
        {
            this->nama = nama;
        }

        void tampilkanGaji(Dosen *d, Staff *s)
        {
            cout << "=== Informasi Gaji di " << nama << " ===" << endl;
            lihatGajiDosen(d);
            lihatGajiStaff(s);
        }
    };

    int main() 
    {
    Mahasiswa mhs("Budi Santoso", "12345");
    Dosen dsn("Dr. Ahmad", "D001", "Lektor", 8000000);
    Staff stf("Siti", "S001", 5000000);
    Universitas univ("Universitas XYZ");
    
    cout << "=== Data Awal ===" << endl;
    mhs.tampilInfo();
    dsn.tampilInfo();
    stf.tampilInfo();
    
    cout << "\n=== Setelah Dosen Memberi Nilai ===" << endl;
    dsn.beriNilai(&mhs, 85.5);
    mhs.tampilInfo();
    
    cout << "\n=== Setelah Staff Mengubah Pangkat Dosen ===" << endl;
    stf.ubahPangkat(&dsn, "Profesor");
    dsn.tampilInfo();
    
    cout << "\n=== Akses Gaji Melalui Friend Function ===" << endl;
    univ.tampilkanGaji(&dsn, &stf);
    
    return 0;
}
