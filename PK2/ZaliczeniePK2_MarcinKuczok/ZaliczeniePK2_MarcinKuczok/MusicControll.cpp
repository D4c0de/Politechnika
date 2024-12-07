#include "MusicControll.h"
#include <iostream>

MusicControll::MusicControll()
{
	music.setBuffer(buffer);
	music.setVolume(50);
	music.setLoop(false);
}

void MusicControll::addtoList(std::string path)
{
	buffer.loadFromFile(path);
	music.play();
}
void MusicControll::ResumeMusic()
{
	music.play();
}
void MusicControll::PauseMusic()
{
	music.pause();
}
void MusicControll::StopMusic()
{
	music.stop();
}
void MusicControll::SetVolume(float volume)
{
	music.setVolume(volume);
}

MusicControll::~MusicControll()
{

}