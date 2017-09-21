// TestCollection.cpp
// Damir Pulatov
// COSC 2030
// 09/20/2017

/*
I received help from TA, and from the following websites:
https://www.cs.fsu.edu/~myers/c++/notes/rand.html

*/

#include<iostream>
#include"Collection.h"

using namespace std;

int main()
{

	Collection<int> testCollection;

	// Test insert(x) method
	for (int i = 0; i < 10; i++)
	{
		testCollection.insert(i);
	}

	testCollection.print();
	cout << endl;


	// Test insert() method with overflow
	cout << "Inserting 10 and 11" << endl;
	testCollection.insert(10);
	testCollection.insert(11);
	testCollection.print();
	cout << endl;

	// Test remove(x) method in different positions
	cout << "Remove 0, 11, 4" << endl;
	testCollection.remove(0);
	testCollection.remove(11);
	testCollection.remove(4);
	testCollection.print();
	cout << endl;


	// Test removeRandom() method
	cout << "Remove at random" << endl;
	testCollection.removeRandom();
	testCollection.print();
	cout << endl;
	

	// Test notContained(x) method
	if (testCollection.notContained(4))
	{
		cout << "4 is not contained in the collection" << endl;
	}
	else
	{
		cout << "4 is contained in the collection" << endl;
	}
	cout << endl;


	// Test makeEmpty() method and insert a new element
	testCollection.makeEmpty();
	testCollection.print();
	cout << endl;
	
	testCollection.insert(1);
	testCollection.print();

	return 0;
}