#pragma once

#include "SettigsMenu.h"


class CreatorConsole : public SettingsMenu {
protected:
    

public:
    choice menu2() override;
    CreatorConsole() : SettingsMenu() {};
};