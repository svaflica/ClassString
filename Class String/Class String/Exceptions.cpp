#include "stdafx.h"
#include "Exceptions.h"


Exceptions::Exceptions()
{
}


const char* 
Exceptions::getMessage() const
{
	return message_;
}


Exceptions::~Exceptions()
{
}
