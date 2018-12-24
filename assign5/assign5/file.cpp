//file.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "file.h"
using namespace std;

File::File()
{};
File::File(string name)
{
	filename=name;
}
string File::getfilename()
{
	return filename; 
}
string File::printfile()
{
	return "";
}

string AudioFile::printfile()
{
	return "";
}
AudioFile::AudioFile(string name)
{
	filename=name;
}


string ImageFile::printfile()
{
	return "The file being printed with the name "+filename+" is an Imagefile";
}
ImageFile::ImageFile(string name)
{
	filename=name;
}

string TextFile::printfile()
{
	return "The file being printed with the name "+filename+" is a Text";
}
TextFile::TextFile(string name)
{
	filename=name;
}

