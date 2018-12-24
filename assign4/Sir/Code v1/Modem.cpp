
#include "Modem.h"
#include "SIMCard.h"
#include<vector>
using namespace std;

Modem::Modem(string wt, long long imei):wtech(wt), sim(0), IMEInumber(imei)
{
}


Modem::~Modem()
{
}

void Modem::addSim(SIMCard *s)
{
	sim = s;

}
SIMCard *Modem::getSim() const
{
	return sim;
}

long long Modem::getNumber() const
{
	if (sim)
		return sim->getNumber();
	else
		return 0;
}


string Modem::getTechnology() const
{
	return wtech;
}