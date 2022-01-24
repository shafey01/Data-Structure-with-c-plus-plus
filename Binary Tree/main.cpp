#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree tree;

    tree.Add(50);
    tree.Add(40);
    tree.Add(45);
    tree.Add(60);
    tree.Add(70);
    tree.Add(300);


    tree.Traverse();
    cout<<endl;
    cout<<".............................."<<endl;
    cout<<tree.DisplayMaxDepth()<<endl;


    return 0;
}
