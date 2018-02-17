#include "stdafx.h"
#include "String.h"
#include "Memory_Exception.h"
#include "Length_Exception.h"
#include "Out_Of_Range.h"
#include "Refer_To_Nullptr.h"


String::String()
{
	value_ = nullptr;
	/*value_ = new char[1];
	value_[0] = '\0';*/

	length_ = 0;
}


String::~String()
{
	delete[] value_;
}


String::String(const char* value)
{
	if (value == nullptr)
		throw "Value is empty";

	length_ = strlen(value);
	value_ = new char[length_ + 1];
	if (value_ == nullptr)
		throw Memory_Exception();

	for (int i = 0; i <= length_; i++)
		value_[i] = value[i];
}


String::String(int length, char symbol)
{
	if (length <= 0)
		throw Length_Exception();

	length_ = length;
	value_ = new char[length + 1];
	if (value_ == nullptr)
		throw Memory_Exception();

	for (int i = 0; i <= length; i++)
		value_[i] = symbol;
}


String::String(const String& string)
{

	*this = string;

}


String&
String::operator=(const String& string)
{
	if (this == &string)
		return *this;

	if (value_ != nullptr)
		delete[] value_;

	if (string.length_ == 0) {
		value_ = nullptr;

		length_ = 0;
	}

	value_ = new char[string.length_ + 1];
	if (value_ == nullptr)
		throw Memory_Exception();

	length_ = string.length_;

	for (int i = 0; i <= string.length_; i++)
		value_[i] = string.value_[i];

	return *this;
}


String operator+(const String& str, const String& str2)
{
	if (str2.value_ == nullptr)
	{
		return String(str);
	}

	String temp;

	temp.length_ = str.length_ + str2.length_;
	temp.value_ = new char[temp.length_ + 1];
	if (temp.value_ == nullptr)
		throw Memory_Exception();

	for (int i = 0; i < str.length_; i++)
		temp.value_[i] = str.value_[i];

	for (int i = str.length_; i <= temp.length_; i++)
		temp.value_[i] = str2.value_[i - str.length_];

	return temp;
}

bool
String::operator==(const String& string)
{
	return (this->cmp(string) == 0);
}

bool
String::operator==(const char* string)
{
	return (this->cmp(string) == 0);
}


bool
String::operator<=(const String& string)
{
	int check = this->cmp(string);

	return ((check == 1) || (check == 0));
}


bool
String::operator<=(const char* string)
{
	int check = this->cmp(string);

	return ((check == 1) || (check == 0));
}


bool
String::operator>=(const String& string)
{
	int check = this->cmp(string);

	return ((check == -1) || (check == 0));
}


bool
String::operator>=(const char* string)
{
	int check = this->cmp(string);

	return ((check == -1) || (check == 0));
}


bool
String::operator>(const String& string)
{
	return (this->cmp(string) == -1);
}


bool
String::operator>(const char *string)
{
	return (this->cmp(string) == -1);
}


bool
String::operator<(const String& string)
{
	int check = this->cmp(string);

	return (this->cmp(string) == 1);
}


bool
String::operator<(const char* string)
{
	int check = this->cmp(string);

	return ((check == 1) || (check == 0));
}


ostream& operator<<(ostream& out, String& string)
{
	out << string.value_;

	return out;
}


int
String::cmp(const String& string)
{
	int check = 0;
	bool flagEnd = (value_[check] != '\0' && string.value_[check] != '\0');
	while (value_[check] == string.value_[check] && flagEnd)
		check++;

	if (value_[check] == string.value_[check])
		return 0;
	else if (value_[check] > string.value_[check])
		return 1;
	else
		return -1;
}


int
String::cmp(const char *string)
{
	int check = 0;
	while (value_[check] == string[check] && value_[check] != '\0' && value_[check] != '\0')
		check++;

	if (value_[check] == value_[check])
		return 0;
	else if (value_[check] > value_[check])
		return 1;
	else
		return -1;
}



int
String::getLength()
{
	return this->length_;
}


int
String::getIndexOfSymbol(char symbol)
{
	if (value_[0] == '\0')
		return -1;

	for (int i = 0; (i < length_); i++)
		if (value_[i] == symbol)
			return (i + 1);

	return -1;
}


int
String::getIndexOfWord(String& string)
{
	if (*this == string)
		return 0;
	else
	{
		int index = -1;
		int n = length_;
		int i, j;

		for (i = 0, j = 0; (j != -1) && (i < n); i++)
		{
			if (value_[i] == string.value_[j])
			{
				if (j == 0)
					index = i + 1;

				j++;

				if (string.value_[j] == 0)
					j = -1;
			}
			else {
				j = 0;
				index = -1;
			}
		}

		return index;
	}
}


String operator*(String& str, int N)
{
	if (N < 0) {
		throw "Unpositive parameter!";
		return str;
	}

	if (N == 0)
		return String();

	if (N == 1)
		return str;

	String temp;
	temp.length_ = str.length_ * N;
	temp.value_ = new char[temp.length_];
	if (temp.value_ == nullptr)
		throw Memory_Exception();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < str.length_; j++)
			temp.value_[j + i * str.length_] = str.value_[j];
	temp.value_[temp.length_] = 0;

	return temp;
}


String& invert(String& string)
{
	if (string.value_[0] == '\0')
		throw "Error, the string is empty!";
	else {
		if (string.length_ == 1)
			return string;

		for (int i = 0; i < string.length_ / 2; i++)
		{
			char t = string.value_[i];
			string.value_[i] = string.value_[string.length_ - i - 1];
			string.value_[string.length_ - i - 1] = t;
		}

		return string;
	}
}


char&
String::operator[](int N)
{
	if (value_ = nullptr)
		throw Refer_To_Nullptr();

	if (N < 0 || N >= length_)
		throw Out_Of_Range();

	return value_[N];
}


void* operator new[](size_t N)
{
	void* ptr = malloc(N);

	if (ptr == 0)
		throw Memory_Exception();
		
	return ptr;
}


String& 
String::toLower()
{
	bool alpha;
	bool upper;
	for (int i = 0; i < length_; i++) {
		alpha = isAlpha(value_[i]);
		upper = isUpper(value_[i]);

		if (alpha && upper)
			value_[i] = value_[i] + 32;
		else 
			value_[i] = value_[i];
	}

	return *this;
}


String& 
String::toUpper()
{
	bool alpha;
	bool lower;
	for (int i = 0; i < length_; i++) {
		alpha = isAlpha(value_[i]);
		lower = isLower(value_[i]);

		if (alpha && lower)
			value_[i] = value_[i] - 32;
		else 
			value_[i] = value_[i];
	}

	return *this;
}


bool 
String::isAlpha(char &symbol)
{
	bool upperSymbol = (64 < symbol && symbol < 91); 
	bool lowerSymbol = (96 < symbol && symbol < 123);

	if (upperSymbol || lowerSymbol)
		return true;
	else
		return false;
}


bool 
String::isLower(char &symbol)
{

	if (96 < symbol && symbol < 123)
		return true;
	else
		return false;
}


bool 
String::isUpper(char &symbol)
{
	if (64 < symbol && symbol < 91)
		return true;
	else
		return false;
}