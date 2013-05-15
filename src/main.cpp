#include "server.h"
#include "console.h"   
#include "threadpool.h"
#include "settings.h"

int main( int argc, char** argv ){

	// create all component
	SmartPointer<Settings> settings(new Settings());
	SmartPointer<Server> server(new Server());
	SmartPointer<Console> console(new Console());
	SmartPointer<Threadpool> threadpool(new Threadpool());
	
	// primary initialize
	console->initialize();
	
	// secondary initialize
	settings->initialize();
	server->initialize();
	threadpool->initialize();
	
	// start threads
	server->Start();
	console->Start();
	
	// wait for all threads to complete
	server->thread_join();
	console->thread_join();
	
	return 0;
	
};