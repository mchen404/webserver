#include "console.h"

Console::Console():_running(true){

};

void Console::Run(){

	std::string input;
	
	while(_running){
			
		input = "";
		getline(std::cin, input);
		std::cout << "CONSOLE: " << input << std::endl;
		
	}
	
};