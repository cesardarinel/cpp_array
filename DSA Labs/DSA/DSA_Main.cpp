/************/
/* Includes */
/************/

#include <ctime>
#include <iostream>
using namespace std;
#include "TestSuite.h"
#include "DSA_Defines.h"

/***********/
/* Defines */
/***********/

#define _CRTDBG_MAP_ALLOC

#define LAB1	1
#define LAB2	2
#define LAB3	3
#define LAB4	4
#define LAB5	5
#define LAB6	6
#define LAB7	7
#define LAB8	8
#define LAB9	9
#define EXIT	0

/**************/
/* Prototypes */
/**************/

void DisplayMenu();

void Lab1Tests();
void Lab2Tests();
void Lab3Tests();
void Lab4Tests();
void Lab5Tests();
void Lab6Tests();
void Lab7Tests();
void Lab8Tests();
void Lab9Tests();

int main() {

	// Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// this function call will set a breakpoint at the location of a leaked block
	// set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);

#if 1
	srand(unsigned int(time(0)));
	int choice = -1;
	bool exitLoop = false;


	while (!exitLoop) {

		system("cls");
		DisplayMenu();

		// Input validation
		for (;;) {
			cout << "Lab Selection: ";
			if (cin >> choice && choice >= EXIT && choice <= LAB9) {
				cin.ignore(INT_MAX, '\n');
				break;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if (EXIT == choice)
			break;

		system("cls");
		switch (choice) {
		case LAB1:
			Lab1Tests();
			break;
		case LAB2:
			Lab2Tests();
			break;
		case LAB3:
			Lab3Tests();
			break;
		case LAB4:
			Lab4Tests();
			break;
		case LAB5:
			Lab5Tests();
			break;
		case LAB6:
			Lab6Tests();
			break;
		case LAB7:
			Lab7Tests();
			break;
		case LAB8:
			Lab8Tests();
			break;
		case LAB9:
			Lab9Tests();
			break;
		}

		cout << "\n\n";
		system("pause");
	}
#endif

	return 0;
}

void DisplayMenu() {
	cout << "1) Lab 1 - Sorting\n"
		<< "2) Lab 2 - vector\n"
		<< "3) Lab 3 - DynArray\n"
		<< "4) Lab 4 - list\n"
		<< "5) Lab 5 - DList\n"
		<< "6) Lab 6 - unordered_map\n"
		<< "7) Lab 7 - Dictionary\n"
		<< "8) Lab 8 - Binary Search Tree\n"
		<< "9) Lab 9 - Huffman Compression\n"
		<< "0) Exit\n";
}


void Lab1Tests() {
#if SORTING_BUBBLE_SORT
	TestSuite::SortingBubbleSortSmall();
	TestSuite::SortingBubbleSortLarge();
#endif
#if SORTING_SELECTION_SORT
	TestSuite::SortingSelectionSortSmall();
	TestSuite::SortingSelectionSortLarge();
#endif
#if SORTING_INSERTION_SORT
	TestSuite::SortingInsertionSortSmall();
	TestSuite::SortingInsertionSortLarge();
#endif
#if SORTING_HEAP_SORT
	TestSuite::SortingHeapSortSmall();
	TestSuite::SortingHeapSortLarge();
#endif
#if SORTING_SEQUENTIAL_SEARCH
	TestSuite::SearchingSequentialSmall();
	TestSuite::SearchingSequentialLarge();
#endif
#if SORTING_BINARY_SEARCH
	TestSuite::SearchingBinarySmall();
	TestSuite::SearchingBinaryLarge();
#endif
}

void Lab2Tests() {
#if PALINDROME_NUMBER
	TestSuite::CheckForPalindrome();
#endif
#if VECTOR_FILL_FILE
	TestSuite::VectorFillFromFile();
#endif
#if VECTOR_FILL_ARRAY
	TestSuite::VectorFillFromArray();
#endif
#if VECTOR_CLEAR
	TestSuite::VectorClear();
#endif
#if VECTOR_SORT
	TestSuite::VectorSortAscending();
	TestSuite::VectorSortDescending();
#endif
#if VECTOR_BRACKETS
	TestSuite::VectorIndexing();
#endif
#if VECTOR_CONTAINS
	TestSuite::VectorContainsTrue();
	TestSuite::VectorContainsFalse();
#endif
#if VECTOR_MOVE_PALINDROME
	TestSuite::VectorMovePalindrome();
#endif

}

void Lab3Tests() {
#if LAB3
#if DYNARRAY_CTOR
	TestSuite::DynArrayDefaultConstructorNoArgs();
	TestSuite::DynArrayDefaultConstructorWithArgs();
#endif
#if DYNARRAY_COPY_CTOR
	TestSuite::DynArrayCopyConstructorInt();
	TestSuite::DynArrayCopyConstructorClass();
#endif
#if DYNARRAY_ASSIGNMENT_OP
	TestSuite::DynArrayAssignmentOperatorInt();
	TestSuite::DynArrayAssignmentOperatorClass();
#endif
#if DYNARRAY_BRACKET_OP
	TestSuite::DynArrayBracketOperator_ReadOnlyInt();
	TestSuite::DynArrayBracketOperator_ReadOnlyClass();
	TestSuite::DynArrayBracketOperator_Write();
#endif
#if DYNARRAY_ACCESSORS
	TestSuite::DynArrayAccessors_Size();
	TestSuite::DynArrayAccessors_Capacity();
#endif
#if DYNARRAY_CLEAR
	TestSuite::DynArrayClear();
#endif
#if DYNARRAY_RESERVE_ZERO
	TestSuite::DynArrayReserveZero();
#endif
#if DYNARRAY_RESERVE_DOUBLE
	TestSuite::DynArrayReserveDouble();
#endif
#if DYNARRAY_RESERVE_SPEC 
	TestSuite::DynArrayReserveSpecific();
#endif
#if DYNARRAY_RESERVE_SMALLER
	TestSuite::DynArrayReserveSmaller();
#endif
#if DYNARRAY_APPEND_NO_RESIZE
	TestSuite::DynArrayAppendNoResize();
#endif
#if DYNARRAY_APPEND_RESIZE
	TestSuite::DynArrayAppendResize();
#endif
#endif	// end LAB_3
}

void Lab4Tests() {
#if LAB_4
#if LIST_QUEUE_ADD
	TestSuite::ListQueueAdd();
#endif
#if LIST_STACK_ADD
	TestSuite::ListStackAdd();
#endif
#if LIST_QUEUE_REMOVE
	TestSuite::ListQueueRemove();
#endif
#if LIST_STACK_REMOVE
	TestSuite::ListStackRemove();
#endif
#if LIST_INSERT_INDEX
	TestSuite::ListInsertIndex();
#endif
#if LIST_INSERT_ITER
	TestSuite::ListInsertIterator();
#endif
#if LIST_REMOVE_DECIMAL
	TestSuite::ListRemoveDecimal();
#endif
#endif	// end LAB_4
}

void Lab5Tests() {
#if LAB_5
#if LIST_CTOR
	TestSuite::LinkedListDefaultConstructor();
#endif
#if LIST_NODE_CTOR
	TestSuite::LinkedListNodeConstructorWithDefaults();
	TestSuite::LinkedListNodeConstructor();
#endif
#if LIST_COPY_CTOR
	TestSuite::LinkedListCopyConstructorInt();
	TestSuite::LinkedListCopyConstructorClass();
#endif
#if LIST_ASSIGNMENT_OP
	TestSuite::LinkedListAssignmentOperatorInt();
	TestSuite::LinkedListAssignmentOperatorClass();
#endif
#if LIST_ADDHEAD
	TestSuite::LinkedListAddHeadEmpty();
	TestSuite::LinkedListAddHeadExisting();
#endif
#if LIST_ADDTAIL
	TestSuite::LinkedListAddTailEmpty();
	TestSuite::LinkedListAddTailExisting();
#endif
#if LIST_CLEAR
	TestSuite::LinkedListClear();
#endif
#if LIST_INSERT
	TestSuite::LinkedListInsertEmpty();
	TestSuite::LinkedListInsertHead();
	TestSuite::LinkedListInsertMiddle();
#endif
#if LIST_ERASE
	TestSuite::LinkedListEraseEmpty();
	TestSuite::LinkedListEraseHead();
	TestSuite::LinkedListEraseTail();
	TestSuite::LinkedListEraseMiddle();
#endif
#if LIST_ITER_BEGIN
	TestSuite::LinkedListIterBegin();
#endif
#if LIST_ITER_END
	TestSuite::LinkedListIterEnd();
#endif
#if LIST_ITER_INCREMENT
	TestSuite::LinkedListIterPreIncrement();
	TestSuite::LinkedListIterPostIncrement();
#endif
#if LIST_ITER_DECREMENT
	TestSuite::LinkedListIterPreDecrement();
	TestSuite::LinkedListIterPostDecrement();
#endif
#endif // end LAB_5
}

void Lab6Tests() {
#if LAB_6
#if MAP_POPULATE_LETTER_VALUES
	TestSuite::MapPopulateLetterValues();
#endif
#if MAP_GET_LETTER_VALUE
	TestSuite::MapGetLetterValue();
#endif
#if MAP_GET_WORD_VALUE
	TestSuite::MapGetWordValue();
#endif
#if MAP_CREATE_PAIR
	TestSuite::MapCreatePair();
#endif
#if MAP_LOAD_FILE
	TestSuite::MapLoadFile();
#endif
#if MAP_FIND_WORD_SCORE
	TestSuite::MapFindWordScore();
#endif
#endif
}

void Lab7Tests() {
#if LAB_7

#if DICT_CTOR
	TestSuite::DictConstructor();
#endif
#if DICT_PAIR_CTOR
	TestSuite::DictPairConstructor();
#endif
#if DICT_COPY_CTOR		
	TestSuite::DictCopyConstructor();
#endif
#if DICT_ASSIGNMENT_OP	
	TestSuite::DictAssignmentOperator();
#endif
#if DICT_CLEAR			
	TestSuite::DictClear();
#endif
#if DICT_INSERT			
	TestSuite::DictInsert();
#endif
#if DICT_FIND			
	TestSuite::DictFind();
#endif
#if DICT_REMOVE			
	TestSuite::DictRemove();
#endif



#endif // end LAB_7
}

void Lab8Tests() {
#if LAB_8
#if BST_CTOR
	TestSuite::BSTDefaultConstructor();
#endif
#if BST_NODE_CTOR
	TestSuite::BSTNodeConstructor();
#endif
#if BST_COPY_CTOR
	TestSuite::BSTCopyConstructor();
#endif
#if BST_ASSIGNMENT_OP
	TestSuite::BSTAssignmentOperator();
#endif
#if BST_CLEAR
	TestSuite::BSTClear();
#endif
#if BST_PUSH_ROOT
	TestSuite::BSTPushRoot();
#endif
#if BST_PUSH_ROOT_LEFT
	TestSuite::BSTPushRootLeft();
#endif
#if BST_PUSH_ROOT_RIGHT
	TestSuite::BSTPushRootRight();
#endif
#if BST_PUSH_LEFT
	TestSuite::BSTPushLeft();
#endif
#if BST_PUSH_RIGHT
	TestSuite::BSTPushRight();
#endif
#if BST_CONTAINS_TRUE
	TestSuite::BSTContainsTrue();
#endif
#if BST_CONTAINS_FALSE
	TestSuite::BSTContainsFalse();
#endif
#if BST_REMOVE_CASE0_ROOT
	TestSuite::BSTRemoveCase0Root();
#endif
#if BST_REMOVE_CASE0
	TestSuite::BSTRemoveCase0();
#endif
#if BST_REMOVE_CASE1_ROOT_LEFT
	TestSuite::BSTRemoveCase1RootLeft();
#endif
#if BST_REMOVE_CASE1_ROOT_RIGHT
	TestSuite::BSTRemoveCase1RootRight();
#endif
#if BST_REMOVE_CASE1_LEFT_LEFT
	TestSuite::BSTRemoveCase1LeftLeft();
#endif
#if BST_REMOVE_CASE1_LEFT_RIGHT
	TestSuite::BSTRemoveCase1LeftRight();
#endif
#if BST_REMOVE_CASE1_RIGHT_LEFT
	TestSuite::BSTRemoveCase1RightLeft();
#endif
#if BST_REMOVE_CASE1_RIGHT_RIGHT
	TestSuite::BSTRemoveCase1RightRight();
#endif
#if BST_REMOVE_CASE2_ROOT
	TestSuite::BSTRemoveCase2Root();
#endif
#if BST_REMOVE_CASE2_SUBTREE
	TestSuite::BSTRemoveCase2Subtree();
#endif
#if BST_REMOVE_CASE2_NO_SUBTREE
	TestSuite::BSTRemoveCase2NonRootNoSubtree();
#endif
#if BST_REMOVE_NOT_FOUND
	TestSuite::BSTRemoveNotFound();
#endif
#if BST_IN_ORDER_TRAVERSAL
	TestSuite::BSTInOrderTraversal();
#endif
#endif // End LAB_8
}

void Lab9Tests() {
#if LAB_9
#if HUFFMAN_CTOR
	TestSuite::HuffmanConstructor();
#endif
#if HUFFMAN_GENERATE_FREQUENCY
	TestSuite::HuffmanGenerateFrequencyTable();
#endif
#if HUFFMAN_GENERATE_LEAFLIST
	TestSuite::HuffmanGenerateLeafList();
#endif
#if HUFFMAN_GENERATE_TREE
	TestSuite::HuffmanGenerateTree();
#endif
#if HUFFMAN_GENERATE_ENCODING
	TestSuite::HuffmanGenerateEncodingTable();
#endif
#if HUFFMAN_COMPRESS
	TestSuite::HuffmanCompress();
#endif
#if HUFFMAN_DECOMPRESS
	TestSuite::HuffmanDecompress();
#endif
#endif // END LAB_9
}