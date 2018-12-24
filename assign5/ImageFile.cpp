#include "ImageFile.h"
string ImageFile::printfile()
{
	return "Name is "+filename+" : IMAGEFILE";
}
ImageFile::ImageFile(string name)
{
	filename=name;
}