#pragma once
class Exceptions
{
public:
	Exceptions();
	virtual ~Exceptions();

	const char* getMessage();

private:
	const char *message_ = "Some exception in class String!";
};

