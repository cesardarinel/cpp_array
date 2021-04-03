#include "TestSuite.h"
#include "Timer.h"
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable : 26812)



int IntWrapper::mCounter = 0;
int IntWrapper::mIsEqualCounter = 0;

#if LAB_1
#include "Sorting.h"
#endif

#if LAB_2 
#include "DSA_Lab2.h"
#endif

#if LAB_3
#include "DynArray.h"
#endif

#if LAB_4
#include "DSA_Lab4.h"
#endif

#if LAB_5
#include "DList.h"
#endif

#if LAB_6
#include "DSA_Lab6.h"
#endif

#if LAB_7
#include "HashFunctions.h"
#include "Dictionary.h"
#include <fstream>
#include <vector>
#endif

#if LAB_8
#include "BST.h"
#endif

#if LAB_9
#include "Huffman.h"
#endif

#pragma warning(disable: 6386)

#pragma region Global test structs and methods
// Used within several unit tests for user-defined values
struct UserDefined {
	string mString;
	int mValue = -1;

	UserDefined(const string _str = "", int _val = -1) : mString(_str), mValue(_val) { }

	bool operator==(const UserDefined& b) {
		return (this->mString == b.mString &&
			this->mValue == b.mValue);
	}
	bool operator!=(const UserDefined& b) {
		return (this->mString != b.mString ||
			this->mValue != b.mValue);
	}
};

// Used to display messages for unit testing
// In:	_msg		The message to display
//		_success	Determines pass or fail text
void PrintMessage(const string& _msg, bool _success) {

	ConsoleColor color = (_success ? ConsoleColor::Green : ConsoleColor::Red);
	Console::ForegroundColor(color);
	cout << (_success ? "PASS" : "FAIL - ");
	cout << _msg << '\n';
	Console::ForegroundColor(ConsoleColor::Gray);
}

ostream& operator <<(ostream& _os, const IntWrapper& _rhs) {
	_os << _rhs.mValue;
	return _os;
}

// Creating an array for the small sorting tests
IntWrapper* CreateSmallArray() {
	IntWrapper arr[10] = { 98, 23, 100, 5, 52, 44, 12, 87, 298, 0 };
	IntWrapper* smallArr = new IntWrapper[10];
	for (int i = 0; i < 10; ++i)
		smallArr[i] = arr[i];
	return smallArr;
}

IntWrapper* CreateLargeArray() {
	IntWrapper* largeArr = new IntWrapper[10000];
	int i = 0;
	fstream fin("numbers.txt");
	while (!fin.eof()) {
		fin >> largeArr[i++].mValue;
	}
	fin.close();

	return largeArr;
}

#pragma endregion

// Lab 1 Unit Tests
#if LAB_1
void TestSuite::SortingBubbleSortSmall() {
	cout << "Testing bubble sort on small array\n";

	// Getting array to sort
	IntWrapper* smallArray = CreateSmallArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Bubble Sort
	BubbleSort(smallArray, 10);

	// Testing
	bool sorted = true;
	for (int i = 1; i < 10; ++i) {
		if (smallArray[i] < smallArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 10; ++index)
				cout << smallArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 75)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");
	
	// Success
	if (sorted &&
		75 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] smallArray;
}

void TestSuite::SortingBubbleSortLarge() {
	cout << "Testing bubble sort on large array\n";

	// Getting array to sort
	IntWrapper* largeArray = CreateLargeArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Bubble Sort
	BubbleSort(largeArray, 1000);

	// Testing
	bool sorted = true;
	for (int i = 1; i < 1000; ++i) {
		if (largeArray[i] < largeArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 765654)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		765654 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] largeArray;
}

void TestSuite::SortingSelectionSortSmall() {
	cout << "Testing selection sort on small array\n";

	// Getting array to sort
	IntWrapper* smallArray = CreateSmallArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Selection Sort
	SelectionSort(smallArray, 10);

	// Testing
	bool sorted = true;
	for (int i = 1; i < 10; ++i) {
		if (smallArray[i] < smallArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 10; ++index)
				cout << smallArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 21)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		21 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] smallArray;
}

void TestSuite::SortingSelectionSortLarge() {
	cout << "Testing selection sort on large array\n";

	// Getting array to sort
	IntWrapper* largeArray = CreateLargeArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Selection Sort
	SelectionSort(largeArray, 1000);


	// Testing
	bool sorted = true;
	for (int i = 1; i < 1000; ++i) {
		if (largeArray[i] < largeArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 1000; ++index)
				cout << largeArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 2985)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		2985 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] largeArray;
}

void TestSuite::SortingInsertionSortSmall() {
	cout << "Testing insertion sort on small array\n";

	// Getting array to sort
	IntWrapper* smallArray = CreateSmallArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Insertion Sort
	InsertionSort(smallArray, 10);

	// Testing
	bool sorted = true;
	for (int i = 1; i < 10; ++i) {
		if (smallArray[i] < smallArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 10; ++index)
				cout << smallArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}

	if (IntWrapper::mCounter != 43)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		43 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] smallArray;
}

void TestSuite::SortingInsertionSortLarge() {
	cout << "Testing insertion sort on large array\n";

	// Getting array to sort
	IntWrapper* largeArray = CreateLargeArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Insertion Sort
	InsertionSort(largeArray, 1000);

	// Testing
	bool sorted = true;
	for (int i = 1; i < 1000; ++i) {
		if (largeArray[i] < largeArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 1000; ++index)
				cout << largeArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 257216)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		257216 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] largeArray;
}

void TestSuite::SortingHeapSortSmall() {
	cout << "Testing heap sort on small array\n";

	// Getting array to sort
	IntWrapper* smallArray = CreateSmallArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Heap Sort
	HeapSort(smallArray, 10);


	// Testing
	bool sorted = true;
	for (int i = 1; i < 10; ++i) {
		if (smallArray[i] < smallArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 10; ++index)
				cout << smallArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 81)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		81 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] smallArray;
}

void TestSuite::SortingHeapSortLarge() {
	cout << "Testing heap sort on large array\n";

	// Getting array to sort
	IntWrapper* largeArray = CreateLargeArray();
	// zeroing out the counter
	IntWrapper::mCounter = 0;

	// Heap Sort
	HeapSort(largeArray, 1000);


	// Testing
	bool sorted = true;
	for (int i = 1; i < 1000; ++i) {
		if (largeArray[i] < largeArray[i - 1]) {
			PrintMessage("Array is not sorted correctly");
			cout << "Array: ";
			for (int index = 0; index < 1000; ++index)
				cout << largeArray[index].mValue << ' ';
			cout << '\n';
			sorted = false;
			break;
		}
		if (!sorted)
			break;
	}
	if (IntWrapper::mCounter != 27207)
		PrintMessage("Algorithm is incorrect.  Double-check pseudo-code");

	// Success
	if (sorted &&
		27207 == IntWrapper::mCounter)
		PrintMessage("", true);

	// Cleaning up memory
	delete[] largeArray;
}

void TestSuite::SearchingSequentialSmall() {
	cout << "Testing sequential search on small array";

	// Getting array to sort
	IntWrapper* smallArray = CreateSmallArray();
	// zeroing out the counter
	IntWrapper::mIsEqualCounter = 0;

	// Testing
	// int index = SequentialSearch()


	delete[] smallArray;
}

void TestSuite::SearchingSequentialLarge() {

}

void TestSuite::SearchingBinarySmall() {

}

void TestSuite::SearchingBinaryLarge() {

}

#endif

// Lab 2 Unit Tests
#if LAB_2

#if PALINDROME_NUMBER
void TestSuite::CheckForPalindrome() {
	cout << "Testing to see if numbers are palindromes\n";
	
	int palindromeNumbers[8] = { 6, 55, 494, 7117, 45654, 123321, 7654567, 44566544 };
	int nonPalindromeNumbers[7] = { 12, 983, 6423, 29811, 239582, 5820183, 14826038 };
	bool success = true;

	// Test palindromes
	for (int i = 0; i < 8; ++i)
		if (IsPalindromeNumber(palindromeNumbers[i]) == false) {
			PrintMessage(to_string(palindromeNumbers[i]) + " is not registering as a palindrome number");
			success = false;
		}

	// Testing non-palindromes
	for (int i = 0; i < 7; ++i)
		if (IsPalindromeNumber(nonPalindromeNumbers[i]) == true) {
			PrintMessage(to_string(nonPalindromeNumbers[i]) + " is registering as a palindrome number");
			success = false;
		}

	// Success
	if (success)
		PrintMessage("", true);
}
#endif

#if VECTOR_FILL_FILE
void TestSuite::VectorFillFromFile() {
	cout << "Testing filling vector from a file\n";

	bool success = true;
	IntWrapper* nums = CreateLargeArray();
	DSA_Lab2 vec;

	// Fill in vector from file
	vec.Fill("numbers.bin");

	// Tests
	if (!vec.mValues.size()) {
		PrintMessage("Values were not added to vector");
		success = false;
	}
	if (vec.mValues.size() != 0 && vec.mValues[0] == 10000) {
		PrintMessage("File header was not read");
		success = false;
	}
	if (vec.mValues.size() != 10000) {
		PrintMessage("Not all values were added to vector");
		success = false;
	}
	for (int i = 0; i < vec.mValues.size(); ++i) {
		if (vec.mValues[i] != nums[i]) {
			PrintMessage("One (or more) values were not read/added to vector correctly");
			success = false;
			break;
		}
	}

	// Sucess
	if (success)
		PrintMessage("", true);

	// Cleanup
	delete[] nums;
}
#endif

