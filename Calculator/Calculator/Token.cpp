#include "stdafx.h"
#include "Token.h"

Token::Token()
{
}

Token::Token(char inType, double inValue)
	:type(inType), value(inValue)
{

}

void Token::print()
{
	std::cout << type << " " << value << std::endl;
}

Token::~Token()
{

}

