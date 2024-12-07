#include "UserProfile.h"
using namespace uesrProfile;
UserProfile::UserProfile()
{
}

std::string UserProfile::getLogin()
{
	return login;
}

std::string UserProfile::getPasswordHash()
{
	return PasswordHash;
}

void UserProfile::updatePassword(std::string password)
{
	this->PasswordHash = sha256(password);
}

void UserProfile::SetPassword(std::tuple<std::string, std::string> pass)

{
	this->login = std::get<0>(pass);
	this->PasswordHash = sha256(std::get<1>(pass));
}

void UserProfile::setPermissionLevel(int _permissionLevel)
{
	this->permissionLevel = (permisonLevel)_permissionLevel;
}

int UserProfile::getPermissionLevel()
{
	return permissionLevel;
}

