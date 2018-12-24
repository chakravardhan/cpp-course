#include <string>
#include <iostream>
#include "server1.h"
using namespace std;
string Server::FileSearch(string file)
	{
		int j;
		File * temp;
		for (int i = 0; i < database1.size(); ++i)
		{
			for(j=0;j<database1[i].getfilesize();j++)
			{
				temp=database1[i].getfile(j);
				if(file.compare(temp->getfilename())==0)
				{
					return temp->printfile();
				}
			}
		}
		return "";
	}
void Server::setPDefault(string name)
{
	PDefault=name;
}
void Server::setCDefault(string colour)
{
	CDefault=colour;
}
int Server::Psearchindex(string name)
	{
		int i;
		for(i=0;i<database2.size();i++)
		{
			if(database2[i].getprintername()== name)
				return i;
		}
		return 0;
	}
Printer Server::PrinterSearch(string name)
	{
		int i;
		for(i=0;i<database2.size();i++)
		{
			if(database2[i].getprintername()== name)
				return database2[i];
		}	
		return database2[0];
	}
int Server::getInt(string a)
	{
		if(a=="BW")
			return 1;
		else if (a=="COLOUR")
			return 2;
		return 3;
	}
int Server::Pcheck(string print)
	{
		for (int i = 0; i < database2.size(); ++i)
		{
			if(print.compare(database2[i].getprintername())==0)
				return 1;
		}
		return 0;
	}
int Server::searchFolder(string Fname)
	{
		for (int i = 0; i < database1.size(); ++i)
		{
			if(Fname.compare(database1[i].name)==0)
				return i;
		}
		return 0;
	}
/*void Server::printAllP()
	{
		for (int i = 0; i < Printers.size(); ++i)
		{
			cout<<Printers[i].getName()<<" "<<Printers[i].getPtype()<<endl;
		}
	}*/
Server::Server()
	{
		CDefault="BW";
	}
void Server::addRequest(string file, string colour, string print)
	{
		if(colour=="")
			colour=CDefault;
		if(print=="")
			print=PDefault;
		if(Pcheck(colour)!=1)
		{
			Printer Default = PrinterSearch(print);
			if(getInt(Default.getprintercolor())<getInt(colour))
				return;
			else
			{
				req.push_back(Stacks(print,file,colour));
			}
		}
		else
		{
			print=colour;
			colour=CDefault;
			Printer Default = PrinterSearch(print);
			if(getInt(Default.getprintercolor())<getInt(colour))
				return;
			else
			{
				req.push_back(Stacks(print,file,colour));
			}

		}
	}
	
void Server::printstacks()
	{
		int i;

		Printer * temp;
		for(i=0;i<req.size();i++)
		{
			temp=&(database2[Psearchindex(req[i].printer)]);
			if(time(0)>(temp->getTime()))
			{
				if(FileSearch(req[i].file)!="")
				{
					temp->addTime();
					cout<<FileSearch(req[i].file)<<" by "<<temp->getprintername()<<endl;
				}	
				else
					cout<<"File not Supported"<<endl;
				req.erase(req.begin()+i);
				i--;
			}	
		}
	}
void Server::pushFile(string Fname,File * f)
	{
		database1[searchFolder(Fname)].pushFile(f);
	}
void Server::pushFolder(string Fname)
	{
		Folder temp;
		temp.name=Fname;
		database1.push_back(temp);
	}
void Server::pushPrinter(string name,string type,string ptype)
	{
		Printer temp;
		temp.AssignName(name);
		temp.AssignType(type);
		temp.AssignPType(ptype);
		database2.push_back(temp);
	}
int Server::getStacksize()
	{
	return req.size();
	}
