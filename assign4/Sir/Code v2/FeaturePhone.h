

#include "MobilePhone.h"
class FeaturePhone :
	public MobilePhone
{
public:
	FeaturePhone(string model, Manufacturer man, vector<Modem *>& imodems);
	~FeaturePhone();

	void print(ostream& os) const;

};

