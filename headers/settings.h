#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "recipient.h"
#include "datatype.h"
#include "global.h"

class Settings: public Recipient{

private:
	SettingsData * _settingsData;
	
	void parse(const std::string &);
	
public:
	Settings();
	void initialize();
	void receiveMessage(Message &);
};

#endif