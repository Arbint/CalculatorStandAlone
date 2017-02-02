// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UniverSalInclude.h"
#include "Token.h"
#include "TokenStream.h"
#include "Fucs.h"
int main()
{
	try
	{
		TokenStream inputStream;
		double x = Expression(inputStream);
		std::cout << "the result is: " << x << std::endl;
		return 0;
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

