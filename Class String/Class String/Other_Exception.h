#pragma once
#include "Exceptions.h"
class Other_Exception :
	public Exceptions
{
public:
	Other_Exception();
	Other_Exception(const char *message);

	~Other_Exception();

	const char *getMessage();

private:
	const char *message_;
};

