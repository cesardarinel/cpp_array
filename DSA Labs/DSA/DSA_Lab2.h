#pragma once

// Only compile if LAB_2 is on
#if LAB_2

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Checks to see if a number is a palindrome (reads the same forwards and backwards)
//		An example of a palindrome word would be "racecar"
//
// In: _num			The number to check
//
// Return: True, if the number is a palindrome number
inline bool IsPalindromeNumber(unsigned int _num) {
	
}


class DSA_Lab2
{
	friend class TestSuite;	// Giving access to test code


private:

	vector<unsigned int> mValues;		// contains all of the values
	vector<unsigned int> mPalindromes;	// contains just the numbers that are palindromes

public:

	// Fill out the vector with the contents of the binary file
	//		First four bytes of the file are the number of ints in the file
	//
	// In:	_input		Name of the file to open
	//
	// Note: Make sure the vector is empty and shrunk to 0 capacity before adding values
	void Fill(const char* _input) {
	
	}

	// Fill out the vector with the contents of an array
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	//
	// Note: Make sure the vector is empty and shrunk to 0 capacity before adding values
	void Fill(const unsigned int* _arr, int _size) {
	
	}

	// Remove all elements from vector and decrease capacity to 0
	void Clear() {
	
	}

	// Sort the vector 
	//
	// In:	_ascending		To sort in ascending order or not
	void Sort(bool _ascending) {
	
	}

	// Get an individual element from the mValues vector
	int operator[](int _index) {
	
	}

	// Determine if a value is present in the vector
	// 
	// In:	_val		The value to check for
	//
	// Return: True, if the value is present
	bool Contains(unsigned int _val) const {
	
	}

	// Move all palindrome numbers from mValues vector to mPalindromes vector
	//
	// Pseudocode:
	//		iterate through the main values vector
	//			if the value is a palindrome
	//				add it to the palindrome vector
	//				remove it from the values vector
	void MovePalindromes() {
	
	}
};




#endif