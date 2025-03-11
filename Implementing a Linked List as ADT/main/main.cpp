#include <iostream>
#include "ADT.h"

using namespace std;

int main()
{
    LinkedList list;

    list.insertBack(10); ///Insert at the end of the list
    list.insertBack(20);

    list.insertFront(5); ///Insert at the beginning of the list
    list.insertFront(1);

    ///Display Linked List
    cout << "Original Linked List: \n";
    list.display();

    ///Search List.
    cout << "\nSearching for 20: " << (list.search(20) ? "Found :)" : "Not Found :(") << endl;

    ///Delete value
    list.deleteValue(10);
    cout << "\nAfter deleting 10: \n";
    list.display();

    ///Print reverse
    cout << "\nPrint List in Reverse:\n";
    list.printReverse();

    return 0;
}
