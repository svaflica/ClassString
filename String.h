#pragma once

#include <iostream>
// Возможно я затёр заголовки!!!

using namespace std;

class String
{
public:
	// Ok
	String();
	// Недочёты
	String(const char* value);
	// Ok +/-
	String(int length, char symbol);
	// Ok +/-
	String(const String& string);

	// Ok
	~String();

	// Можно улучшить
	String& operator=(const String& string);

	// Вопрос. Есть недочёт
	friend String operator+(const String& string, const String& string2);
	// Недочёты
	friend String operator*(String& str, int N);

	// Недочёт по всем сравнениям
	bool operator==(const String& string);
	bool operator==(const char* string);
	bool operator<=(const String& string);
	bool operator>=(const String& string);
	bool operator>(const String& string);
	bool operator<(const String& string);

	// Недочёты
	friend String& invert(String& string);
	// Ок
	friend ostream& operator<<(ostream& out, String& string);
	//Ok
	char& operator[](int N);

	// Ok
	int getLength();
	// Можно оптимизировать
	int getIndexOfSymbol(char symbol);
	// Из-за функции выше можно улучшить и этот метод
	int getIndexOfWord(String& string);

	void* operator new[](size_t N);
private:
	char* value_;
	int length_;

	int cmp(const String& string);
};
