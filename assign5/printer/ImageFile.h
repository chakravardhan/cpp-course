#include "file.h"
using namespace std;
class Imagefile : public file
{
	private:
		string Type;
	public:
		string PrintCommand()
		{
			return "Name is "+Name+" Type is "+Type;
		}
		void AssignType(string type)
		{
			Type =type;
		}
};