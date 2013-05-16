#ifndef _DATATYPE_H_
#define _DATATYPE_H_

#include <string>

#define DEFAULT_HOST 	"localhost"
#define DEFAULT_PORT 	8080

enum MessageID{
	SHUTDOWN,
	GET_SETTINGS,
	ERROR_MESSAGE,
	DEFAULT
};

struct SettingsData{
	
	std::string host;
	int port;
	
	// default settings
	SettingsData():host(DEFAULT_HOST),port(DEFAULT_PORT){
	};

};

struct Message{

	private:
		MessageID _id;
		void * _data;
		
		
	public:
		Message():_id(DEFAULT),_data(0){};
	
		void setID(MessageID id){
			_id = id;
		};
		
		void setData(void * data){
			_data = data;
		};
		
		MessageID getID(){
			return _id;	
		};
		
		void * getData(){
			return _data;
		};
		
};

template<class T>
struct SmartPointer{

	private:
		T * pointer;
	
	public:
		SmartPointer(T * object):pointer(object){
		};
		
		~SmartPointer(){
		
			delete(pointer);
			pointer = 0;
		
		};

		T * operator->(){
		
			return pointer;
		
		};
	
		void operator=(T * object){
			delete(pointer);
			pointer = object;
		};
}; 

#endif