

#include <vector>
using namespace std;


class MobilePhone;
class Network
{
public:
	Network();
	virtual ~Network();

	bool         addPhone(MobilePhone *phone);
	MobilePhone *findPhone(long long number);

	bool         makeCall(long long fromPhone, long long toPhone);

private:
	vector<MobilePhone *> phones;  // does not "own" phone - don't delete
};

