//in printer.cpp
#include "printer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>


using namespace std;
Printer::Printer()
{
	t=time(0);
}	
time_t Printer::gett()
{
	return t;
}
void Printer::addt()
{
	int i;
	t=time(0);
	i=(rand()%7)+3;
	t += i;
}
string Printer::getprintercolor()
{
	return printercolor;
}
void Printer::assignprintername(string name)
{
	printername=name;
}
void Printer::assignprintertype(string type)
{
	printertype =type;
}
string Printer::getprintername()
{
	return printername;
}
void Printer::assignprintercolor(string type)
{
	printercolor =type;
}

