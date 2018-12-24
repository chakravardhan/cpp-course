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
