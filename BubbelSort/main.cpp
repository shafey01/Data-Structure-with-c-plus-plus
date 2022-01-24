#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
    LinkedList l;

    l.Add(10);
    l.Add(1);
    l.Add(13);
    l.Add(0);
    l.Add(20);
    l.Add(15);
    l.Add(12);

    int result =  l.GetDataByIndex(1);
    cout<<"................................."<<endl;
    l.Display();
    cout<<endl;
    cout<<"................................."<<endl;
    l.BubbelSort();

    l.Display();


    if(l.BinarSearch(19))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"NOt Found"<<endl;
    }
    return 0;
}
