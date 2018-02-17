#pragma once

#include <iostream>

using namespace std;

class String
{
private:
	char* value_;
	int length_;

	int cmp(const String& string);
	int cmp(const char *string);

public:
	String();
	String(const char* value);
	String(int length, char symbol);
	String(const String& string);

	~String();

	String& operator=(const String& string);

	friend String operator+(const String& string, const String& string2);
	friend String operator*(String& str, int N);

	bool operator==(const String& string);
	bool operator==(const char *string);
	bool operator<=(const String& string);
	bool operator<=(const char *string);
	bool operator>=(const String& string);
	bool operator>=(const char *string);
	bool operator>(const String& string);
	bool operator>(const char *string);
	bool operator<(const String& string);
	bool operator<(const char *string);

	char& operator[](int N);

	void* operator new[](size_t N);

	friend String& invert(String& string);
	friend ostream& operator<<(ostream& out, String& string);

	int getLength();
	int getIndexOfSymbol(char symbol);
	int getIndexOfWord(String& string);

	String& toLower();
	String& toUpper();
	bool isAlpha(char &symbol);
	bool isLower(char &symbol);
	bool isUpper(char &symbol);
};

