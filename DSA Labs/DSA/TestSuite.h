#pragma once

/************/
/* Includes */
/************/
#include "DSA_Defines.h"

#include "Console.h"
using namespace System;

#include <string>
#include <iostream>
using namespace std;

#if LAB_9
#include "Huffman.h"
#endif


// Forward class declarations
template<typename Key, typename Value> class Dictionary;
template<typename Type> class BST;

// Used to print out PASS/FAIL messages
// 
// In:	_msg		The string to print (reason for failure)
//		_success	Determines the PASS/FAIL result
void PrintMessage(const string& _msg, bool _success = false);

// A wrapper class for an int for use with Lab 1 sorting algorithms
class IntWrapper {
public:
	int mValue = -1;			// The value being stored
	static int mCounter;		// Counter used to keep track of assignments/initializations
	static int mIsEqualCounter;	// Counter used for binary search

	// Default constructor
	//		Only needed to create arrays in unit tests
	IntWrapper() {}

	// Constructor
	//
	// In:	_value		The value to store
	IntWrapper(int _value) : mValue(_value) { }

	// Copy constructor
	//		Used to initialize one object to another
	//		
	// In:	_copy		The object to copy from
	IntWrapper(const IntWrapper& _copy) {
		*this = _copy;
	}

	// Overloaded typecast operator to convert to int
	operator int() {
		return mValue;
	}

	// Assignment operator
	//		Used to assign one object to another
	// 
	// In:	_assign				The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	IntWrapper& operator=(const IntWrapper& _assign) {
		if (this != &_assign) {
			mValue = _assign.mValue;
			mCounter++;
		}
		return *this;
	}

	// Macro for defining all six relational operators
	//		Used for comparisons in sorting
	//
	// In:	op		The operator to overload
#define RELATIONAL_OP(op)\
	bool operator op(const IntWrapper& _b) const {\
		return mValue op _b.mValue;\
	}

	RELATIONAL_OP(>)
	RELATIONAL_OP(<)
	RELATIONAL_OP(>=)
	RELATIONAL_OP(<=)
	RELATIONAL_OP(!=)

	bool operator==(const IntWrapper& _b) const {
		mIsEqualCounter++;
		return mValue == _b.mValue;
	}

	friend ostream& operator <<(ostream& _os, const IntWrapper& _rhs);
};

// A plethora of unit test functions
class TestSuite {

public:

	// Sorting/Searching Unit Tests
#if LAB_1
	static void SortingBubbleSortSmall();
	static void SortingBubbleSortLarge();
	static void SortingSelectionSortSmall();
	static void SortingSelectionSortLarge();
	static void SortingInsertionSortSmall();
	static void SortingInsertionSortLarge();
	static void SortingHeapSortSmall();
	static void SortingHeapSortLarge();
	static void SearchingSequentialSmall();
	static void SearchingSequentialLarge();
	static void SearchingBinarySmall();
	static void SearchingBinaryLarge();
#endif // END LAB_1

	// vector Unit Tests
#if LAB_2
	static void CheckForPalindrome();
	static void VectorFillFromFile();
	static void VectorFillFromArray();
	static void VectorClear();
	static void VectorSortAscending();
	static void VectorSortDescending();
	static void VectorIndexing();
	static void VectorContainsTrue();
	static void VectorContainsFalse();
	static void VectorMovePalindrome();
#endif // END LAB_2

