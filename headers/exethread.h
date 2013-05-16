#ifndef _EXETHREAD_H_
#define _EXETHREAD_H_

#include "thread.h"

class Exethread: public Thread{

private:

public:

	Exethread();
	
	~Exethread();
	
	void run();

};

#endif