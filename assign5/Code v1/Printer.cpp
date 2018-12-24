#include "Printer.h"
#include "Server.h"

Printer::Printer(): whenFree(0), pname("Unnamed Printer"),  mode(0)
{
    //ctor. Not strictly needed at all
}

Printer::Printer(string name, string pmode):  whenFree(0), pname(name),  mode(pmode)
{

}


Printer::~Printer()
{
    //dtor
}

void
Printer::setBlockPeriod(int secs)
{
    whenFree = Server::getTime() + secs*1000;  // assume getTime is in millisecs - to stretch it out some
}

bool Printer::isAvailable()
{
    return Server::getTime() > whenFree;
}

string
Printer::getName()
{
    return pname;
}