	/* DynArray Unit Tests */
#if LAB_3
	static void DynArrayDefaultConstructorNoArgs();
	static void DynArrayDefaultConstructorWithArgs();
	static void DynArrayCopyConstructorInt();
	static void DynArrayCopyConstructorClass();
	static void DynArrayAssignmentOperatorInt();
	static void DynArrayAssignmentOperatorClass();
	static void DynArrayBracketOperator_ReadOnlyInt();
	static void DynArrayBracketOperator_ReadOnlyClass();
	static void DynArrayBracketOperator_Write();
	static void DynArrayAccessors_Size();
	static void DynArrayAccessors_Capacity();
	static void DynArrayClear();
	static void DynArrayReserveZero();
	static void DynArrayReserveDouble();
	static void DynArrayReserveSpecific();
	static void DynArrayReserveSmaller();
	static void DynArrayAppendNoResize();
	static void DynArrayAppendResize();
#endif // END LAB_3

#if LAB_4
	static void ListQueueAdd();
	static void ListStackAdd();
	static void ListQueueRemove();
	static void ListStackRemove();
	static void ListInsertIndex();
	static void ListInsertIterator();
	static void ListRemoveDecimal();
#endif // END LAB_4

#if LAB_5
	static void LinkedListDefaultConstructor();
	static void LinkedListNodeConstructorWithDefaults();
	static void LinkedListNodeConstructor();
	static void LinkedListCopyConstructorInt();
	static void LinkedListCopyConstructorClass();
	static void LinkedListAssignmentOperatorInt();
	static void LinkedListAssignmentOperatorClass();
	static void LinkedListAddHeadEmpty();
	static void LinkedListAddHeadExisting();
	static void LinkedListAddTailEmpty();
	static void LinkedListAddTailExisting();
	static void LinkedListClear();
	static void LinkedListInsertEmpty();
	static void LinkedListInsertHead();
	static void LinkedListInsertMiddle();
	static void LinkedListEraseEmpty();
	static void LinkedListEraseHead();
	static void LinkedListEraseTail();
	static void LinkedListEraseMiddle();
	static void LinkedListIterBegin();
	static void LinkedListIterEnd();
	static void LinkedListIterPreIncrement();
	static void LinkedListIterPostIncrement();
	static void LinkedListIterPreDecrement();
	static void LinkedListIterPostDecrement();
#endif // END LAB_5

#if LAB_6
	static void MapPopulateLetterValues();
	static void MapGetLetterValue();
	static void MapGetWordValue();
	static void MapCreatePair();
	static void MapLoadFile();
	static void MapFindWordScore();
#endif // END LAB_6

#if LAB_7
	static unsigned int BadHash(const float& _f);
	static Dictionary<float, string>* GenerateDictionary();
	static void DictHashFunc1();
	static void DictHashFunc2();
	static void DictConstructor();
	static void DictPairConstructor();
	static void DictCopyConstructor();
	static void DictAssignmentOperator();
	static void DictClear();
	static void DictInsert();
	static void DictInsertOverwrite();
	static void DictFind();
	static void DictRemove();
	static void DictRemoveNotFound();
#endif // END LAB_7

#if LAB_8
	static BST<int>* GenerateTree();
	static void BSTDefaultConstructor();
	static void BSTNodeConstructor();
	static void BSTCopyConstructor();
	static void BSTAssignmentOperator();
	static void BSTClear();
	static void BSTPushRoot();
	static void BSTPushRootLeft();
	static void BSTPushRootRight();
	static void BSTPushLeft();
	static void BSTPushRight();
	static void BSTContainsTrue();
	static void BSTContainsFalse();
	static void BSTRemoveCase0Root();
	static void BSTRemoveCase0();
	static void BSTRemoveCase1RootLeft();
	static void BSTRemoveCase1RootRight();
	static void BSTRemoveCase1LeftLeft();
	static void BSTRemoveCase1LeftRight();
	static void BSTRemoveCase1RightLeft();
	static void BSTRemoveCase1RightRight();
	static void BSTRemoveCase2Root();
	static void BSTRemoveCase2Subtree();
	static void BSTRemoveCase2NonRootNoSubtree();
	static void BSTRemoveNotFound();
	static void BSTInOrderTraversal();
#endif	// END LAB_8

#if LAB_9
	// Helper method
	static int HuffmanCompareTree(Huffman::HuffNode* _a, Huffman::HuffNode* _b);

	static void HuffmanConstructor();
	static void HuffmanGenerateFrequencyTable();
	static void HuffmanGenerateLeafList();
	static void HuffmanGenerateTree();
	static void HuffmanGenerateEncodingTable();
	static void HuffmanCompress();
	static void HuffmanDecompress();
#endif	// END LAB_9

};