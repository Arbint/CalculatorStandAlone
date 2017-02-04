#include "stdafx.h"
#include "Token.h"
#include "TokenStream.h"
#include "Fucs.h"

void error(std::string errorMessage)
{
	throw std::runtime_error(errorMessage);
}

double Expression(TokenStream& inputStream)
{
	double left = Term(inputStream);
	Token nextToken = inputStream.Get();
	while (true)
	{
		switch (nextToken.type)
		{
		case '+':
			left += Term(inputStream);
			nextToken = inputStream.Get();
			break;
		case '-':
			left -= Term(inputStream);
			nextToken = inputStream.Get();
			break;
		case ';':
			return left;
		case 'q':
			exit(0);
		default:
			inputStream.PutBack(nextToken);
			return left;
		}
	}
	return left;
}

double Term(TokenStream& inputStream)
{
	double left = Factorial(inputStream);
	Token NextToken = inputStream.Get();
	while (true)
	{
		switch (NextToken.type)
		{
		case '*':
			left *= Factorial(inputStream);
			NextToken = inputStream.Get();
			break;
		case '/':
			left /= Factorial(inputStream);
			NextToken = inputStream.Get();
			break;
		default:
			inputStream.PutBack(NextToken);
			return left;
			break;
		}
	}
}

double Factorial(TokenStream& inputStream)
{
	double left = Primary(inputStream);
	Token NextToken = inputStream.Get();
	while (true)
	{
		switch (NextToken.type)
		{
		case '!':
			left = CalculateFactorial(left);
			NextToken = inputStream.Get();
			break;
		default:
			inputStream.PutBack(NextToken);
			return left;
			break;
		}
	}
	return left;
}

double Primary(TokenStream& inputStream)
{
	Token PrimaryToken = inputStream.Get();
	switch (PrimaryToken.type)
	{
	case '8':
		return PrimaryToken.value;
	case '(':
	{
		double returnValue = Expression(inputStream);
		Token NextToken = inputStream.Get();
		if (NextToken.type != ')')
		{
			error("Missing corresponding ')'");
		}
		return returnValue;
	}
	case '{':
	{
		double returnValue = Expression(inputStream);
		Token NextToken = inputStream.Get();
		if (NextToken.type != '}')
		{
			error("Missing corresponding ')'");
		}
		return returnValue;
	}
	case ';':
		return PrimaryToken.value;
	case 'q':
		exit(0);
	default:
		error("wrongPrimary");
		break;
	}
	return 0;
}

double CalculateFactorial(double inNumber)
{
	if (inNumber < 0)
	{
		error("get factorial with root smaller than 0");
	}
	if (inNumber == 0)
	{
		return 1;
	}
	int IntValue = static_cast<int>(inNumber);
	for (int loopValue = IntValue - 1; loopValue > 0; --loopValue)
	{
		IntValue *= loopValue;
	} 
	return IntValue;
}

