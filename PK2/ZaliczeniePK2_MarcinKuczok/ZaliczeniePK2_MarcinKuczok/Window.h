#pragma once
#include "UI.h"
class Window : public UI
{
    int type;   
    int width;  
    int height; 

   public:
       Window();
       Window(bool);
       ~Window();
       void initialize()override;
       std::tuple<std::string, std::string> GetPassword() override;
       void PrintMessage(std::string message) override;
       std::string Response() override;
       choice PrintContextMenu() override;
       int GetVolume() override;
       void printRecord(record) override;
       void printCreator(Creator) override;
       std::tuple<std::string, std::string> ChangePassword() override;
       void alert(std::string alertMessage)override;
       void AddSong(record*)override;
};

