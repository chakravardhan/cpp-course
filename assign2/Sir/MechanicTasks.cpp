

#include "Mechanic.h"
#include "FrontDesk.h"

int main(int argc, char* argv[])
{
	Mechanic mechanic;
	FrontDesk fdesk(mechanic);
	
	fdesk.processRequests();

	return 0;
}

#if 0
R 15
R 21
N
N
N
R 92
R 401
R 827
N
N
R 82
R 910
E

#endif
