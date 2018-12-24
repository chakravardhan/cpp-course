//file1.h
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

class File
{
	public:
		string filename;
		File()
		{
			filename="";
		}
		File(string fname)
		{
			filename=fname;
		}
		string getfilename()
		{
			return filename; 
		}
		virtual string printfile()
		{
			return "";
		}
};
class TextFile : public File
{
	private:
		string ftype;
	public:
		string printfile()
		{
			return "Suprgya Bhushan" ;
		}
		TextFile(string type1)
		{
			ftype =type1;
		}

};
class AudioFile : public File
{
	private:
		string ftype;
	public:
		string printfile()
		{
			return "";
		}
		AudioFile(string type1)
		{
			ftype =type1;
		}
};
class ImageFile : public File
{
	private:
		string ftype;
	public:
		string printfile()
		{
			return "Image file";
		}
		ImageFile(string type1)
		{
			ftype =type1;
		}
};
class Folder
{
	private:
		File f;
		vector <File*> folder;
	public:
		string name;
		int foldersize()
		{
			return folder.size();
		}
		File * g(int i)
		{
			return folder[i];
		}
		int get()
		{
			return folder.size();
		}
		string getfilename()
		{
			return f.filename;
		}
		void pushFile(File * f)
		{
			folder.push_back(f);
		}
};

class Printer
{
	private:
		string printername;
		string printertype;
		string printercolor;
		time_t timev;
		
	public:
		vector <Printer*> printer;
		Printer()
		{
			timev=time(0);
		}
		time_t gettime()
		{
			return timev;
		}
		void addtime()
		{
			int i;
			timev=time(0);
			i=(rand()%7)+3;
			timev=timev+i;
		}
		
		Printer(string pname)
		{
			printername=pname;
		}
		void PrinterType(string ptype)
		{
			printertype=ptype;
		}
		void PrinterColor(string pcolor)
		{
			printercolor=pcolor;
		}
		void printPrints()
		{
			cout<<printername<<endl;
		}
		string getprintername()
		{
			return printername;
		}
		string getprintercolor()
		{
			return printercolor;
		}
		void addprinter(string pname1)
		{
			printer.push_back(new Printer(pname1));
		}
		int printersize()
		{
			return printer.size();
		}
		Printer * getprinter(int i)
		{
			return printer[i];
		}	
};

class Stacks
{
	private:
		int avail;
	public:
		string printername1;
		string filename1;
		string printercolor1;
		Stacks(string pname2,string fname2,string colour)
		{
			printername1=pname2;
			filename1=fname2;
			printercolor1=colour;
		}
		string printer()
		{
			return printername1;
		}
		string file()
		{
			return filename1;
		}
};

class Server
{
	private:
		vector <Printer> database2;
		vector <Folder> database1;
		string PDefault;
		string CDefault;
	public:
		vector <Stacks> req;
		Server()
		{
			CDefault="BW";
		}

		void setPDefault(string name)
		{
			PDefault=name;
		}

		void setCDefault(string name)
		{
			CDefault=name;
		}

		Printer P(string pname3)
		{
			int i;
			for(i=0;i<database2.size();i++)
			{
				if(database2[i].getprintername()==pname3)
					return database2[i];
			}
			return Printer();			
		}
		int Psearchindex(string pname3)
		{
			int i;
			for(i=0;i<database2.size();i++)
			{
				if(database2[i].getprintername()==pname3)
					return i;
			}
			return 0;			
		}

		int Pcheck(string a)
		{
			int i;
			for(i = 0; i < database2.size(); ++i)
			{
				if(a.compare(database2[i].getprintername())==0)
					return 1;
			}
			return 0;
		}
		string F(string fname3)
		{
			int j;
			File * temp;
			for(int i = 0; i < database1.size(); ++i)
			{
				for(j=0;j<database1[i].get();j++)
				{
					temp=database1[i].g(j);
					if(fname3.compare(temp->getfilename())==0)
					{
						return temp->printfile();
					}
				}
			}
			return "";
		}	

		
		int getInt(string a)
		{
			if(a=="BW")
				return 1;
			else if (a=="COLOUR")
				return 2;
			return 0;
		}	

		int searchFolder(string Fname)
		{
			for (int i = 0; i < database1.size(); ++i)
			{
				if(Fname.compare(database1[i].name)==0)
					return i;
			}
			return 0;
		}
		void reqadd(string file, string colour="", string printer="")
		{
			if(colour=="")
				colour=CDefault;
			if(printer=="")
				printer=PDefault;
			if(Pcheck(colour)!=1)
			{
				Printer Default = P(printer);
				if(getInt(Default.getprintercolor())<getInt(colour))
					return;
				else
				{
					req.push_back(Stacks(printer,file,colour));
				}
			}
			else
			{
				printer=colour;
				colour=CDefault;
				Printer Default = P(printer);
				if(getInt(Default.getprintercolor())<getInt(colour))
					return;
				else
				{
					req.push_back(Stacks(printer,file,colour));
				}

			}
			
		}
		void printstacks()
		{
			int k;
			Printer * print;
			for(k=0;k<req.size();k++)
			{
				print=&(database2[Psearchindex(req[k].printername1)]);
				if(time(0)>(print->gettime()))
				{
					if(F(req[k].filename1)!="")
					{
						print->addtime();
						cout<<F(req[k].filename1)<<" by "<<print->getprintername()<<endl;
					}
					else
						cout<<"File not Supported"<<endl;
					req.erase(req.begin()+k);
					k--;
				}	
			}
		}
			
		void pushFile(string Fname,File * f)
		{
			database1[searchFolder(Fname)].pushFile(f);
		}
		void pushFolder(string Fname)
		{
			Folder temp;
			temp.name=Fname;
			database1.push_back(temp);
		}

		int getStacksize()
		{
			return req.size();
		}

		


};
#endif
