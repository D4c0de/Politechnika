#pragma once

#include "UserProfile.h"
#include "UI.h"
#include "choice.h"
#include "MusicControll.h"
#include "ServerControll.h"
#include <queue>
#include <mutex>
#include <thread>
#include "Window.h"
#include "Console.h"
#include "Creator.h"
#include "SHA256.h"
#include "UserProfile.h"
class App
{
private:
	bool consoleMode;
	uesrProfile::UserProfile* user;
	MusicControll *music;
	ServerControll* server;
	UI* ui;
	std::queue<std::string>* consoleQueue=new std::queue<std::string>;
	
	void initialize(bool bypass_authoryzation);
	void TryToLogin2();
	void AddNextSong(record);
	int awaitInput();
	record browse(choice);
	void ChangePassword();
	void AddSong();
public:
	
	App();
	App(bool _consloeMode);
	App(bool _consloeMode,int bypass_authoryzation);
	~App();
};

