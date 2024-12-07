#pragma once
#include <queue>
#include <cstdlib>
#include <iostream>
#include "choice.h"
#include "record.h"
class SettingsMenu
{
public:
	SettingsMenu();
	virtual choice menu2()=0;
};

