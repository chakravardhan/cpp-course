#include "file.h"
using namespace std;
class ImageFile : public File
{
	public:
		string printfile();
		ImageFile(string name);
};