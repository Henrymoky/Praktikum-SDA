## SOAL 3

Buat implementasi Queue manual menggunakan linked list untuk simulasi antrian printer yang memproses dokumen berdasarkan urutan kedatangan (FIFO).
Struktur Data:

````c++
#include <iostream>
#include <string>
using namespace std;

// Struktur node buat queue
struct Node {
    string document;
    Node* next;
};

// Fungsi enqueue -> buat nambah dokumen ke antrian printer
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // --- LENGKAPI DI SINI ---
    // 1. Kalau antrian kosong, front dan rear langsung ke newNode
    if (front == nullptr) {
        front = rear = newNode;
    }
    // 2. Kalau gak kosong, sambungkan rear lama ke node baru dan update rear
    else {
        rear->next = newNode;
        rear = newNode;
    }
    // --- LENGKAPI DI SINI ---
}

// Fungsi dequeue -> buat ngambil dokumen pertama di antrian
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // --- LENGKAPI DI SINI ---
    // 1. Simpan data dari front node
    Node* temp = front;
    string doc = temp->document;

    // 2. Geser front ke node berikutnya
    front = front->next;

    // 3. Kalau setelah geser front jadi nullptr, berarti queue kosong -> rear juga nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    // 4. Hapus node lama biar gak bocor memori
    delete temp;

    // 5. Return data dokumen yang dihapus
    return doc;
    // --- LENGKAPI DI SINI ---
}

// Fungsi buat memproses semua dokumen di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    // --- LENGKAPI DI SINI ---
    // Selama masih ada dokumen di antrian, ambil satu-satu dan tampilkan
    while (front != nullptr) {
        string currentDoc = dequeue(front, rear);
        cout << "Memproses: " << currentDoc << endl;
    }
    // --- LENGKAPI DI SINI ---
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // Tambahkan dokumen ke antrian printer
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;

    // Proses semua dokumen
    processAllDocuments(front, rear);

    // Komentar tambahan versi saya:
    // Jadi logikanya ini kebalikan dari stack
    // Yang pertama masuk (enqueue) bakal keluar duluan waktu di-dequeue.
    // Pas semua dokumen diproses, queue jadi kosong lagi.
    // Cocok banget buat simulasi antrian printer kayak gini.

    return 0;
}


Hanya Info:

Queue menggunakan prinsip FIFO (First-In, First-Out). Dokumen yang pertama masuk antrian akan diproses pertama kali. Pointer front menunjuk ke elemen yang akan dikeluarkan, dan rear menunjuk ke posisi untuk elemen baru.

Output:

```c++
Memulai pemrosesan antrian printer:
Memproses: Document1.pdf
Memproses: Report.docx
Memproses: Presentation.pptx
````

---
