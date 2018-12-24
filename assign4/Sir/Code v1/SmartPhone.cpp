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
