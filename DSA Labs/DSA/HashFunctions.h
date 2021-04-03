// HashFunctions.h - Hashing functions used for Dictionary (Lab 6)

#pragma once

#include <string>
using namespace std;

// Number of buckets to use for each hashFunc
#define HASH_BUCKETS1	0
#define HASH_BUCKETS2	0

// HashFunc1 - Used for hashing integer value keys
// In:	_val		The value to hash
//
// Return: The index of the bucket to add/find this value at
unsigned int HashFunc1(const int& _val);

// HashFunc2 - Used for hashing string value keys
// In:	_val		The value to hash
//
// Return: The index of the bucket to add/find this value at
unsigned int HashFunc2(const string& _val);

