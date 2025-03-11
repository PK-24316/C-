#ifndef ADT_H
#define ADT_H

#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    ///Pointer to the first node.
    Node *head;

    void printReverse(Node* node) const;

public:
    LinkedList(); ///Constructor.
    ~LinkedList(); ///Destructor.

    ///Function Prototypes.
    void insertFront(int value);
    void insertBack(int value);
    bool deleteValue(int value);
    bool search(int value) const;
    void display() const;
    bool isEmpty() const;
    void printReverse(Node *head);
    void printReverse() const;
};
#endif // ADT_H
