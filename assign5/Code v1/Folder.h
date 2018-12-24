#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>
using namespace std;

class File;
class Folder
{
    public:
        Folder();
        Folder(string name);
        virtual ~Folder();

        void addFile(File *);
        File *findFile(string name);  // null if no such file

    protected:
    private:
        string fname;
        vector<File *> files;         // folder "owns" the files
};

#endif // FOLDER_H
