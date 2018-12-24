#include "TextFile.h"

TextFile::TextFile()
{
    //ctor
}

TextFile::~TextFile()
{
    //dtor
}

string TextFile::getPrintRep()
{
    return ("The contents of the text file" + getName());
}
