#include <iostream>

using namespace std;

struct Roti
{
    string kode_roti;
    string nama_roti;
    int harga_roti;
}; 

Roti roti[] = {
    {"R001", "Roti Tawar", 7000},
    {"R002", "Roti Manis", 5000},
    {"R003", "Roti Coklat", 20000},
    {"R004", "Roti Keju", 12000},
    {"R005", "Roti Bakar", 10000}
};

void tampilan_roti(){
    system("cls");
    
    Roti *ptr_roti = roti;

    int n = sizeof(roti) / sizeof(*roti);
    cout << "===========================================" << endl;
    cout << "Nama\t\t Kode\t\t Harga" << endl;
    cout << "===========================================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (ptr_roti+i)->nama_roti << "\t" << (ptr_roti+i)->kode_roti << "\t\t" << (ptr_roti+i)->harga_roti << endl;
    }
    cout << "===========================================" <<endl;
}

void sequential(){
    string kode;
    cout << "Masukkan kode roti: ";
    cin >> kode;
    int n = sizeof(roti) / sizeof(*roti);
    for (int i = 0; i < n; i++) {
        if (roti[i].kode_roti == kode) {
            cout << "Roti ditemukan: " << roti[i].nama_roti << " - " << roti[i].harga_roti << endl;
            return;
        }
    }
    cout << "Roti tidak ditemukan." << endl;
}

void bubble_sort() {
    int n = sizeof(roti) / sizeof(*roti);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (roti[j].harga_roti < roti[j + 1].harga_roti) {
                swap(roti[j], roti[j + 1]);
            }
        }
    }
}
void binary(){
    bubble_sort();
    string nama;
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, nama);

    bubble_sort();

    int left = 0, right = sizeof(roti) / sizeof(*roti) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (roti[mid].nama_roti == nama) {
            cout << "Roti ditemukan: " << roti[mid].kode_roti << " - " << roti[mid].harga_roti << endl;
            return;
        } else if (roti[mid].nama_roti < nama) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

void quick_sort(Roti arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high].harga_roti;
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j].harga_roti < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}



int main(){
    int menu;
    char pilihan;
    do
    {
        cout << "Pilih menu : " << endl;
        cout << "1. Tampilan Roti" << endl;
        cout << "2. Cari Berdasarkan Kode" << endl;
        cout << "3. Cari Berdasarkan Nama" << endl;
        cout << "4. Sort Harga Roti (asc)" << endl;
        cout << "5. Sort Harga Roti (desc)" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            tampilan_roti();
            break;
        case 2:
            sequential();
            break;
        case 3:
            binary();
            break;
        case 4:
            quick_sort(roti, 0, sizeof(roti) / sizeof(*roti) - 1);
            cout << "Roti telah diurutkan berdasarkan harga (asc)." << endl;
            break;
        case 5:
            bubble_sort();
            cout << "Roti telah diurutkan berdasarkan harga (desc)." << endl;
            break;
        case 6:
            cout << "Terima kasih" << endl;
            exit(0);
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }
        cout << "Kembali ke menu? (y/n) : ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');
    
    return 0;
}
