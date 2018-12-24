#include "AudioFile.h"
string AudioFile::printfile()
{
	return "Name is "+filename+" : AUDIOFILE";
}
AudioFile::AudioFile(string name)
{
	filename=name;
}

