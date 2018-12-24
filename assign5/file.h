//file.h
#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class File
{
	protected:
		string filename;
	public:
		File(string fname)
		{
			filename=fname;
		}
		virtual void printStats()
		{
			cout<<filename<<endl;
		} 
};
class FileType: public File
{
	protected:
		string filename;
		string filetype; 
	public:
		FileType(string fname,string ftype):File(fname)
		{
			filetype=ftype;
		}	
		void printStats()
		{
			File::printStats();
			cout<<filetype<<endl;
		}
};
class Folder
{
	private:
		int j;
		string foldername;
		vector <File> folder;
	public:
		void addfile(File f)
		{
			folder.push_back(f);
		}
		void getfile(vector <File> database,string value)
		{
			for(j=0;j<database.size();j++)
			{
				/*if (file is present in folder)
				{
					ADD THAT FILE TO THE STACK OF REQUESTS OR FILE;
				}*/
			}
		}
};

class Printer
{
	protected:
		string printername;
	public:
		Printer(string pname)
		{
			printername=pname;
		}
		virtual void printPrints();
		
};
class PrinterType : public Printer
{
	protected:
		string printercolor;
		string printertype;
	public:
		PrinterType(string pname,string pcolor,string ptype) : Printer(pname)
		{
			printercolor=pcolor;
			printertype=ptype;
		}
		void printPrints();
};





class PrinterResponse
{
	private:
		PrinterType c;
		
	public:
		int availability;
		int getTime()
		{
			//return the time after the program has elapsed by;
			return 0;
		}
		int check()
		{
			if(availability==1)
				return 1;
			else
				return 0;
		}
		int response_handling(string particular_printer,string color)
		{
			/*if(particular_printer c.printercolor==color)
			  	return 1;
			  else
			  	return 0;*/
			return 0;
		}		
};

class Server
{
	private:
		vector <Printer> database1;
		PrinterResponse respond;
		//int avail;
		//int check;
	public:
		int request_handling(string printer= default scanned_printer_name,string color)
		{
			if(respond.response_handling(printer,color)==1)
			{
				cout<<"File can be handled"<<endl;
				return 1;
			}
			else
			{
				cout<<"Can't be handled"<<endl;
				return 0;
			}
		}
		int request_availability(string printer= default scanned_printer_name,string color)
		{
			/*if((request_handling(printer,color)==1) && (particular_printer is not busy))
			{
				avail=1;
				return avail;
			}
			else
			{
				avail=0;
				return avail;
			}*/
			return 0;
		}
		int response_check()
		{
			/*
			if(avail==1)
				return 1;
			else
				return 0;*/
			return 0;
		}
		int response(string file)
		{
			/*check=response_check();
			if(check==1)
			{
				print file and content according to its type which will be taken from FileType Class;
			}
			else
			{
				pop front from file stack;
				push back to particular_printer stack;
			}*/
		}	
};
#endif