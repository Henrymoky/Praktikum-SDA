#include <iostream>
using namespace std;

struct Mahasiswa
{
    char nama[50];
    char nim[20];
    float ipk;
};

int main()
{
    const int n = 4; // karena NIM genap
    Mahasiswa mhs[n];

    cout << "Input data " << n << " mahasiswa:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    // bubble sort ascending berdasarkan IPK
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mhs[j].ipk > mhs[j + 1].ipk)
            {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }

    cout << "\nData Mahasiswa setelah diurutkan (IPK Ascending):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }

    return 0;
}
