#pragma once
#include "Exceptions.h"
class Refer_To_Nullptr :
	public Exceptions
{
public:
	Refer_To_Nullptr();
	~Refer_To_Nullptr();
	const char* getMessage();

private:
	const char *MESSAGE_ = "Refer_To_Nullptr!";
};

