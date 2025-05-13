#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *pre;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }
};

class DLL
{
public:
    node *head, *tail;
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void printForward()
    {
        cout << "Printing in forward direction" << endl;
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void printBackword()
    {
        cout << "Printing in backward direction" << endl;
        node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->pre;
        }
        cout << "NULL" << endl;
    }

    void insertAtBegining(int data)
    {
        node *newNode = new node(data);
        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    void insertionAtEnd(int data)
    {
        node *newNode = new node(data);
        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    void deleteAtBegining()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "Cannot delete, list is empty" << endl;
            return;
        }
        node *temp = head;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->pre = NULL;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "Cannot delete, list is empty" << endl;
            return;
        }
        node *temp = tail;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->pre;
            tail->next = NULL;
        }
        delete temp;
    }

    void insertAftergivenNodeValue(int data, int value)
    {
        node *newNode = new node(data);
        if (head == nullptr)
        {
            cout << "Cannot insert, list is empty" << endl;
            return;
        }
        node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }
        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->pre = temp;
            tail = newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->next->pre = newNode;
        temp->next = newNode;
        newNode->pre = temp;
    }
        void deleteAfterGivenNodeValue(int key)
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Cannot delete, insufficient nodes" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "No node exists after the given key" << endl;
            return;
        }
        node *toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != NULL)
        {
            toDelete->next->pre = temp;
        }
        else
        {
            tail = temp;
        }
        delete toDelete;
    }
    void insertBeforeGivenNodeValue(int data, int value)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            cout << "Cannot insert, list is empty" << endl;
            return;
        }
        if (head->data == value)
        {
            insertAtBegining(data);
            return;
        }
        node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }
        node *temp2 = temp->pre;
        temp->pre = newNode;
        newNode->next = temp;
        temp2->next = newNode;
        newNode->pre = temp2;
    }

    void deleteBeforeGivingNodeValue(int key)
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Cannot delete, insufficient nodes" << endl;
            return;
        }
        node *temp = head->next;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->pre == NULL)
        {
            cout << "No node exists before the given key" << endl;
            return;
        }
        node *toDelete = temp->pre;
        if (toDelete == head)
        {
            head = head->next;
            head->pre = NULL;
        }
        else
        {
            toDelete->pre->next = temp;
            temp->pre = toDelete->pre;
        }
        delete toDelete;
    }


};

int main()
{
    DLL dll;
    dll.insertAtBegining(10);
    dll.insertionAtEnd(20);
    dll.insertAftergivenNodeValue(15, 10);
    dll.insertBeforeGivenNodeValue(5, 10);
    dll.printForward();
    dll.deleteAtBegining();
    dll.deleteAtEnd();
    dll.deleteBeforeGivingNodeValue(15);
    dll.deleteAfterGivenNodeValue(10);
    dll.printForward();
    return 0;
}