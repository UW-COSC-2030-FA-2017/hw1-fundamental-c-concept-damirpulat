// Collection.h
// Damir Pulatov
// COSC 2030
// 09/21/2017


#ifndef COLLECTION_H
#define COLLECTION_H

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

/*
	Store objects in collection template class using pointer to array
	Maximum size of array is passed through constructor with default at 10
	Everytime user puts more elements in array than max size allows,
	the size of array doubles
*/
template<class Object>
class Collection
{
public:

	// Constructor with a default value for max size of 10
	Collection(int size = 10);
	~Collection();

	// remove all objects from the collection
	void makeEmpty();

	// check if collection is empty
	bool isEmpty() const;

	// insert an object x into the end of collection
	void insert(Object x);

	// remove an object x from the collection (as long as it exists)
	bool remove(Object x);

	// remove an object at random from the collection
	void removeRandom();

	// returns true iff an object that is equal to x is not present in the collection
	bool notContained(Object x) const;

	// method to test my class template
	void print() const;

private:
	int currentSize;
	Object *storage;
	int maxSize;
};


/*
	initialize current size to zero
	default maximum capacity is 10
	implement array using pointers
*/
template <class Object>
Collection<Object>::Collection(int size)
{
	currentSize = 0;
	maxSize = size;
	storage = new Object[maxSize];
	if (storage == NULL)
	{
		cout << "Can't allocate enough memory" << endl;
	}
}


template <class Object>
Collection<Object>::~Collection()
{
	// Free memory
	delete [] storage;
}


// check if collection is empty
template <class Object>
bool Collection<Object>::isEmpty() const
{
	if (currentSize == 0)
	{
		return true;
	}

	return false;
}


// remove all objects from the collection
template <class Object>
void Collection<Object>::makeEmpty()
{
	// free memory and reset current size to zero
	delete [] storage;
	currentSize = 0;

	storage = new Object[maxSize];
	
	return;
}

/*
	Insert an object x into the end of collection
	If there is an overflow, double the maximum capacity of array
*/
template <class Object>
void Collection<Object>::insert(Object x)
{
	// check if size of array exceeds maximum size
	// if it does, increase array size
	if (currentSize < maxSize)
	{
		storage[currentSize] = x;
		currentSize++;
	}
	else
	{
		// double max size of array 
		maxSize = maxSize * 2;
		Object *tmp = new Object[maxSize];

		// copy all the elements in a new array
		for (int i = 0; i < currentSize; i++)
		{
			tmp[i] = storage[i];
		}
		
		// free unused memory and point storage to new array
		delete[] storage;
		storage = tmp;

		storage[currentSize] = x;
		currentSize++;
		
	}

}


/*
	remove(Object x) first checks if object is in collection
	if it is, it shiftes all the elements in the collection if needed
	and decreases current size field
	return true, if object is in collection and is removed
	return false otherwise
*/
template <class Object>
bool Collection<Object>::remove(Object x)
{
	// find the object
	for (int i = 0; i < currentSize; i++)
	{
		if (storage[i] == x)
		{
			// remove object and shift elements
			for (int j = i; j < currentSize; j++)
			{
				storage[j] = storage[j + 1];
			}
			currentSize--;
			return true;
		}
	}

	return false;
}


/*
	remove an element of collection at random
	use cstdlib and ctime headers to generate a random position number
*/
template <class Object>
void Collection<Object>::removeRandom()
{
	// seed the random number generator
	srand(time(0));

	// get random number and contents of collection at that position
	// call remove(x) method
	int position = rand() % currentSize;
	remove(storage[position]);
	
	return;
}


// returns true iff an object that is equal to x is not present in the collection
template <class Object>
bool Collection<Object>::notContained(Object x) const
{
	// iterate through array and if object is found, return false
	for (int i = 0; i < currentSize; i++)
	{
		if (storage[i] == x)
		{
			return false;
		}
	}

	return true;
}

/*
	print the contents of collection and current size for testing
*/
template <class Object>
void Collection<Object>::print() const
{
	for (int i = 0; i < currentSize; i++)
	{
		if (i == currentSize - 1)
		{
			cout << storage[i];
		}
		else
		{
			cout << storage[i] << ", ";
		}
	}

	cout << endl;
	cout << "current size is " << currentSize << endl;
	return;
}
#endif