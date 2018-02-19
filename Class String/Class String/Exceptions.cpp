#include "stdafx.h"
#include "Exceptions.h"


Exceptions::Exceptions()
{
}


const char* 
Exceptions::getMessage()
{
	return message_;
}


Exceptions::~Exceptions()
{
}