#if VECTOR_FILL_ARRAY
void TestSuite::VectorFillFromArray() {
	cout << "Testing filling vector from an array\n";

	bool success = true;
	DSA_Lab2 vec;
	unsigned int nums[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	// Fill in vector from file
	vec.Fill(nums, 10);

	// Tests
	if (!vec.mValues.size()) {
		PrintMessage("Values were not added to vector");
		success = false;
	}
	if (vec.mValues.size() != 10) {
		PrintMessage("Not all values were added to vector");
		success = false;
	}
	for (int i = 0; i < vec.mValues.size(); ++i) {
		if (vec.mValues[i] != nums[i]) {
			PrintMessage("One (or more) values were not read/added to vector correctly");
			success = false;
			break;
		}
	}

	// Sucess
	if (success)
		PrintMessage("", true);
}
#endif

#if VECTOR_CLEAR
void TestSuite::VectorClear() {
	cout << "Testing Clear method for vector\n";

	bool success = true;
	DSA_Lab2 vec;
	unsigned int nums[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	// Filling in vector manually
	for (int i = 0; i < 10; ++i)
		vec.mValues.push_back(nums[i]);

	vec.Clear();

	if (vec.mValues.size() != 0) {
		PrintMessage("Vector was not cleared");
		success = false;
	}
	if (vec.mValues.capacity() != 0) {
		PrintMessage("Capacity was not reset");
		success = false;
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if VECTOR_SORT
void TestSuite::VectorSortAscending() {
	cout << "Testing ascending sort on vector\n";

	bool success = true;
	DSA_Lab2 vec;

	int nums[10];
	// Filling in with random values.
	for (int i = 0; i < 10; ++i) {
		nums[i] = rand();
		vec.mValues.push_back(nums[i]);
	}
	sort(nums, nums + 10);

	vec.Sort(true);

	for (int i = 0; i < 10; ++i) {
		if (vec.mValues[i] != nums[i]) {
			PrintMessage("vector was not sorted correctly");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);
}

void TestSuite::VectorSortDescending() {
	cout << "Testing descending sort on vector\n";

	bool success = true;
	DSA_Lab2 vec;

	int nums[10];
	// Filling in with random values.
	for (int i = 0; i < 10; ++i) {
		nums[i] = rand();
		vec.mValues.push_back(nums[i]);
	}
	sort(nums, nums + 10, greater<int>());

	vec.Sort(false);

	for (int i = 0; i < 10; ++i) {
		if (vec.mValues[i] != nums[i]) {
			PrintMessage("vector was not sorted correctly");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if VECTOR_BRACKETS
void TestSuite::VectorIndexing() {
	cout << "Testing [] indexing on vector\n";

	bool success = true;
	DSA_Lab2 vec;
	int nums[10];
	// Filling in with random values.
	for (int i = 0; i < 10; ++i) {
		nums[i] = rand();
		vec.mValues.push_back(nums[i]);
	}

	for (int i = 0; i < 10; ++i) {
		if (vec[i] != nums[i]) {
			PrintMessage("operator[] did not return the correct value");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);

}
#endif

#if VECTOR_CONTAINS
void TestSuite::VectorContainsTrue() {
	cout << "Testing to see if a vector contains a value (found)\n";

	bool success = true;
	DSA_Lab2 vec;
	int nums[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	for (int i = 0; i < 10; ++i)
		vec.mValues.push_back(nums[i]);

	if (vec.Contains(80) == false) {
		PrintMessage("Contains returned false when value was in vector");
		success = false;
	}

	if (success)
		PrintMessage("", true);
}

void TestSuite::VectorContainsFalse() {
	cout << "Testing to see if a vector contains a value (not found)\n";

	bool success = true;
	DSA_Lab2 vec;
	int nums[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	for (int i = 0; i < 10; ++i)
		vec.mValues.push_back(nums[i]);

	if (vec.Contains(11) == true) {
		PrintMessage("Contains returned false when value was in vector");
		success = false;
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if VECTOR_MOVE_PALINDROME
void TestSuite::VectorMovePalindrome() {
	cout << "Testing creating vector of palindromes\n";

	bool success = true;
	DSA_Lab2 vec;
	IntWrapper* nums = CreateLargeArray();

	const int palindromes[23] = {	190091,	245542,	39293,	276672,	473374,
									369963, 502205, 643346, 24942,	787787,
									45454,	69096,	39593,	572275,	602206,
									88588,	84148,	222222,	929929,	785587,
									281182,	3223,	40004
	};

	// Fill in the vector
	for (int i = 0; i < 10000; ++i)
		vec.mValues.push_back(nums[i]);

	vec.MovePalindromes();

	if (vec.mValues.size() != 9977) {
		PrintMessage("Palindrome values were not erased from mValues vector");
		success = false;
	}
	if (vec.mPalindromes.size() != 23) {
		PrintMessage("Palindrome values were not added to mPalindromes vector");
		success = false;
	}

	for (int i = 0; i < vec.mPalindromes.size(); ++i) {
		if (vec.mPalindromes[i] != palindromes[i]) {
			PrintMessage("Palindrome number was not found in mPalindromes vector");
			success = false;
			break;
		}
	}
	
	if (success)
		PrintMessage("", true);

	// Clean up
	delete[] nums;
}
#endif
#endif


#if LAB_3
#if DYNARRAY_CTOR
void TestSuite::DynArrayDefaultConstructorNoArgs() {

	cout << "Testing default constructor\n";
	DynArray<int> da;
	if (da.mSize)
		PrintMessage("Size is not correct value");
	if (da.mCapacity)
		PrintMessage("Capacity is not correct value");
	if (da.mArray)
		PrintMessage("Array should be null");

	if (!da.mSize && !da.mCapacity && !da.mArray)
		PrintMessage("", true);
}
void TestSuite::DynArrayDefaultConstructorWithArgs() {
	cout << "Testing constructor (passing value)\n";
	DynArray<int> da(10);
	if (da.mSize)
		PrintMessage("Size is not correct value");
	if (da.mCapacity != 10)
		PrintMessage("Capacity is not correct value");
	if (!da.mArray)
		PrintMessage("Array should not be null");

	if (!da.mSize && da.mCapacity == 10 && da.mArray)
		PrintMessage("", true);
}
#endif
				
#if DYNARRAY_COPY_CTOR
void TestSuite::DynArrayCopyConstructorInt() {
	cout << "Testing copy constructor with built-in type\n";

	// Creating object to test from
	DynArray<int> original(5);
	for (int i = 0; i < 5; ++i)
		original[original.mSize++] = i;

	// Copy constructor
	DynArray<int> copy = original;

	// Testing
	if (copy.mArray == original.mArray)
		PrintMessage("Shallow copy of array");
	if (copy.mSize != original.mSize)
		PrintMessage("Size is not correct value");
	if (copy.mCapacity != original.mCapacity)
		PrintMessage("Capacity is not correct value");
	for(unsigned int i = 0; i < copy.mSize; ++i)
		if (copy.mArray[i] != original.mArray[i]) {
			PrintMessage("Values in array are not equal");
			break;
		}

	if (copy.mArray != original.mArray &&
		copy.mSize == original.mSize &&
		copy.mCapacity == original.mCapacity)
		PrintMessage("", true);
}
void TestSuite::DynArrayCopyConstructorClass() {
	cout << "Testing copy constructor with user-defined type\n";

	// Creating object to test from
	DynArray<UserDefined> original(5);
	for (int i = 0; i < 5; ++i) {
		original.mArray[i].mString = i + 65;
		original.mArray[i].mValue = i;
	}
		

	// Copy constructor
	DynArray<UserDefined> copy = original;

	// Testing
	if (copy.mArray == original.mArray)
		PrintMessage("Shallow copy of array");
	if (copy.mSize != original.mSize)
		PrintMessage("Size is not correct value");
	if (copy.mCapacity != original.mCapacity)
		PrintMessage("Capacity is not correct value");
	for (unsigned int i = 0; i < copy.mSize; ++i)
		if (copy.mArray[i] != original.mArray[i]) {
			PrintMessage("Values in array are not equal");
			break;
		}

	if (copy.mArray != original.mArray &&
		copy.mSize == original.mSize &&
		copy.mCapacity == original.mCapacity)
		PrintMessage("", true);
}
#endif
				
#if DYNARRAY_ASSIGNMENT_OP
void TestSuite::DynArrayAssignmentOperatorInt() {
	cout << "Testing assignment operator on built-in types\n";

	DynArray<int> original(5), assign;
	for (int i = 0; i < 5; ++i)
		original[original.mSize++] = i;

	// Assignment operator
	assign = original;

	// Testing
	if (assign.mArray == original.mArray)
		PrintMessage("Shallow assign of array");
	if (assign.mSize != original.mSize)
		PrintMessage("Size is not correct value");
	if (assign.mCapacity != original.mCapacity)
		PrintMessage("Capacity is not correct value");
	for(unsigned int i = 0; i < assign.mSize; ++i)
		if (assign.mArray[i] != original.mArray[i]) {
			PrintMessage("Values in array are not equal");
			break;
		}

	if (assign.mArray != original.mArray &&
		assign.mSize == original.mSize &&
		assign.mCapacity == original.mCapacity)
		PrintMessage("", true);

}
void TestSuite::DynArrayAssignmentOperatorClass() {
	cout << "Testing copy constructor with user-defined type\n";

	// Creating object to test from
	DynArray<UserDefined> original(5), assign;
	for (int i = 0; i < 5; ++i) {
		original.mArray[i].mString = i + 65;
		original.mArray[i].mValue = i;
	}


	// Assignment operator
	assign = original;

	// Testing
	if (assign.mArray == original.mArray)
		PrintMessage("Shallow assign of array");
	if (assign.mSize != original.mSize)
		PrintMessage("Size is not correct value");
	if (assign.mCapacity != original.mCapacity)
		PrintMessage("Capacity is not correct value");
	for (unsigned int i = 0; i < assign.mSize; ++i)
		if (assign.mArray[i] != original.mArray[i]) {
			PrintMessage("Values in array are not equal");
			break;
		}

	if (assign.mArray != original.mArray &&
		assign.mSize == original.mSize &&
		assign.mCapacity == original.mCapacity)
		PrintMessage("", true);
}
#endif
		
#if DYNARRAY_BRACKET_OP
void TestSuite::DynArrayBracketOperator_ReadOnlyInt() {
	cout << "Testing [] operator (read-only) for built-in types\n";

	DynArray<int> da(1);
	da.mArray[0] = 1;

	// Testing
	if (da[0] != 1)
		PrintMessage("Value returned is incorrect");

	else
		PrintMessage("", true);
}
void TestSuite::DynArrayBracketOperator_ReadOnlyClass() {
	cout << "Testing [] operator (read-only) for user-defined types\n";

	DynArray<UserDefined> da(1);
	da.mArray[0] = { "Test", 10 };

	// Testing
	if (da[0].mString != "Test" && da[0].mValue != 10)
		PrintMessage("Value returned is incorrect");

	else
		PrintMessage("", true);
}
void TestSuite::DynArrayBracketOperator_Write() {
	cout << "Testing [] operator for writing\n";

	DynArray<int> da(5);

	da[4] = 2;

	// Testing
	if (da.mArray[4] != 2)
		PrintMessage("Value written is incorrect");

	else
		PrintMessage("", true);
}
#endif
		
#if DYNARRAY_ACCESSORS
void TestSuite::DynArrayAccessors_Size() {
	cout << "Testing Size accessor\n";
	DynArray<char> da;
	da.mSize = 7;

	// Testing
	if (da.Size() != 7)
		PrintMessage("Size accessor is returning incorrect value.");
	else
		PrintMessage("", true);
}
void TestSuite::DynArrayAccessors_Capacity() {
	cout << "Testing Capacity accessor\n";

	DynArray<char> da;
	da.mCapacity = 4;

	// Testing
	if (da.Capacity() != 4)
		PrintMessage("Capacity accessor is returning incorrect value.");
	else
		PrintMessage("", true);
}
#endif

#if DYNARRAY_CLEAR
void TestSuite::DynArrayClear() {
	cout << "Testing Clear method\n";
	DynArray<int> da(4);

	da.Clear();

	// Testing
	if (da.mArray != nullptr)
		PrintMessage("Array should be null");
	if (da.mCapacity != 0)
		PrintMessage("Capacity should be 0");
	if (da.mSize != 0)
		PrintMessage("Size should be 0");

	if (!da.mCapacity && !da.mSize && !da.mArray)
		PrintMessage("", true);
}
#endif

#if DYNARRAY_RESERVE_ZERO
void TestSuite::DynArrayReserveZero() {
	cout << "Testing Reserve from empty DynArray\n";

	DynArray<int> da;

	da.Reserve();

	if (da.mArray == nullptr)
		PrintMessage("Array not pointing to valid memory");
	if (da.mCapacity != 1)
		PrintMessage("Capacity should be 1");
	if (da.mSize != 0)
		PrintMessage("Size should be 0");

	if (da.mArray &&
		1 == da.mCapacity &&
		0 == da.mSize)
		PrintMessage("", true);
}
#endif

#if DYNARRAY_RESERVE_DOUBLE
void TestSuite::DynArrayReserveDouble() {
	cout << "Testing Reserve with default doubling capacity\n";

	DynArray<int> da(10);
	da.mSize = 5;
	for (unsigned int i = 0; i < da.mSize; ++i)
		da.mArray[i] = i;
	int* arrayAddress = da.mArray;

	da.Reserve();

	// Testing
	if (da.mArray == nullptr)
		PrintMessage("Array not pointing to valid memory");
	if (da.mArray == arrayAddress)
		PrintMessage("New array was not made");
	for(int i = 0; i < 5; ++i)
		if (da.mArray[i] != i) {
			PrintMessage("Data in array was not copied over correctly");
			break;
		}
	if (da.mCapacity != 20)
		PrintMessage("Capacity should be doubled");
	if (da.mSize != 5)
		PrintMessage("Size should not change");

	if (da.mArray &&
		da.mCapacity == 20 &&
		da.mSize == 5)
		PrintMessage("", true);
}
#endif

#if DYNARRAY_RESERVE_SPEC
void TestSuite::DynArrayReserveSpecific() {
	cout << "Testing Reserve with specific value\n";
	
	DynArray<int> da(10);
	da.mSize = 5;
	for (unsigned int i = 0; i < da.mSize; ++i)
		da.mArray[i] = i;
	int* arrayAddress = da.mArray;

	da.Reserve(15);

	// Testing
	if (da.mArray == nullptr)
		PrintMessage("Array not pointing to valid memory");
	if (da.mArray == arrayAddress)
		PrintMessage("New array was not made");
	for (int i = 0; i < 5; ++i)
		if (da.mArray[i] != i) {
			PrintMessage("Data in array was not copied over correctly");
			break;
		}
	if (da.mCapacity != 15)
		PrintMessage("Capacity is not the same as value passed in");
	if (da.mSize != 5)
		PrintMessage("Size was changed");

	if (da.mArray &&
		da.mCapacity == 15 &&
		da.mSize == 5)
		PrintMessage("", true);
}
#endif

#if DYNARRAY_RESERVE_SMALLER
void TestSuite::DynArrayReserveSmaller() {
	cout << "Testing Reserve with a smaller value than current capacity\n";

	DynArray<int> da(10);
	da.mSize = 5;
	for (unsigned int i = 0; i < da.mSize; ++i)
		da.mArray[i] = i;
	int* arrayAddress = da.mArray;

	da.Reserve(1);

	if (da.mArray != arrayAddress)
		PrintMessage("Array was changed/re-allocated");
	for (int i = 0; i < 5; ++i)
		if (da.mArray[i] != i) {
			PrintMessage("Data in array was changed");
			break;
		}
	if (da.mCapacity != 10)
		PrintMessage("Capacity was changed");
	if (da.mSize != 5)
		PrintMessage("Size was changed");

	if (da.mArray == arrayAddress &&
		da.mCapacity == 10 &&
		da.mSize == 5)
		PrintMessage("", true);
}
#endif

#if DYNARRAY_APPEND_NO_RESIZE
void TestSuite::DynArrayAppendNoResize() {
	cout << "Testing Append with no need to resize\n";

	DynArray<int> da(5);

	for (int i = 0; i < 5; ++i)
		da.Append(i * 10);
	
	// Testing
	if (nullptr == da.mArray)
		PrintMessage("Array is not pointing to valid memory");
	for (int i = 0; i < 5; ++i)
		if (da.mArray[i] != i*10) {
			PrintMessage("Data in array was not added correctly");
			break;
		}
	if (da.mCapacity != 5)
		PrintMessage("Capacity is not correct value");
	if (da.mSize != 5)
		PrintMessage("Size is not correct value");

	if (da.mArray &&
		da.mCapacity == 5 &&
		da.mSize == 5)
		PrintMessage("", true);
}
#endif

#if DYNARRAY_APPEND_RESIZE
void TestSuite::DynArrayAppendResize() {
	cout << "Testing Append with need to resize\n";

	DynArray<int> da(3);

	for (int i = 0; i < 5; ++i)
		da.Append(i * 10);

	// Testing
	if (nullptr == da.mArray)
		PrintMessage("Array is not pointing to valid memory");
	for (int i = 0; i < 5; ++i)
		if (da.mArray[i] != i*10) {
			PrintMessage("Data in array was not added correctly");
			break;
		}
	if (da.mCapacity != 6)
		PrintMessage("Capacity is not correct value");
	if (da.mSize != 5)
		PrintMessage("Size is not correct value");

	if (da.mArray &&
		da.mCapacity == 6 &&
		da.mSize == 5)
		PrintMessage("", true);
}
#endif

#endif	// END LAB_2

#if LAB_4

#if LIST_QUEUE_ADD
void TestSuite::ListQueueAdd() {
	cout << "Testing adding to a list using queue ordering\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };

	DSA_Lab4 queue;

	queue.QueueOrderingAdd(arr, 5);

	if (queue.mList.size() != 5) {
		PrintMessage("Not all values were added to list (or list was not cleared)\n");
		success = false;
	}
	list<float>::iterator it = queue.mList.begin();
	for (int i = 0; i < 5; ++i, ++it) {
		if (*it != arr[i]) {
			PrintMessage("One (or more) values were not added with queue ordering");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);

}
#endif

#if LIST_STACK_ADD
void TestSuite::ListStackAdd() {
	cout << "Testing adding to a list using stack ordering\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };

	DSA_Lab4 stack;

	stack.StackOrderingAdd(arr, 5);

	if (stack.mList.size() != 5) {
		PrintMessage("Not all values were added to list (or list was not cleared)\n");
		success = false;
	}
	list<float>::iterator it = stack.mList.begin();
	for (int i = 4; i >= 0; --i, ++it) {
		if (*it != arr[i]) {
			PrintMessage("One (or more) values were not added with stack ordering");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if LIST_QUEUE_REMOVE
void TestSuite::ListQueueRemove() {
	cout << "Testing removing from a list using queue ordering\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };

	DSA_Lab4 queue;

	queue.mList = list<float>(arr, arr + 5);

	float temp = queue.QueueOrderingRemove();

	if (temp != 5.6f) {
		PrintMessage("Correct value was not returned (not queue ordering)");
		success = false;
	}
	if (queue.mList.size() != 4) {
		PrintMessage("Value was not removed from the list");
		success = false;
	}
	
	if (success)
		PrintMessage("", true);
}
#endif

#if LIST_STACK_REMOVE
void TestSuite::ListStackRemove() {
	cout << "Testing removing from a list using stack ordering\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };
	reverse(arr, arr + 5);

	DSA_Lab4 queue;

	queue.mList = list<float>(arr, arr + 5);

	float temp = queue.StackOrderingRemove();

	if (temp != 0.43f) {
		PrintMessage("Correct value was not returned (not queue ordering)");
		success = false;
	}
	if (queue.mList.size() != 4) {
		PrintMessage("Value was not removed from the list");
		success = false;
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if LIST_INSERT_INDEX
void TestSuite::ListInsertIndex() {
	cout << "Testing inserting into a list at a specified index\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };
	float cmp[6] = { 5.6f, 99.32f, 2.25f, 11.98f, 7.2f, 0.43f };


	DSA_Lab4 lst;
	lst.mList = list<float>(arr, arr + 5);
	
	lst.Insert(2.25f, 2);

	if (lst.mList.size() != 6) {
		PrintMessage("Size of list not correct (value not added?)");
		success = false;
	}
	list<float>::iterator it = lst.mList.begin();
	for (int i = 0; i < 6; ++i, ++it) {
		if (*it != cmp[i]) {
			PrintMessage("Value was not added at correct position");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if LIST_INSERT_ITER
void TestSuite::ListInsertIterator() {
	cout << "Testing inserting into a list using an iterator\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };
	float cmp[6] = { 5.6f, 99.32f, 2.25f, 11.98f, 7.2f, 0.43f };


	DSA_Lab4 lst;
	lst.mList = list<float>(arr, arr + 5);
	list<float>::iterator it = lst.mList.begin();
	++++it;

	lst.Insert(2.25f, it);

	if (lst.mList.size() != 6) {
		PrintMessage("Size of list not correct (value not added?)");
		success = false;
	}
	it = lst.mList.begin();
	for (int i = 0; i < 6; ++i, ++it) {
		if (*it != cmp[i]) {
			PrintMessage("Value was not added at correct position");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);
}
#endif

#if LIST_REMOVE_DECIMAL
void TestSuite::ListRemoveDecimal() {
	cout << "Testing removing values with decimal > .5\n";

	bool success = true;
	float arr[5] = { 5.6f, 99.32f, 11.98f, 7.2f, 0.43f };
	float cmp[3] = { 99.32f, 7.2f, 0.43f };

	DSA_Lab4 lst;
	lst.mList = list<float>(arr, arr + 5);

	int removed = lst.RemoveDecimalGreater(0.5f);

	if (lst.mList.size() != 3) {
		PrintMessage("Size of list not correct");
		success = false;
	}
	if (removed != 2) {
		PrintMessage("Function not returning correct value");
		success = false;
	}
	
	list<float>::iterator it = lst.mList.begin();
	for (int i = 0; i < 3; ++i, ++it) {
		if (*it != cmp[i]) {
			PrintMessage("One (or more) values were not removed");
			success = false;
			break;
		}
	}

	if (success)
		PrintMessage("", true);
}
#endif
#endif

#if LAB_5
#if LIST_CTOR
void TestSuite::LinkedListDefaultConstructor() {
	cout << "Testing DList's default constructor\n";
	
	DList<int> list;

	if (list.mHead)
		PrintMessage("head is not null");
	if (list.mTail)
		PrintMessage("tail is not null");
	if (list.mSize)
		PrintMessage("size is not zero");

	if (!list.mHead && !list.mTail)
		PrintMessage("", true);
}
#endif

#if LIST_NODE_CTOR
void TestSuite::LinkedListNodeConstructorWithDefaults() {
	cout << "Testing DList::Node constructor with default node parameters\n";

	DList<int>::Node node(10);

	if (10 != node.data)
		PrintMessage("Data in node is incorrect");
	if (node.next)
		PrintMessage("Node's next is not null");
	if (node.prev)
		PrintMessage("Node's prev is not null");

	if (10 == node.data && !node.next && !node.prev)
		PrintMessage("", true);
}
void TestSuite::LinkedListNodeConstructor() {
	cout << "Testing DList::Node constructor with valid node parameters\n";

	DList<int>::Node prev(5);
	DList<int>::Node next(3);
	DList<int>::Node node(10, &next, &prev);

	if (10 != node.data)
		PrintMessage("Data in node is incorrect");
	if (node.next != &next)
		PrintMessage("Node's next is not pointing to correct node");
	if (node.prev != &prev)
		PrintMessage("Node's prev is not pointing to correct node");

	if (10 == node.data &&
		node.next == &next &&
		node.prev == &prev)
		PrintMessage("", true);
}
#endif

#if LIST_COPY_CTOR
void TestSuite::LinkedListCopyConstructorInt() {
	cout << "Testing copy constructor with built-in type\n";

	DList<float> list;

	// Adding in a few nodes (non-conventional code)
	list.mHead = new DList<float>::Node(1.1f);
	list.mHead->next = new DList<float>::Node(2.2f);
	list.mHead->next->next = new DList<float>::Node(3.3f);
	list.mHead->next->next->next = nullptr;
	list.mSize = 3;

	// Calling copy constructor
	DList<float> copy(list);

	if (copy.mSize != 3)
		PrintMessage("Size is incorrect value");
	if (copy.mHead->data != 1.1f &&
		copy.mHead->next->data != 2.2f &&
		copy.mHead->next->next->data != 3.3f)
		PrintMessage("One (or more) nodes have the incorrect value");
	if (copy.mHead->next->next->next)
		PrintMessage("No null pointer at the end of the list");
	if (copy.mHead->prev)
		PrintMessage("Head's previous pointer is not null");

	if (3 == copy.mSize &&
		copy.mHead->data == 1.1f &&
		copy.mHead->next->data == 2.2f &&
		copy.mHead->next->next->data == 3.3f &&
		!copy.mHead->next->next->next &&
		!copy.mHead->prev)
		PrintMessage("", true);
}
void TestSuite::LinkedListCopyConstructorClass() {
	cout << "Testing copy constructor with user-defined type\n";

	DList<UserDefined> list;
	UserDefined array[3] = {
		UserDefined("Alpha", 1),
		UserDefined("Bravo", 2),
		UserDefined("Charlie", 3)
	};

	// Adding in a few nodes (non-conventional code)
	list.mHead = new DList<UserDefined>::Node(UserDefined("Alpha", 1));
	list.mHead->next = new DList<UserDefined>::Node(UserDefined("Bravo", 2));
	list.mHead->next->next = new DList<UserDefined>::Node(UserDefined("Charlie", 3));
	list.mHead->next->next->next = nullptr;
	list.mSize = 3;

	// Calling copy constructor
	DList<UserDefined> copy(list);

	if (copy.mSize != 3)
		PrintMessage("Size is incorrect value");
	if (copy.mHead->data != array[0] &&
		copy.mHead->next->data != array[1] &&
		copy.mHead->next->next->data != array[2])
		PrintMessage("One (or more) nodes have the incorrect value");
	if (copy.mHead->next->next->next)
		PrintMessage("No null pointer at the end of the list");
	if (copy.mHead->prev)
		PrintMessage("Head's previous pointer is not null");

	if (3 == copy.mSize &&
		copy.mHead->data == array[0] &&
		copy.mHead->next->data == array[1] &&
		copy.mHead->next->next->data == array[2] &&
		!copy.mHead->next->next->next &&
		!copy.mHead->prev)
		PrintMessage("", true);
}
#endif

#if LIST_ASSIGNMENT_OP
void TestSuite::LinkedListAssignmentOperatorInt() {
	cout << "Testing assignment operator with built-in type\n";

	DList<float> list;
	DList<float> assign;

	// Adding in a few nodes (non-conventional code)
	list.mHead = new DList<float>::Node(1.1f);
	list.mHead->next = new DList<float>::Node(2.2f);
	list.mHead->next->next = new DList<float>::Node(3.3f);
	list.mHead->next->next->next = nullptr;
	list.mSize = 3;

	// Calling assignment operator
	assign = list;

	if (assign.mSize != 3)
		PrintMessage("Size is incorrect value");
	if (assign.mHead->data != 1.1f &&
		assign.mHead->next->data != 2.2f &&
		assign.mHead->next->next->data != 3.3f)
		PrintMessage("One (or more) nodes have the incorrect value");
	if (assign.mHead->next->next->next)
		PrintMessage("No null pointer at the end of the list");
	if (assign.mHead->prev)
		PrintMessage("Head's previous pointer is not null");

	if (3 == assign.mSize &&
		assign.mHead->data == 1.1f &&
		assign.mHead->next->data == 2.2f &&
		assign.mHead->next->next->data == 3.3f &&
		!assign.mHead->next->next->next &&
		!assign.mHead->prev)
		PrintMessage("", true);
}
void TestSuite::LinkedListAssignmentOperatorClass() {
	cout << "Testing assignment operator with user-defined type\n";

	DList<UserDefined> list;
	DList<UserDefined> assign;

	UserDefined array[3] = {
		UserDefined("Alpha", 1),
		UserDefined("Bravo", 2),
		UserDefined("Charlie", 3)
	};

	// Adding in a few nodes (non-conventional code)
	list.mHead = new DList<UserDefined>::Node(UserDefined("Alpha", 1));
	list.mHead->next = new DList<UserDefined>::Node(UserDefined("Bravo", 2));
	list.mHead->next->next = new DList<UserDefined>::Node(UserDefined("Charlie", 3));
	list.mHead->next->next->next = nullptr;
	list.mSize = 3;

	// Calling assignment operator
	assign = list;

	if (assign.mSize != 3)
		PrintMessage("Size is incorrect value");
	if (assign.mHead->data != array[0] &&
		assign.mHead->next->data != array[1] &&
		assign.mHead->next->next->data != array[2])
		PrintMessage("One (or more) nodes have the incorrect value");
	if (assign.mHead->next->next->next)
		PrintMessage("No null pointer at the end of the list");
	if (assign.mHead->prev)
		PrintMessage("Head's previous pointer is not null");

	if (3 == assign.mSize &&
		assign.mHead->data == array[0] &&
		assign.mHead->next->data == array[1] &&
		assign.mHead->next->next->data == array[2] &&
		!assign.mHead->next->next->next &&
		!assign.mHead->prev)
		PrintMessage("", true);
}
#endif

#if LIST_ADDHEAD
void TestSuite::LinkedListAddHeadEmpty() {
	cout << "Testing AddHead on empty list\n";

	DList<string> list;

	list.AddHead("first");
	
	if (!list.mHead)
		PrintMessage("Head was not assigned to created node");
	if (!list.mTail)
		PrintMessage("Tail was not assigned to created node");
	if (list.mHead != list.mTail)
		PrintMessage("Head and Tail should point to same node");
	if (list.mHead->data != "first")
		PrintMessage("Node's data was not set");
	if (list.mHead->prev != nullptr)
		PrintMessage("Node's prev is not correctly set");
	if (list.mHead->next != nullptr)
		PrintMessage("Node's next is not correctly set");
	if (list.mSize != 1)
		PrintMessage("Size is incorrect");

	if (list.mHead == list.mTail &&
		list.mHead->data == "first" &&
		list.mHead->prev == nullptr &&
		list.mHead->next == nullptr &&
		1 == list.mSize)
		PrintMessage("", true);
}
void TestSuite::LinkedListAddHeadExisting() {
	cout << "Testing AddHead on existing list\n";

	DList<string> list;

	list.AddHead("first");
	list.AddHead("second");

	// Creating some temporary Node pointers for ease of testing
	DList<string>::Node* tempHead = list.mHead;
	DList<string>::Node* tempTail = list.mTail;

	if (!list.mHead)
		PrintMessage("Head was not assigned to created node");
	if (!list.mTail)
		PrintMessage("Tail was not assigned to created node");
	if (list.mHead->data != "second")
		PrintMessage("Nodes are not linked together correctly");
	if (list.mHead->next != tempTail)
		PrintMessage("Head is not tied to the next node in the list");
	if (list.mTail && list.mTail->prev != tempHead)
		PrintMessage("Second node is not tied to head");
	if (list.mSize != 2)
		PrintMessage("Size is incorrect");

	if (list.mHead->next == tempTail &&
		list.mTail->prev == tempHead &&
		2 == list.mSize)
		PrintMessage("", true);
}
#endif

#if LIST_ADDTAIL
void TestSuite::LinkedListAddTailEmpty() {
		cout << "Testing AddTail on empty list\n";

		DList<string> list;

		list.AddTail("first");

		if (!list.mHead)
			PrintMessage("Head was not assigned to created node");
		if (!list.mTail)
			PrintMessage("Tail was not assigned to created node");
		if (list.mHead != list.mTail)
			PrintMessage("Head and Tail should point to same node");
		if (list.mHead->data != "first")
			PrintMessage("Node's data was not set");
		if (list.mHead->prev != nullptr)
			PrintMessage("Node's prev is not correctly set");
		if (list.mHead->next != nullptr)
			PrintMessage("Node's next is not correctly set");
		if (list.mSize != 1)
			PrintMessage("Size is incorrect");

		if (list.mHead == list.mTail &&
			list.mHead->data == "first" &&
			list.mHead->prev == nullptr &&
			list.mHead->next == nullptr &&
			1 == list.mSize)
			PrintMessage("", true);
}
void TestSuite::LinkedListAddTailExisting() {
	cout << "Testing AddHead on existing list\n";

	DList<string> list;

	list.AddTail("first");
	list.AddTail("second");

	// Creating some temporary Node pointers for ease of testing
	DList<string>::Node* tempHead = list.mHead;
	DList<string>::Node* tempTail = list.mTail;

	if (!list.mHead)
		PrintMessage("Head was not assigned to created node");
	if (!list.mTail)
		PrintMessage("Tail was not assigned to created node");
	if (list.mTail && list.mTail->data != "second")
		PrintMessage("Nodes are not linked together correctly");
	if (list.mHead->next != tempTail)
		PrintMessage("Head is not tied to the next node in the list");
	if (list.mTail->prev != tempHead)
		PrintMessage("Second node is not tied to head");
	if (list.mSize != 2)
		PrintMessage("Size is incorrect");

	if (list.mHead->next == tempTail &&
		list.mTail->prev == tempHead &&
		2 == list.mSize)
		PrintMessage("", true);
}
#endif

#if LIST_CLEAR
void TestSuite::LinkedListClear() {
	cout << "Testing Clear method\n";

	DList<int> list;

	// Adding some nodes (non-conventional code)
	list.mHead = new DList<int>::Node(1);
	list.mHead->next = new DList<int>::Node(2, nullptr, list.mHead);
	list.mHead->next->next = new DList<int>::Node(3, nullptr, list.mHead->next);
	list.mTail = list.mHead->next->next;
	list.mSize = 3;

	list.Clear();

	if (list.mHead)
		PrintMessage("Head is not null");
	if (list.mTail)
		PrintMessage("Tail is not null");
	if (list.mSize)
		PrintMessage("Size is not zero");

	if (!list.mHead &&
		!list.mTail &&
		!list.mSize)
		PrintMessage("", true);

}
#endif

#if LIST_INSERT
void TestSuite::LinkedListInsertEmpty() {
	cout << "Testing Insert on empty list\n";

	DList<double> list;
	DList<double>::Iterator iter;
	iter.mCurr = list.mHead;

	list.Insert(iter, 0.1);


	if (!list.mHead)
		PrintMessage("Head is not pointing to a valid node");
	else {
		if (list.mHead->data != 0.1)
			PrintMessage("Head's data is not set correctly");
		if (list.mHead->prev)
			PrintMessage("Head's prev is not set correctly");
		if (list.mHead->next)
			PrintMessage("Head's next is not set correctly");
	}
	if (!list.mTail)
		PrintMessage("Tail is not pointing to a valid node");
	else {
		if (list.mTail->data != 0.1)
			PrintMessage("Tail's data is not set correctly");
		if (list.mTail->prev)
			PrintMessage("Tail's prev is not set correctly");
		if (list.mTail->next)
			PrintMessage("Tail's next is not set correctly");
	}	
	if (iter.mCurr != list.mHead)
		PrintMessage("Iterator is not pointing to inserted node");
	if (list.mSize != 1)
		PrintMessage("Size is incorrect");

	if (list.mHead &&
		list.mTail &&
		list.mHead == list.mTail &&
		list.mHead->data == 0.1 &&
		1 == list.mSize &&
		iter.mCurr == list.mHead)
		PrintMessage("", true);
}
void TestSuite::LinkedListInsertHead() {
	cout << "Testing Insert in front of head\n";

	DList<double> list;
	list.mTail = list.mHead = new DList<double>::Node(0.2);
	list.mSize = 1;
	DList<double>::Iterator iter;
	iter.mCurr = list.mHead;

	list.Insert(iter, 0.1);

	if (!list.mHead)
		PrintMessage("Head is not pointing to a valid node");
	else {
		if (list.mHead->data != 0.1)
			PrintMessage("Head's data is not set correctly");
		if (list.mHead->prev)
			PrintMessage("Head's prev is not set correctly");
		if (!list.mHead->next)
			PrintMessage("Head's next is not set correctly");
	}
	if (!list.mTail)
		PrintMessage("Tail is not pointing to a valid node");
	else {
		if (list.mTail->data != 0.2)
			PrintMessage("Tail's data is not set correctly");
		if (!list.mTail->prev)
			PrintMessage("Tail's prev is not set correctly");
		if (list.mTail->next)
			PrintMessage("Tail's next is not set correctly");
	}
	if (iter.mCurr != list.mHead)
		PrintMessage("Iterator is not pointing to inserted node");
	if (list.mSize != 2)
		PrintMessage("Size is incorrect");

	if (list.mHead &&
		list.mTail &&
		list.mHead->data == 0.1 &&
		list.mTail->data == 0.2 && 
		2 == list.mSize &&
		iter.mCurr == list.mHead)
		PrintMessage("", true);
}
void TestSuite::LinkedListInsertMiddle() {
	cout << "Testing Insert in middle of list\n";

	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mTail = list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);

	DList<double>::Iterator iter;
	iter.mCurr = list.mHead->next;

	list.Insert(iter, 0.4);

	if (list.mHead->next->data != 0.4)
		PrintMessage("Node not inserted at correct location (or pointers are not linked correctly)");
	if (list.mTail->prev->data != 0.4)
		PrintMessage("Node not inserted at correct location (or pointers are not linked correctly)");
	if (iter.mCurr->data != 0.4)
		PrintMessage("Iterator is not pointing to inserted node"); 
	if (iter.mCurr->prev != list.mHead)
		PrintMessage("Inserted node's prev pointer is not correct");
	if (iter.mCurr->next != list.mTail)
		PrintMessage("Inserted node's next pointer is not correct");
	
	if (iter.mCurr->data == 0.4 &&
		iter.mCurr->prev == list.mHead &&
		iter.mCurr->next == list.mTail &&
		list.mHead->next == iter.mCurr &&
		list.mTail->prev == iter.mCurr)
		PrintMessage("", true);

}
#endif

#if LIST_ERASE
void TestSuite::LinkedListEraseEmpty() {
	cout << "Testing Erase on an empty list\n";

	DList<int> list;

	DList<int>::Iterator iter;
	iter.mCurr = list.mHead;

	list.Erase(iter);

	// If you don't crash, success!
	PrintMessage("", true);
}
void TestSuite::LinkedListEraseHead() {
	cout << "Testing Erase by erasing head\n";

	DList<double> list;
	
	// Adding a couple nodes (non-conventional code)
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mTail = list.mHead->next;
	list.mSize = 2;
	DList<double>::Node* newHead = list.mHead->next;

	DList<double>::Iterator iter;
	iter.mCurr = list.mHead;

	list.Erase(iter);

	if (iter.mCurr != newHead)
		PrintMessage("iter's current is not pointing to correct node");
	if (list.mHead != newHead)
		PrintMessage("head is not pointing to correct node");
	if (list.mHead->prev)
		PrintMessage("head's prev should be null");
	if (list.mTail != newHead)
		PrintMessage("tail is not pointing to correct node");
	if (list.mSize != 1)
		PrintMessage("Size is incorrect");

	if (iter.mCurr == newHead &&
		list.mHead == newHead &&
		!list.mHead->prev &&
		list.mTail == newHead &&
		1 == list.mSize)
		PrintMessage("", true);
}
void TestSuite::LinkedListEraseTail() {
	cout << "Testing Erase on tail\n";

	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mHead->next->next = new DList<double>::Node(0.3, nullptr, list.mHead->next);
	list.mTail = list.mHead->next->next;
	list.mSize = 3;

	DList<double>::Iterator iter;
	iter.mCurr = list.mTail;

	list.Erase(iter);

	if(iter.mCurr != nullptr)
		PrintMessage("iter's current is not pointing to correct node");
	if (list.mTail != list.mHead->next)
		PrintMessage("tail is not pointing to correct node");
	if (list.mTail->next)
		PrintMessage("tail's next should be null");
	if (list.mTail->prev != list.mHead)
		PrintMessage("tail's prev is not pointing to correct node");
	if (list.mSize != 2)
		PrintMessage("Size is incorrect");

	if (!iter.mCurr &&
		list.mTail == list.mHead->next &&
		list.mTail->prev == list.mHead &&
		!list.mTail->next &&
		2 == list.mSize)
		PrintMessage("", true);
}
void TestSuite::LinkedListEraseMiddle() {
	cout << "Testing Erase on middle of list\n";

	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mHead->next->next = new DList<double>::Node(0.3, nullptr, list.mHead->next);
	list.mSize = 3;
	list.mTail = list.mHead->next->next;

	DList<double>::Iterator iter;
	iter.mCurr = list.mHead->next;

	list.Erase(iter);

	if (iter.mCurr != list.mTail)
		PrintMessage("iter's current is not pointing to correct node");
	if (iter.mCurr->prev != list.mHead)
		PrintMessage("iter's current prev is not pointing to correct node");
	if (iter.mCurr->next != nullptr)
		PrintMessage("iter's current next is not pointing to correct node");
	if (list.mHead->next != list.mTail)
		PrintMessage("List is not linked correctly after erasing");
	if (list.mTail->prev != list.mHead)
		PrintMessage("List is not linked correctly after erasing");
	if (list.mSize != 2)
		PrintMessage("Size is incorrect");

	if (iter.mCurr == list.mTail &&
		iter.mCurr->prev == list.mHead &&
		iter.mCurr->next == nullptr &&
		list.mHead->next == list.mTail &&
		list.mTail->prev == list.mHead &&
		2 == list.mSize)
		PrintMessage("", true);
}
#endif

#if LIST_ITER_BEGIN
void TestSuite::LinkedListIterBegin() {
	cout << "Testing Begin method\n";

	DList<bool> list;
	list.mHead = new DList<bool>::Node(true);
	
	DList<bool>::Iterator iter = list.Begin();

	if (iter.mCurr != list.mHead)
		PrintMessage("Iterator's current is not pointing to correct node");

	if (iter.mCurr == list.mHead)
		PrintMessage("", true);
}
#endif

#if LIST_ITER_END
void TestSuite::LinkedListIterEnd() {
	cout << "Testing End method\n";

	DList<bool> list;
	
	list.mHead = new DList<bool>::Node(true);
	list.mHead->next = new DList<bool>::Node(true, nullptr, list.mHead);

	DList<bool>::Iterator iter = list.End();

	if (iter.mCurr != nullptr)
		PrintMessage("Iterator's current is not pointing to correct node");

	if (!iter.mCurr)
		PrintMessage("", true);
}
#endif

#if LIST_ITER_INCREMENT
void TestSuite::LinkedListIterPreIncrement() {
	cout << "Testing Iterator pre-fix increment\n";
	
	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mHead->next->next = new DList<double>::Node(0.3, nullptr, list.mHead->next);
	
	DList<double>::Iterator iter;
	iter.mCurr = list.mHead;

	iter = ++iter;

	if (iter.mCurr != list.mHead->next)
		PrintMessage("Iterator's current is not pointing to correct node");

	if (iter.mCurr == list.mHead->next)
		PrintMessage("", true);
}
void TestSuite::LinkedListIterPostIncrement() {
	cout << "Testing Iterator pre-fix increment\n";

	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mHead->next->next = new DList<double>::Node(0.3, nullptr, list.mHead->next);

	DList<double>::Iterator iter;
	iter.mCurr = list.mHead;

	DList<double>::Iterator prevIter = iter++;

	if (iter.mCurr != list.mHead->next)
		PrintMessage("Iterator's current is not pointing to correct node");
	if (prevIter.mCurr != list.mHead)
		PrintMessage("Post-fix increment is not returning correct iterator");

	if (iter.mCurr == list.mHead->next &&
		prevIter.mCurr == list.mHead)
		PrintMessage("", true);
}
#endif

#if LIST_ITER_DECREMENT
void TestSuite::LinkedListIterPreDecrement() {
	cout << "Testing Iterator pre-fix increment\n";

	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mHead->next->next = new DList<double>::Node(0.3, nullptr, list.mHead->next);

	DList<double>::Iterator iter;
	iter.mCurr = list.mHead->next;

	iter = --iter;

	if (iter.mCurr != list.mHead)
		PrintMessage("Iterator's current is not pointing to correct node");
	
	if (iter.mCurr == list.mHead)
		PrintMessage("", true);
}
void TestSuite::LinkedListIterPostDecrement() {
	cout << "Testing Iterator post-fix decrement\n";

	DList<double> list;
	list.mHead = new DList<double>::Node(0.1);
	list.mHead->next = new DList<double>::Node(0.2, nullptr, list.mHead);
	list.mHead->next->next = new DList<double>::Node(0.3, nullptr, list.mHead->next);

	DList<double>::Iterator iter;
	iter.mCurr = list.mHead->next;
	
	DList<double>::Iterator iterNext = iter--;

	if (iter.mCurr != list.mHead)
		PrintMessage("Iterator's current is not pointing to correct node");
	if(iterNext.mCurr != list.mHead->next)
		PrintMessage("Post-fix decrement is not returning correct iterator");

	if (iter.mCurr == list.mHead)
		PrintMessage("", true);
}
#endif
#endif	// END LAB_5

#if LAB_6
#if MAP_POPULATE_LETTER_VALUES
void TestSuite::MapPopulateLetterValues() {
	cout << "Testing population of letter values\n";

	int values[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	DSA_Lab6 scrabble;
	bool success = true;

	scrabble.PopulateLetterValues(values);
	
	for (int i = 0; i < 26; ++i) {
		if (scrabble.mLetterValues[i] != values[i]) {
			PrintMessage("Value at [" + to_string(i) + "] is incorrect");
			success = false;
			break;
		}
	}

	// Success
	if (success)
		PrintMessage("", true);	
}
#endif

#if MAP_GET_LETTER_VALUE 
void TestSuite::MapGetLetterValue() {
	cout << "Testing getting the value of a single letter\n";

	DSA_Lab6 scrabble;
	int values[3];
	int fakeResults[3] = { 0, 2, 32 }; 
	bool success = true;
	
	// Filling in letters with dummy values
	memset(scrabble.mLetterValues, 0, sizeof(short) * 26);
	for (int i = 0; i < 26; i++)
		scrabble.mLetterValues[i] = i * 2;

	// Testing several letters
	values[0] = scrabble.GetLetterValue('A');
	values[1] = scrabble.GetLetterValue('B');
	values[2] = scrabble.GetLetterValue('Q');

	for (int i = 0; i < 3; ++i) {
		if (values[i] != fakeResults[i]) {
			PrintMessage("GetLetterValue is not returning correct value");
			success = false;
			break;
		}
	}

	// Success
	if (success)
		PrintMessage("", true);
}
#endif

#if MAP_GET_WORD_VALUE 
void TestSuite::MapGetWordValue() {
	cout << "Testing getting the value of a word\n";

	DSA_Lab6 scrabble;
	int values[3];
	int fakeResults[3] = { 45, 88, 165 };
	bool success = true;

	// Filling in letters with dummy values
	memset(scrabble.mLetterValues, 0, sizeof(short) * 26);
	for (int i = 0; i < 26; i++)
		scrabble.mLetterValues[i] = i;

	// Testing several words
	values[0] = scrabble.GetWordValue("APPLE");
	values[1] = scrabble.GetWordValue("PEROXIDE");
	values[2] = scrabble.GetWordValue("UMBRAGEOUSNESS");

	for (int i = 0; i < 3; ++i) {
		if (values[i] != fakeResults[i]) {
			PrintMessage("GetWordValue is not returning correct value");
			success = false;
			break;
		}
	}

	// Success
	if (success)
		PrintMessage("", true);
}
#endif

#if MAP_CREATE_PAIR
void TestSuite::MapCreatePair() {
	cout << "Testing creating a pair for the map\n";

	DSA_Lab6 scrabble;
	pair<string, short> pairValues[3];
	pair<string, short> fakeResults[3] = { make_pair("APPLE", 45), make_pair("PEROXIDE", 88), make_pair("UMBRAGEOUSNESS",165) };
	bool success = true;

	// Filling in letters with dummy values
	memset(scrabble.mLetterValues, 0, sizeof(short) * 26);
	for (int i = 0; i < 26; i++)
		scrabble.mLetterValues[i] = i;

	// Testing several words
	pairValues[0] = scrabble.CreatePair("APPLE");
	pairValues[1] = scrabble.CreatePair("PEROXIDE");
	pairValues[2] = scrabble.CreatePair("UMBRAGEOUSNESS");

	for (int i = 0; i < 3; ++i) {
		if (pairValues[i].first != fakeResults[i].first) {
			PrintMessage("CreatePair is not storing word correctly");
			success = false;
			break;
		}
		if (pairValues[i].second != fakeResults[i].second) {
			PrintMessage("CreatePair is not storing correct word value");
			success = false;
			break;
		}
	}

	// Success
	if (success)
		PrintMessage("", true);

}
#endif

#if MAP_LOAD_FILE
void TestSuite::MapLoadFile() {
	cout << "Testing loading file into unordered_map\n";

	DSA_Lab6 scrabble;
	int results[3];
	int fakeResults[3] = { 45, 88, 165 };
	bool success = true;

	// Filling in letters with dummy values
	memset(scrabble.mLetterValues, 0, sizeof(short) * 26);
	for (int i = 0; i < 26; i++)
		scrabble.mLetterValues[i] = i;

	scrabble.LoadWords("words.txt");

	results[0] = scrabble.mScrabbleMap.find("APPLE")->second;
	results[1] = scrabble.mScrabbleMap.find("PEROXIDE")->second;
	results[2] = scrabble.mScrabbleMap.find("UMBRAGEOUSNESS")->second;

	if (178636 != scrabble.mScrabbleMap.size()) {
		PrintMessage("Not all words were loaded into map");
		success = false;
	}

	for (int i = 0; i < 3; ++i) {
		if (results[i] != fakeResults[i]) {
			PrintMessage("Word value is incorrect");
			success = false;
			break;
		}
	}
	
	if (success)
		PrintMessage("", true);
}
#endif

#if MAP_FIND_WORD_SCORE
void TestSuite::MapFindWordScore() {
	cout << "Testing finding score in the map\n";

	DSA_Lab6 scrabble;
	string words[4] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS", "WORDNOTFOUND"};
	int wordScores[4] = { 9, 18, 19, -1 };
	bool success = true;

	for (int i = 0; i < 4; ++i) {
		if (scrabble.FindValueInMap(words[i]) != wordScores[i]) {
			PrintMessage("FindValue not returning correct result");
			success = false;
			break;
		}
	}

	// Success
	if (success)
		PrintMessage("", true);
}
#endif
#endif

#if LAB_7

unsigned int TestSuite::BadHash(const float& _f) {
	return int(_f * 10) % 17;
}

Dictionary<float, string>* TestSuite::GenerateDictionary() {
	typedef Dictionary<float, string>::Pair myPair;

	Dictionary<float, string>* dict = new Dictionary<float, string>(17, BadHash);

	// Populating dictionary 
	// NOTE:	Not using hashing function because each person is writing their own.
	//			This will just put items in a few buckets to simulate functionality.
	float vals[10] = { 0.1f, 2.4f, 9.9f, 10.7f, 39.2f, 3.0f, 3.1f, 28.4f, 1.7f, 6.2f };
	int currBucket = 0;
	for (int i = 0; i < 10; ++i) {
		currBucket = int(vals[i] * 10) % 17;	// Dummy hashing algorithm
		dict->mTable[currBucket].push_back(myPair(vals[i], to_string(vals[i])));
	}

	return dict;
}


#if DICT_HASH_FUNC

struct HashQuality {
	int totalBuckets;	// Total number of buckets
	int totalItems;		// Total number of items
	int empty;			// Number of empty buckets
	int lowBucket;		// Minimum items in non-zero bucket
	int highBucket;		// Maximum items in non-zero bucket
};

HashQuality CalcHashQuality(int* _buckets, int _numBuckets) {
	// Initializing struct
	HashQuality hq = { _numBuckets, 0, 0, _buckets[0], _buckets[0] };

	// Go through all "buckets"
	for (int i = 0; i < hq.totalBuckets; ++i) {
		// If there are no items...
		if (0 == _buckets[i])
			hq.empty++;

		else {
			// Add to the total items
			hq.totalItems += _buckets[i];

			// Finding the lowest number of items in a bucket
			if (_buckets[i] < _buckets[hq.lowBucket])
				hq.lowBucket = i;
			// Finding the highest number of items in a bucket
			else if (_buckets[i] > _buckets[hq.highBucket])
				hq.highBucket = i;
		}
	}

	cout << "\tTotal Items:\t\t" << hq.totalItems << '\n'
		<< "\tTotal Buckets:\t\t" << hq.totalBuckets << '\n'
		<< "\tEmpty Buckets:\t\t" << hq.empty << " - " << float(hq.empty) / hq.totalBuckets << '\n'
		<< "\tSmallest Bucket:\t" << _buckets[hq.lowBucket] << '\n'
		<< "\tBiggest Bucket:\t\t" << _buckets[hq.highBucket] << '\n';

	return hq;
}

 void TestSuite::DictHashFunc1() {
	 cout << "Testing HashFunc1 quality (int keys)\n";
	 // Creating the correct number of buckets
	 int* buckets = new int[HASH_BUCKETS1];
	 int curr;
	 vector<int> values;
	 // Setting all buckets to 0
	 memset(buckets, 0, sizeof(int) * HASH_BUCKETS1);

	 // Reading in all of the values
	 ifstream ifl("numbers.txt");
	 while (!ifl.eof()) {
		 ifl >> curr;
		 ifl.get();
		 values.push_back(curr);
	 }
	 ifl.close();
	 
	 // Testing hash function
	 for (int i = 0; i < values.size(); ++i) {
		 buckets[HashFunc1(values[i])]++;
	 }

	 HashQuality quality = CalcHashQuality(buckets, HASH_BUCKETS1);

	 float emptyPercentage = (float)quality.empty / quality.totalBuckets;

	 if (emptyPercentage > .25f)
		 PrintMessage("Empty buckets > 25%");
	 if (buckets[quality.highBucket] > 15)
		 PrintMessage("One or more buckets contain > 15 keys");

	 if (emptyPercentage <= .25f &&
		 buckets[quality.highBucket] <= 15)
		 PrintMessage("", true);
}

void TestSuite::DictHashFunc2() {
	cout << "Testing HashFunc1 quality (int keys)\n";
	// Creating the correct number of buckets
	int* buckets = new int[HASH_BUCKETS2];
	string curr;
	vector<string> values;
	// Setting all buckets to 0
	memset(buckets, 0, sizeof(int) * HASH_BUCKETS2);

	// Reading in all of the values
	ifstream ifl("words.txt");
	while (!ifl.eof()) {
		getline(ifl, curr);
		values.push_back(curr);
	}
	ifl.close();

	// Testing hash function
	for (int i = 0; i < values.size(); ++i) {
		buckets[HashFunc2(values[i])]++;
	}

	HashQuality quality = CalcHashQuality(buckets, HASH_BUCKETS2);

	float emptyPercentage = (float)quality.empty / quality.totalBuckets;

	if (emptyPercentage > .25f)
		PrintMessage("Empty buckets > 25%");
	if (buckets[quality.highBucket] > 15)
		PrintMessage("One or more buckets contain > 15 keys");

	if (emptyPercentage <= .25f &&
		buckets[quality.highBucket] <= 15)
		PrintMessage("", true);
}
#endif

#if DICT_CTOR

void TestSuite::DictConstructor() {
	cout << "Testing constructor\n";

	Dictionary<float, string> dict(321, BadHash);

	if (dict.mTable == nullptr)
		PrintMessage("Table should not be null");
	if (dict.mNumBuckets != 321)
		PrintMessage("numBuckets has incorrect value");
	if (dict.mHashFunc != TestSuite::BadHash)
		PrintMessage("hashFunc is not pointing to valid function");

	// Success
	if (dict.mTable &&
		321 == dict.mNumBuckets &&
		dict.mHashFunc == BadHash)
		PrintMessage("", true);
}
#endif

#if DICT_PAIR_CTOR
void TestSuite::DictPairConstructor() {
	cout << "Testing Pair constructor\n";

	Dictionary<float, string>::Pair pair(2.1f, "Two point one f");
	string str = "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >";
	string keyString = typeid(pair.key).name();

	if (keyString != "float")
		PrintMessage("Key is of incorrect type");
	if (typeid(pair.value).name() != str)
		PrintMessage("Value is of incorrect type"); 
	if (pair.key != 2.1f)
		PrintMessage("Key has incorrect value");
	if (pair.value != "Two point one f")
		PrintMessage("Value has incorrect value");

	// Success
	if (keyString == "float" &&
		typeid(pair.value).name() == str &&
		2.1f == pair.key &&
		"Two point one f" == pair.value)
		PrintMessage("", true);
}
#endif

#if DICT_COPY_CTOR
void TestSuite::DictCopyConstructor() {
	cout << "Testing copy constructor\n";
	Dictionary<float, string>* original = GenerateDictionary();
	size_t copyBucketSize, originalBucketSize;
	list<Dictionary<float, string>::Pair> originalBucket;
	bool correctBuckets = true, correctItems = true;

	Dictionary<float, string> copy(*original);

	if (copy.mTable == original->mTable)
		PrintMessage("Table is using a shallow copy");
	if (copy.mNumBuckets != original->mNumBuckets)
		PrintMessage("numBuckets has incorrect value");
	if (copy.mHashFunc != original->mHashFunc)
		PrintMessage("hashFunc is not pointing to correct function");
	// Checking each bucket
	for (int i = 0; i < 17; ++i) {
		copyBucketSize = copy.mTable[i].size();
		originalBucketSize = copy.mTable[i].size();

		if (copyBucketSize != originalBucketSize) {
			PrintMessage("Size of buckets is incorrect");
			correctBuckets = false;
			break;
		}

		originalBucket = original->mTable[i];
		// Checking to make sure each individual bucket has the correct values
		for(auto copyIter = copy.mTable[i].begin(); copyIter != copy.mTable[i].end(); ++copyIter) {
			if (find(originalBucket.begin(), originalBucket.end(), *copyIter) == originalBucket.end()) {
				PrintMessage("One or more items was not found in correct bucket");
				correctItems = false;
				break;
			}
		}
	}

	// Success
	if (copy.mTable != original->mTable &&
		copy.mNumBuckets == original->mNumBuckets &&
		copy.mHashFunc == original->mHashFunc &&
		correctBuckets &&
		correctItems)
		PrintMessage("", true);

	delete original;
}
#endif

#if DICT_ASSIGNMENT_OP
void TestSuite::DictAssignmentOperator() {
	cout << "Testing assignment operator\n";
	Dictionary<float, string>* original = GenerateDictionary();
	size_t copyBucketSize, originalBucketSize;
	list<Dictionary<float, string>::Pair> originalBucket;
	bool correctBuckets = true, correctItems = true;


	Dictionary<float, string> assign(0, nullptr);
	// Copy constructor
	assign = *original;

	if (assign.mTable == original->mTable)
		PrintMessage("Table is using a shallow copy");
	if (assign.mNumBuckets != original->mNumBuckets)
		PrintMessage("numBuckets has incorrect value");
	if (assign.mHashFunc != original->mHashFunc)
		PrintMessage("hashFunc is not pointing to correct function");
	// Checking each bucket
	for (int i = 0; i < 17; ++i) {
		copyBucketSize = assign.mTable[i].size();
		originalBucketSize = assign.mTable[i].size();

		if (copyBucketSize != originalBucketSize) {
			PrintMessage("Size of buckets is incorrect");
			correctBuckets = false;
			break;
		}

		originalBucket = original->mTable[i];
		// Checking to make sure each individual bucket has the correct values
		for (auto copyIter = assign.mTable[i].begin(); copyIter != assign.mTable[i].end(); ++copyIter) {
			if (find(originalBucket.begin(), originalBucket.end(), *copyIter) == originalBucket.end()) {
				PrintMessage("One or more items was not found in correct bucket");
				correctItems = false;
				break;
			}
		}
	}

	// Success
	if (assign.mTable != original->mTable &&
		assign.mNumBuckets == original->mNumBuckets &&
		assign.mHashFunc == original->mHashFunc &&
		correctBuckets &&
		correctItems)
		PrintMessage("", true);

	delete original;
}
#endif

#if DICT_CLEAR
void TestSuite::DictClear() {
	cout << "Testing Clear method\n";

	Dictionary<float, string>* dict = GenerateDictionary();
	bool bucketsCleared = true;
	dict->Clear();

	if (nullptr == dict->mTable)
		PrintMessage("Table should not be deleted");
	if (0 == dict->mNumBuckets)
		PrintMessage("numBuckets should not be reset");
	if (0 == dict->mHashFunc)
		PrintMessage("hashFunc should not be reset");
	for(unsigned int i = 0; i < dict->mNumBuckets; ++i)
		if (dict->mTable[i].size() != 0) {
			PrintMessage("At least one bucket has a size greater than zero");
			bucketsCleared = false;
			break;
		}
			
	// Success
	if (dict->mTable &&
		dict->mNumBuckets &&
		dict->mHashFunc &&
		bucketsCleared)
		PrintMessage("", true);

	delete dict;
}
#endif

#if DICT_INSERT
void TestSuite::DictInsert() {
	cout << "Testing Insert method (new key)\n";
	
	// Creating an alias and other variables needed for testing
	typedef Dictionary<float, string>::Pair myPair;
	Dictionary<float, string> dict(17, BadHash);
	unsigned int correctBucket;
	bool found = false;
	myPair foundPair(0, "zero");

	// Calling insert
	dict.Insert(4.5f, "four point five f");

	// Using hash function to get bucket
	correctBucket = BadHash(4.5f);

	// Iterating through bucket 
	for (list<myPair>::const_iterator iter = dict.mTable[correctBucket].begin();
		iter != dict.mTable[correctBucket].end(); iter++) {
		if ((*iter).key == 4.5f) {
			found = true;
			foundPair = *iter;
			break;
			}
	}

	if (!found)
		PrintMessage("Data was not found in correct bucket");
	if (foundPair.key != 4.5f)
		PrintMessage("Key has incorrect value");
	if (foundPair.value != "four point five f")
		PrintMessage("Value has incorrect value");

	// Success
	if (found &&
		foundPair == myPair(4.5f, "four point five f"))
		PrintMessage("", true);
}

void TestSuite::DictInsertOverwrite() {
	cout << "Testing Insert method (existing key)\n";

	// Creating an alias and other variables needed for testing
	typedef Dictionary<float, string>::Pair myPair;
	Dictionary<float, string> dict(17, BadHash);
	unsigned int correctBucket;
	bool found = false;
	myPair foundPair(0, "zero");

	// Calling insert
	dict.Insert(4.5f, "four point five f");
	// Overwriting same key
	dict.Insert(4.5f, "four point five eff");

	// Using hash function to get bucket
	correctBucket = BadHash(4.5f);

	// Iterating through bucket 
	for (list<myPair>::const_iterator iter = dict.mTable[correctBucket].begin();
		iter != dict.mTable[correctBucket].end(); iter++) {
		if ((*iter).key == 4.5f) {
			found = true;
			foundPair = *iter;
			break;
		}
	}

	if (!found)
		PrintMessage("Data was not found in correct bucket");
	if (foundPair.key != 4.5f)
		PrintMessage("Key has incorrect value");
	if (foundPair.value != "four point five eff")
		PrintMessage("Value has incorrect value");

	// Success
	if (found &&
		foundPair == myPair(4.5f, "four point five eff"))
		PrintMessage("", true);
}

#endif

#if DICT_FIND
void TestSuite::DictFind() {
	cout << "Testing Find method\n";

	Dictionary<float, string>* dict = GenerateDictionary();

	const string* result = dict->Find(39.2f);

	if (*result != "39.200001")
		PrintMessage("Find did not return correct result (possibly not looking in correct bucket)");

	// Success
	if (*result == "39.200001")
		PrintMessage("", true);

	delete dict;
}
#endif

#if DICT_REMOVE
void TestSuite::DictRemove() {
	cout << "Testing Remove method (Item in Dictionary)\n";

	Dictionary<float, string>* dict = GenerateDictionary();
	int correctBucket = BadHash(39.2f);
	size_t bucketSize = dict->mTable[correctBucket].size();
	


	bool found = dict->Remove(39.2f);

	if (false == found)
		PrintMessage("Find is not returning correct result");

	for(auto iter = dict->mTable[correctBucket].begin();
		iter != dict->mTable[correctBucket].end(); iter++)
		if (39.2f == iter->key) {
			PrintMessage("Item was not removed properly");
			break;
		}

	// Success
	if (found &&
		dict->mTable[correctBucket].size() == bucketSize-1)
		PrintMessage("", true);

	delete dict;
}

void TestSuite::DictRemoveNotFound() {
	cout << "Testing Remove method (Item not in Dictionary)\n";

	Dictionary<float, string>* dict = GenerateDictionary();
	int correctBucket = BadHash(11.0f);
	size_t bucketSize = dict->mTable[correctBucket].size();

	bool found = dict->Remove(11.0f);

	if (found)
		PrintMessage("Find is not returning correct result");

	for (auto iter = dict->mTable[correctBucket].begin();
		iter != dict->mTable[correctBucket].end(); iter++)
		if (11.0f == iter->key) {
			PrintMessage("Item was not removed properly");
			break;
		}

	// Success
	if (found &&
		dict->mTable[correctBucket].size() == bucketSize)
		PrintMessage("", true);

	delete dict;
}

#endif

#endif // END LAB_6

#if LAB_8

BST<int>* TestSuite::GenerateTree() {
	BST<int>* bst = new BST<int>;

	bst->mRoot = new BST<int>::Node(50);
	bst->mRoot->left = new BST<int>::Node(25);
	bst->mRoot->left->left = new BST<int>::Node(10);
	bst->mRoot->left->right = new BST<int>::Node(35);
	bst->mRoot->left->left->right = new BST<int>::Node(15);
	bst->mRoot->right = new BST<int>::Node(75);
	bst->mRoot->right->left = new BST<int>::Node(65);
	bst->mRoot->right->left->left = new BST<int>::Node(60);
	bst->mRoot->right->right = new BST<int>::Node(100);
	bst->mRoot->right->right->left = new BST<int>::Node(80);

	/*
						50
						/\
				25				75
				/\				/\
			10		35		65		100
			  \				/		/
				15		   60	  80
	
	*/

	return bst;
}

#if BST_CTOR
void TestSuite::BSTDefaultConstructor() {

	cout << "Testing default constructor\n";
	BST<int> bst;
	if (bst.mRoot)
		PrintMessage("Root should be null");

	// Success
	if (!bst.mRoot)
		PrintMessage("", true);

}
#endif

#if BST_NODE_CTOR
void TestSuite::BSTNodeConstructor() {

	cout << "Testing BST::Node constructor with valid node parameters\n";

	BST<int>::Node node(10);

	if (10 != node.data)
		PrintMessage("Data in node is incorrect");
	if (node.left || node.right)
		PrintMessage("Node is not a leaf node");

	// Success
	if (10 == node.data &&
		!node.left &&
		!node.right)
		PrintMessage("", true);
}
#endif

#if BST_COPY_CTOR
void TestSuite::BSTCopyConstructor() {
	cout << "Testing copy constructor with built-in type\n";
	// Creating an initial list
	BST<int>* original = GenerateTree();

	// Calling copy constructor
	BST<int> copy(*original);

	if (copy.mRoot == original->mRoot)
		PrintMessage("BST is doing shallow copies");
	if (copy.mRoot->data != 50 ||
		copy.mRoot->left->data != 25 ||
		copy.mRoot->left->left->data != 10 ||
		copy.mRoot->left->left->right->data != 15 ||
		copy.mRoot->left->right->data != 35 ||
		copy.mRoot->right->data != 75 ||
		copy.mRoot->right->left->data != 65 ||
		copy.mRoot->right->left->left->data != 60 ||
		copy.mRoot->right->right->data != 100 ||
		copy.mRoot->right->right->left->data != 80)
		PrintMessage("One (or more) nodes have the incorrect value");

	// Success
	if (copy.mRoot != original->mRoot &&
		copy.mRoot->data == 50 &&
		copy.mRoot->left->data == 25 &&
		copy.mRoot->left->left->data == 10 &&
		copy.mRoot->left->left->right->data == 15 &&
		copy.mRoot->left->right->data == 35 &&
		copy.mRoot->right->data == 75 &&
		copy.mRoot->right->left->data == 65 &&
		copy.mRoot->right->left->left->data == 60 &&
		copy.mRoot->right->right->data == 100 &&
		copy.mRoot->right->right->left->data == 80)
		PrintMessage("", true);

	delete original;
}
#endif

#if BST_ASSIGNMENT_OP
void TestSuite::BSTAssignmentOperator() {
	cout << "Testing assignment operator with built-in type\n";
	
	// Creating an initial list
	BST<int>* original = GenerateTree();
	BST<int> assign;

	// Adding something to assign in order
	assign.mRoot = new BST<int>::Node(50);

	// Calling assignment operator
	assign = *original;

	if (assign.mRoot == original->mRoot)
		PrintMessage("BST is doing shallow copies");
	if (assign.mRoot->data != 50 ||
		assign.mRoot->left->data != 25 ||
		assign.mRoot->left->left->data != 10 ||
		assign.mRoot->left->left->right->data != 15 ||
		assign.mRoot->left->right->data != 35 ||
		assign.mRoot->right->data != 75 ||
		assign.mRoot->right->left->data != 65 ||
		assign.mRoot->right->left->left->data != 60 ||
		assign.mRoot->right->right->data != 100 ||
		assign.mRoot->right->right->left->data != 80)
		PrintMessage("One (or more) nodes have the incorrect value");

	// Success
	if (assign.mRoot != original->mRoot &&
		assign.mRoot->data == 50 &&
		assign.mRoot->left->data == 25 &&
		assign.mRoot->left->left->data == 10 &&
		assign.mRoot->left->left->right->data == 15 &&
		assign.mRoot->left->right->data == 35 &&
		assign.mRoot->right->data == 75 &&
		assign.mRoot->right->left->data == 65 &&
		assign.mRoot->right->left->left->data == 60 &&
		assign.mRoot->right->right->data == 100 &&
		assign.mRoot->right->right->left->data == 80)
		PrintMessage("", true);

	delete original;
}
#endif

#if BST_CLEAR
void TestSuite::BSTClear() {
	cout << "Testing Clear\n";

	// Generating a tree
	BST<int>* bst = GenerateTree();

	bst->Clear();

	if (bst->mRoot)
		PrintMessage("Root is not null");

	// Success
	if (!bst->mRoot)
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_PUSH_ROOT
void TestSuite::BSTPushRoot() {
	cout << "Testing Push on an empty tree\n";

	BST<int> bst;

	bst.Push(50);

	/*
			50
	*/

	if (!bst.mRoot)
		PrintMessage("Root node is null");
	if (bst.mRoot && bst.mRoot->data != 50)
		PrintMessage("Root is not storing the correct value");
	if (bst.mRoot && bst.mRoot->left || bst.mRoot->right)
		PrintMessage("Root is not a leaf node");

	// Success
	if (bst.mRoot && 
		bst.mRoot->data == 50 &&
		!bst.mRoot->left &&
		!bst.mRoot->right)
		PrintMessage("", true);
}
#endif

#if BST_PUSH_ROOT_LEFT
void TestSuite::BSTPushRootLeft() {
	cout << "Testing Push on a tree with only a root node (left)\n";

	BST<int> bst;

	bst.Push(50);
	bst.Push(25);

	/*
			50
			/
		  25
	*/

	if (bst.mRoot->data != 50)
		PrintMessage("Root is not storing the correct value");
	if (bst.mRoot->left && bst.mRoot->left->data != 25)
		PrintMessage("Left leaf node is not storing the correct value");
	if (bst.mRoot->right)
		PrintMessage("Root's right node is not null");

	// Success
	if (bst.mRoot->data == 50 &&
		bst.mRoot->left &&
		bst.mRoot->left->data == 25 &&
		!bst.mRoot->right)
		PrintMessage("", true);
}
#endif

#if BST_PUSH_ROOT_RIGHT
void TestSuite::BSTPushRootRight() {
	cout << "Testing Push on a tree with only a root node (right)\n";
	
	BST<int> bst;

	bst.Push(50);
	bst.Push(75);

	/*
			50
			  \
			   75
	*/

	if (bst.mRoot->data != 50)
		PrintMessage("Root is not storing the correct value");
	if (bst.mRoot->right && bst.mRoot->right->data != 75)
		PrintMessage("Right leaf node is not storing the correct value");
	if (bst.mRoot->left)
		PrintMessage("Root's left node is not null");

	// Success
	if (bst.mRoot->data == 50 &&
		bst.mRoot->right &&
		bst.mRoot->right->data == 75 &&
		!bst.mRoot->left)
		PrintMessage("", true);

}
#endif

#if BST_PUSH_LEFT
void TestSuite::BSTPushLeft() {
	cout << "Testing Push on a left Node not connected to the root\n";

	BST<int> bst;

	bst.Push(50);
	bst.Push(25);
	bst.Push(35);

	/*
			50
			/
		  25
		   \
		    35
	*/

	if (!bst.mRoot->left->right)
		PrintMessage("Node not added in the correct place");
	if (bst.mRoot->left->right && bst.mRoot->left->right->data != 35)
		PrintMessage("Node added does not contain correct value");

	// Success
	if (bst.mRoot->left->right &&
		bst.mRoot->left->right->data == 35)
		PrintMessage("", true);
}
#endif

#if BST_PUSH_RIGHT
void TestSuite::BSTPushRight() {
	cout << "Testing Push on a right Node not connected to the root\n";

	BST<int> bst;

	bst.Push(50);
	bst.Push(75);
	bst.Push(100);

	/*
			50
			 \
			  75
			    \
				100
	*/	

	if (!bst.mRoot->right->right)
		PrintMessage("Node not added in the correct place");
	if (bst.mRoot->right->right && bst.mRoot->right->right->data != 100)
		PrintMessage("Node added does not contain correct value");

	// Success
	if (bst.mRoot->right->right &&
		bst.mRoot->right->right->data == 100)
		PrintMessage("", true);
}
#endif

#if BST_CONTAINS_TRUE
void TestSuite::BSTContainsTrue() {
	cout << "Testing Contains on a value that is present in the list\n";

	BST<int>* bst = GenerateTree();

	bool found = bst->Contains(60);

	if (!found)
		PrintMessage("Contains returned false (value was in list)");

	// Success
	else
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_CONTAINS_FALSE
void TestSuite::BSTContainsFalse() {
	cout << "Testing Contains on a value that is not present in the list\n";

	BST<int>* bst = GenerateTree();

	bool found = bst->Contains(1);

	if (found)
		PrintMessage("Contains returned true (value was not in list)");

	// Success
	else
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_REMOVE_CASE0_ROOT
void TestSuite::BSTRemoveCase0Root() {
	cout << "Testing Remove on root (Case 0)\n";

	BST<int> bst;
	bst.mRoot = new BST<int>::Node(50);
	
	bool result = bst.Remove(50);

	if (bst.mRoot)
		PrintMessage("Root was not removed");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (!bst.mRoot &&
		result)
		PrintMessage("", true);

}
#endif

#if BST_REMOVE_CASE0
void TestSuite::BSTRemoveCase0() {
	cout << "Testing Remove on non-root (Case 0)\n";

	BST<int> bst;
	bst.mRoot = new BST<int>::Node(50);
	bst.mRoot->right = new BST<int>::Node(75);
	bst.mRoot->right->left = new BST<int>::Node(65);
	
	/*
			50
			 \
			  75
			  /
			 65
	*/

	bool result = bst.Remove(65);

	/*
			50
			 \
			  75
	*/

	if (bst.mRoot->right->left)
		PrintMessage("Parent node's pointer was not set to null");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if(!bst.mRoot->right->left &&
		result)
		PrintMessage("", true);
}
#endif

#if BST_REMOVE_CASE1_ROOT_LEFT
void TestSuite::BSTRemoveCase1RootLeft() { 
	cout << "Testing Remove from Root /w left child (Case 1)\n";

	BST<int> bst;
	bst.mRoot = new BST<int>::Node(50);
	bst.mRoot->left = new BST<int>::Node(25);
	bst.mRoot->left->left = new BST<int>::Node(20);
	bst.mRoot->left->right = new BST<int>::Node(35);

	/*
			50
			/
		  25
		  / \
		20	35
	*/

	bool result = bst.Remove(50);

	/*
		   25
		  / \ 
		 20	 35
	*/

	if (bst.mRoot && bst.mRoot->data != 25)
		PrintMessage("Root does not contain correct value");
	if (bst.mRoot->left && bst.mRoot->left->data != 20)
		PrintMessage("Root's left value is incorrect");
	if (bst.mRoot->right && bst.mRoot->right->data != 35)
		PrintMessage("Root's right value is incorrect");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst.mRoot && bst.mRoot->data == 25 &&
		bst.mRoot->left && bst.mRoot->left->data == 20 &&
		bst.mRoot->right && bst.mRoot->right->data == 35 &&
		result)
		PrintMessage("", true);
}
#endif

#if BST_REMOVE_CASE1_ROOT_RIGHT
void TestSuite::BSTRemoveCase1RootRight() {
	cout << "Testing Remove from Root /w right child (Case 1)\n";

	BST<int> bst;
	bst.mRoot = new BST<int>::Node(50);
	bst.mRoot->right = new BST<int>::Node(75);
	bst.mRoot->right->left = new BST<int>::Node(65);
	bst.mRoot->right->right = new BST<int>::Node(100);
	
	/*
			50
			 \
			  75
			 /  \
			65	100
	*/

	bool result = bst.Remove(50);

	/*
		    75
		   /  \
		  65  100
	*/
	if (bst.mRoot && bst.mRoot->data != 75)
		PrintMessage("Root does not contain correct value");
	if (bst.mRoot->left && bst.mRoot->left->data != 65)
		PrintMessage("Root's left value is incorrect");
	if (bst.mRoot->right && bst.mRoot->right->data != 100)
		PrintMessage("Root's right value is incorrect");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst.mRoot && bst.mRoot->data == 75 &&
		bst.mRoot->left && bst.mRoot->left->data == 65 &&
		bst.mRoot->right && bst.mRoot->right->data == 100 &&
		result)
		PrintMessage("", true);
}
#endif

#if BST_REMOVE_CASE1_LEFT_LEFT
void TestSuite::BSTRemoveCase1LeftLeft() {
	cout << "Testing Remove on non-root left node that has a left child (Case 1)\n";

	BST<int>* bst = GenerateTree();
	/*
						50
						/\
				25				75
				/\				/\
			10		35		65		100
			  \				/		/
				15		   60	  80

	*/

	bool result = bst->Remove(65);

	/*
						50
						/\
				25				75
				/\				/\
			10		35		60		100
			  \						/
				15				  80

	*/

	if (bst->mRoot->right->left &&
		bst->mRoot->right->left->data != 60)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	if (bst->mRoot->right->left &&
		bst->mRoot->right->left->data == 60 &&
		result)
		PrintMessage("", true);


	delete bst;
}
#endif

#if BST_REMOVE_CASE1_LEFT_RIGHT
void TestSuite::BSTRemoveCase1LeftRight() {
	cout << "Testing Remove on left node that has a right child (Case 1)\n";

	BST<int>* bst = GenerateTree();
	/*
						50
						/\
				25				75
				/\				/\
			10		35		65		100
			  \				/		/
				15		   60	  80

	*/

	bool result = bst->Remove(10);

	/*
						50
						/\
				25				75
				/\				/\
			15		35		60		100
			  						/
								  80

	*/

	if (bst->mRoot->left->left &&
		bst->mRoot->left->left->data != 15)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	if (bst->mRoot->left->left &&
		bst->mRoot->left->left->data == 15 &&
		result)
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_REMOVE_CASE1_RIGHT_LEFT
void TestSuite::BSTRemoveCase1RightLeft() {
	cout << "Testing Remove on right that has a right left (Case 1)\n";

	BST<int> bst;
	bst.mRoot = new BST<int>::Node(50);
	bst.mRoot->right = new BST<int>::Node(75);
	bst.mRoot->right->left = new BST<int>::Node(65);

	/*
			50
			 \
			  75
			 /
			65
	*/

	bool result = bst.Remove(75);

	/*
			50
			 \
			  65
	*/

	if(bst.mRoot->right && bst.mRoot->right->data != 65)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst.mRoot->right && bst.mRoot->right->data == 65 && 
		result)
		PrintMessage("", true);
}
#endif

#if BST_REMOVE_CASE1_RIGHT_RIGHT
void TestSuite::BSTRemoveCase1RightRight() {
	cout << "Testing Remove on right node that has a right child (Case 1)\n";

	BST<int> bst;
	bst.mRoot = new BST<int>::Node(50);
	bst.mRoot->right = new BST<int>::Node(75);
	bst.mRoot->right->right = new BST<int>::Node(100);
	/*
			50
			 \
			  75
			    \
				100
	*/

	bool result = bst.Remove(75);

	/*
			50
			 \
			  100
	*/

	if(bst.mRoot->right && bst.mRoot->right->data != 100)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst.mRoot->right && bst.mRoot->right->data == 100 &&
		result)
		PrintMessage("", true);
}
#endif

#if BST_REMOVE_CASE2_ROOT
void TestSuite::BSTRemoveCase2Root() {
	cout << "Testing Remove on Root (Case 2)\n";

	BST<int>* bst = GenerateTree();
	
	/*
						50
						/\
				25				75
				/\				/\
			10		35		65		100
			  \				/		/
				15		   60	  80
	*/

	bool result = bst->Remove(50);

	/*
					60
					/\
			25				75
			/\				/\
		10		35		65		100
		  \						/
			15		   		   80
*/

	if (bst->mRoot && bst->mRoot->data != 60)
		PrintMessage("Root does not contain correct value");
	if (bst->mRoot->right->left->left)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst->mRoot && bst->mRoot->data == 60 &&
		!bst->mRoot->right->left->left && 
		result)
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_REMOVE_CASE2_SUBTREE
void TestSuite::BSTRemoveCase2Subtree() {
	cout << "Testing Remove on non-root with subtree (Case 2)\n";

	BST<int>* bst = GenerateTree();
	bst->mRoot->right->right->left->right = new BST<int>::Node(85);
	/*
						50
						/\
				25				75
				/\				/\
			10		35		65		100
			  \				/		/
				15		   60	  80
									\
									 85
	*/

	bool result = bst->Remove(75);

	/*
						50
						/\
				25				80
				/\				/\
			10		35		65		100
			  \				/		/
				15		   60	  85
	*/

	if(bst->mRoot->right && bst->mRoot->right->data != 80)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (bst->mRoot->right->right->left && bst->mRoot->right->right->left->data != 85)
		PrintMessage("Subtree was not linked correctly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst->mRoot->right && bst->mRoot->right->data == 80 &&
		bst->mRoot->right->right->left && bst->mRoot->right->right->left->data == 85 &&
		result)
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_REMOVE_CASE2_NO_SUBTREE
void TestSuite::BSTRemoveCase2NonRootNoSubtree() {
	cout << "Testing Remove on non-root with no subtree (Case 2)\n";

	BST<int>* bst = GenerateTree();

	/*
					50
					/\
			25				75
			/\				/\
		10		35		65		100
		  \				/		/
			15		   60	  80
	*/

	bool result = bst->Remove(75);

	/*
				50
				/\
		25				80
		/\				/\
	10		35		65		100
	  \				/		
		15		   60	  
*/

	if (bst->mRoot->right && bst->mRoot->right->data != 80)
		PrintMessage("Incorrect node was removed or not linked properly");
	if (bst->mRoot->right->right && bst->mRoot->right->right->left != nullptr)
		PrintMessage("Node was not swapped and removed correctly");
	if (!result)
		PrintMessage("Remove did not return correct result");

	// Success
	if (bst->mRoot->right && bst->mRoot->right->data == 80 &&
		bst->mRoot->right->right && !bst->mRoot->right->right->left &&
		result)
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_REMOVE_NOT_FOUND			
void TestSuite::BSTRemoveNotFound() {
	cout << "Testing Remove on a value not in tree\n";

	BST<int>* bst = GenerateTree();

	/*
					50
					/\
			25				75
			/\				/\
		10		35		65		100
		  \				/		/
			15		   60	  80
	*/

	bool result = bst->Remove(40);

	if (result)
		PrintMessage("Remove did not return correct result");

	// Success
	else
		PrintMessage("", true);

	delete bst;
}
#endif

#if BST_IN_ORDER_TRAVERSAL
void TestSuite::BSTInOrderTraversal() {
	cout << "Testing in-order traversal\n";

	BST<int>* bst = GenerateTree();
	string inOrderStr = "10 15 25 35 50 60 65 75 80 100";

	string result = bst->InOrder();

	if (result[result.size()-1] == ' ')
		PrintMessage("String has a trailing space");
	else if (result != inOrderStr)
		PrintMessage("Method not returning string in correct order");
		
	// Success
	if (result == inOrderStr)
		PrintMessage("", true);

	delete bst;
}
#endif
#endif	// END LAB_8

#if LAB_9
int TestSuite::HuffmanCompareTree(Huffman::HuffNode* _a, Huffman::HuffNode* _b) {
	// Check for empty
	if (!_a && !_b)
		return 1;

	// One is empty
	else if (!_a || !_b)
		return 0;

	// Both non-empty
	else {
		return	(_a->value == _b->value &&
				 _a->freq == _b->freq &&
				 HuffmanCompareTree(_a->left, _b->left) &&
				 HuffmanCompareTree(_a->left, _b->left));
	}

}


unsigned int* GetFreqTable(int _fileNumber) {

	unsigned int* freqTable = new unsigned int[257];

	// us-cities.txt
	if(!_fileNumber) {
								//	0		1		2		3		4		5		6		7		8		9
		unsigned int freq[257] = {	0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 0
									18579,	0,		0,		18579,	0,		0,		0,		0,		0,		0,		// 10
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0, 		// 20
									0,		0,		5984,	0,		0,		0,		0,		0,		0,		2, 		// 30
									0,		0,		0,		0,		0,		1,		0,		0,		0,		0, 		// 40
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 50
									0,		0,		0,		0,		0,		933,	1933,	2616,	816,	834,	// 60
									1002,	1076,	1447,	334,	305,	533,	1442,	1913,	824,	582,	// 70
									1594,	56,		1157,	2337,	798,	116,	508,	1274,	2,		101,	// 80
									51,		0,		0,		0,		0,		0,		0,		13765,	1778,	2928,	// 90
									4107,	16254,	1025,	2723,	3479,	9870,	37,		2568,	11884,	2495,	// 100
									11333,	11486,	1761,	115,	10804,	6800,	8469,	3886,	2337,	1926,	// 110
									278,	2814,	231,	0,		0,		0,		0,		0,		0,		0, 		// 120
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 130
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0, 		// 140
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 150
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0, 		// 160
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 170
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 180
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 190
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 200
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 210
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 220
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 230
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 240
									0,		0,		0,		0,		0,		0,		202882 };						// 250
		memcpy(freqTable, freq, sizeof(unsigned int) * 257);
	}
	// words.txt
	else {
								//	0		1		2		3		4		5		6		7		8		9
		unsigned int freq[257] = {	0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 0
									178635,	0,		0,		0,		0,		0,		0,		0,		0,		0,		// 10
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 20 
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 30
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 40
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 50
									0,		0,		0,		0,		0,		120923,	30120,	64162,	54854,	182711,	// 60
									20016,	43460,	36764,	140275,	2674,	14435,	84604,	44853,	106737,	103479,	// 70
									46599,	2584,	112444,	150189,	104029,	52104,	15429,	12416,	4761,	25860,	// 80
									7601,	0,		0,		0,		0,		0,		0,		0,		0,		0,		// 90
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 100
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 110
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 120
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 130
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 140
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 150
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 160
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 170
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 180
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 190
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 200
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 210
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 220
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 230
									0,		0,		0,		0,		0,		0,		0,		0,		0,		0,		// 240
									0,		0,		0,		0,		0,		0,		1762718							// 250

		};

		
		memcpy(freqTable, freq, sizeof(unsigned int) * 257);
	}
	return freqTable;
}

void TestSuite::HuffmanConstructor() {
	cout << "Testing Huffman constructor\n";

	Huffman huff("test.txt");
	bool success = true;
	unsigned int test = 0;

	if (huff.mFileName != "test.txt") {
		PrintMessage("Filename was not copied into data member");
		success = false;
	}
	
	for(int i = 0; i < 256; ++i)
		if (memcmp(&huff.mFrequencyTable[i], &test, 4) != 0) {
			PrintMessage("One (or more) indices have not been set to 0");
			success = false;
			break;
		}

	if (success)
		PrintMessage("", true);
}

void TestSuite::HuffmanGenerateFrequencyTable() {
	cout << "Testing Huffman frequency table generation\n";

	int fileNum = rand() % 2;
	Huffman* write = new Huffman(fileNum == 0 ? "us-cities.txt" : "words.txt");
	bool success = true;
	unsigned int test = 0;	
	unsigned int* freq = GetFreqTable(fileNum);

	write->GenerateFrequencyTable();

	// Checking to ensure that all frequency values are correct
	for (int i = 0; i < 257; ++i)
		if (memcmp(&write->mFrequencyTable[i], &freq[i], 4) != 0) {
			PrintMessage("One or more values in frequency table are incorrect");
			success = false;
			break;
		}

	// Clean up
	delete[] freq;
	delete write;

	// Success
	if (success)
		PrintMessage("", true);
}

void TestSuite::HuffmanGenerateLeafList() {
	cout << "Testing Huffman leaf list generation\n";

	int fileNum = rand() % 2;
	Huffman huff(fileNum == 0 ? "us-cities.txt" : "words.txt");
	int leafSize = !fileNum ? 57 : 27;
	bool success = true;
	unsigned int test = 0;
	unsigned int* freq = GetFreqTable(fileNum);

	memcpy(huff.mFrequencyTable, freq, sizeof(unsigned int) * 257);

	huff.GenerateLeafList();

	// Checking leaf list size
	if (huff.mLeafList.size() != leafSize) {
		PrintMessage("Leaf list is incorrect size (did you accidentally include the total?)");
		success = false;
	}

	// Checking to make sure each non-0 frequency is in leaf list
	for (auto iter = huff.mLeafList.begin(); iter != huff.mLeafList.end(); ++iter) {
		if ((*iter)->freq != freq[(*iter)->value]) {
			PrintMessage("Frequency of one or more nodes is incorrect");
			success = false;
			break;
		}
	}

	delete[] freq;

	// Clean up
	for (int i = 0; i < huff.mLeafList.size(); ++i)
		delete huff.mLeafList[i];

	// Success
	if (success)
		PrintMessage("", true);
}

struct leaf {
	short val;
	unsigned int freq;
};

void TestSuite::HuffmanGenerateTree() {
	cout << "Testing generation of Huffman tree\n";

	Huffman huff("dummy.txt");
	bool success = true;

	// Generating data for string/file containing "This is a test."
	
	leaf leafNodes[9] = {	{' ', 3},
							{'.', 1},
							{'T', 1},
							{'a', 1},
							{'e', 1},
							{'h', 1},
							{'i', 2},
							{'s', 3},
							{'t', 2},
	};

	// Adding leaves to list
	for (int i = 0; i < 9; ++i)
		huff.mLeafList.push_back(new Huffman::HuffNode(leafNodes[i].val, leafNodes[i].freq));
		
// Creating tree in a convuluted way to not give away the answer
	Huffman::HuffNode tree[17] = {
		/* 0 */		Huffman::HuffNode(-1,	15,	&tree[1],	&tree[2],	nullptr),
		/* 1 */		Huffman::HuffNode(-1,	6,	&tree[3],	&tree[4],	&tree[0]),
		/* 2 */		Huffman::HuffNode(-1,	9,	&tree[5],	&tree[6],	&tree[0]),
		/* 3 */		Huffman::HuffNode(-1,	3,	&tree[7],	&tree[8],	&tree[1]),
		/* 4 */		Huffman::HuffNode('s',	3,	nullptr,	nullptr,	&tree[1]),
		/* 5 */		Huffman::HuffNode(-1,	4,	&tree[9],	&tree[10],	&tree[2]),
		/* 6 */		Huffman::HuffNode(-1,	5,	&tree[11],	&tree[12],	&tree[2]),
		/* 7 */		Huffman::HuffNode('e',	1,	nullptr,	nullptr,	&tree[3]),
		/* 8 */		Huffman::HuffNode('i',	2,	nullptr,	nullptr,	&tree[3]), 
		/* 9 */		Huffman::HuffNode(-1,	2,	&tree[13],	&tree[14],	&tree[5]), 
		/* 10 */	Huffman::HuffNode(-1,	2,	&tree[15],	&tree[16],	&tree[5]), 
		/* 11 */	Huffman::HuffNode('t',	2,	nullptr,	nullptr,	&tree[6]), 
		/* 12 */	Huffman::HuffNode(' ',	3,	nullptr,	nullptr,	&tree[6]), 
		/* 13 */	Huffman::HuffNode('h',	1,	nullptr,	nullptr,	&tree[9]), 
		/* 14 */	Huffman::HuffNode('a',	1,	nullptr,	nullptr,	&tree[9]), 
		/* 15 */	Huffman::HuffNode('.',	1,	nullptr,	nullptr,	&tree[10]), 
		/* 16 */	Huffman::HuffNode('T',	1,	nullptr,	nullptr,	&tree[10]), 
	};
	
	huff.GenerateTree();
	bool identical = HuffmanCompareTree(huff.mRoot, &tree[0]);

	if (!identical) {
		PrintMessage("Trees are not identical.   Double-check algorithm");
		success = false;
	}

	// Clean up
	huff.ClearTree();

	if (success)
		PrintMessage("", true);

}

void TestSuite::HuffmanGenerateEncodingTable() {
	cout << "Testing generation of Huffman encoding table\n";

	Huffman huff("dummy.txt");
	bool success = true;

	// Generating data for string/file containing "This is a test."
		// Creating tree in a convuluted way to not give away the answer
	Huffman::HuffNode tree[17] = {
		/* 0 */		Huffman::HuffNode(-1,	15,	&tree[1],	&tree[2],	nullptr),
		/* 1 */		Huffman::HuffNode(-1,	6,	&tree[3],	&tree[4],	&tree[0]),
		/* 2 */		Huffman::HuffNode(-1,	9,	&tree[5],	&tree[6],	&tree[0]),
		/* 3 */		Huffman::HuffNode(-1,	3,	&tree[7],	&tree[8],	&tree[1]),
		/* 4 */		Huffman::HuffNode('s',	3,	nullptr,	nullptr,	&tree[1]),
		/* 5 */		Huffman::HuffNode(-1,	4,	&tree[9],	&tree[10],	&tree[2]),
		/* 6 */		Huffman::HuffNode(-1,	5,	&tree[11],	&tree[12],	&tree[2]),
		/* 7 */		Huffman::HuffNode('e',	1,	nullptr,	nullptr,	&tree[3]),
		/* 8 */		Huffman::HuffNode('i',	2,	nullptr,	nullptr,	&tree[3]),
		/* 9 */		Huffman::HuffNode(-1,	2,	&tree[13],	&tree[14],	&tree[5]),
		/* 10 */	Huffman::HuffNode(-1,	2,	&tree[15],	&tree[16],	&tree[5]),
		/* 11 */	Huffman::HuffNode('t',	2,	nullptr,	nullptr,	&tree[6]),
		/* 12 */	Huffman::HuffNode(' ',	3,	nullptr,	nullptr,	&tree[6]),
		/* 13 */	Huffman::HuffNode('h',	1,	nullptr,	nullptr,	&tree[9]),
		/* 14 */	Huffman::HuffNode('a',	1,	nullptr,	nullptr,	&tree[9]),
		/* 15 */	Huffman::HuffNode('.',	1,	nullptr,	nullptr,	&tree[10]),
		/* 16 */	Huffman::HuffNode('T',	1,	nullptr,	nullptr,	&tree[10]),
	};

	Huffman::HuffNode* leafNodes[9] = {
		&tree[12],	// ' '
		&tree[15],	// '.'
		&tree[16],	// 'T'
		&tree[14],	// 'a'
		&tree[7],	// 'e'
		&tree[13],	// 'h'
		&tree[8],	// 'i'
		&tree[4],	// 's'
		&tree[11],	// 't'
	};


	// Adding leaves to list
	for (int i = 0; i < 9; ++i)
		huff.mLeafList.push_back(leafNodes[i]);

	// Test data
	vector<bool> encodingData[9];
	int indices[9] = { ' ', '.', 'T', 'a', 'e', 'h', 'i', 's', 't' };
	encodingData[0].push_back(1); encodingData[0].push_back(1); encodingData[0].push_back(1);
	encodingData[1].push_back(1); encodingData[1].push_back(0); encodingData[1].push_back(1); encodingData[1].push_back(0);
	encodingData[2].push_back(1); encodingData[2].push_back(0); encodingData[2].push_back(1); encodingData[2].push_back(1);
	encodingData[3].push_back(1); encodingData[3].push_back(0); encodingData[3].push_back(0); encodingData[3].push_back(1);
	encodingData[4].push_back(0); encodingData[4].push_back(0); encodingData[4].push_back(0);
	encodingData[5].push_back(1); encodingData[5].push_back(0); encodingData[5].push_back(0); encodingData[5].push_back(0);
	encodingData[6].push_back(0); encodingData[6].push_back(0); encodingData[6].push_back(1);
	encodingData[7].push_back(0); encodingData[7].push_back(1); 
	encodingData[8].push_back(1); encodingData[8].push_back(1); encodingData[8].push_back(0);

	huff.mRoot = &tree[0];

	huff.GenerateEncodingTable();

	for(int i = 0; i < 9; ++i)
		if (huff.mEncodingTable[indices[i]] != encodingData[i]) {
			PrintMessage(to_string(indices[i]) + " Encoding data is incorrect.   Did you not reverse the codes?");
			success = false;
		}

	if (success)
		PrintMessage("", true);

}

void TestSuite::HuffmanCompress() {
	cout << "Testing compression of file using Huffman algorithm (this might take a few seconds)\n";

	int fileNum = rand() % 2;
	string fileName = fileNum == 0 ? "us-cities.txt" : "words.txt";
	string compressedFileName = fileNum == 0 ? "us-cities.bin" : "words.bin";
	string checkFileName = fileNum == 0 ? "us-cities_check.bin" : "words_check.bin";
	char* checkBuffer, * studentBuffer;
	int checkTotal, studentTotal;

	Huffman huff(fileName);
	bool success = true;

	huff.Compress(compressedFileName.c_str());

	// Open the two files to do a byte-by-byte comparison
	ifstream checkFile(checkFileName, ios_base::binary);
	ifstream studentFile(compressedFileName, ios_base::binary);

	// Read all of both files
	checkFile.seekg(0, ios_base::end);
	studentFile.seekg(0, ios_base::end);
	checkTotal = (int)checkFile.tellg();
	studentTotal = (int)studentFile.tellg();
	checkFile.seekg(0, ios_base::beg);
	studentFile.seekg(0, ios_base::beg);
	checkBuffer = new char[checkTotal];
	studentBuffer = new char[studentTotal];
	checkFile.read(checkBuffer, checkTotal);
	studentFile.read(studentBuffer, studentTotal);

	if (studentTotal != checkTotal) {
		PrintMessage("Incorrect file size");
		success = false;
	}
	if (success && memcmp(studentBuffer, checkBuffer, studentTotal) != 0) {
		PrintMessage("Data is incorrect");
		success = false;
	}


	delete[] checkBuffer;
	delete[] studentBuffer;

	// Success
	if (success)
		PrintMessage("", true);
	
}

void TestSuite::HuffmanDecompress() {
	cout << "Testing decompression of file using Huffman algorithm (this might take a few seconds)\n";

	int fileNum = rand() % 2;
	string compressedFileName = fileNum == 0 ? "us-cities_check.bin" : "words_check.bin";
	string checkFileName = fileNum == 0 ? "us-cities.txt" : "words.txt";
	string studentFileName = fileNum == 0 ? "us-cities_uncompressed.txt" : "words_uncompressed.txt";
	char* checkBuffer, * studentBuffer;
	int checkTotal, studentTotal;

	Huffman huff(compressedFileName);
	bool success = true;

	huff.Decompress(studentFileName.c_str());

	// Open the two files to do a byte-by-byte comparison
	ifstream checkFile(checkFileName, ios_base::binary);
	ifstream studentFile(studentFileName, ios_base::binary);

	// Read all of both files
	checkFile.seekg(0, ios_base::end);
	studentFile.seekg(0, ios_base::end);
	checkTotal = (int)checkFile.tellg();
	studentTotal = (int)studentFile.tellg();
	checkFile.seekg(0, ios_base::beg);
	studentFile.seekg(0, ios_base::beg);
	checkBuffer = new char[checkTotal];
	studentBuffer = new char[studentTotal];
	checkFile.read(checkBuffer, checkTotal);
	studentFile.read(studentBuffer, studentTotal);

	if (studentTotal != checkTotal) {
		PrintMessage("Incorrect file size");
		success = false;
	}
	if (success && memcmp(studentBuffer, checkBuffer, studentTotal) != 0) {
		PrintMessage("Data is incorrect");
		success = false;
	}

	delete[] checkBuffer;
	delete[] studentBuffer;

	// Success
	if (success)
		PrintMessage("", true);
}
#endif	// END LAB_9