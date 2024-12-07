#pragma once
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <string>
#include <vector>
#include "record.h"
#include "choice.h"
#include "Creator.h"
namespace SQL
{
class RemDB
{
public:
	RemDB();
	RemDB(std::string server);
	~RemDB();
	void connect(std::string username, std::string Password);
	void disconnect();

	std::string InsertSong(record* r);
	void deletelastSong(int id);
	std::vector <Creator>* lookupCreators(creatorSerchType c, std::string keyword);
	std::vector<record>* lookupSongs(choice, std::string keyword);


	int Aithorize(std::string login, std::string hashPassword);
	int getPermissionLevel(int id);
	bool ChangePassword(int id,std::string oldPassword,std::string newPassword);
private:
	bool bypass;
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *pstmt;
	std::string server;
};

}