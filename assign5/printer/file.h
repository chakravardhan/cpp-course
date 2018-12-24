#include <iostream>
#include <fstream>
using namespace std;
class file
{
	public:
		string Name;
		file()
		{
			Name="";
		}
		file(string name)
		{
			Name=name;
		}
		string getName()
		{
			return Name;
		}
		virtual string PrintCommand()
		{
			return "Function in Derived classes";
		}
};