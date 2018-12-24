#include <iostream>
using namespace std;

#include "SDCard.h"


SDCard::SDCard(int cap):capacity(cap)
{
}


SDCard::~SDCard()
{
}

int SDCard::getCapacity() const
{
	return capacity;

}


void
SDCard::print(ostream& os) const
{

}

