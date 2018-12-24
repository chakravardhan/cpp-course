//file.h
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;
class File
{
	protected:
		string filename;
	public:
		File();
		File(string name);
		string getfilename();
		virtual string printfile();
};
class AudioFile : public File
{
public:
	string printfile();
	AudioFile(string name);
};
class ImageFile : public File
{
	public:
		string printfile();
		ImageFile(string name);
};
class TextFile : public File
{
public:
	string printfile();
	TextFile(string name);
};
#endif
