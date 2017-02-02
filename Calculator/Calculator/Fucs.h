#pragma once
#include "UniverSalInclude.h"

//forward declaration
class Token;
class TokenStream;

void error(std::string errorMessage);

double Expression(TokenStream& inputStream);
double Term(TokenStream& inputStream);
double Primary(TokenStream& inputStream);