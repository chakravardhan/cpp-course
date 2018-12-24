#include "File.h"

File::File():name("New File")
{
}

File::File(string n):name(n)
{

}

File::~File()
{

}

string File::getName()
{
    return name;
}
