#include "SIMCard.h"


SIMCard::SIMCard(string op, long long num) :oper(op), number(num)
{
}


SIMCard::~SIMCard()
{
}

 string SIMCard::getOperator() const
{
	return oper;
}
long long SIMCard::getNumber() const
{
	return number;
}
