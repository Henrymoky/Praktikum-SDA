#include <iostream>
#include <string>
using namespace std;

struct Flight
{
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight *next;
};

Flight *head = NULL;
int counter = 0; // untuk penomoran kode penerbangan

// ASCII art pesawat untuk hiasan
void menuArt()
{
    cout << "                        __|__" << endl;
    cout << "-------------------@--@--(_)--@--@-------------------" << endl;
}

// Membuat kode penerbangan otomatis berdasarkan NIM
string generateKode()
{
    string base = "JT-070";
    if (counter == 0)
    {
        counter++;
        return base;
    }
    else
    {
        return base + "-" + to_string(counter++);
    }
}

// Tambah jadwal penerbangan di akhir
void tambahJadwal(string tujuan, string status)
{
    Flight *baru = new Flight();
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = NULL;

    if (head == NULL)
    {
        head = baru;
    }
    else
    {
        Flight *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "🛫 Jadwal berhasil ditambahkan: " << baru->kodePenerbangan << endl;
}

// Sisipkan jadwal di posisi tertentu
void sisipJadwal(string tujuan, string status)
{
    int posisi = 2; // karena NIM 070 → digit terakhir 0 → posisi = 2
    Flight *baru = new Flight();
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;

    if (head == NULL || posisi <= 1)
    {
        baru->next = head;
        head = baru;
        return;
    }

    Flight *temp = head;
    for (int i = 1; i < posisi - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    baru->next = temp->next;
    temp->next = baru;
}

// Hapus jadwal paling awal
void hapusAwal()
{
    if (head == NULL)
    {
        cout << "⚠️ Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight *hapus = head;
    head = head->next;
    cout << "🗑️ Jadwal " << hapus->kodePenerbangan << " berhasil dihapus." << endl;
    delete hapus;
}

// Update status penerbangan
void updateStatus(string kode)
{
    Flight *temp = head;
    while (temp != NULL)
    {
        if (temp->kodePenerbangan == kode)
        {
            cout << "Masukkan status baru: ";
            string newStatus;
            getline(cin >> ws, newStatus);
            temp->status = newStatus;
            cout << "✅ Status penerbangan " << kode << " berhasil diperbarui." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "❌ Jadwal dengan kode " << kode << " tidak ditemukan." << endl;
}

// Tampilkan semua jadwal
void tampilkan()
{
    if (head == NULL)
    {
        cout << "⚠️ Tidak ada jadwal penerbangan." << endl;
        return;
    }
    Flight *temp = head;
    cout << "\n🛩️ ================== DAFTAR JADWAL PENERBANGAN ================== 🛩️\n";
    cout << "   ✈️  Kode        | Tujuan                | Status\n";
    cout << "------------------------------------------------------------------\n";
    while (temp != NULL)
    {
        cout << "   " << temp->kodePenerbangan
             << string(12 - temp->kodePenerbangan.size(), ' ')
             << "| " << temp->tujuan
             << string(22 - temp->tujuan.size(), ' ')
             << "| " << temp->status << endl;
        temp = temp->next;
    }
    cout << "==================================================================\n";
}

// Menu utama
void menu()
{
    int pilihan;
    string tujuan, status, kode;

    do
    {
        cout << "\n";

        menuArt();
        cout << "+--------------------------------------------------------------+\n";
        cout << "|                 FLIGHT SCHEDULE SYSTEM                       |\n";
        cout << "|                [ Henry Moky - NIM 070 ]                      |\n";
        cout << "+--------------------------------------------------------------+\n";
        cout << "| 1.🛫 Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2.🛬 Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3.🗑️ Hapus Jadwal Paling Awal                                 |\n";
        cout << "| 4.🔄 Update Status Penerbangan                               |\n";
        cout << "| 5.📋 Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0.❌ Keluar                                                  |\n";
        cout << "+--------------------------------------------------------------+\n";
        menuArt();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            tambahJadwal(tujuan, status);
            break;
        case 2:
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            sisipJadwal(tujuan, status);
            break;
        case 3:
            hapusAwal();
            break;
        case 4:
            cout << "Masukkan kode penerbangan yang ingin diupdate: ";
            getline(cin, kode);
            updateStatus(kode);
            break;
        case 5:
            tampilkan();
            break;
        case 0:
            cout << "👋 Keluar dari program...\n";
            break;
        default:
            cout << "⚠️ Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}

int main()
{
    menu();
    return 0;
}
