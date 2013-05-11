#include "console.h"

Console::Console():_running(true){
};

void Console::initialize(){
	
	// Register for messages
	MessageType messagesToRegister[] = {SHUTDOWN};
	_messageDispatcher->Register(this,messagesToRegister);
	
};

void Console::run(){

	std::string input;
	
	while(_running){
			
		input = "";
		getline(std::cin, input);
		std::cout << "CONSOLE: " << input << std::endl;
		
		if(0 == input.compare("SHUTDOWN")){
			Message message;
			message.setType(SHUTDOWN);
			_messageDispatcher->sendMessage(message);
		}
	}
	
};

void Console::receiveMessage(Message &message){

	MessageType type = message.getType();
	
	switch(type){
	
		case SHUTDOWN:{
			_running = false;
			std::cout << "CONSOLE RECEIVED SHUTDOWN\n";
			break;
		}
		default:{
			break;
		}
		
	}
	
};