## SOAL 5

Buat sebuah fungsi untuk menukar posisi node head dan node tail dalam sebuah circular doubly linked list tanpa menukar datanya, melainkan dengan memanipulasi pointernya.

Struktur Data:

```c++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head.
 * Pointer head akan di-update setelah penukaran.
 */
void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev; // tail adalah node sebelum head (karena circular)

    // --- LENGKAPI DI SINI ---
    // Kalau cuma dua node, cukup tukar langsung
    if (head->next == tail) {
        // hubungkan ulang biar head & tail tukar posisi
        tail->next = head;
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        head_ref = tail; // update head ke tail
        return;
    }

    // Simpan tetangga head dan tail sebelum diubah
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // Putuskan koneksi lama dan sambungkan ulang dengan posisi ditukar
    // Hubungkan tail ke head_next
    tail->next = head_next;
    head_next->prev = tail;

    // Hubungkan head ke tail_prev
    head->prev = tail_prev;
    tail_prev->next = head;

    // Sambungkan head & tail biar tetap circular
    head->next = tail;
    tail->prev = head;

    // Update head_ref biar head sekarang jadi tail
    head_ref = tail;
    // --- LENGKAPI DI SINI ---
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    // Tukar posisi head dan tail
    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    // Komentar tambahan versi saya:
    // kita gak mindahin datanya satu-satu, tapi cuma nyetel ulang arah pointer aja.
    // head yang awalnya di depan sekarang jadi di belakang, tail jadi di depan.
    // Karena list-nya circular, sambungan depannya nyatu lagi ke belakang.
    // Intinya mainin prev & next biar posisinya tukar tanpa ubah nilai datanya. 🔁

    return 0;
}


Hanya Info:

Kunci untuk soal ini adalah menggambar dan memvisualisasikan koneksi antar node. Dengan menyimpan node tetangga (head_next dan tail_prev) sebelum melakukan perubahan, kita memiliki semua referensi yang dibutuhkan untuk menyambungkan kembali list dalam urutan yang baru tanpa kehilangan node manapun.
```
