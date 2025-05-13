#include <iostream>
#include<climits>
using namespace std;

//Normal way to implement stack using array
const int capacity=5;
int stack[capacity];
int top=-1;
bool isEmpty()
{
    if(top==-1)return true;
    return false;
    
}
bool isFull()
{
    if(top==capacity-1)return true;
    return false;
}
void push(int data)
{
    if(isFull())
    {
        cout<<"\n stack overflow ";
        return ;
    }
    top++;
    stack[top]=data;
}
void pop()
{
    if(isEmpty())
    {
        cout<<"\n stack underflow ";
        return ;
    }
    top--;
}
int peek()
{
    if(isEmpty()) return INT_MIN;
    return stack[top];
}
void print()
{
    cout<<"\nelements are \n";
    for(int i=top;i>=0;i--)cout<<stack[i]<<endl;
}

// dynamically allocated stack using array
class Stack
{
    int capacity;
    int top;
    int *stack;
    public:
    Stack(int capacity)
    {
        this->top=-1;
        this->capacity=capacity;
        this->stack=new int[capacity];
    }
    bool isEmpty()
    {
        if(top==-1)return true;
        return false;
    }
    bool isFull()
    {
        if(top==capacity-1)return true;
        return false;
    }
    void push(int data)
    {
        if(isFull())
        {
            cout<<"\nstack overflow";
            return ;
        }
        top++;
        stack[top]=data;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"\nstack underflow";
            return;
        }
        top--;
    }
    int peek()
    {
        if(isEmpty())return INT_MAX;
        return stack[top];
    }
    void print()
    {
        cout<<"\nelements are \n";
        for(int i=top;i>=0;i--)cout<<stack[i]<<endl;
    }
};
// using linkded list to implement stack
class node 
{
    public:
    int data ;
    node *next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class StackLL
{
    node *top;
    public:
    StackLL()
    {
        top=NULL;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void push(int value)
    {
        node *newnode=new node(value);
        newnode->next=top;
        top=newnode;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow";
            return;
        }
        node *copy=top;
        top=top->next;
        delete copy;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"stack underflow";
            return INT_MAX;
        }
        return top->data;
    }
    void print()
    {
        node *temp=top;
        while(temp)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    // Using the dynamically allocated stack
    Stack arrayStack(5); // Create a stack with capacity 5
    int x = arrayStack.peek();
    if (x == INT_MIN)
    {
        cout << "\nnothing on top";
    }
    else
        cout << "top=" << x;
    arrayStack.print();

    // Using the linked list-based stack
    StackLL llStack; // Create a linked list-based stack
    llStack.push(10);
    llStack.push(20);
    llStack.push(30);
    llStack.print();
    llStack.pop();
    cout << "Top element: " << llStack.peek() << endl;
    llStack.print();

    return 0;
}