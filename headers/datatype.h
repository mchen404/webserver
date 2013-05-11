#ifndef _DATATYPE_H_
#define _DATATYPE_H_

enum MessageType{
	SHUTDOWN,
	DEFAULT
};

/* template<class T>
struct Data{

private:
	T _data;
		public:
	void setData(T data){
		_data = data;
	};
	
};
 */

struct Message{

	private:
		MessageType _type;
		void * _data;
		
		
	public:
		Message():_type(DEFAULT),_data(0){};
	
		void setType(MessageType type){
			_type = type;
		};
		
		void setData(void * data){
			_data = data;
		};
		
		MessageType getType(){
			return _type;	
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
		
		};

		T * operator->(){
		
			return pointer;
		
		};
	
};


#endif