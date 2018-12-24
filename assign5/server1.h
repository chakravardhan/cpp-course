#include "printer.h"
#include "folder.h"
#include "stacks.h"
#include <iostream>
#include <vector>
using namespace std;
class Server
{
private:
	vector <Printer> database2;
	vector <Folder> database1;
	string FileSearch(string file);
	Printer PrinterSearch(string name);
	int getInt(string a);
	int Pcheck(string print);
	int searchFolder(string Fname);
	vector <Stacks> req;
	int Psearchindex(string name);
	string PDefault;
	string CDefault;
public:
	Server();
	//void printAllP();
	void setPDefault(string name);
	void setCDefault(string colour);
	void addRequest(string file, string colour="", string print="");
	void printstacks();
	void pushFile(string Fname,File * f);
	void pushFolder(string Fname);
	void pushPrinter(string name,string type,string ptype);
	int getStacksize();
};
