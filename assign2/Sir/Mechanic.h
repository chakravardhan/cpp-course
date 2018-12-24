
#include <vector>
using namespace std;

class Mechanic
{
private:

	vector<int> jobs;

	void addJob(int id);
	void processTopJob();
	bool haveJobs();

public:

	void processRequest(int jobType, int jobId = 0);  // jobType: 0: new, 1: none, 2: end 

};

