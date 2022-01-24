#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
    Node *head, *tail;

    public:
        int static length;
        LinkedList()
        {
            head = tail = NULL;
        }

        void Add(int data)
        {
            Node *node = new Node(data);
            length++;
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

        int GetDataByIndex(int index)
        {
            Node* current = head;
            int count = 0;


            while(current != NULL)
            {
                if(count == index)
                {
                     return current->Data;
                }


                count++;
                current = current->Next;
            }

            return 0;

        }

        int BinarSearch(int data)
        {
            int mid, low = 0, high = length -1;





            while(low <= high)
            {
                mid = (low + high) / 2;

                if(GetDataByIndex(mid) > data)
                {


                    high = mid -1;

                }
               else if(GetDataByIndex(mid) < data)
                {
                    low = mid +1;

                }

                else
                {
                    return 1;

                }

            }

            return 0;

        }


        struct Node* SWAP (Node* node1, Node* node2)
        {
            struct Node* temp = node2->Next;
            node2->Next = node1;
            node1->Next = temp;

            return node2;
        };


        int BubbelSort()
        {
            int done;
            struct Node** headForSort;

            for(int i=0; i<= length; i++)
            {
                headForSort = &head;
                done = 0;
                for(int j = 0; j < length -i -1; j++)
                {
                    struct Node* s1 = *headForSort;
                    struct Node* s2 = s1->Next;

                    if(s1->Data > s2->Data)
                    {
                        *headForSort = SWAP(s1, s2);
                        done = 1;
                    }

                    headForSort = &(*headForSort)->Next;
                }

                if(done == 0)
                    return 0;
            }


        }
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

int LinkedList::length = 0;

#endif // LINKEDLIST_H
