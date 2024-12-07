#include "UserConsole.h"

choice UserConsole::menu2()
{
	std::string choice;
	while (true)
	{
		system("cls");

		std::cout << "1. Chenge Password" << std::endl;
		std::cout << "0. Back" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			return chengePassword;
		}
		/*else if (choice == "0")
		{
			return PrintContextMenu();
		}
		else
		{
			PrintMessage("invalid input try agan");
		}*/
	}
}
