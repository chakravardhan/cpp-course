#include <iostream>
using namespace std; 

#include "Manufacturer.h"


Manufacturer::Manufacturer(string n, string c) :mname(n), mcountry(c)
{
}


Manufacturer::~Manufacturer()
{
}

const string& Manufacturer::name() const
{
	return mname;
}
const string& Manufacturer::country() const
{
	return mcountry;
}



void
Manufacturer::print(ostream& os) const
{
	cout << "Manufacturer: " << mname << " , Country: " << mcountry << endl;
}
