#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList myList;

    myList.Add(3);
    myList.Add(5);
    myList.Add(7);
    myList.Add(9);
    myList.Add(11);

    myList.Remove(3);
    myList.Remove(15);

    myList.InPlaceRevrse();

    myList.Display();

    myList.InsertAfter(6, 5);

    return 0;
}
