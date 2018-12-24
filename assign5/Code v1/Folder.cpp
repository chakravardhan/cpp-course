#include "Folder.h"
#include "File.h"

Folder::Folder()
{
    //ctor
}

Folder::~Folder()
{
   for(vector<File *>::iterator it = files.begin(); it != files.end(); it++)
   {
       delete *it;
   }
}

Folder::Folder(string name):fname(name)
{
    files = vector<File *>();
}

void
Folder::addFile(File *file)
{
    files.push_back(file);
}

File *
Folder::findFile(string name)  // null if no such file
{
  File *file = 0;
  for(vector<File *>::iterator it = files.begin(); (file == 0) && (it != files.end()); it++) {
    if((*it)->getName() == name) {
        file = *it;
    }
  }
  return file;
}
