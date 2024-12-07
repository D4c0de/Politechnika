#include "Console.h"
#include <Windows.h>
#include <CreatorConsole.h>



void Console::initialize()
{
	x.push_back(new UserConsole);
	x.push_back(new CreatorConsole);
	x.push_back(new AdminConsole);
	
}

std::tuple<std::string, std::string> Console::GetPassword()
{
	std::string login;
	std::string password;
	std	::cout << "Enter username: ";
	std::cin >>login;

	std::cout << std::endl <<"Enter password: ";
	std::cin >> password;
	std::cout << std::endl;


	return std::make_tuple(login,password);
}

void Console::PrintMessage(std::string message)
{
	system("cls");
	std::cout << message << std::endl;
}

std::string Console::Response()
{
	std::string ret;
	std::cin >> ret;
	return ret;
}

choice Console::PrintContextMenu()
{
	std::string choice;
	int i = 0;
	while (true)
	{
		system("cls");

		std::cout << "1. Browser" << std::endl;
		std::cout << "2. Profile" << std::endl;
		std::cout << "3. Settings" << std::endl;
		std::cout << "4. LogOut" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			return menu1();
		}
		else if (choice == "2")
		{
			menu2 = x[id];
			menu2->menu2();
		}
		else if (choice == "3")
		{
			return menu3();
		}
		else if (choice == "4")
		{
			return menu4();
		}
		else
		{
			alert("invalid input try agan");
		}
	}
}

int Console::GetVolume()
{
	system("cls");
	int volume;
	std::cout << "Enter volume:\n";
	std::cin >> volume;
	return volume;
}
void Console::printRecord(record r)
{
	std::cout << r.id << ":	";
	std::cout << "Title: " << r.title << "	";
	std::cout << "Author: " << r.artist << "\n";
}
void Console::printCreator(Creator c)
{
	std::cout << c.id << ":	";
	std::cout << "Title: " << c.name << "	";
	std::cout << "Author: " << c.MusicType << "\n";
}

std::tuple<std::string, std::string> Console::ChangePassword()
{
	std::string oldPass;
	std::string newPass;
	system("cls");
	std::cout << "Enter old password: ";
	std::cin>> oldPass;
	std::cout << "Enter new Password: ";
	std::cin >> newPass;
	return std::tuple<std::string, std::string>(oldPass,newPass);
}

void Console::AddSong(record* r)
{
	std::cout << "Enter title: ";
	std::cin >> r->title;
	std::cout << "Enter Path to file: ";
	std::cin >> r->path;
}

choice Console::menu1()
{
	std::string choice;


	while (true)
	{
		system("cls");

		std::cout << "1. Browse By title\n";
		std::cout << "2. Browse By Author\n";
		std::cout << "0. Back\n";
		std::cin >> choice;
		if (choice == "1")
		{
			return browseByTitle;
		}
		else if (choice == "2")
		{
			return browseByAuthor;
		}
		else if (choice == "0")
		{
			return PrintContextMenu();
		}
		else
		{
			alert("invalid input try agan");
		}
	}
}

choice Console::menu3()
{

	std::string choice;

	while (true)
	{
		system("cls");
		std::cout << "1. Volume" << std::endl;
		std::cout << "2. Resume" << std::endl;
		std::cout << "3. Pause" << std::endl;
		std::cout << "4. Stop" << std::endl;
		std::cout << "0. Back" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			return changeVolume;
		}
		else if (choice == "2")
		{
			return resumeMusic;
		}
		else if (choice == "3")
		{
			return pauseMusic;
		}
		else if (choice == "4")
		{
			return stopMusic;
		}
		else if (choice == "0")
		{
			return PrintContextMenu();
		}
		else
		{
			alert("invalid input try agan");
			continue;
		}
	}
}
choice Console::menu4()
{
	std::string choice;

	while (true)
	{
		system("cls");
		std::cout << "1. Switch Account" << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cout << "0. Back" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			return logOut;
		}
		else if (choice == "2")
		{
			return exitApp;
		}
		else if (choice == "0")
		{
			return PrintContextMenu();
		}
		else
		{
			alert("invalid input try agan");
			continue;
		}
	}
}

void Console::alert(std::string alertMessage)
{
	MessageBox(nullptr, TEXT(alertMessage.c_str()), TEXT("ERROR"), MB_OK);
}

Console::Console()
{

}

Console::~Console()
{
}
