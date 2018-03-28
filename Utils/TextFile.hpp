#pragma once

#include <fstream>
#include <string.h>
#include <exception>
#include <iostream>

namespace utils
{
    using namespace std;

    class TextFile
    {
    private:
        const static int _defMaxLineSize_ = 1024;
        ifstream stream;

    public:
        TextFile(const string& file)
        {            
            stream.exceptions(ifstream::badbit);
            stream.open(file, ios::in);
        }

        ~TextFile()
        {
            if (stream.is_open())
                stream.close();
        }

        string getLine(int maxSize = _defMaxLineSize_)
        {
            try
            {
                 if (!stream.eof() && stream.good())
                 { 
                    char* line = new char[maxSize+1];
                    stream.getline(line, 1024);
                    return string(line);
                 }
                 else
                 {
                     return string();
                 }
            }
            catch (const exception& e)
            {
                cerr << "Caught an exception while reading file " << e.what() << endl;
            }

            return string();
        }
    };
}