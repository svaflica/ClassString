#include "stdafx.h"
#include "Length_Exception.h"


Length_Exception::Length_Exception()
{
}


Length_Exception::~Length_Exception()
{
}


const char* 
Length_Exception::getMessage()
{
	return MESSAGE_;
}
