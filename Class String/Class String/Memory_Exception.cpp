#include "stdafx.h"
#include "Memory_Exception.h"


Memory_Exception::Memory_Exception()
{
}


Memory_Exception::~Memory_Exception()
{
}


const char*
Memory_Exception::getMessage()
{
	return message_;
}
