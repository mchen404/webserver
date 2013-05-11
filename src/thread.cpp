#include "thread.h"

void Thread::Start(){

	pthread_create(&_thread,NULL,Callback,this);

};

void * Thread::Callback(void * data){

	Thread * obj = static_cast<Thread *>(data);
	obj->run();
	
};

void Thread::thread_join(){

	pthread_join(_thread, NULL);

};
