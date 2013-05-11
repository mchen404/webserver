#ifndef _THREAD_H_
#define _THREAD_H_

#include <iostream>
#include <pthread.h>

class Thread{

private:
	pthread_t _thread;
	
	static void * Callback(void *);
	
public:
	
	virtual void Start();
	
	virtual void thread_join();
	
	virtual void run() = 0;
	
};

#endif