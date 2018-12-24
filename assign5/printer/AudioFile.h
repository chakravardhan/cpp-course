#include "file.h"
using namespace std;
class AudioFile : public file
{
	private:
		string Type;
	public:
		string PrintCommand()
		{
			return "Invalid Object";
		}
		void AssignType(string type)
		{
			Type =type;
		}
};