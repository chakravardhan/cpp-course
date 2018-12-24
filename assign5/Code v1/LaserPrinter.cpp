#include "LaserPrinter.h"
#include "File.h"

#include <iostream>
using namespace std;

LaserPrinter::LaserPrinter()
{
    //ctor
}

LaserPrinter::LaserPrinter(string name, string mode):Printer(name, mode)
{

}

LaserPrinter::~LaserPrinter()
{
    //dtor
}

bool
LaserPrinter::print(File *file, string mode) {
    // if mode does not match, return false;
    // this can vary from printer to printer, so we let the derived class check for this
    //

    string prString = file->getPrintRep();
    if(prString == "")     // file is not printable
       return false;

    setBlockPeriod(5 /* random - should depend on file size and printer. Hence set by derived class */);
    cout << "Printing " << "file " << file->getName() << endl;

    return true;
}

