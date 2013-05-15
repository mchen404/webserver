#include "settings.h"

Settings::Settings():_settingsData(new SettingsData()){

};

void Settings::initialize(){

	// Register for messages
	MessageID messagesToRegister[] = {GET_SETTINGS};
	_messageDispatcher->Register(this,messagesToRegister,sizeof(messagesToRegister)/sizeof(messagesToRegister[0]));
	
	//read file
	std::ifstream file;
	file.open("settings.txt");
	if( file.is_open() ){
	
		std::string line;
		
		while ( file.good() )
		{
			getline (file,line);
			parse(line);
		}
		file.close();
	
	} else {
	
		Message message;
		message.setID(ERROR_MESSAGE);
		std::string errorMessage = "Settings: settings.txt was not found, using default settings.";
		message.setData(&errorMessage);
		_messageDispatcher->sendMessage(message);
		
	} 
	
};

void Settings::parse(const std::string &setting){

	std::istringstream line(setting);
	std::string key;
	std::string value;
	
	while(std::getline(line,key,'=') && std::getline(line,value,'=')){
	
		if( !key.compare("address") ){
		
			_settingsData->host = value;
			
		} else if( !key.compare("port") ){
		
			_settingsData->port = atoi(value.c_str());
			
		}
	
	}
	
};

void Settings::receiveMessage(Message &message){

	MessageID messageID = message.getID();
	switch(messageID){
	
		case GET_SETTINGS:{
		
			SettingsData * data = static_cast<SettingsData *> (message.getData());
			memcpy(data,_settingsData,sizeof(SettingsData));
			break;
			
		}
		default:{
			break;
		}
	}

};