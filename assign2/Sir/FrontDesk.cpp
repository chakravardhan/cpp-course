#include "FrontDesk.h"
#include "Mechanic.h"
#include <iostream>
using namespace std;

void FrontDesk::processRequests() {
	bool done = 0;

	while (!done) {
		char jtype;
		
		cin >> jtype;
		if (jtype == 'R') {
			int jobId;
			cin >> jobId;
			mechanic.processRequest(0, jobId);
		}
		else if (jtype == 'N'){
			mechanic.processRequest(1);
		}
		else if (jtype == 'E') {
			mechanic.processRequest(2);
			done = 1;
		}
		else {
			cout << "Invalid input" << endl;
			done = 1;
		}
	}
}
