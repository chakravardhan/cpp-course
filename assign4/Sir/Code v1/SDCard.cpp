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