#pragma once
#include "UniverSalInclude.h"
#include "Fucs.h"
class Token
{
public:
	Token();
	Token(char inType, double inValue);
	void print();
	char type;
	double value;
	~Token();
};

