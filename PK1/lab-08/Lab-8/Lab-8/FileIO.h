#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>s
class FileIO
{
private:
	std::fstream inputFile;
	std::fstream outputFile;
public:
	FileIO(const std::string&, const std::string&);
	~FileIO();
	void RW(std::vector<std::string>);
};