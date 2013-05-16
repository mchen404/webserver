#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <vector>
#include "exethread.h"
#include "datatype.h"
#include "global.h"

class Threadpool{

private:
	SmartPointer< std::vector<Exethread *> > pool;
	
	void spawn();
	
public:
	// Constructor
	Threadpool();
	
	// Deconstructor
	~Threadpool();
	
	void initialize();
	
};

#endif