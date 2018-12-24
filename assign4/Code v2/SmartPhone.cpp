
#include <iostream>
using namespace std;

#include "SmartPhone.h"


SmartPhone::SmartPhone(string model, Manufacturer man, vector<Modem *>& modems, string cmodel, string cmanufacturer)
		:MobilePhone(model, man, modems), compModel(model), compManufacturer(cmanufacturer)
{

}


SmartPhone::~SmartPhone()
{
}

const string& SmartPhone::getCompModel() const
{
	return compModel;
}

const string& SmartPhone::getCompManufacturer() const
{
	return compManufacturer;
}

void
SmartPhone::print(ostream& os) const
{
	cout << "Smartphone: " << endl;
	MobilePhone::print(os);
	cout << "Computer model and manufacturer: " << compModel << " " << compManufacturer << endl;
}

