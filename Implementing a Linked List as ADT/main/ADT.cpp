#include "ADT.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::insertFront(int value)
{
    Node *newNode = new Node{value, head};
    head = newNode;
}

void LinkedList::insertBack(int value)
{
    Node *newNode = new Node{value, nullptr};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

bool LinkedList::deleteValue(int value)
{
    if (head == nullptr) return false;

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data != value)
        current = current->next;

    if (current->next == nullptr) return false;

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    return true;
}

bool LinkedList::search(int value) const
{
    Node *current = head;

    while (current != nullptr)
    {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void LinkedList::display() const
{
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << "Null\n";
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

void LinkedList::printReverse(Node* node) const
{
    if (node == nullptr) return;
    printReverse(node->next);
    cout << node->data << "\t";
}

void LinkedList::printReverse() const
{
    printReverse(head);
    cout << endl;
}
































