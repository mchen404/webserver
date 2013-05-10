#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>
#include <string>
#include "thread.h"

class Console:public Thread{

private:

	friend class Thread;
	bool _running;
	
public:

	Console();
	
	void Run();

};

#endif