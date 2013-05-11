#ifndef SERVER_H_
#define SERVER_H_

#include "datatype.h"
#include "recipient.h"
#include "global.h"
#include "thread.h"
#include <iostream>

class Server: public Recipient, public Thread{

private:

	friend class Thread;
	bool _running;
	
public:

	// Constructor
	Server();
	
	// Deconstructor
	~Server();
	
	// Initialize everything
	void initialize();
	
	void receiveMessage(Message &);

	// Thread run
	void run();
	
};

#endif