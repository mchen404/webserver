#include "thread.h"

void Thread::Start(){

	pthread_create(&_thread,NULL,Callback,this);

};

void * Thread::Callback(void * data){

	Thread * obj = static_cast<Thread *>(data);
	obj->Run();
	
};
