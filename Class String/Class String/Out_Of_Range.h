#pragma once
#include "Exceptions.h"
class Out_Of_Range :
	public Exceptions
{
public:
	Out_Of_Range();
	~Out_Of_Range();
	const char* getMessage();

private:
	const char *message_ = "Out_Of_Range: index should be greater than bottom bound of array and lower than upper bound of array.";
};

