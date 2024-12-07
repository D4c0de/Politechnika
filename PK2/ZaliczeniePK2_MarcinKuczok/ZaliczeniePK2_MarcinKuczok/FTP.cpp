
#include "FTP.h"
#include <string>
namespace FTP {
    FTP::FTP()
    {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        connect();
    }

    FTP::~FTP()
    {
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
  
    size_t writeFileCallback(void* ptr, size_t size, size_t nmemb, FILE* stream)
    {
        size_t written = fwrite(ptr, size, nmemb, stream);
        return written;
    }
    size_t readFileCallback(void* ptr, size_t size, size_t nmemb, FILE* stream)
    {
        size_t retcode = fread(ptr, size, nmemb, stream);
        return retcode;
    }
    bool FTP::upload(std::string local, std::string remote)
    {
        if (!curl) {
			throw std::exception("Can't init curl");
        }

        FILE* fp = fopen(local.c_str(), "rb");
        if (!fp) {
			throw std::exception("Can't open file");
        }

        std::string fullpath = host + "/" + remote;
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_URL, fullpath.c_str());
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, readFileCallback);
        curl_easy_setopt(curl, CURLOPT_READDATA, fp);
        curl_easy_setopt(curl, CURLOPT_USERPWD, userpwd.c_str());

        // Perform the upload
        res = curl_easy_perform(curl);

        // Clean up
        fclose(fp);

        // Check for errors
        if (res != CURLE_OK) {
            return false;
        }

        return true;
    }
    bool FTP::download(std::string remote, std::string local)
    {
        if (!curl) {
            return false;
        }

        FILE* fp = fopen(local.c_str(), "wb");
        if (!fp) {
            return false;
        }
        std::string fullpath = host + "/" + remote;
        curl_easy_setopt(curl, CURLOPT_URL, fullpath.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFileCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fclose(fp);
            return false;
        }

        // Clean up
        fclose(fp);
        return true;
    }

    bool FTP::connect()
    {
        curl_easy_setopt(curl, CURLOPT_URL, host.c_str());
        curl_easy_setopt(curl, CURLOPT_USERPWD, userpwd.c_str());

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            return true;
        }
        return false;
    }
    bool FTP::connect(std::string login,std::string Password)
    {
		userpwd = login + ":" + Password;
		return connect();
    }
}