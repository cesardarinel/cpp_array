#pragma once

#if LAB_4
#include <list>
using namespace std;

class DSA_Lab4 {

	friend class TestSuite;	// Giving access to test code

	// Data members
	list<float> mList;

public:

	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	//
	// Note: Make sure the list is empty and shrunk to 0 capacity before adding values
	void QueueOrderingAdd(const float* _arr, int _size) {
		
	}

	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	//
	// Note: Make sure the list is empty and shrunk to 0 capacity before adding values
	void StackOrderingAdd(const float* _arr, int _size) {
		
	}

	// Remove a single value from the list using queue ordering
	//
	// Return: The value that was removed
	float QueueOrderingRemove() {
		
	}

	// Remove a single value from the list using stack ordering
	//
	// Return: The value that was removed
	float StackOrderingRemove() {
		
	}

	// Insert a value _index nodes away from the head node
	//		If _index is 0 - insert in front of the head/front node
	//		If _index is 5 - insert in front of the 5th node in the list
	//
	// Example:	
	//			0<-[5]<->[1]<->[6]<->[4]<->[2]->0
	//	
	// Inserting a 7 at index 2
	//
	//			0<-[5]<->[1]<->[7]<->[6]<->[4]<->[2]->0
	//
	//
	// In:	_val		The value to insert
	//		_index		The "index" to add at
	void Insert(float _val, int _index) {
		
	}

	// Insert a value at the spot specified by the iterator passed in
	// 
	// In:	_val		The value to insert
	//		_iter		The iterator at the place to insert
	void Insert(float _val, list<float>::iterator _iter) {
		
	}

	// Remove all values from mList that have a decimal place value larger than _decimal 
	//		Example:   
	//					_decimal: 0.45
	//
	//					mList: 498.28			// not removed, because .28 is not greater than .45
	//						   39812.181		// not removed, because .181 is not greater than .45
	//						   983.498			// removed, because .498 is greater than .45
	//						   3981.89			// removed, because .89 is greater than .45
	//						   487.2			// not removed, because .2 is not greater than .45
	//
	//					With these values, the function would return 2
	//
	// In:	_decimal		The decimal value to check against (always less than 1.0)
	//
	// Return: The total number of values removed
	int RemoveDecimalGreater(float _decimal) {

	}
};

#endif

