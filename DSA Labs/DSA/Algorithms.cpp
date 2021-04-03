// Algorithms.cpp - A collection of various algorithms 
//		Used in Lab 1

#include "Algorithms.h"

bool IsPalindromeNumber(unsigned int _num) {
	string strNumber = to_string(_num);

	size_t last = strNumber.size() - 1;

	for (size_t i = 0; i < strNumber.size() / 2; ++i, --last)
		if (strNumber[i] != strNumber[last])
			return false;

	return true;
}