#include "Network.h"
#include "MobilePhone.h"

Network::Network()
{
}


Network::~Network() 
{
}

bool Network::addPhone(MobilePhone *phone)
{
	phones.push_back(phone);
	phone->setNetwork(this);
	return true;
}

MobilePhone *Network::findPhone(long long number)
{
	MobilePhone *nphone = NULL;
	vector<long long> nums;
	for (unsigned int i = 0; (i < phones.size()) && (nphone == NULL); i++) {
		nums.clear();
		phones[i]->getNumbers(nums);
		for (unsigned int j = 0; (j < nums.size()) && (nphone == NULL); j++) {
			if (nums[j] == number)
				nphone = phones[i];
		}
	}
	return nphone;
}


bool Network::makeCall(long long fromPhone, long long toPhone)
{
	MobilePhone *callee = findPhone(toPhone);
	if (callee)
	{
		callee->receiveCall(fromPhone);
		return true;
	}
	else {
		return false;
	}
}