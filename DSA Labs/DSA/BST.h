// BST.h - A binary search tree
#pragma once

// For InOrder method
#include "string.h"
using namespace std;

#if LAB_8
template<typename Type>
class BST {

	friend class TestSuite; // Giving access to test code

	struct Node {
		Type data;
		Node* left, * right;

		// Constructor
		//		Creates a leaf node
		//
		// In:	_data		The value to store in this node
		Node(const Type& _data) {

		}
	};

	// Data members
	Node* mRoot;

public:

	// Default constructor
	//			Creates an empty tree
	BST() {

	}

	// Destructor
	//			Clear all dynamic memory
	~BST() {

	}

	// Copy constructor
	//			Used to initialize one object to another
	//
	// In:	_copy		The object to copy from
	BST(const BST<Type>& _copy) {

	}


	// Assignment operator
	//			Used to assign one object to another
	//
	// In:	_assign		The object to assign from
	//
	// Return:	The invoking object (by reference)
	//		This allows us to daisy-chain
	BST<Type>& operator=(const BST<Type>& _assign) {


	}

private:

	// Optional recursive helper method for use with Rule of 3
	// 
	// In:	_curr		The current Node to copy
	//
	// NOTE:	Use pre-order traversal
	void Copy(const Node* _curr) {

	}

public:

	// Clears out the tree and readies it for re-use
	void Clear() {

	}

private:

	// Optional recursive helper method for use with Clear
	// 
	// In:	_curr		The current Node to clear
	//
	// NOTE:	Use post-order traversal
	void Clear(Node* _curr) {

	}

public:

	// Add a value into the tree
	//
	// In:	_val			The value to add
	void Push(const Type& _val) {

	}

private:

	// Optional recursive helper method for use with Push
	//
	// In:	_val		The value to add
	//		_curr		The current Node being looked at
	void Push(const Type& _val, Node* _curr) {

	}

public:

	// Checks to see if a value is in the tree
	//
	// In:	_val		The value to search for
	//
	// Return:	True, if found
	bool Contains(const Type& _val) {

	}

	// Removes a value from tree (first instance only)
	//
	// In:	_val			The value to search for
	//
	// Return:	True, if a Node was removed
	// NOTE:	Keep in mind the three cases
	//			A) 2 children ("fix" tree)
	//			B) 0 children
	//			C) 1 child
	bool Remove(const Type& _val) {

	}

	// Returns a space-delimited string of the tree in order
	/*
	 Example:
			 24
			/ \
		   10  48
			\   \
			12   50

	 Should return: "10 12 24 48 50"
	*/
	// NOTE:	Use to_string to convert an int to its string equivelent

	string InOrder() {

	}

private:

	// Optional recursive helper method to help with InOrder
	//
	// In:	_curr		The current Node being looked at
	//		_str		The string to add to
	//
	// NOTE:	Use in-order traversal
	void InOrder(Node* _curr, string& _str) {
		
	}

};
#endif