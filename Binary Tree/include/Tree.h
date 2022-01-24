#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <math.h>
#include "Node.h"

using namespace std;

class Tree
{
    Node *root;

    public:
        Tree()
        {
            root = NULL;
        }

        void Add(int data)
        {
            Node *node = new Node(data);

            if(root == NULL)
            {
                root = node;
            }
            else
            {
                Node *current = root;
                Node *parent;

                while(current != NULL)
                {
                    parent = current;

                    if(data > current->Data)
                        current = current->Right;
                    else
                        current = current->Left;
                }

                if(data > parent->Data)
                    parent->Right = node;
                else
                    parent->Left = node;
            }
        }

        void Remove(int data)
        {
            Node *node = GetNodeByData(data);

            if(node == NULL)
                return;

            if(node == root)
            {
                if(root->Left == NULL && root->Right == NULL)
                {
                    root = NULL;
                }
                else if(root->Right == NULL)
                {
                    root = root->Left;
                }
                else if(root->Left == NULL)
                {
                    root = root->Right;
                }
                else
                {
                    Node *newRoot = GetMaxRight(root->Left);

                    if(newRoot != root->Left)
                    {
                        Node *parent = GetParent(newRoot);

                        parent->Right = newRoot->Left;
                        newRoot->Left = root->Left;
                    }

                    newRoot->Right = root->Right;
                    root = newRoot;
                }
            }
            else
            {
                Node *parent = GetParent(node);
                Node *newChild;

                if(node->Left == NULL && node->Right == NULL)
                {
                    /*if(parent->Left == node)
                        parent->Left = NULL;
                    else
                        parent->Right = NULL;*/

                    newChild = NULL;
                }
                else if(node->Right == NULL)
                {
                    /*if(parent->Left == node)
                        parent->Left = node->Left;
                    else
                        parent->Right = node->Left;*/

                    newChild = node->Left;
                }
                else if(node->Left == NULL)
                {
                    /*if(parent->Left == node)
                        parent->Left = node->Right;
                    else
                        parent->Right = node->Right;*/

                    newChild = node->Right;
                }
                else
                {
                    Node *newParent = GetMaxRight(node->Left);

                    if(newParent != node->Left)
                    {
                        Node *grandParent = GetParent(newParent);

                        grandParent->Right = newParent->Left;
                        newParent->Left = node->Left;
                    }

                    newParent->Right = node->Right;

                    /*if(parent->Left == node)
                        parent->Left = newParent;
                    else
                        parent->Right = newParent;*/

                   newChild = newParent;
                }

                if(parent->Left == node)
                    parent->Left = newChild;
                else
                    parent->Right = newChild;
            }

            delete node;
        }

        void Traverse()
        {
            Display(root);
        }



        int DisplayMaxDepth()
        {
            return GetMaxDepth(root);
        }

    protected:

    private:

        void Display(Node *node)
        {
            if(node == NULL)
                return;

            Display(node->Left);
            cout << node->Data << "\t";
            Display(node->Right);
        }

        Node* GetNodeByData(int data)
        {
            Node *current = root;

            while(current != NULL)
            {
                if(data == current->Data)
                    return current;

                if(data > current->Data)
                    current = current->Right;
                else
                    current = current->Left;
            }

            return NULL;
        }

        Node* GetParent(Node *node)
        {
            Node *parent = root;

            while(parent != NULL)
            {
                if(parent->Left == node || parent->Right == node)
                    return parent;

                if(node->Data > parent->Data)
                    parent = parent->Right;
                else
                    parent = parent->Left;
            }

            return NULL;
        }

        Node* GetMaxRight(Node *node)
        {
            Node *current = node;

            while(current->Right != NULL)
                current = current->Right;

            return current;
        }
        int GetMaxDepth(Node* root)
        {
            if(root == NULL)
                return 0;

            return 1 + max(GetMaxDepth(root->Left), GetMaxDepth(root->Right)  );
        }
};

#endif // TREE_H
