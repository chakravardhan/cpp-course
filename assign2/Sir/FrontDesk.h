

class Mechanic;
class FrontDesk
{
private:
	Mechanic &mechanic;
public:

	FrontDesk(Mechanic& m) :mechanic(m) {}

	void processRequests();
};

