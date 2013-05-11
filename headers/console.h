#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>
#include <string>
#include "thread.h"
#include "recipient.h"
#include "global.h"

class Console : public Thread, public Recipient{

private:

	friend class Thread;
	bool _running;
	
public:

	Console();
	
	void initialize();
	
	void run();

	void receiveMessage(Message &);
	
};

#endif