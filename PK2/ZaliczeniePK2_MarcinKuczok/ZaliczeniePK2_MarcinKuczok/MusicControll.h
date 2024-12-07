#pragma once
#include <list>
#include "record.h"
#include <SFML/audio.hpp>
#include <SFML/System.hpp>
class MusicControll
{
private:
    sf::Sound music;
    sf::SoundBuffer buffer;

public:


    MusicControll();
    ~MusicControll();
    void addtoList(std::string path);

    void ResumeMusic();

    void PauseMusic();

    void StopMusic();

    void SetVolume(float volume);
};

