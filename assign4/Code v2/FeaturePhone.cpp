#include <iostream>
using namespace std;


#include "FeaturePhone.h"

FeaturePhone::FeaturePhone(string model, Manufacturer man, vector<Modem *>& imodems)
							:MobilePhone(model, man, imodems )
{
}


FeaturePhone::~FeaturePhone()
{
}

void
FeaturePhone::print(ostream& os) const
{

}
