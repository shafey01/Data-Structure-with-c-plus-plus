#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>


using namespace std;

class LinkedList
{
    Node *head, *tail;
    public:
        LinkedList()
        {
            head = tail = NULL;
        }

        void Add(int data)
        {
            Node *node = new Node(data);

            if(head == NULL)
            {
                head = tail = node;
            }
            else
            {
                tail->Next = node;
                node->Prev = tail;
                tail = node;
            }
        }

        void Display()
        {
            Node *current = head;

            while(current != NULL)
            {
                cout << current->Data << "\t";
                current = current->Next;
            }
        }

        int Remove(int data)
        {
            Node *node = GetNodeByData(data);

            if(node == NULL)
                return 0;

            if(node == head)
            {
                if(node == tail)
                    head = tail = NULL;
                else
                {
                    head = head->Next;
                    head->Prev = NULL;
                }

            }
            else if(node == tail)
            {
                tail = tail->Prev;
                tail->Next = NULL;
            }
            else
            {
                node->Prev->Next = node->Next;
                node->Next->Prev = node->Prev;
            }

            delete node;
            return 1;
        }

        int Search(int data)
        {
            Node *node = GetNodeByData(data);

            return node != NULL;
        }

        void InsertAfter(int data, int afterData);
        void InsertBefore(int data, int beforeData);
        int GetDataByIndex(int index);
        LinkedList* Reverse();
        void InPlaceRevrse();

    protected:

    private:

        Node* GetNodeByData(int data)
        {
            Node *current = head;

            while(current != NULL)
            {
                if(data == current->Data)
                    return current;

                current = current->Next;
            }

            return NULL;
        }
};

#endif // LINKEDLIST_H
