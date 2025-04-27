#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node
{
public:
    // URL of the page
    char url[100];
    // Pointer to the previous node
    Node *prev;
    // Pointer to the next node
    Node *next;

    // Constructor to initialize a node with a URL
    Node(const char *url)
    {
        int i = 0;
        while (url[i] != '\0')
        { // Copy the URL into the character array
            this->url[i] = url[i];
            i++;
        }
        // '\0' Null-terminate the string
        this->url[i] = '\0';
        prev = nullptr;
        next = nullptr;
    }
};

// BrowserHistory class to manage browser navigation
class BrowserHistory
{
private:
    Node *current; // Pointer to the current page

public:
    // Constructor to initialize browser history with a homepage
    BrowserHistory(const char *homepage)
    {
        // Create the first node with the homepage
        current = new Node(homepage);
    }

    // Visit a new URL
    void visit(const char *url)
    {
        // Create a new node
        Node *newNode = new Node(url);
        // Link the new node to the current node
        current->next = newNode;
        // Link the current node to the new node
        newNode->prev = current;
        // Move the current pointer to the new node
        current = newNode;
    }

    // Go back a certain number of steps
    const char *back(int steps)
    {
        // Check if we can go back
        while (steps > 0 && current->prev)
        {
            // Move to the previous page
            current = current->prev;
            steps--;
        }
        // Return the current URL
        return current->url;
    }

    // Go forward a certain number of steps
    const char *forward(int steps)
    {
        // Check if we can go forward
        while (steps > 0 && current->next)
        {
            // Move to the next page
            current = current->next;
            steps--;
        }
        // Return the current URL
        return current->url;
    }

    // Print the entire browsing history
    void printHistory()
    {
        Node *temp = current;
        while (temp->prev)
        { // Move to the head of the list
            temp = temp->prev;
        }
        cout << "Browsing History:" << endl;
        while (temp)
        {
            // Print all nodes
            cout << (temp == current ? "-> " : "   ") << temp->url << endl;
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~BrowserHistory()
    {
        while (current->prev)
        { // Move to the head of the list
            current = current->prev;
        }
        while (current)
        { // Delete all nodes
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    // Initialize browser with homepage
    BrowserHistory browser("google.com");

    // Visit some pages
    browser.visit("github.com");
    browser.visit("leetcode.com");
    browser.visit("stackoverflow.com");

    // Print the current browsing history
    cout << "\n Current history:" << endl;
    browser.printHistory();

    // Navigate back
    cout << "\nGoing back 2 steps: " << browser.back(2) << endl;
    cout << "\nHistory after back:" << endl;
    browser.printHistory();

    // Navigate forward
    cout << "\nGoing forward 1 step: " << browser.forward(1) << endl;
    cout << "\nHistory after forward:" << endl;
    browser.printHistory();

    // Visit a new page
    browser.visit("wikipedia.org");
    cout << "\nHistory after new visit:" << endl;
    browser.printHistory();

    return 0;
}
