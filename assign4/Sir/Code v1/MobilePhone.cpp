#include "MobilePhone.h"
#include "Modem.h"
#include "Network.h"
#include "Camera.h"
#include "SDCard.h"

#include <iostream>
using namespace std;

MobilePhone::MobilePhone(string model, Manufacturer man, const vector<Modem *>& imodems)
:modelName(model), mfr(man), net(0), modems(imodems), sdc(0)
{

}

MobilePhone::~MobilePhone()
{
	for (unsigned int i = 0; i < modems.size(); i++)
		delete modems[i];

	for (unsigned int i = 0; i < cameras.size(); i++)
		delete cameras[i];

	if (sdc)
		delete sdc;
}

void MobilePhone::getNumbers(vector<long long>& nums) const
{
	for (unsigned int i = 0; i < modems.size(); i++) {
		long long num = getNumber(i);
		if (num != 0)
			nums.push_back(modems[i]->getNumber());
	}
}

long long MobilePhone::getNumber(int index) const
{
	return modems[index]->getNumber();
}

bool MobilePhone::makeCall(long long to, long long from )
{
	if (from == 0)
	{
		from = getNumber(0);
	}
	return net->makeCall(from, to);
}

void MobilePhone::receiveCall(long long number)
{
	MobilePhone *fromPhone = net->findPhone(number);

	cout << "Incoming call from: " << number << fromPhone << endl;
}

bool MobilePhone::addSim(SIMCard *sim, unsigned int index) 
{
	if (index >= modems.size()) {
		cout << "Cannot add SIM at location " << index << endl;
		return false;
	}
	modems[index]->addSim(sim);
	return true;
}

SIMCard *MobilePhone::removeSim(unsigned int index) {
	SIMCard * sc = getSIM(index);
	if (sc) {
		modems[index]->addSim(NULL);
	}
	return sc;
}

SIMCard *MobilePhone::getSIM(unsigned int index) const
{
	if (index >= modems.size()) {
		cout << "Cannot get SIM at location " << index << endl;
		return NULL;
	}
	return modems[index]->getSim();

}

void MobilePhone::setNetwork(Network *nw)
{
	net = nw;
}

const Manufacturer& MobilePhone::getManufacturer() const
{
	return mfr;
}

void MobilePhone::getModems(vector<Modem *>& omodems)
{
	omodems = modems;
}
