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
    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue underflow\n"; 
            return; 
        }
        cout << "\nElement deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) 
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // JIka elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1) 
                FRONT = 0; 
            else 
                FRONT = FRONT + 1;
        } 
    }

    void display()
    {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue is empty\n";
        return;
    }

    cout << "\nElements in the queue are...\n";

    // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
    if (FRONT_position <= REAR_position)
    {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
    }
    cout << endl;
}
else
{
    // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array 
    while (FRONT_position <= max - 1) 
    {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
    }
    FRONT_position = 0; 

    // Iterasi dari awal array hingga REAR_position
    while (FRONT_position <= REAR_position) 
    {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
    }
    cout << endl;
    }
}

};

int main()
{
    Queue q;
    char ch;

    while (true)
    {
        try
        {
        cout << "Menu" << endl;
        cout << "1. Implemet insert operation" << endl;
        cout << "2. Implement delete operation" << endl;
        cout << "3. Display value" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> ch;
        cout << endl;

        switch (ch)
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
            return 0:
        }
        default:
        {
            cout << "Invalid option!!"; << endl;
            break;
        }
        }
    }
    catch (const exception& e)
    {
        cout << "Chech for the values entered." << endl;
    }     
}