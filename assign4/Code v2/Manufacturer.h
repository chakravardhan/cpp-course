#ifndef MANUFACTURER_H
#define MANUFACTURER_H

#include <string>
using namespace std;

class Manufacturer
{
public:
	Manufacturer(string n, string c);
	~Manufacturer();

	const string& name() const;
	const string& country() const;

	void print(ostream& os) const;

private:
	const string mname;
	const string mcountry;
};

#endif
