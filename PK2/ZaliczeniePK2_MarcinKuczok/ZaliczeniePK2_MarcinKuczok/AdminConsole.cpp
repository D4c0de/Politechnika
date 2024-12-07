#include "AdminConsole.h"

choice AdminConsole::menu2()
{
	std::string choice;
	while (true)
	{
		system("cls");

		std::cout << "1. Chenge Password" << std::endl;
		std::cout << "2. Add Song" << std::endl;
		std::cout << "3. Destroy Evrything\n";
		std::cout << "0. Back" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			return chengePassword;
		}
		else if (choice == "2")
		{
			return addSong;
		}
		else if (choice == "3")
		{
			throw std::exception("tak");
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
