#pragma once

#include <string>

#include "RemDB.h"
#include "FTP.h"
 class ServerControll:public SQL::RemDB,public FTP::FTP
{
    
public:
    ServerControll();
    ServerControll(bool bypass);
	
    void login(std::string login,std::string pasword);
    ~ServerControll();

    bool addSong(record);

    bool BypassAuth;
    bool isAuthoryzated;
    int permissionLevel;
};
