#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <pthread.h>
#include "console.h"

class Server{

private:
	Console _console;

public:

	// Constructor
	Server();
	
	// Deconstructor
	~Server();
	
	// Initialize everything
	void initialize();

};

#endif