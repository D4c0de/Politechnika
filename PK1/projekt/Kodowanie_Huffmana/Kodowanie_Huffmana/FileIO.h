/**
 * @file FileIO.h
 * @brief Declaration of the FileIO class for file input/output operations.
 */

#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>


class FileIO
{
public:

    FileIO(std::string& input, std::string& output);


    ~FileIO();


    char getChar();
    std::pair<std::string, int>  getDicElement();
    bool getCode(std::string*);
    void resetFile(std::string&);
    void wr(std::string&);
    void wr(char);
    std::bitset<8> bufor;
    int next;
    void check_Buffor();

private:
    std::bitset<8> get_Next8();
    std::bitset<1> get_Next();
    void readToBuffor();
    std::ifstream inputFile; ///< Input file stream.
    std::ofstream outputFile; ///< Output file stream.
};