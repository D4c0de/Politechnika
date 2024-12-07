#pragma once

#include "UserProfile.h"
#include <string>
/**
 * @file Settings.h
 * @brief Class representing user settings
 *
 * The Settings class inherits from UserProfile and represents user settings,
 * including volume settings.
 */
class Settings
{

public:
    std::string outputDevuce; ///< Output device
    int volume; ///< Volume level

};

