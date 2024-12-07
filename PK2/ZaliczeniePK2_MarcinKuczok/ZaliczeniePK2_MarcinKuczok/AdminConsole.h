#pragma once

#include "SettigsMenu.h"
class AdminConsole :
    public SettingsMenu
{
public:
    AdminConsole() :SettingsMenu() {};
    choice menu2() override;
}; 

