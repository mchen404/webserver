#include "server.h"

// Constructor
Server::Server():_running(true){
};

// Deconstructor
Server::~Server(){
};

// Initialize all
void Server::initialize(){
	
	// Register for messages
	MessageID messagesToRegister[] = {SHUTDOWN};
	_messageDispatcher->Register(this,messagesToRegister,sizeof(messagesToRegister)/sizeof(messagesToRegister[0]));
	
	// get settings
	SettingsData settings;
	Message message;
	message.setID(GET_SETTINGS);
	message.setData(&settings);
	_messageDispatcher->sendMessage(message);
	
};

void Server::run(){

	while(_running){

	}
	
};

void Server::receiveMessage(Message &message){

	MessageID messageID = message.getID();
	
	switch(messageID){
	
		case SHUTDOWN:{
			_running = false;
			std::cout << "SERVER RECEIVED SHUTDOWN\n";
			break;
		}
		default:{
			break;
		}
		
	}
	
};