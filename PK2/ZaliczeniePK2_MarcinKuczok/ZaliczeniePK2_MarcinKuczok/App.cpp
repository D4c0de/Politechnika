#include "App.h"

int App::awaitInput()
{

	switch (ui->PrintContextMenu())
	{
		case browseByTitle:
		{
			record next = browse(browseByTitle);
			AddNextSong(next);
			//browes by name
			break;
		}
		case browseByAuthor:
		{
			record next = browse(browseByAuthor);
			AddNextSong(next);
			//browes by author
			break;
		}
		case chengePassword:
		{
			ChangePassword();
			//chenge password
			break;
		}
		case addSong:
		{
			AddSong();
			//add song
			break;
		}
		case changeVolume:
		{
			music->SetVolume(ui->GetVolume());
			//volume
			break;
		}
		case pauseMusic:
		{
			music->PauseMusic();
			//pause
			break;
		}
		case resumeMusic:
		{
			music->ResumeMusic();
			//resume
			break;
		}
		case stopMusic:
		{
			music->StopMusic();
			//stop
			break;
		}
		case logOut:
		{
			
			music->StopMusic();
			TryToLogin2();
			//log out
			break;
		}
		case exitApp:
		{
			return -1;
		}
	default:

		return -1;
	} 
	return 0;
}

record App::browse(choice c)
{
	ui->PrintMessage("keyword:");
	std::string keyword=ui->Response();
	ui->PrintMessage("chose song \n 0: BACK");
	if (c==browseByAuthor)
	{
		std::vector<Creator>* cr = server->lookupCreators(SerchByName, keyword);

		for (int i = 0; i < 10 && i < cr->size(); i++)
		{
			ui->printCreator((*cr)[i]);
		}

		keyword= ui->Response();
		system("cls"); // transfer this to console
		delete cr;
	}
	std::vector<record>* ret =server->lookupSongs(c, keyword);
	for (int i = 0; i < 10 && i < ret->size(); i++)
	{
		ui->printRecord((*ret)[i]);
	}
	int id = std::stoi(ui->Response());
	if (id==0)
	{
		throw std::exception("return");
	}
	else
	{
		std::vector<record>* r = server->lookupSongs(browseByID, std::to_string(id));
		record next = (*r)[0];
		delete r;
		return next;
	}
}

void App::ChangePassword()
{
	std::tuple<std::string, std::string> pass = ui->ChangePassword();
	if (!server->ChangePassword(user->id, sha256(std::get<0>(pass)), sha256(std::get<1>(pass))))
	{
		ui->alert("password chage faild");
	}
	else
	{
		ui->alert ("password chage success");
		user->updatePassword(std::get<1>(pass));
	}
}

void App::AddSong()
{
	if (user->getPermissionLevel()!= uesrProfile::permisonLevel::Creator)
	{
		ui->alert("you dont have permission to add song");
		return;
	}
	record r;
	r.artistID = user->id;
	ui->AddSong(&r);
	if (!server->addSong(r))
	{
		ui->alert("song add faild");
	}
	else
	{
		ui->alert("song add success");
	}

}

void App::initialize(bool bypass_authoryzation)
{
	user = new uesrProfile::UserProfile();
	music = new MusicControll();
	server = new ServerControll();
	try {


		if (bypass_authoryzation == true)
		{
			server->login("admin", "admin");
		}
		else if (bypass_authoryzation == false)
		{
			server->login("user", "user");
			TryToLogin2();
		}
		while (true)
		{
			if (awaitInput() == -1)
			{
				return;
			}
		}
	}

	catch (const std::exception& e)
	{
		ui->PrintMessage(e.what());
	}
}

void App::TryToLogin2()
{
	user->SetPassword(ui->GetPassword());
	user->id = server->Aithorize(user->getLogin(), user->getPasswordHash());
	while (user->id==0) {
		ui->PrintMessage("wrong password");
		user->SetPassword(ui->GetPassword());
		user->id = server->Aithorize(user->getLogin(), user->getPasswordHash());
	}
	user->setPermissionLevel(server->getPermissionLevel(user->id));
	ui->id = user->id;
	if (user->getPermissionLevel() == 1)
	{
		delete server;
		server = new ServerControll();
		server->login("creator", "creator");
	}
	else if (user->getPermissionLevel() == 2)
	{
		delete server;
		server = new ServerControll();
		server->login("admin", "admin");
	}
}

void App::AddNextSong(record r)
{
	if (r.id==-1)
	{
		return;
	}
	if (!server->download(r.path, "music.mp3"))
	{
		ui->alert("FailedToAddSong");
		return;
	}
	
	music->addtoList("music.mp3");
	ui->PrintMessage("song added");
}


App::App(bool _consloeMode)
{
	if (_consloeMode)
	{
		ui = new Console();
	}
	else
	{
		ui = new Window();
	}
	consoleMode = _consloeMode;
	initialize(false);
}

App::App(bool _consloeMode=false, int bypass_authoryzation=0)
{
	if (_consloeMode)
	{
		ui = new Console();
	}
	else
	{
		ui = new Window();
	}
	ui->initialize();
	consoleMode = _consloeMode;
	initialize(bypass_authoryzation);

}
App::~App()
{
	delete user;
	delete server;
	delete ui;
}
