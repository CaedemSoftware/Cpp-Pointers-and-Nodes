#include <iostream>
using namespace std;

int main() {
	string *ptr1 = nullptr;
	string *ptr2 = nullptr;
	ptr1 = new string{ "hello" };
	ptr2 = ptr1;
	cout << "ptr1: " << ptr1 << endl;
	cout << "ptr2: " << ptr2 << endl;
	delete ptr1;
	//delete ptr2; //visual studios runtime exception
	cout << "ptr1: " << ptr1 << endl;
	cout << "ptr2: " << ptr2 << endl;
	return  0;
}
