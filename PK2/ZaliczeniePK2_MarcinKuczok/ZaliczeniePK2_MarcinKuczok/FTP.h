#pragma once
#include <string>
#include <curl/curl.h>
#include <iostream>
namespace FTP
{

	class FTP
	{
	private:
		std::string host = "ftp:/127.0.0.1:21";
		std::string userpwd = "admin:admin";
		CURL* curl;
		CURLcode res;
	public:
		FTP();
		~FTP();
		bool upload(std::string local, std::string remote);
		bool download(std::string remote, std::string local);
		bool connect();
		bool connect(std::string login, std::string Password);
	};
}

