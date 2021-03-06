#pragma once
#include "Exceptions.h"
class Length_Exception :
	public Exceptions
{
public:
	Length_Exception();
	Length_Exception(int check);
	~Length_Exception();
	const char* getMessage();

private:
	const char *MESSAGE_ = "Length_Exception: length should be positive and less than upper bound";
};

