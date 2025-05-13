#include <iostream>
#include <climits>
using namespace std;

class Queue
{
    int front, rear, capacity;
    int *queue;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->front = -1;
        this->rear = -1;
        this->queue = new int[capacity];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == capacity - 1;
    }

    void enqueue(int data)
    {
        if (isFull())
            return;
        if (isEmpty())
            front = 0;
        rear++;
        queue[rear] = data;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }

    int Front()
    {
        if (isEmpty())
            return INT_MAX;
        return queue[front];
    }

    void print()
    {
        if (isEmpty())
            return;
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
};

// Using linked list to implement queue
struct node
{
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class QueueLL
{
    node *front, *rear;

public:
    QueueLL()
    {
        this->front = NULL;
        this->rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int data)
    {
        node *newnode = new node(data);
        if (front == NULL)
        {
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = rear->next;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        node *temp = front;
        front = front->next;
        delete temp;
        if (front == NULL)
            rear = NULL;
    }

    int Front()
    {
        if (isEmpty())
            return INT_MAX;
        return front->data;
    }

    void print()
    {
        node *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.dequeue();
    q.print();

    QueueLL qll;
    qll.enqueue(100);
    qll.enqueue(200);
    qll.enqueue(300);
    qll.print();
    qll.dequeue();
    qll.print();

    return 0;
}
