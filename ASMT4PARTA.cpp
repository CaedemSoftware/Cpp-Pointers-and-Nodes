// ASMT4PARTA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// these are code examples with no specific output, but rather exists to show how pointers work
// Statement 1: 
void rawPointer() {
    int* myPointer(new int(100));
    int* myOtherPointer = myPointer;
    delete myPointer;
    myPointer = nullptr;
    // delete myOtherPointer;    <- this will cause an error 
    // this is bad: if we want to account for every pointer, we have to delete them manually too.
}

void rawPointer2() {
    int* anotherPointer(new int(200));
    delete anotherPointer; // i have to delete it manually to account for it, which is tedious manually
}

void smartPointer() {
    unique_ptr<int> smartPointer(new int(100)); // declaration syntax of a unique smart pointer
   
    // pretend i use the pointer here...

    // not much to show here, but rather just to explain: I do not have to delete this pointer because smart pointers will handle it for me
}


// Statement 2:

void smartPointer2() {
    unique_ptr<string> smartPointer2(new string("This is a pretty smart pointer.")); 
    

    // same syntax as above. i wrote this again to demonstrate that once the function ends, the smart pointer will delete everything by calling the...
    // ...deconstructor automatically when it goes outside of the program scope. we do not have to do it manually
}


// Statement 3:

class myClass
{
public:
    string* pizza;
    string* stromboli;
    void someRandomMethod() {
        pizza = stromboli;
    }
    // Please refer to main.
};

class mySmartClass
{
public:
    unique_ptr<string> pizza;
    // Please refer to main for this one alkso.
    // This will automatically be deleted whenever we delete mySmartClass.   
};


// Statement 4:

void convertSmartPointer() {
    unique_ptr<string> firstSmartPointer(new string("This is also a pretty smart pointer."));
    shared_ptr<string> secondSmartPointer = move(firstSmartPointer); 
    // This is the process in which a unique pointer is converted into a shared pointer.
}

// Statement 5

void weakPointer() {
    shared_ptr<string> anotherSharedPointer(new string("This is a shared pointer.")); 
    weak_ptr<string> myWeakPointer = anotherSharedPointer;
    // This makes a weak pointer point to the same thing as a shared pointer. Once it reaches the end of this program's scope, it will be deleted.
}


int main()
{
    // Statement 3
    myClass* someObject = new myClass();
    someObject->someRandomMethod();
    delete someObject; // This deletes the object, HOWEVER, this will not delete all the strings and ints we made in our method.
    
    mySmartClass* someOtherObject = new mySmartClass();
    delete someOtherObject; // Deleting the object with a smart pointer inside will have the pointer automatically delete the stuff inside, however.

    cout << "Program's done." << endl;
    
}

