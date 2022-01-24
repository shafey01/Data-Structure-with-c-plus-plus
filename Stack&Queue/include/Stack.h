#ifndef STACK_H
#define STACK_H
#include<iostream>
#include "Node.h"
using namespace std;
class Stack
{

   struct Node* tail = NULL;

public:


    void Push(int data)
    {


       struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->Data = data;
        node->Next = tail;
        tail = node;
    }
    int Pop(int &data)
    {
        if(!IsEmpty())
        {
            Node* node;
            node = tail;
            data = node->Data;
            tail = tail->Next;
            node->Next = NULL;
            delete node;
            return data;

        }

        return 0;
    }

    void display()
    {
        Node* node = tail;
        cout<<"Display1"<<endl;

        if(!IsEmpty())
        {

            while(node != NULL)
            {

                cout<<node->Data << "\t";
                node = node->Next;
            }

        }
    }



protected:

private:

    int IsEmpty()
    {
        if(tail == NULL)
            return 1;

        return 0;
    }
};

#endif // STACK_H
