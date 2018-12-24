//in main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "server.h"
#include "file.h"
using namespace std;
int main()
{
	int noprinters,nofiles=0,n=0;
	string PrinterName,PrinterType,PrinterColor,MainFolder,FolderName,FileName,FileType,a,b,c,d,Default;
	Printer p;
	Folder f;
	Server s; 

	ifstream infile ("in1.txt");
	infile>>noprinters;
	while(n<noprinters)
	{		
		infile>>PrinterName;
		infile>>PrinterType;
		infile>>PrinterColor;
		s.addprinter(PrinterName,PrinterType,PrinterColor);
		n++;
	}
	n=0;
	infile>>MainFolder;
	s.addfolder(MainFolder);
	infile>>FolderName;
	cout<<FolderName<<endl;
	infile>>nofiles;
	while(n<nofiles)
	{		
		infile>>FileName;
		infile>>FileType;
		if(FileType.compare("IMAGE")==0)
		{
			s.addfile(FolderName,new ImageFile(FileName));
		}
		else if(FileType.compare("TEXT")==0)
		{
			s.addfile(FolderName,new TextFile(FileName));
		}
		else if(FileType.compare("AUDIO")==0)
		{
			s.addfile(FolderName,new AudioFile(FileName));
		}
		n++;
	}	
	infile>>a;
	while(a!="END")
	{
		if(a=="SETDEFAULT")
		{
			infile>>Default;
			s.setPDefault(Default);			
		}
		else if(a=="PRINT")
		{
			infile>>b;			
			infile>>c;
			if((c=="PRINT") || (c=="SETDEFAULT") || (c=="END"))
			{
				a=c;
				s.reqadd(b);
				s.printstacks();
				continue;
			}
			infile>>d;
			if((d=="PRINT") || (d=="SETDEFAULT") || (d=="END"))
			{
				a=d;
				s.reqadd(b,c);
				s.printstacks();
				continue;
			}
			s.reqadd(b,c,d);
			s.printstacks();
		}
		infile>>a;
	}
	infile.close();
	cout<<endl;

	while(s.getStacksize()!=0)
	{
		s.printstacks();
	}
	return 0;
}
	
