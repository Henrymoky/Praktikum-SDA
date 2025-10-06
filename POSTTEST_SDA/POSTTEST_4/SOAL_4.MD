## SOAL 4

Anda memiliki sebuah circular doubly linked list yang datanya sudah terurut (ascending). Buatlah fungsi untuk menyisipkan sebuah node baru ke dalam list tersebut sehingga urutannya tetap terjaga.

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
 * Fungsi ini menerima referensi ke pointer head dan data yang akan disisipkan.
 * Pointer head bisa berubah jika data baru menjadi elemen terkecil.
 */
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // --- LENGKAPI DI SINI ---
    Node* current = head_ref;

    // Kasus 2: Jika data baru lebih kecil dari head, berarti harus jadi head baru
    if (data < head_ref->data) {
        Node* last = head_ref->prev; // node terakhir (karena circular)

        // Hubungkan newNode di depan head
        newNode->next = head_ref;
        newNode->prev = last;
        last->next = newNode;
        head_ref->prev = newNode;

        // Update head biar newNode jadi node pertama
        head_ref = newNode;
        return;
    }

    // Kasus 3: Sisipkan di tengah atau akhir
    // Traversal untuk cari posisi yang tepat
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // Setelah posisi ditemukan, sisipkan setelah current
    Node* nextNode = current->next;
    current->next = newNode;
    newNode->prev = current;
    newNode->next = nextNode;
    nextNode->prev = newNode;
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

int main() {
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    // Komentar tambahan versi saya:
    // - Kalau list masih kosong, node pertama bakal nyambung ke dirinya sendiri (circular).
    // - Kalau data baru lebih kecil dari head, dia langsung jadi head baru.
    // - Kalau data di tengah atau akhir, kita cari posisi yang pas biar urutan tetap naik.
    // - Karena circular, kita pastikan node terakhir nyambung ke head lagi biar muter terus.
    // Intinya: ini kayak antrian melingkar yang tetep urut dari kecil ke besar 🔁

    return 0;
}


Hanya Info:

Karena listnya sirkular dan terurut, kita bisa dengan cepat memeriksa apakah node baru harus diletakkan di awal (lebih kecil dari head) atau di akhir (lebih besar dari tail/head->prev). Jika tidak, kita baru melakukan traversal untuk mencari posisi di tengah.

---
```
