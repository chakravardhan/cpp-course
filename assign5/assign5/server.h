//in server.h
#ifndef SERVER_H
#define SERVER_H
#include "stacks.h"
#include "printer.h"
#include "folder.h"
#include <iostream>
#include <vector>
using namespace std;
class Server
{
	private:
		vector <Folder> database1;
		vector <Printer> database2;
		vector <Stacks> req;
		int Pcheck(string a);
		int comparison(string a);
		int FolderSearch(string Fname);
		int Psearchindex(string pname3);
		string PDefault;
		string CDefault;
		string FileSearch(string fname3);
		Printer PrinterSearch(string pname3);
	public:
		
		Server();
		void addfile(string Fname,File * f);
		void addfolder(string Fname);
		void addprinter(string name,string type,string ptype);
		void setPDefault(string name);
		void setCDefault(string name);
		void reqadd(string file,string colour="",string print="");
		void printstacks();
		int getStacksize();
};
#endif
