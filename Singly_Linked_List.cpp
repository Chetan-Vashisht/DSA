#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    void print()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "linkedlist is empty";
            return;
        }
        cout << "elements are ";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
    void insertAtBeginning(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    void insertAtEnd(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    void deleteAtBeginning()
    {
        if (head == NULL)
        {
            cout << "LL is empty cant't delete ";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "LL is empty can't delete ";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    void insertBeforeGivenNodeData(int data, int value)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            cout << "LL is empty can't insert ";
            return;
        }
        if (head->data == value)
        {
            newnode->next = head;
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "given data not found ";
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void insertAfterGivenNodeData(int data, int value)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            cout << "LL is empty can't insert ";
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != value)
            temp = temp->next;
        if (temp == NULL)
        {
            cout << "given data not found ";
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void deleteAfterGivenNodeData(int value)
    {
        if (head == NULL)
        {
            cout << "LL is empty can't delete ";
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != value)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL)
        {
            cout << "given data not found or no next node to delete ";
            return;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
    void deleteBeforeGivenNodeData(int value)
    {
        if (head == NULL)
        {
            cout << "LL is empty can't delete ";
            return;
        }
        if (head->data == value)
        {
            cout << "no node before head ";
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "given data not found ";
            return;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
};

int main()
{

    return 0;
}