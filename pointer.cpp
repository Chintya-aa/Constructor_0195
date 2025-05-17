#include <iostream>
#include <string>
using namespace std;

class Dosen; 
class Staff; 

class Mahasiswa 
{
private:
    string nama;
    string NIM;
    float nilai;
public:
    Mahasiswa(string nama, string NIM) {
        this->nama = nama;
        this->NIM = NIM;
        this->nilai = 0;
    }
    void tampil() {
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

    void beriNilai(Mahasiswa* m, float nilai) {
        m->nilai = nilai;
    }
    void tampil() {
        cout << "Dosen: " << nama << " (NIDN: " << NIDN << "), Pangkat: " << pangkat << ", Gaji: " << gaji << endl;
    }

    friend class Staff;
    friend void lihatGajiDosen(Dosen* d);
};

class Staff 
{
private:
    string nama;
    string idStaff;
    float gaji;
public:
    Staff(string nama, string idStaff, float gaji) 
    {
        this->nama = nama;
        this->idStaff = idStaff;
        this->gaji = gaji;
    }
    // Staff mengubah pangkat dosen lewat pointer
    void ubahPangkat(Dosen* d, string pangkatBaru) 
    {
        d->pangkat = pangkatBaru;
    }
    void tampil() 
    {
        cout << "Staff: " << nama << " (ID: " << idStaff << "), Gaji: " << gaji << endl;
    }

    friend void lihatGajiStaff(Staff* s);
};

// Friend function untuk lihat gaji dosen
void lihatGajiDosen(Dosen* d) {
    cout << "Gaji Dosen " << d->nama << ": Rp " << d->gaji << endl;
}

void lihatGajiStaff(Staff* s) {
    cout << "Gaji Staff " << s->nama << ": Rp " << s->gaji << endl;
}

int main() 
{
    Mahasiswa* mhs = new Mahasiswa("Budi", "12345");
    Dosen* dsn = new Dosen("Pak Ahmad", "D001", "Lektor", 8000000);
    Staff* stf = new Staff("Bu Sari", "S001", 5000000);

    cout << "=== Data Awal ===" << endl;
    mhs->tampil();
    dsn->tampil();
    stf->tampil();

    cout << "\n=== Dosen Memberi Nilai ke Mahasiswa ===" << endl;
    dsn->beriNilai(mhs, 85.5);
    mhs->tampil();

    cout << "\n=== Staff Mengubah Pangkat Dosen ===" << endl;
    stf->ubahPangkat(dsn, "Profesor");
    dsn->tampil();

    cout << "\n=== Lihat Gaji Dosen dan Staff (Friend Function) ===" << endl;
    lihatGajiDosen(dsn);
    lihatGajiStaff(stf);

    delete mhs;
    delete dsn;
    delete stf;

    return 0;
}
