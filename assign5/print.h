//file.h
#ifndef FILE_H
#define FILE_H
#include<iostream>

using namespace std;

class File
{
	protected:
		string filename;
	public:
		virtual string printfile()
		{
			return "File Printing acc to types";
		}
};
class TextFile : public File
{
	private:
		string ftype;
	public:
		string printfile()
		{
			return "Suprgya Bhushan" ;
		}
};
class AudioFile : public File
{
	private:
		string ftype;
	public:
		string printfile()
		{
			return "Audio file";
		}
};
class ImageFile : public File
{
	private:
		string ftype;
	public:
		string printfile()
		{
			return "Image file";
		}
};
#endif