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
	int counter = 1;
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
	double left = Primary(inputStream);
	Token NextToken = inputStream.Get();
	while (true)
	{
		switch (NextToken.type)
		{
		case '*':
			left *= Primary(inputStream);
			NextToken = inputStream.Get();
			break;
		case '/':
			left /= Primary(inputStream);
			NextToken = inputStream.Get();
			break;
		default:
			inputStream.PutBack(NextToken);
			return left;
			break;
		}
	}
}

double Primary(TokenStream& inputStream)
{
	Token PrimaryToken = inputStream.Get();
	PrimaryToken.print();
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
