#include <cstdlib>
#include <string>
using namespace std;
class printer
{
	private:
	string Type;	//laser or inkjet or dot
	string Name;
	string PType;	//BW or colour
	public:
	time_t timev;
	void AssignName(string name)
	{
		Name=name;
	}
	void AssignType(string type)
	{
		Type =type;
	}
	string getName()
	{
		return Name;
	}
	void AssignPType(string type)
	{
		PType =type;
	}
	void addTime()
	{
		int i;
		i=(rand()%7)+3;
		timev += i;
	}
};