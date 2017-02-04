#include "stdafx.h"
#include "TokenStream.h"


TokenStream::~TokenStream()
{
}

TokenStream::TokenStream()
{

}

Token TokenStream::Get()
{
	if (bIsBufferFull)
	{
		bIsBufferFull = false;
		return Buffer;
	}
	char rawInput;
	std::cin >> rawInput;
	switch (rawInput)
	{
	case '+': case '-': case '*': case '/': case '(': case ')': case ';': case 'q':
	case '{': case '}': case '!':
		return Token(rawInput, 0);
	case '.': case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
	{
		double NumberInput;
		std::cin.putback(rawInput);
		std::cin >> NumberInput;
		return Token('8', NumberInput);
	}
	default:
		break;
	}
	error("Wrong Token");
	return Token();
}

void TokenStream::PutBack(Token & TokenToPutBack)
{
	if (bIsBufferFull)
	{
		error("Buffer already Full");
	}
	bIsBufferFull = true;
	Buffer = TokenToPutBack;
}


