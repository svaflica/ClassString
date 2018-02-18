#include "stdafx.h"
#include "Other_Exception.h"

Other_Exception::Other_Exception()
{
	message_ = "Other Exception!";
}


Other_Exception::Other_Exception(const char *message)
{
	message_ = message;
}



const char*
Other_Exception::getMessage()
{
	return message_;
}


Other_Exception::~Other_Exception()
{
}
