#include <iostream>

using namespace std;

// 1. Local Scope:
// - Variables declared inside a function or block are only accessible within that block.
// - They are destroyed after the block ends.
void localScopeExample()
{
    int localVar = 10;                              // Local variable
    cout << "Local variable: " << localVar << endl; // Accessible here
}
// localVar is not accessible here

// 2. Global Scope:
// - Variables declared outside any function are accessible throughout the program.
int globalVar = 20; // Global variable

void globalScopeExample()
{
    cout << "Global variable: " << globalVar << endl; // Accessible
}

// 3. Function Scope:
// - Variables declared as function parameters are accessible within the function only.
void functionScopeExample(int paramVar)
{
    cout << "Function parameter: " << paramVar << endl; // Accessible inside the function
}

// 4. File Scope (Static Variables):
// - Static variables at the global level are restricted to the file they are declared in.
static int staticVar = 30; // File-scoped variable

void fileScopeExample()
{
    cout << "File-scope static variable: " << staticVar << endl; // Accessible here within the file
}

// 5. Class Scope:
// - Member variables of a class can be accessed using objects of the class.
class Example
{
    int classVar; // Member variable
public:
    void setVar(int value)
    {
        classVar = value;
    }
    int getVar()
    {
        return classVar;
    }
};


int main()
{
    // Local Scope Example
    localScopeExample();

    // Global Scope Example
    globalScopeExample();

    // Function Scope Example
    functionScopeExample(50);

    // File Scope Example
    fileScopeExample();

    // Class Scope Example
    Example obj;
    obj.setVar(60);
    cout << "Class variable: " << obj.getVar() << endl;


    return 0;
}
