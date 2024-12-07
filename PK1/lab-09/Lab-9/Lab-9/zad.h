#pragma once
#include <fstream>
#include <vector>
#include <map>

int zad1(std::ifstream* fi){
	std::map<std::string, int> map;
	int t=0;
	std::string word;
	while (*fi>>word)
	{
		map[word]++;
	}
	return t;
}
void zad2(std::ifstream* fi) {
	std::map<std::string, std::string> map;
	std::string key;
	std::string mate;

	*fi >> key;
	mate = key;
	bool flag = true;
	while (*fi >> key)
	{
		map.insert({ key, mate });

	}
}

void index(std::ifstream* fi) {
	std::map<std::string, int> map;
	char c; int index = 0;
	std::string buff;
	while (*fi >>c)
	{
		if (c=='\n')
		{
			index++;
		}
		else if(c==' ')
		{
			map.insert({ buff=+index, index });
			buff.clear();
		}
		else
		{
			buff += c;
		}
	}
}