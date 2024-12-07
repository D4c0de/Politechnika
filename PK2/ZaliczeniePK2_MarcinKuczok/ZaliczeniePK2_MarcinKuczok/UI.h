#pragma once
#include <string>
#include <tuple>
#include "record.h"
#include "choice.h"
#include "Creator.h"

 class UI
{
	public:
	int id;
	virtual void initialize() = 0;
	virtual void printRecord(record)=0;
	virtual void printCreator(Creator) = 0;
	virtual std::tuple<std::string, std::string> GetPassword()=0;
	virtual void PrintMessage(std::string message)=0;
	virtual std::string Response()=0;
	virtual choice PrintContextMenu()=0;
	virtual int GetVolume()=0;
	virtual ~UI()=default;
	virtual std::tuple<std::string, std::string> ChangePassword() = 0;
	virtual void alert(std::string alertMessage) = 0;
	virtual void AddSong(record*) = 0;
};

