#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <string>
using namespace std;


class Printer;
class File;
class Server
{
    public:
        static int getTime();

        Server();
        ~Server();

        void addPrinter(Printer *);
        void setDefaultPrinter(Printer *printer);
        void requestPrint(File *file, string mode = "BW", Printer *printer = 0); // FILE == 0 ==> end of requests

    protected:
    private:
        class Request {
            public:
            Request(File *f, string m, Printer *p):file(f), mode(m), pr(p), processed(false) {}
            File *file;
            string mode;
            Printer *pr;
            bool processed;
        };
        vector<Printer *> printers;     // "owns" the printers, should clean them up
        vector<Request *> tasks;
        Printer *defaultPr;

        Printer *getPrinter(string name);
        void clearPendingTasks();
};

#endif // SERVER_H
