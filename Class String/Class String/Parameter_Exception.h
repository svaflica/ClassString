#pragma once
#include "Exceptions.h"
class Parameter_Exception :
	public Exceptions
{
public:
	Parameter_Exception();
	Parameter_Exception(const char *nameFunction, const char *nameParameter);

	const char *getNameParameter();
	const char *getNameFunction();
	const char *getMessage();

	~Parameter_Exception();

private:
	const char *nameFunction_;
	const char *nameParameter_;
	const char *message_ = "Parameter in function is invalid";
};

