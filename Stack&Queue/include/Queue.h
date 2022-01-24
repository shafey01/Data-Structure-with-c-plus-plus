#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Queue
{

    struct Node* front = NULL;
    struct Node* end = NULL;
    public:

        void Inqueue(int data)
        {

            if(end == NULL)
            {
                struct Node* node = (struct Node*) malloc(sizeof(struct Node));


                node->Next = NULL;
                node->Data = data;
                front = end = node;

            }
            else
            {

            struct Node* node = (struct Node*) malloc(sizeof(struct Node));

            end->Next = node;
            node->Data = data;
            node->Next = NULL;
            end = node;

            }


        }
        int Dequeue(int &data)
        {
            Node* node;
            node = front;
            if(!IsEmpty())
            {   if(front == end)
                    {
                        data = node->Data;
                        delete node;
                        front = end = NULL;
                        return data;
                    }
                data = node->Data;
                front = node->Next;
                delete node;
                return data;
            }

            return 0;
        }

        void Displayw()
        {
            Node* node;
            node = front;


            if(!IsEmpty())
            {

                while(node != NULL)
                {

                    cout<<node->Data<<"\t";
                    node = node->Next;
                }
            }
        }



    protected:

    private:

        int IsEmpty()
    {
        if(front == NULL && end == NULL)
            return 1;

        return 0;
    }
};

#endif // QUEUE_H
