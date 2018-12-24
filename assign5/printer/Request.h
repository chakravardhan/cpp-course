#include <cstdlib>
#include <string>
using namespace std;
class Request
{
	public:
		string printer;
		string file;
		string colour;
		Request(string a, string b, string c)
		{
			printer=a;
			file=b;
			colour=c;
		}
};