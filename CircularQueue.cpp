/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * - en queue for inserting an element into the queue
 * - de queue for removing an element from the queue
 * - show data / display for displaying the elements in the queue
 * 
 * @section How to use
 * 1. Insert 
 * 2. Remove
 * 3. Display
 * 4. Exit
 * 
 * @author yProfile
 * - Name: Nur Azizah Ulinnuha
 * - Nim: 20240140252
 * - Class: E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;

/**
 * @class Queue
 * @brief This class is for operation queues
 * 
 */

class Queue 
{
private:
    int FRONT; /// private variable front for indicate the first element
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for indicate the maximum size of the queue
    int queue_array[5]; /// private array for storing the elements of the queue

public: 
    /**
     * @brief Constructor for Queue class
     * set default queues null
     * with front =-1 and rear = -1
     */
    Queue()
    {
        FRONT = -1; /// Inisialisasi FRONT, menandakan antrian awalnya kosong
        REAR = -1; /// Inisialisasi REAR, menandakan antrian awalnya kosong
    }

    /**
     * @brief method for entering data into a queue
     * This method checks if the queue is full before inserting a new element.
     */
     void insert()
    {
        int num; /// Variabel lokal untuk menyimpan input pengguna
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (REAR == (FRONT - 1) % (max - 1))) {
            cout << "\nQueue overflow\n"; //1.a
            return; /// Hentikan fungsi jika penuh
        }

        // 2. Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            FRONT = 0; /// Jika ya, atur FRONT ke indeks 0
            REAR = 0; /// Jika ya, atur REAR ke indeks 0
        }
        else
        {
         /// Jika REAR berada di posisi terakhir array, kembali ke awal array
         if (REAR == max - 1)
            REAR = 0; 
            else 
            REAR = REAR + 1; /// Jika tidak, geser REAR ke posisi berikutnya
        }
        queue_array[REAR] = num; /// Masukkan elemen ke posisi REAR yang baru
    }

    /**
     * @brief Menghapus sebuah elemen dari antrian.
     * This method checks if the queue is empty before removing the front element.
     */
    void remove()
    {
        /// Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue underflow\n"; 
            return; 
        }
        cout << "\nThe Element deleted from the queue is: " << queue_array[FRONT] << "\n";

        /// Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) 
        {
            FRONT = -1; /// Reset antrian menjadi kosong
            REAR = -1; /// Reset antrian menjadi kosong
        }
        else
        {
            /// JIka elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1) /// Jika FRONT berada di posisi terakhir array
                FRONT = 0; 
            else 
                FRONT = FRONT + 1; /// Jika tidak, geser FRONT ke posisi berikutnya
        } 
    }

    /**
     * @brief Menampilkan semua elemen dalam antrian.
     * This method iterates through the queue and prints each element.
     */
    void display()
    {
        int FRONT_position = FRONT; /// Inisialisasi posisi FRONT untuk iterasi
        /// Inisialisasi posisi REAR untuk iterasi
        int REAR_position = REAR; /// Inisialisasi posisi REAR untuk iterasi

        /// Cek apakah antrian kosong
        if (FRONT == -1) /// Jika FRONT adalah -1, berarti antrian kosong
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        /// Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR

        if (FRONT_position <= REAR_position)
        {
            /// Iterasi dari FRONT hingga REAR
           while (FRONT_position <= REAR_position)
          {
              cout << queue_array[FRONT_position] << " ";
              FRONT_position++; /// Pindah ke elemen berikutnya
          }
          FRONT_position = 0; /// Kembali ke awal array
          cout << endl;
}
else
{
        /// Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array 
        while (FRONT_position <= max - 1) 
        {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
        }
        FRONT_position = 0; 

        /// Iterasi dari awal array hingga REAR_position
        while (FRONT_position <= REAR_position) 
        {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
       }
        cout << endl;
       }
    }
};

/**
 * @brief Fungsi utama (entry point) untuk menjalankan program antrian.
 * Menyediakan menu interaktif berbasis konsol bagi pengguna untuk
 * melakukan operasi-operasi pada antrian.
 * @return int Mengembalikan 0 jika program berhasil dijalankan.
 */
int main()
{
    Queue q; /// Membuat objek 'q' dari kelas Queue. Constructor akan dipanggil
    char ch; /// Variabel untuk menyimpan pilihan menu dari pengguna

    while (true)
    {
        try
        {
        cout << "Menu" << endl;
        cout << "1. Implement insert operation" << endl; /// Panggil metode insert()
        cout << "2. Implement delete operation" << endl; /// Panggil metode remove()
        cout << "3. Display value" << endl; /// Panggil metode display()
        cout << "4. Exit" << endl; /// Keluar dari program
        cout << "Enter your choice (1-4): ";
        cin >> ch;
        cout << endl;

        switch (ch) /// Pilih operasi berdasarkan input
        {
        case '1':      
        {
            q.insert();
            break;
        }
        case '2':
        {
            q.remove();
            break;
        }
        case '3':
        {
            q.display();
            break;
        }
        case '4':
        {
            return 0;
        }
        default:
        {
            cout << "Invalid option!!" << endl;
            break;
        }
        }
    }
    catch (const exception& e)
    {
        cout << "Chech for the values entered." << endl;
    }     
}; /// Akhir dari class Queue