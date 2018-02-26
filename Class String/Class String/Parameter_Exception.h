#pragma once
#include "Exceptions.h"
class Parameter_Exception :
	public Exceptions
{
public:
	Parameter_Exception();
	Parameter_Exception(const char *nameFunction, const char *nameParameter);

	const char *getNameParameter() const;
	const char *getNameFunction() const;
	const char *getMessage() const;

	~Parameter_Exception();

private:
	const char *nameFunction_;
	const char *nameParameter_;
	const char *message_ = "Parameter in function is invalid";
};

