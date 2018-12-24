#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <File.h>


class TextFile : public File
{
    public:
        TextFile();
        TextFile(string n);
        ~TextFile();

        string getPrintRep();

    protected:
    private:

};

#endif // TEXTFILE_H
