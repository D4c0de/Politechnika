

#include "FileIO.h"

 
FileIO::FileIO(std::string& input, std::string& output) :
    inputFile(input,std::ios::binary),
    outputFile(output,std::ios::binary)
{
    if (!inputFile.good())
    {
        throw std::exception("Error: Can't gain access to the input file");
    }
    if (!outputFile.good())
    {
        throw std::exception("Error: Can't gain access to the output file");
    }
    next = 7;
}

FileIO::~FileIO()
{
    inputFile.close();
    outputFile.close();
}


char FileIO::getChar()
{
    char c;
    if (inputFile.get(c)) {
        return c;
    };
    return -1;
}


std::pair<std::string, int> FileIO::getDicElement()
{
    std::pair<std::string, int> ret;

    char c;
    char input;
    bool;
    while (true)
    {
        if ((c=get_Next8().to_ullong()) == 255)
        {
            break;
        }
        int size = get_Next8().to_ullong();
        std::string code;
        for (size_t i = 0; i < size+1; i++)
        {
            code += get_Next().to_string();
        }
        return { code,c};
    }
    return std::pair<std::string, int>{"end", 1};
}


void FileIO::wr(char str)
{
    outputFile << str;
}

void FileIO::check_Buffor()
{
    if (next==-1)
    {
        next =7;
        int c = bufor.to_ullong();
        outputFile.write((char*)&c, 1);
        bufor.reset();
    }
}
std::bitset<8> FileIO::get_Next8()
{
    std::bitset<8> ret;
    for (int i = 7; i >=0; i--)
    {
        readToBuffor();
        ret.set(i, bufor[next--]);
    }
    return ret;
}
std::bitset<1> FileIO::get_Next()
{
    readToBuffor();
    return std::bitset<1>(bufor[next--]);
}
void FileIO::readToBuffor()
{
    if (next!=-1)
    {
        return;
    }
    char c;
    if (inputFile.read(& c, 1)) {
        bufor=std::bitset<8>(c);
        next = 7;
    }
}
void FileIO::wr(std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '0') {
            bufor.set(next--, false);
        }
        else
        {
            bufor.set(next--, true);
        }
        check_Buffor();
    }
}
bool FileIO::getCode(std::string* str)
{
    char c;
    if (inputFile.get(c))
    {
        *str += c;
        return true;
    }
    return false;
}

void FileIO::resetFile(std::string& in)
{
    inputFile.close();
    inputFile.open(in);
}
