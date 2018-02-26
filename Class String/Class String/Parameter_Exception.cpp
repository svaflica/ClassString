#include "stdafx.h"
#include "Parameter_Exception.h"


Parameter_Exception::Parameter_Exception()
{
	nameFunction_ = "Unknown";
	nameParameter_ = "Unknown";
}


Parameter_Exception::Parameter_Exception(const char *nameFunction, const char *nameParameter)
{
	nameFunction_ = nameFunction;
	nameParameter_ = nameParameter;
}


const char*
Parameter_Exception::getNameParameter() const
{
	return nameParameter_;
}


const char*
Parameter_Exception::getNameFunction() const
{
	return nameFunction_;
}


const char*
Parameter_Exception::getMessage() const
{
	return message_;
}


Parameter_Exception::~Parameter_Exception()
{
}
