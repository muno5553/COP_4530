//Gustavo J. Munoz
//Assignment 2 - usestack.cpp
//September 30, 2014
//test custom Stack class

#include <iostream>
#include "Vector.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main(int argc, char* argv[])
{

// Checking if stack works properly -------------------------------------
stack<int> mystack1;

// Int stack
mystack1.push(1);
mystack1.push(2);
mystack1.push(3);
mystack1.push(-1);
mystack1.push(-2);
mystack1.push(-3);

cout << "top element of integer stack: " << mystack1.top() << "\n" << endl;

// Char stack
stack<char> mystack2;

cout << "Inputting characters 'a', 'b', 'c','d' " << endl; 
mystack2.push('a');
mystack2.push('b');
mystack2.push('c');
mystack2.push('d');
cout << "top element of character stack: " << mystack2.top() << endl;

cout << "Calling pop() to delete top element." << endl;
mystack2.pop();
cout << "top element character of stack: " << mystack2.top() << endl;

cout << "Calling pop() to delete rest of elements." << endl;
mystack2.pop();
mystack2.pop();
mystack2.pop();
cout << "top element of stack: " << mystack2.top() << endl;
cout << "Is the stack empty? 1 = yes, 0 = no: " << mystack2.empty() << endl;

cout << "Stack works" << endl;


// Add elements to stack
stack<int> mystack3;
for (int i = 0; i < 10; i++)
{
   mystack3.push(i);
}

// Checking if vector works properly ------------------------------------
Vector<int> myVector1;

myVector1.push_back(1);
myVector1.push_back(2);
myVector1.push_back(3);
myVector1.push_back(-1);
myVector1.push_back(-2);
myVector1.push_back(-3);

//cout << "size of vector: " << myVector1.size() << endl;

Vector<char> myVector2;

myVector2.push_back('a');
myVector2.push_back('b');
myVector2.push_back('c');
myVector2.push_back('d');

//cout << "size of vector: " << myVector2.size() << endl;

// Checking if queue works properly ------------------------------------
queue<int> myqueue1;

myqueue1.push(1);
myqueue1.push(2);
myqueue1.push(3);

	return 0;

}
