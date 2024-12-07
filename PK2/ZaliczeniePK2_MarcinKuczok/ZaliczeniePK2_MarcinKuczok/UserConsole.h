#pragma once
#include "SettigsMenu.h"
class UserConsole :
    public SettingsMenu
{
public:
    choice menu2() override;
    UserConsole() :SettingsMenu() {};
};

