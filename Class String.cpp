// Class String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "String.h"


int main()
{
	String obj("It");
	String obj2("Works");
	String str(1, 'o');

	obj = obj + obj2;
	cout << "It's maybe working! " << obj << '\n';

	if (obj2 == "Lol"){
		cout << "It's maybe working! " << obj2 << '\n';
	}

	if (obj2 <= obj)
		cout << obj2 << " <= " << obj << '\n';

	if (obj2 <= obj2)
		cout << obj2 << " <= " << obj2 << '\n';

	if (obj >= obj2)
		cout << obj << " >= " << obj2 << '\n';
	
	if (obj >= obj)
		cout << obj2 << " >= " << obj2 << '\n';

	cout << "Length of " << obj << " = " << obj.getLength();

	cout << "Index of o "<< " = " << obj.getIndexOfSymbol(str);

	cout << "Index of " << obj2 << " = " << obj.getIndexOfWord("Lol") << '\n';

	cout << "Index of " << obj2 << " = " << obj.getIndexOfWord(obj2) << '\n';

	cout << appendToLine(obj2, obj, 4);

    return 0;
}

