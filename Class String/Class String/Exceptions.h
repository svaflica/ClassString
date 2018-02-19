#pragma once
class Exceptions
{
public:
	Exceptions();
	~Exceptions();

	const char* getMessage();

private:
	const char *message_ = "Some exception in class String!";
};

