#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include "server.h"
#include "file.h"

using namespace std;
int main()
{
	Server PrintServer;
	int NOPrinter,NOFiles;
	ifstream infile ("in1.txt");
	infile>>NOPrinter;
	string name, type, ptype;
	for (int i = 0; i < NOPrinter; ++i)
	{
		infile>>name>>type>>ptype;
		PrintServer.pushPrinter(name,type,ptype);
	}
	//PrintServer.printAllP();
	string check,foname,fname,ftype,colour;
	infile>>check;
	while(check.compare("END")!=0)
	{
		if(check.compare("FOLDER")==0)
		{
			infile>>foname;
			PrintServer.pushFolder(foname);
			infile>>NOFiles;
			for (int j = 0; j < NOFiles; ++j)
			{
	
				infile>>fname>>ftype;
				if(ftype.compare("TEXT")==0)
				{
					PrintServer.pushFile(foname,new TextFile(fname));
				}
				else if(ftype.compare("AUDIO")==0)
				{
					PrintServer.pushFile(foname,new AudioFile(fname));
				}
				else if(ftype.compare("IMAGE")==0)
				{
					PrintServer.pushFile(foname,new ImageFile(fname));
				}
			}
		}
		else if(check.compare("SETDEFAULT")==0)
		{
			infile>>name;
			PrintServer.setPDefault(name);
		}
		else if(check.compare("PRINT")==0)
		{
			infile>>fname;
			infile>>colour;
			if(colour.compare("PRINT")==0 || colour.compare("SETDEFAULT")==0||colour.compare("END")==0)
			{
				check=colour;
				PrintServer.addRequest(fname);
				PrintServer.printstacks();
				continue;
			}
			infile>>name;
			if(name.compare("PRINT")==0 || name.compare("SETDEFAULT")==0|| name.compare("END")==0)
			{
				check=name;
				PrintServer.addRequest(fname,colour);
				PrintServer.printstacks();
				continue;
			}
			PrintServer.addRequest(fname,colour,name);
			PrintServer.printstacks();
		}
		infile>>check;
	}
	infile.close();
	while(PrintServer.getStacksize()!=0)
	{
		PrintServer.printstacks();
	}

}