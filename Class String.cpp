// Class String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "String.h"
#include "Memory_Exception.h"
#include "Length_Exception.h"
#include "Out_Of_Range.h"
#include "Refer_To_Nullptr.h"

int main()
{
	try 
	{
		String obj(-3, 'a');

		String obj2;

		obj2 = obj.toUpper();

		cout << obj2 << "\n";

		return 0;
	}
	catch (Memory_Exception error) 
	{
		cout << error.getMessage();
	}

	catch (Length_Exception error)
	{
		cout << error.getMessage();
	}

	catch (Out_Of_Range error)
	{
		cout << error.getMessage();
	}

	catch (Refer_To_Nullptr error)
	{
		cout << error.getMessage();
	}
}

