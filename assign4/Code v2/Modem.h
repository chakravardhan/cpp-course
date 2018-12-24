
#include <vector>
#include <string>
using namespace std;
class SIMCard;

class Modem
{
public:
	Modem(string wt, long long imei);
	virtual ~Modem();

	void     addSim(SIMCard *);
	SIMCard *getSim() const;
	long long getNumber() const;
	long long getIMEI() const;

	string getTechnology() const;

	void print(ostream& os) const;

private:
	const string wtech;
	const long long IMEInumber;
	SIMCard *sim;    // does not "own" SIM - do not delete
};


