//folder.h
#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "file.h"

using namespace std;

class Folder
{
	private:
		vector <File*> folder;
	public:
		string name;		
		File * getfile(int i);
		void addfile1(File * f);
		int getfilesize();
		int foldersize();
		
		
};
#endif
