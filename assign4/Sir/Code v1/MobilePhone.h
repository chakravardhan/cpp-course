#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include <string>
#include <vector>
using namespace std;

class Modem;
class Camera;
class SDCard;
class SIMCard;
class Network;

#include "Manufacturer.h"

class MobilePhone
{

public:

	~MobilePhone();

	void     getNumbers(vector<long long>& nums) const;
	long long getNumber(int index = 0) const;

	bool     makeCall(long long to, long long from = 0);
	void     receiveCall(long long number);

	bool     addSim(SIMCard *sim, unsigned int index);
	SIMCard *removeSim(unsigned int i);
	SIMCard *getSIM(unsigned int i) const;
	bool     addSDcard(SDCard *sd);
	SDCard  *removeSDCard();

	void     setNetwork(Network *net);

	const Manufacturer& getManufacturer() const;

	void     getModems(vector<Modem *>& modems);

	virtual void print() {}  // can be used to conveniently get the right kind of print invoked. Not implemented yet

protected:
	// we don't objects of type MobilePhone to be directly created - only derived classes should be constructed
	MobilePhone(string model, Manufacturer man, const vector<Modem *>& imodems);
	
private:
	const string modelName;
	const Manufacturer mfr;
	
	Network *net;  // network it is regstered to

	// "owned" by this class

	vector<Modem *> modems; 
	vector<Camera *> cameras;
	SDCard *sdc;

};

#endif
