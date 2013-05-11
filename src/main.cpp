#include "server.h"
#include "console.h"   

int main( int argc, char** argv ){

	SmartPointer<Server> server(new Server());
	server->initialize();
	server->Start();
	
	SmartPointer<Console> console(new Console());
	console->initialize();
	console->Start();
	
	server->thread_join();
	console->thread_join();
	
	return 0;
	
};