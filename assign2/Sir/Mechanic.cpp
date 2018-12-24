
#include "Mechanic.h"
#include <iostream>
using namespace std;

void Mechanic::processRequest(int jobType, int jobId)
{
	switch (jobType){
	case 0:
		addJob(jobId);
		break;
	case 1:
		if (haveJobs())
			processTopJob();
		break;
	case 2:
		while (haveJobs()) {
			processTopJob();
		}
		break;
	default:
		break;
	}
}

void Mechanic::addJob(int id){
	jobs.push_back(id);
}

void Mechanic::processTopJob() {
	int jobId = jobs.back();
	cout << "Processing job " << jobId << endl;
	jobs.pop_back();
}

bool Mechanic::haveJobs() {
	return (jobs.size() > 0);
}