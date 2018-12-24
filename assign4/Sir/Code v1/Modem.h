
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

	string getTechnology() const;

private:
	const string wtech;
	const long long IMEInumber;
	SIMCard *sim;    // does not "own" SIM - do not delete
};


