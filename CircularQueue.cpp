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

