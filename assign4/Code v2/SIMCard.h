

#include <string>
using namespace std;

class SIMCard
{
public:
	SIMCard(string op, long long num);
	virtual ~SIMCard();

	string getOperator() const;
	long long getNumber() const;

	void print(ostream& os) const;

private:
	const string oper;
	const long long number;
};

