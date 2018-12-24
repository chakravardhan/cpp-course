//in printer.h
#ifndef PRINTER_H
#define PRINTER_H
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
class Printer
{
	private:
		string printertype;	
		string printername;
		string printercolor;	
		time_t t;
	public:
		Printer();
		time_t gett();
		void addt();
		void assignprintername(string name);
		void assignprintertype(string type);
		void assignprintercolor(string type);		
		string getprintername();
		string getprintercolor();		
};
#endif

