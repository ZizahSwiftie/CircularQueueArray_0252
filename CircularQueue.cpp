#include <iostream>
using namespace std;

class Queue 
{
private:
    static const int  max = 5;
    int FRONT, FEAR;
    int queue_array[5];
public: 
    Queue()
    {
        FRONT = -1;
        FEAR = -1;  
    }
     void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

    // 1. cek apakah antrian penuh
        if ((FRONT == 0 && FEAR == max - 1) || (FEAR == (FRONT - 1) % (max - 1))) {
            cout << "\nQueue overflow\n"; //1.a
            return; // 1.b
        }

    // 2. Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            FRONT = 0; // 2.a
            FEAR = 0; // 2.b
        }
        else
        {
         // Jika REAR berada di posisi terakhir array, kembali ke awal array
         if (FEAR == max - 1)
                REAR = 0; 
            else 
                REAR = REAR + 1;
        }
        queue_array[FEAR] = num; 
    }

