#ifndef CIRCALQUEUE_H
#define CIRCALQUEUE_H

#include "Node.h"
class CircalQueue
{
    int front, length, size;
    int* arr;
    public:
        CircalQueue(int _size) {

        front = -1;
        length = 0;
        size = _size;
        arr = new int[size];

        }

        void Inqueue(int data)
        {
            if(length != size)
            {
                length ++;
                arr[ (length + front) % size ] = data;

            }
            else
            {
                return;

            }



        }

        int Dequeue(int &x)
        {
            if(length == 0)
                return ;

            front = (front +1) % size;
            x= arr[front];
            length --;

            return x;



        }

        void Display()
        {   int c = front;
            while(c < length)
            cout <<arr[c++]<<"\t";
        }

    protected:


    private:



};

#endif // CIRCALQUEUE_H
