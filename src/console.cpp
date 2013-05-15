#include "console.h"

Console::Console():_running(true){
};

void Console::initialize(){
	
	// Register for messages
	MessageID messagesToRegister[] = {SHUTDOWN,ERROR_MESSAGE};
	_messageDispatcher->Register(this,messagesToRegister,sizeof(messagesToRegister)/sizeof(messagesToRegister[0]));
	
};

void Console::run(){

	std::string input;
	
	while(_running){
			
		input = "";
		getline(std::cin, input);
		std::cout << "CONSOLE: " << input << std::endl;
		
		if(!input.compare("SHUTDOWN")){
			Message message;
			message.setID(SHUTDOWN);
			_messageDispatcher->sendMessage(message);
		}
	}
	
};

void Console::receiveMessage(Message &message){

	const MessageID messageID = message.getID();
	
	switch(messageID){
	
		case SHUTDOWN:{
			_running = false;
			std::cout << "CONSOLE RECEIVED SHUTDOWN\n";
			break;
		}
		case ERROR_MESSAGE:{
			const std::string errorMessage = *static_cast<std::string *>( message.getData() );
			std::cout << errorMessage << std::endl;
		};
		default:{
			break;
		}
		
	}
	
};