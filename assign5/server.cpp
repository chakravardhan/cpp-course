//in server.cpp
#include <string>
#include <iostream>
#include "server.h"

void Server::setPDefault(string name)
{
	PDefault=name;
}
void Server::setCDefault(string name)
{
	CDefault=name;
}	

int Server::Psearchindex(string pname3)
{
	int i;
	for(i=0;i<database2.size();i++)
	{
		if(database2[i].getprintername()==pname3)
			return i;
	}
	return 0;			
}
string Server::FileSearch(string fname3)
{
	int j;
	File * temp;
	for(int i = 0; i < database1.size(); ++i)
	{
		for(j=0;j<database1[i].getfilesize();j++)
		{
			temp=database1[i].getfile(j);
			if(fname3.compare(temp->getfilename())==0)
			{
				return temp->printfile();
			}
		}
	}
	return "";
}
Printer Server::PrinterSearch(string pname3)
{
	int i;
	for(i=0;i<database2.size();i++)
	{
		if(database2[i].getprintername()==pname3)
			return database2[i];
	}
	return database2[0];			
}

int Server::comparison(string a)
{
	if(a=="BW")
		return 1;
	else if (a=="COLOUR")
		return 2;
	return 0;
}	
int Server::Pcheck(string a)
{
	int i;
	for(i = 0; i < database2.size(); ++i)
	{
		if(a.compare(database2[i].getprintername())==0)
			return 1;
	}
	return 0;
}
Server::Server()
{
	CDefault="BW";
}		
int Server::FolderSearch(string Fname)
{
	for (int i = 0; i < database1.size(); ++i)
	{
		if(Fname.compare(database1[i].name)==0)
			return i;
	}
	return 0;
}
void Server::reqadd(string file,string colour,string print)
	{
		if(colour=="")
			colour=CDefault;
		if(print=="")
			print=PDefault;
		if(Pcheck(colour)!=1)
		{
			Printer D = PrinterSearch(print);
			if(comparison(D.getprintercolor())<comparison(colour))
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
			Printer D = PrinterSearch(print);
			if(comparison(D.getprintercolor())<comparison(colour))
				return;
			else
			{
				req.push_back(Stacks(print,file,colour));
			}

		}
	}

void Server::printstacks()
{
	int k;
	Printer * print;
	for(k=0;k<req.size();k++)
	{
		print=&(database2[Psearchindex(req[k].printername2)]);
		if(time(0)>(print->gett()))
		{
			if(FileSearch(req[k].filename2)!="")
			{
				print->addt();
				cout<<FileSearch(req[k].filename2)<<" printed by the printer "<<print->getprintername()<<endl;
			}
			else
				cout<<"File cannot be handled by the printer!!!!! "<<print->getprintername()<<endl;
			req.erase(req.begin()+k);
			k--;
		}	
	}
}
			
void Server::addfile(string Fname,File * f)
{
	database1[FolderSearch(Fname)].addfile1(f);
}
void Server::addfolder(string Fname)
{
	Folder temp;
	temp.name=Fname;
	database1.push_back(temp);
}
void Server::addprinter(string pname4,string ptype4,string pcolor4)
{
	Printer temp;
	temp.assignprintername(pname4);
	temp.assignprintertype(ptype4);
	temp.assignprintercolor(pcolor4);
	database2.push_back(temp);
}
int Server::getStacksize()
{
	return req.size();
}

