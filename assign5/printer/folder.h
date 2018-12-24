#include <vector>
#include "file.h"
using namespace std;
class folder
{
	private:
		vector <file*> files;
	public:
		file name1;
		/*folder()
		{
			name1="";
		}*/

		int getNoFiles()
		{
			return files.size();
		}
		file * getFile(int i)
		{
			return files[i];
		}
		void pushFile()
		{
			files.push_back(new file(name1.Name));
		}
};