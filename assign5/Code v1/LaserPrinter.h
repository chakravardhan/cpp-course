#ifndef LASERPRINTER_H
#define LASERPRINTER_H

#include <Printer.h>


class LaserPrinter : public Printer
{
    public:
        LaserPrinter();
        LaserPrinter(string name, string mode);

        virtual ~LaserPrinter();

        bool print(File *file, string mode);
    protected:
    private:
        int mode;
};

#endif // LASERPRINTER_H
