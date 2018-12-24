//folder.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "folder.h"

using namespace std;
int Folder::foldersize()
{
	return folder.size();
}
int Folder::getfilesize()
{
	return folder.size();
}
void Folder::addfile1(File * f)
{
	folder.push_back(f);
}
File * Folder::getfile(int i)
{
	return folder[i];
}

