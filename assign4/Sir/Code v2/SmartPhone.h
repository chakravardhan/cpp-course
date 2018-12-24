
#include "MobilePhone.h"
class SmartPhone :
	public MobilePhone
{
public:
	SmartPhone(string model, Manufacturer man, vector<Modem *>& modem, string cmodel, string cmanufacturer);
	~SmartPhone();

	const string& getCompModel() const;
	const string& getCompManufacturer() const;

	void print(ostream& os) const;

private:
	const string compModel;
	const string compManufacturer;
};

