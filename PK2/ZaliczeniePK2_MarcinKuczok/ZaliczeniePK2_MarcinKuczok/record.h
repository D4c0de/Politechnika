#pragma once
#include <string>

struct record
{
	record();
	record(int id, std::string title, std::string artist, std::string path);
	record(int id);
	int id;
	std::string title;
	std::string artist;
	int artistID;
	std::string path;
}; 
