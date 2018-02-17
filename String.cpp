#include "String.h"

// Все замечания
// Мелкие (желательно делать так)
// ---> вместо символа tab лучше использовать
//      пробелы (можно настроить, чтобы tab'ы равнялись пробелам)
// ---> коментарии не писать на одной строке с кодом
// ---> если в блоках if else находится оператор
//      безусловного перехода, то можно не писать else
// ---> Про последовательность по модификаторам доступа. Порядок следующий:
//      public -> protected -> private
//
// Между мелкими и средними
// ---> использование нулвого указателя в качестве значения
//      не очень хорошая мысль. Порождает дополнительные проверки
// ---> для каждого типа использовать явные литералы соответствующие их типу, т.е.
//      bool flag = 1;    // плохо!
//      bool flag = true; // хорошо
//      char ch = '\0';   // хорошо
//      char ch = 0;      // плохо!
// ---> в функциях, возвращающих bool-значение можно
//      условные конструкции записывать в return
// ---> функция getIndexOfSymbol возвращает позицию, а не индекс (индексация с нуля).
//      Момент спорен
// ---> Зачем возвращать String в функции invert.
//      Ведь она на входе изменяет строку. В результате получам две
//      перевёрнутые строки.
//
// Очень серьёзные
// ---> функция cmp. Надо написать более красиво (у себя)
// ---> функция
//      int getIndexOfSymbol(String& string);
//      возможно не правильно реализованна. По названию сложно
//      понять, что она делает
//
// Мысли по улучшению (касается и меня)
// ---> сделать конструктор с параметром, принимающим длину строки
// ---> *(Расплывчато)* пояснять "неочевидные" места кода (забить на это. Понимание придёт с опытом)

String::String()
{
	value_ = new char[1];
	value_[0] = '\0';

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

	for (int i = 0; i < length_; i++)
		value_[i] = value[i];
	value_[length_] = '\0';
}


String::String(int length, char symbol)
{
	if (length <= 0)
		throw "Length is unpositive";

	value_ = new char[length + 1];
	length_ = length;

	for (int i = 0; i < length; i++)
		value_[i] = symbol;
	value_[length] = '\0';
}


String::String(const String& string)
{
		length_ = string.length_;
		value_ = new char[length_ + 1];

		for (int i = 0; i < string.length_; i++)
			value_[i] = string.value_[i];
		value_[length_] = '\0';
}


String&
String::operator=(const String& string)
{
		if (this == &string)
			return *this;

		delete[] value_;
		value_ = new char[string.length_ + 1];
		length_ = string.length_;

		for (int i = 0; i < string.length_; i++)
			value_[i] = string.value_[i];
		value_[string.length_] = '\0';

		return *this;
}


String operator+(const String& str, const String& str2)
{
	if (str2.value_[0] == '\0')
	{
		return String(str);
	}

	String temp;

	temp.length_ = str.length_ + str2.length_;
	temp.value_ = new char[temp.length_ + 1];

	for (int i = 0; i < str.length_; i++)
		temp.value_[i] = str.value_[i];

	for (int i = str.length_; i < temp.length_; i++)
		temp.value_[i] = str2.value_[i - str.length_];
	temp.value_[temp.length_] = '\0';

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
	// а ещё лучше сравнивать без создания объекта
	String temp(string);

	return (this->cmp(temp) == 0);
}


bool
String::operator<=(const String& string)
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
String::operator>(const String& string)
{
	return (this->cmp(string) == -1);
}

bool
String::operator<(const String& string)
{
	int check = this->cmp(string);

	return (this->cmp(string) == 1);
}


ostream& operator<<(ostream& out, String& string)
{
	for (int i = 0; i < string.length_; i++)
		out << string.value_[i];

	return out;
}


int
String::cmp(const String& string)
{
	int check = 0;
	while (value_[check] == string.value_[check] && value_[check] != '\0' && string.value_[check] != '\0')
		check++;

	if (value_[check] == string.value_[check])
	    return 0;
	if (value_[check] > string.value_[check])
	    return 1;
	if (value_[check] < string.value_[check])
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

	int index = -1;

	for (int i = 0; (i < length_); i++)
		if (value_[i] == symbol)
			return (i + 1);
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
			else
				index = -1;
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
	if ((value_ != 0) && (N >= 0) && (N < length_))
		return value_[N];
}


void* operator new[](size_t N)
{
		void* ptr = malloc(N);

		if (ptr == 0)
			throw "Error, memory is full";
		else
			return ptr;
}