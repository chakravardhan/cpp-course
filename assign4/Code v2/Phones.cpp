
#include "stdafx.h"
#include "Network.h"
#include "SmartPhone.h"
#include "FeaturePhone.h"
#include "SIMCard.h"
#include "Modem.h"

#include <iostream>
using namespace std;

void readPhones(vector<MobilePhone *>& phones)
{
	int numPhones;
	cin >> numPhones;
	string ptype, manName, manCountry, modelName, cman, cmodel, wtech;
	int numModems;
	vector<long long>imeis;
	vector<Modem *> modems;

	//	<S or F> <Phone Manufacturer info> <Model> <computer info> <Modem Info> <num Modems> <list of IMEI numbers>

	for (int i = 0; i < numPhones; i++) {
		cin >> ptype >> manName >> manCountry >> modelName;
		if (ptype == "S") {
			cin >> cman >> cmodel;
		}
		cin >> wtech >> numModems;
		imeis.clear();
		modems.clear();
		for (int j = 0; j < numModems; j++) {
			long long imei;
			cin >> imei;
			modems.push_back(new Modem(wtech, imei));
		}
		MobilePhone *mp = 0;
		if (ptype == "S") {
			mp = new SmartPhone(modelName, Manufacturer(manName, manCountry), modems, cmodel, cman);
		}
		else if (ptype == "F" ) {
			mp = new FeaturePhone(modelName, Manufacturer(manName, manCountry), modems);
		}
		if (mp)
			phones.push_back(mp);
		else
			cout << "Error - could not create phone" << endl;
	}

}

void readSims(vector<SIMCard *>& sims)
{
	string op;
	long long num;
	int numSims;
	
	cin >> numSims;
	for (int i = 0; i < numSims; i++) {
		cin >> op >> num;
		sims.push_back(new SIMCard(op, num));
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Network net;
	vector<MobilePhone *> phones;
	vector<SIMCard *>     sims;

	// read in data file and create phones and SIMs
	// 1a.
	readPhones(phones);
	for (unsigned int i = 0; i < phones.size(); i++) {
		net.addPhone(phones[i]);
	}

	// 1b.
	readSims(sims);
	for (unsigned int i = 0; i < sims.size(); i++) {
		phones[i]->addSim(sims[i], 0);
	}

	// process requests
	//
	// 2. Phone with number 9876543210 calls phone with number 9001234567
	//
	MobilePhone *p1 = net.findPhone(9876543210);
	if (p1)
		p1->makeCall(9001234567, 9876543210);
	else
		cout << "Invalid number for caller " << endl;

	//
	// 3. Remove SIM from phone 2 and add that SIM to phone 0
	// 
	SIMCard *sc1 = phones[2]->removeSim(0);
	phones[0]->addSim(sc1, 1);

	//
	// 4. Phone 3 calls phone number 9001234567
	// 
	phones[3]->makeCall(9001234567);

	cout << endl;
	//
	// 5. List the <manufacturer name, country> of all the phones in the network.
	//
	cout << "Phones in the network:" << endl;

	for (unsigned int i = 0; i < phones.size(); i++) {
		cout << "Phone " << i << " Manufacturer: Name: " << phones[i]->getManufacturer().name()
			<< " Country: " << phones[i]->getManufacturer().country() << endl;
	}
			
	cout << endl;

	//
	// 6. List the numbers of all LTE phones in the network
	//
		
	cout << "LTE Phones:" << endl;
	vector<Modem *> modems;
	for (unsigned int i = 0; i < phones.size(); i++) {
		modems.clear();
		phones[i]->getModems(modems);
		for (unsigned int j = 0; j < modems.size(); j++) {
			if (modems[j]->getTechnology() == "LTE") {
				cout << "IMEI: " << modems[j]->getIMEI() << "  Number: " << modems[j]->getNumber() << endl;
			}
		}
	}
	cout << endl;

	//
	// 7. the wireless technology of all phones that have the computer platform from manufacturer Q.
	//
	
	// I've skipped this for now, since there seem to be some compiler dependencies in the use of dynamic_cast.
	//

	//
	// 8. List the number of phones in the network of each type: GSM, GPRS, WCDMA, LTE
	//
	int numGSM = 0, numGPRS = 0, numWCDMA = 0, numLTE = 0;

	for (unsigned int i = 0; i < phones.size(); i++) {
		modems.clear();
		phones[i]->getModems(modems);
		for (unsigned int j = 0; j < modems.size(); j++) {
			string wt = modems[j]->getTechnology();
			if (wt == "LTE")
				numLTE++;
			else if (wt == "GSM")
				numGSM++;
			else if (wt == "GPRS")
				numGPRS++;
			else if (wt == "WCDMA")
				numWCDMA++;
		}
	}
	cout << "Types of phones in the network: " << "GSM: " << numGSM << ", GPRS: " << numGPRS << " WCDMA: " << numWCDMA << " LTE: " << numLTE << endl;
	cout << endl;

	// Print out info on all phones in the network
	for (unsigned int i = 0; i < phones.size(); i++) {
	
		phones[i]->print(cout);
		cout << endl;

	}

	// cleanup phones and sims since these are created here and not "owned" by anyone else
	for (unsigned int i = 0; i < phones.size(); i++) {
		delete phones[i];
	}

	for (unsigned int i = 0; i < sims.size(); i++) {
		delete sims[i];
	}

	return 0;
}


#if 0
6
S Sam China Fire3 Q 4340 WCDMA 2 1234567890 2345678901
F Nok Denmark B71 GSM 1 9876543210
S Son India Sun1 I Proton1 LTE 1 8729391018
F Luck Japan P2345 WCDMA 1 97287018290
S Sam China Fire5 S Q234 LTE 2 9904098124 4881248234
F Mic India X234 GSM 2 22902348 90234823904
4
Sp 9876543210
Or 9123456789
Sp 9001234567
Or 7890123456

# endif
