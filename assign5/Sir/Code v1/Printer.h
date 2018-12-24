#ifndef PRINTER_H
#define PRINTER_H

#include <string>
using namespace std;
class File;

class Printer
{
    public:

        virtual ~Printer();

        bool isAvailable();
        string getName();

        virtual bool print(File *, string mode) = 0;   // false if it cannot print this type and mode

    protected:
        Printer();
        Printer(string name, string mode);

        void setBlockPeriod(int secs);
    private:
        int whenFree;
        string pname;
        string mode;
};

#endif // PRINTER_H
