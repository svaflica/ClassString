#pragma once
#include "Exceptions.h"
class Memory_Exception :
	public Exceptions
{
public:
	Memory_Exception();
	~Memory_Exception();
	const char* getMessage() const;

private:
	const char *message_ = "Memory_Exception: memory is full. Please, free some space.";
};

