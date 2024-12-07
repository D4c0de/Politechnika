#include "ServerControll.h"

ServerControll::ServerControll():
	RemDB(),
	BypassAuth(false)
{
}

ServerControll::ServerControll(bool bypass) :
	RemDB(),
	BypassAuth(bypass)
{
}
void ServerControll::login(std::string login, std::string password)
{
	RemDB::connect(login, password);
	FTP::connect(login,password);
}


ServerControll::~ServerControll()
{
}

bool ServerControll::addSong(record r)
{
	try
	{
		std::string remotePath =RemDB::InsertSong(&r);
		FTP::upload(r.path, remotePath);
		return true;
	}
	catch (const std::exception&)
	{
		try
		{
			RemDB::deletelastSong(r.id);
		}
		catch (const std::exception&)
		{

		}
		return false;
	}


}
