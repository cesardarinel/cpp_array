// DList.h - A doubly-linked list
// (similar to the stl list)

#pragma once


template<typename Type>
class DList {

	friend class TestSuite; // Giving access to test code

	// Node structor a doubly linked list
	struct Node {

		// Data members
		Type data;				// The value being stored
		Node* next, * prev;		// Pointers to the next and previous nodes

		// Constructor
		//
		// In:	_data			The value to store
		//		_next			Pointer to the next node in the list
		//		_prev			Pointer to the previous node in the list
		Node(const Type& _data, Node* _next = nullptr, Node* _prev = nullptr) {

		}
	};

public:

	// An iterator class to made traversal more efficient
	class Iterator {
	public:

		// Data members
		Node* mCurr;

		// Pre-fix increment operator
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
							I
							R
		*/
		// Return:	The Iterator (the invoking object)
		Iterator& operator++() {

		}

		// Post-fix increment operator
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
					  R		I

		*/
		// Return:	The Iterator (before increment)
		// NOTE:	Will need a temporary pointer
		Iterator operator++(int) {

		}

		// Pre-fix decrement operator
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I
				R
		*/
		// Return:	The Iterator (the invoking object)
		Iterator& operator--() {

		}

		// Post-fix decrement operator
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I	  R

		*/
		// Return:	The Iterator (before decrement)
		// NOTE:	Will need a temporary pointer
		Iterator operator--(int) {

		}

		// Gets the value the iterator is currently pointing to
		//
		// Return:	The data of the current iterator
		Type& operator*() {

		}
	};

	// Data members
	Node* mHead;			// The head (first node) of the list
	Node* mTail;			// The tail (last node) of the list
	unsigned int mSize;		// Current number of nodes being stored

public:

	// Default constructor
	//		Creates a new empty linked list
	DList() {

	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DList() {

	}

	// Copy constructor
	//		Used to initialize one object to another
	//
	// In:	_copy			The object to copy from
	DList(const DList& _copy) {

	}

	// Assignment operator
	//		Used to assign one object to another
	//
	// In:	_assign			The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DList& operator=(const DList& _assign) {

	}

private:

	// Optional recursive helper method for use with Rule of 3
	//
	// In:	_curr		The current Node to copy
	void Copy(const Node* _curr) {

	}

public:
	// Add a piece of data to the front of the list
	//
	// In:	_data			The object to add to the list
	void AddHead(const Type& _data) {

	}

	// Add a piece of data to the end of the list
	//
	// In:	_data			The object to add to the list
	void AddTail(const Type& _data) {

	}

	// Clear the list of all dynamic memory
	//			Resets the list to its default state
	void Clear() {

	}

private:

	// Optional recursive helper method for use with Clear
	// 
	// In:	_curr		The current Node to clear
	void Clear(const Node* _curr) {

	}

public:

	// Insert a piece of data *before* the passed-in iterator
	//
	// In:	_iter		The iterator
	//		_data		The value to add
	//
	// Example:
	/*
		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[9]<->[5]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Inserting at head or empty list
	// NOTE:	The iterator should now be pointing to the new node created
	Iterator Insert(Iterator& _iter, const Type& _data) {

	}

	// Erase a Node from the list
	//
	// In:	_iter		The iterator
	//
	// Example
	/*

		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Erasing head or tail
	// NOTE:	The iterator should now be pointing at the node after the one erased
	Iterator Erase(Iterator& _iter) {

	}

	// Set an Iterator at the front of the list
	// 
	// Return: An iterator that is pointing to the list's head
	Iterator Begin() {

	}

	// Set an Iterator pointing to the end of the list
	// 
	// Return: An iterator that is pointing to a null pointer
	Iterator End() {

	}
};