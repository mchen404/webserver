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
	MessageType messagesToRegister[] = {SHUTDOWN};
	_messageDispatcher->Register(this,messagesToRegister);
	
};

void Server::run(){

	while(_running){

	}
	
};

void Server::receiveMessage(Message &message){

	MessageType type = message.getType();
	
	switch(type){
	
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