#pragma once
#include "UniverSalInclude.h"
#include "Token.h"
class TokenStream
{
public:
	TokenStream();


	Token Get();
	void PutBack(Token& TokenToPutBack);

	~TokenStream();
private:
	Token Buffer;
	bool bIsBufferFull = false;
};

