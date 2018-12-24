#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include <File.h>


class AudioFile : public File
{
    public:
        AudioFile(string name);
        ~AudioFile();

        string getPrintRep();

    protected:
    private:
};

#endif // AUDIOFILE_H
