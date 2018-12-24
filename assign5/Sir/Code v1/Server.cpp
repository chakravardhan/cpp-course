#include "Server.h"
#include "Printer.h"

#include <vector>
#include <iterator>
using namespace std;

static int currTime = 0;

Server::Server():defaultPr(0)
{
      printers =  vector<Printer *>();
      tasks =  vector<Request *>();
}

Server::~Server()
{
    for(vector<Printer *>::iterator it = printers.begin(); it != printers.end(); it++)
        delete *it;

    for(vector<Request *>::iterator it = tasks.begin(); it != tasks.end(); it++)
        delete *it;
}

 int
 Server::getTime()
 {
     return ++currTime;
 }

void
Server::addPrinter(Printer *p)
{
    printers.push_back(p);
    if(defaultPr == 0)
        setDefaultPrinter(p);  // ensures we don't have to check for this elsewhere
}
void
Server::setDefaultPrinter(Printer *printer)
{
    defaultPr = printer;
}

void
Server::requestPrint(File *file, string mode, Printer *printer)
{
    if(file == 0) {  // FILE == 0 ==> end of requests
        clearPendingTasks();
    } else {
        if (printer == 0)
            printer = defaultPr;
        if(printer->isAvailable()) {
            printer->print(file, mode);
        } else {
            tasks.push_back(new Request(file, mode, printer));
        }
    }
}

Printer *
Server::getPrinter(string name)
{
    Printer *p = 0;
    for(vector<Printer *>::iterator it = printers.begin(); (p == 0) && (it != printers.end()); it++) {
        if((*it)->getName() == name)
            p = *it;
    }
    return p;
}

void
Server::clearPendingTasks()
{
    bool pendingTasks = true;
    while(pendingTasks) {
        pendingTasks = false;
        for(vector<Request *>::iterator it = tasks.begin(); it != tasks.end(); it++) {
            Request *req = (*it);
            if(req->pr->isAvailable()) {
                req->pr->print(req->file, req->mode);
                req->processed = true;
            } else {
                pendingTasks = true;
            }
        }
    }
}
