#include <vector>
#include "folder.h"
#include "printer.h"
#include "Request.h"
class Server
{
private:
	vector <printer> Printers;
	vector <folder> Folders;
public:
	string searchFile(string filename)
	{
		int j;
		file * temp;
		for(int i = 0; i < Folders.size(); ++i)
		{
			for(j=0;j<Folders[i].getNoFiles();j++)
			{
				temp=Folders[i].getFile(j);
				if(temp->getName()==filename)
				{
					return temp->PrintCommand();
				}
			}
		}
		return 0;
	}
	printer searchPrinter(string name)
	{
		int i;
		for(i=0;i<Printers.size();i++)
		{
			if(Printers[i].getName()== name)
				return Printers[i];
		}
	}
	int getInt(string a)
	{
		if(a=="BW")
			return 1;
		else if (a=="COLOUR")
			return 2;
	}
	int checkPrinter(string print)
	{
		for (int i = 0; i < Printers.size(); ++i)
		{
			if(print.compare(Printers[i].getName())==0)
				return 1;
		}
		return 0;
	}
	int searchFolder(string Fname)
	{
		for (int i = 0; i < Folders.size(); ++i)
		{
			if(Fname.compare(Folders[i].name)==0)
				return i;
		}
	}
public:
	vector <Request> r;
	static string DefaultPrinter;
	static string DefaultColour;
	void addRequest(string file, string colour=DefaultColour, string printer=DefaultPrinter)
	{
		if(checkPrinter(colour)!=1)
		{
			printer & Default = searchPrinter(printer);
			if(getInt(Default.getPtype())>getInt(colour))
				return;
			else
			{
				requests.push_back(Request(printer,file,colour));
			}
		}
		else
		{
			printer=colour;
			colour=DefaultColour;
			printer & Default = searchPrinter(printer);
			if(getInt(Default.getPtype())>getInt(colour))
				return;
			else
			{
				requests.push_back(Request(printer,file,colour));
			}

		}
	}
	
	void CompleteRequests()
	{
		int i;
		printer * temp;
		for(i=0;i<r.size();i++)
		{
			temp=&(searchPrinter(r[i].printer));
			if(time(0)>(temp->timev))
			{
				temp->timev= time(0);
				temp->addTime();
				if(searchFile(request[i].file)!="Invalid Object")
					cout<<searchFile(request[i].file)<<endl;
				else
					cout<<"File not Supported"<<endl;
				requests.pop(i);
				i--;
			}	
		}
	}
	void pushFile(string Fname,file * f)
	{
		Folders[searchFolder(Fname)].pushFile(f);
	}
	void pushFolder(string Fname)
	{
		folder temp;
		temp.name=Fname;
		Folders.push_back(temp);
	}
};