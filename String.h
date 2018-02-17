#pragma once

#include <iostream>
// �������� � ���� ���������!!!

using namespace std;

class String
{
public:
	// Ok
	String();
	// ��������
	String(const char* value);
	// Ok +/-
	String(int length, char symbol);
	// Ok +/-
	String(const String& string);

	// Ok
	~String();

	// ����� ��������
	String& operator=(const String& string);

	// ������. ���� �������
	friend String operator+(const String& string, const String& string2);
	// ��������
	friend String operator*(String& str, int N);

	// ������� �� ���� ����������
	bool operator==(const String& string);
	bool operator==(const char* string);
	bool operator<=(const String& string);
	bool operator>=(const String& string);
	bool operator>(const String& string);
	bool operator<(const String& string);

	// ��������
	friend String& invert(String& string);
	// ��
	friend ostream& operator<<(ostream& out, String& string);
	//Ok
	char& operator[](int N);

	// Ok
	int getLength();
	// ����� ��������������
	int getIndexOfSymbol(char symbol);
	// ��-�� ������� ���� ����� �������� � ���� �����
	int getIndexOfWord(String& string);

	void* operator new[](size_t N);
private:
	char* value_;
	int length_;

	int cmp(const String& string);
};
