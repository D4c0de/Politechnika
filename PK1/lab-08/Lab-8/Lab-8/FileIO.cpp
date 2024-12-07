#include "FileIO.h"

FileIO::FileIO(const std::string& input, const std::string& output)
{
	inputFile.open(input, std::ios::in);
	if (!inputFile.good())
	{
		throw std::exception("Error: Cant gain acces to input file");
	}
	outputFile.open(output, std::ios::out);
	if (!outputFile.good())
	{
		throw std::exception("Error: Cant gain acces to output file");
	}

}

FileIO::~FileIO()
{
	inputFile.close();
	outputFile.close();
}

void FileIO::RW(std::vector<std::string> command)
{
	std::string line;
	while (std::getline(inputFile, line)) {
		std::string line_content, command;
        parse_line(line, line_content, command);
        std::string processed_line = execute_command(line_content, command);
        outputFile << processed_line << '\n';
	}
}
void parse_line(const std::string& line, std::string& line_content, std::string& command)  {
    size_t command_start = line.find(" [% ");
    if (command_start != std::string::npos) {
        line_content = line.substr(0, command_start);
        command = line.substr(command_start + 4, line.size() - command_start - 5);
    }
    else {
        line_content = line;
        command = "";
    }
}
std::string execute_command(const std::string& line_content, const std::string& command) {
    if (command.empty()) {
        return line_content;
    }

    if (command == "remove") {
        return remove_whitespace(line_content);
    }
    else if (command.find("remove ") == 0) {
        std::string chars_to_remove = command.substr(7);
        return remove_chars(line_content, chars_to_remove);
    }
    else if (command == "count") {
        return std::to_string(count_whitespace(line_content));
    }
    else if (command.find("count ") == 0) {
        std::string chars_to_count = command.substr(6);
        return count_chars(line_content, chars_to_count);
    }
    else if (command.find("replace ") == 0) {
        std::istringstream iss(command.substr(8));
        std::string x, y;
        iss >> x >> y;
        return replace_string(line_content, x, y);
    }
    else {
        return line_content;
    }
}

std::string remove_whitespace(const std::string& s)  {
    std::string result = s;
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}

std::string remove_chars(const std::string& s, const std::string& chars)  {
    std::string result = s;
    for (char c : chars) {
        result.erase(std::remove(result.begin(), result.end(), c), result.end());
    }
    return result;
}

int count_whitespace(const std::string& s)  {
    return std::count_if(s.begin(), s.end(), ::isspace);
}

std::string count_chars(const std::string& s, const std::string& chars)  {
    std::ostringstream oss;
    for (char c : chars) {
        oss << std::count(s.begin(), s.end(), c) << ' ';
    }
    return oss.str();
}

std::string replace_string(const std::string& s, const std::string& x, const std::string& y)  {
    std::string result = s;
    size_t pos = 0;
    while ((pos = result.find(x, pos)) != std::string::npos) {
        result.replace(pos, x.length(), y);
        pos += y.length();
    }
    return result;
}