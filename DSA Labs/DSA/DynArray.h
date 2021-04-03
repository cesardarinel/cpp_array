// DynArray.h - A dynamically-allocated resizeable array
//	(similar to the stl vector)

#pragma once

#if LAB_3
template<typename Type>
class DynArray {

	friend class TestSuite;	// Giving access to test code

	Type* mArray;
	unsigned int mSize;
	unsigned int mCapacity;

public:

	// Default constructor
	//		Creates a new object
	// In:	_startingCap		An initial size to start the array at (optional)
	DynArray(unsigned int _startingCap = 0) {
		
	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DynArray() {
		
	}

	// Copy constructor
	//		Used to initialize one object to another
	// In:	_da				The object to copy from
	DynArray(const DynArray& _da) {
		
	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_da				The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DynArray& operator=(const DynArray& _da) {
	
	}

	// Overloaded [] operator
	//		Used to access an element in the internal array (read-only)
	// In:	_index			The index to access at
	//
	// Return: The item at the specified index (by reference)
	const Type& operator[](int _index) const {
	
	}

	// Overloaded [] operator
	//		Used to access an element in the internal array (writeable)
	// In:	_index			The index to access at
	//
	// Return: The item at the specified index (by reference)
	Type& operator[](int _index) {
		
	}

	// Get the current number of elements actively being used
	//
	// Return: The current number of elements used
	int Size() const {
		
	}

	// Get the current capacity of the internal array
	//
	// Return: The capacity of the array
	int Capacity() const {
		
	}

	// Clear the class for re-use
	//			Should clean up all dynamic memory and leave the object the same as if the default constructor had been called
	void Clear() {
		
	}

	// Add an item to the end of the array
	//			Should resize the array if needed
	// In:	_data			The item to be added
	void Append(const Type& _data) {
		
	}

	// Resizes the internal array, and copies all data over
	// In: _newCapacity		The new capacity of the array
	//	NOTE:	If 0 is passed, the array should double in size
	//			If _newCapacity < mCapacity, do nothing
	//
	//	SPECIAL CASE: If mCapacity is 0, then it should be set to 1
	void Reserve(unsigned int _newCapacity = 0) {
		
	}

};
#endif