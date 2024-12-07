#pragma once
#include <queue>
#include <stdlib.h>
#include <mutex>
#include <iostream>
#include "choice.h"
#include <stdlib.h>
#include "record.h"
#include "UI.h"
#include "SettigsMenu.h"
#include "AdminConsole.h"
#include "UserConsole.h"
class Console:public UI
{
private:
	choice menu1();
	choice menu3();
	choice menu4();
protected:
	int accoutType;
	SettingsMenu* menu2;
	std::vector<SettingsMenu*> x;
public:
	void initialize()override;

	std::tuple<std::string, std::string> GetPassword() override;
	void PrintMessage(std::string message) override;
	std::string Response() override;
	choice PrintContextMenu() override;
	int GetVolume() override;
	void printRecord(record) override;
	void printCreator(Creator) override;
	std::tuple<std::string, std::string> ChangePassword()override;
	void alert(std::string alertMessage)override;
	void AddSong(record*)override;

	Console();
	~Console();
};
