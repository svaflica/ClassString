// Class String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "String.h"
#include "Memory_Exception.h"
#include "Length_Exception.h"
#include "Out_Of_Range.h"
#include "Refer_To_Nullptr.h"
#include "Other_Exception.h"
#include "Parameter_Exception.h"

int main()
{
	try 
	{
		String obj("Super mount!");

		String obj2;

		//Sho ce za oshibka?
		obj2 = copyPartly(2, 7, obj);

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
	catch (Other_Exception error)
	{
		cout << error.getMessage();
	}
	catch (Parameter_Exception error)
	{
		cout << error.getMessage()<< "\n";
		cout << "Name of Function: " << error.getNameFunction() << "\n";
		cout << "Name of Parameter: " << error.getNameParameter() << "\n";
	}
}

