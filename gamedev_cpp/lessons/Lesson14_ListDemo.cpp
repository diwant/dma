//============================================================================
// Name        : ListDemo.cpp
// Author      : Andrew Uzilov (andrew.uzilov@gmail.com)
// Version     :
// Description : Some demo code for how to make and use lists.
//
// A "list" is a special object that comes from the C++ Standard Template
// Library (STL).  It is documented here:
//     http://cplusplus.com/reference/stl/list/
//============================================================================


// This include is VERY IMPORTANT!!  Without it, we can't use lists.
#include <list>

// This include allows us to use "cout".
#include <iostream>

// This line makes is so that don't have to type "std::" in front of
// "list" and "cout" and so forth.
using namespace std;

int main() {

	// This declares a variable called "myList", which will contain objects of
	// type "string".  All items in a list MUST have the same type, and that
	// type must go between the angle brackets.
	list<string> myList;

	// Right now, the list is empty.
	cout << "The list has " << myList.size() << " items." << endl;

	// Let's add some items (strings) to the end of the list.
	myList.push_back ("are");
	myList.push_back ("awesome");
	myList.push_back ("and");
	myList.push_back ("fast");

	// We can also add items to the front of the list.
	myList.push_front ("lists");
	myList.push_front ("C++");

	// Now, the list has this many items.
	cout << "The list now has " << myList.size() << " items." << endl;

	cout << "--------------------" << endl;

	// How do we loop over the list?
	// We have to create an iterator, a special object that points to an item
	// in the list.
	// Let's create an iterator variable called "it".
	list<string>::iterator it;

	// Now, let's loop using a "for" loop.
	// The methods/functions "begin()" and "end()" return other iterators.
	// Comparing two iterators with "!=" compares if they are pointing to the
	// same list item.
	for (it = myList.begin(); it != myList.end(); it++) {
		// To fetch the item in the list, we treat the iterator like a
		// pointer: so, we use "*" and "->" notation.

		// Here, we just fetch the item and print it.
		cout << "Using for loop to look at item: " << *it << endl;

		// Here, we fetch the item (an object), call a method on it,
		// and print the value that this method returns.
		cout << "This item is " << it->size() << " characters long" << endl;
	}

	cout << "--------------------" << endl;

	// We can also loop using a "while" loop.
	// We'll reuse the "it" variable, make it point to the front of the list,
	// and keep going as long as it's not pointing to the end of a list.
	it = myList.begin();
	while (it != myList.end()) {
		cout << "Using while loop at item: " << *it << endl;
		it++;  // manually move iterator to next item
	}

	cout << "--------------------" << endl;

	// We can easily remove an item from a list, as long as we can create an
	// object that is identical to the item.
	myList.remove ("lists");
	cout << "The list has " << myList.size() << " items after using remove()" << endl;

	cout << "--------------------" << endl;

	// How do we remove an item if we don't know it?
	// We can use iterators to remove items with a certain property.
	// Let's say we want to remove all strings of size 3 from a list.
	it = myList.begin();
	while (it != myList.end()) {
		if (it->size() == 3) {
			cout << "Erasing item: " << *it << endl;
			// Remove whatever "it" is pointing to.
			// This method returns a new iterator that points to the
			// item AFTER the item that was erased.
			it = myList.erase (it);
		}
		else {
			it++;  // manually  move the iterator
		}
	}

	cout << "The list has " << myList.size() << " items after using erase() with iterators" << endl;
	cout << "These items are:" << endl;

	for (it = myList.begin(); it != myList.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
