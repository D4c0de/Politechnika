#pragma once

#include <string>
#include "SHA256.h"
#include "Settings.h"

/**
 * @file UserProfile.h
 * @brief Class representing a user profile
 *
 * The UserProfile class represents a user profile, inheriting from Authoryzation
 * and Settings, and containing information such as permission level.
 */
namespace uesrProfile
{


	enum permisonLevel
	{
		User = 0,
		Creator = 1,
		Admin = 2
	};
	class UserProfile
	{
	private:
		std::string login;
		std::string PasswordHash;
		permisonLevel permissionLevel;
	public:
		int id;

		UserProfile();


		std::string getLogin();
		std::string getPasswordHash();
		void updatePassword(std::string password);
		void SetPassword(std::tuple <std::string, std::string> pass);
		void setPermissionLevel(int permissionLevel);
		int getPermissionLevel();
		///< Permission level of the user
	};
}