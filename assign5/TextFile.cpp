#include "TextFile.h"
string TextFile::printfile()
{
	return "Name is "+filename+" : TEXTFILE";
}
TextFile::TextFile(string name)
{
	filename=name;
}

