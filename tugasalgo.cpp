#include <iostream>
#include <iomanip>

using namespace std;

struct Roti {
    string nama;
    string kode;
    double harga;
};

void tampildata(Roti* ptrRoti, int jumlah) {
    cout << "Toko Roti Mang Aung:\n";
    cout << setfill('=') << setw(40) << " " << endl;
    cout << left << setfill(' ') << setw(5) << "No" << setw(20) << "Nama Roti" << setw(10) << "Kode" << setw(10) << "Harga" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(5) << i + 1 << setw(20) 
        << (*(ptrRoti + i)).nama << setw(10) 
        << (*(ptrRoti + i)).kode << setw(10) 
        << (*(ptrRoti + i)).harga << endl;
    }
    cout << setfill('=') << setw(40) << " " << endl;
}

void carirotinama(Roti daftar[], int jumlah, string namacari, bool terurut) {
    if (!terurut) {
        cout << "urutin dulu datanya BOY" << endl;
        return;
    }
    cout << "mo nyari roti yang mana? ";
    cin.ignore();
    getline(cin, namacari);

    int awal = 0, akhir = jumlah - 1, tengah;
    bool ketemu = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;

        if (daftar[tengah].nama == namacari) {
            ketemu = true;
            cout << "Nama  : " << daftar[tengah].nama << endl;
            cout << "Kode  : " << daftar[tengah].kode << endl;
            cout << "Harga : Rp" << daftar[tengah].harga << endl;
            return;
        } else if (daftar[tengah].nama < namacari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    cout << "GAADA " << namacari << endl;
}

void carirotikode(Roti daftar[], int jumlah, string kodecari) {
    bool ketemu = false;
    cout << "Masukkan kode roti yang dicari: ";
        cin.ignore();
        getline(cin, kodecari);

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].kode == kodecari) {
            ketemu = true;
            cout << "Nama  : " << daftar[i].nama << endl;
            cout << "Kode  : " << daftar[i].kode << endl;
            cout << "Harga : Rp" << daftar[i].harga << endl;
            break;
        }
    }

    if (!ketemu) {
        cout << "MANA ADA CODE " << kodecari << endl;
    }
}

int partitionnama(Roti daftar[], int low, int high) {
    string pivot = daftar[high].nama;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (daftar[j].nama < pivot) {
            i++;
            swap(daftar[i], daftar[j]);
        }
    }
    swap(daftar[i + 1], daftar[high]);
    return i + 1;
}
void quicknama(Roti daftar[], int low, int high) {
    if (low < high) {
        int pi = partitionnama(daftar, low, high);
        quicknama(daftar, low, pi - 1);
        quicknama(daftar, pi + 1, high);
    }
}

int partitionharga(Roti daftar[], int low, int high) {
    double pivot = daftar[high].harga;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (daftar[j].harga < pivot) {
            i++;
            swap(daftar[i], daftar[j]);
        }
    }
    swap(daftar[i + 1], daftar[high]);
    return (i + 1);
}
void quickharga(Roti daftar[], int low, int high) {
    if (low < high) {
        int pi = partitionharga(daftar, low, high); 
        quickharga(daftar, low, pi - 1);  
        quickharga(daftar, pi + 1, high);
    }
}

void bubblesort(Roti daftar[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (daftar[j].harga < daftar[j + 1].harga) {
                swap(daftar[j], daftar[j + 1]);
            }
        }
    }
}

int main() {
    int pilihan;
    string kodecari,namacari;
    bool terurut = false;

    Roti daftarRoti[] = {
        {"Roti pedas gacor", "R001", 10000},
        {"Roti pedas ambyar", "R002", 7000},
        {"Roti kematian", "R003", 15000},
        {"Roti acid", "R004", 11000},
        {"Roti pedas lvl dewa", "R005", 13000}
    };
    int jumlah = sizeof(daftarRoti) / sizeof(daftarRoti[0]);

  do 
  {     cout << "Menu pilihan " << endl;
        cout << "1. tampilkan daftar roti " << endl;
        cout << "2. cari nama roti " << endl;
        cout << "3. cari kode roti " << endl;
        cout << "4. sort harga roti (asc)" << endl;
        cout << "5. sort harga roti (desc)" << endl;
        cout << "6. sort nama" << endl;
        cout << "7. keluar"<< endl;
        cout << "Masukkan pilihan : "; cin >> pilihan;
    
    switch (pilihan)
  {
  case 1:
    tampildata(daftarRoti, 5);
    break;
    case 2:
        carirotinama(daftarRoti, jumlah, namacari, terurut);
    break;
    case 3: 
        carirotikode(daftarRoti, jumlah, kodecari);
        break;
    case 4:
        quickharga(daftarRoti, 0, jumlah - 1);
        terurut = true;
        cout << "Data berhasil diurutkan" << endl;
        tampildata(daftarRoti,5);
    break;
    case 5:
        bubblesort(daftarRoti, 5);
        cout << "Data berhasil diurutkan secara descending berdasarkan harga!\n";
        tampildata(daftarRoti, 5);
    break;
    case 6:
    quicknama(daftarRoti, 0, jumlah - 1);
    terurut = true;
    cout << "Data berhasil diurutkan" << endl;
    tampildata(daftarRoti,5);
    break;
  default:
  cout << " pilihan tidak valid"<< endl;
    break;
  }
    
  } while (pilihan != 7);
  cout << "Tanya doang kaga beli" << endl;
  return 0;
}