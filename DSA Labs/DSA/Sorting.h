// Sorting.h - A collection of sorting and searching algorithms 
//		Used in Lab 1

#pragma once

#if LAB_1
// Bubble sort an array in ascending order
//		This is a templated function
//
// In:	_arr		The array to sort
//		_size		The number of elements in _arr
template<typename Type>
void BubbleSort(Type* _arr, int _size) {
	
}

// Selection sort an array in ascending order
//		This is a templated function
//
// In:	_arr		The array to sort
//		_size		The number of elements in _arr
template<typename Type>
void SelectionSort(Type* _arr, int _size) {
	
}


// Selection sort an array in ascending order
//		This is a templated function
//
// In:	_arr		The array to sort
//		_size		The number of elements in _arr
template<typename Type>
void InsertionSort(Type* _arr, int _size) {


	
}




// Heapify a subtree
template<typename Type>
void Heapify(Type* _arr, int _size, int _index) {
	
}

//		This is a recursive function
template<typename Type>
void HeapSort(Type* _arr, int _index) {
	
}

// Find an item in an array using a sequential search
//
// In:	_val		The value to search for
//		_arr		The array to search
//		_size		The number of elements in the array
//
// Return: The index _val was found at (or -1 if not present)
template<typename Type>
int SequentialSearch(const Type& _val, const Type* _arr, int _size) {
	
}

// Find an item in an array using a binary search
//		This is a recursive function
//
// In:	_val		The value to search for
//		_arr		The array to search
//		_minIndex	Minimum index in searching area
//		_maxIndex	Maximum index in searching area
//
// Return: The index _val was found at (or -1 if not present)
template<typename Type>
int BinarySearch(const Type& _val, const Type* _arr, int _minIndex, int _maxIndex) {
	
}
#endif