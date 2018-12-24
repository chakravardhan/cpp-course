#include <iostream>
#include<vector>
using namespace std;

#include "Modem.h"
#include "SIMCard.h"


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

long long Modem::getIMEI() const
{
	return IMEInumber;
}

string Modem::getTechnology() const
{
	return wtech;
}


void
Modem::print(ostream& os) const
{
	cout << wtech << " IMEI: " << IMEInumber << " " ;
	if (sim) {
		sim->print(os);
		cout << endl;
	}
	else {
		cout << " No SIM" << endl;
	}
}

