#include "messageDispatcher.h"

MessageDispatcher::MessageDispatcher(){
	
};

MessageDispatcher::~MessageDispatcher(){

};

void MessageDispatcher::Register(Recipient * recipient, const MessageType messagesToRegister[]){
	
	// get number of elements in array
	int size = sizeof(messagesToRegister)/sizeof(messagesToRegister[0]);
	
	for(int index = 0; index < size; index++){
		
		// message type
		MessageType messageType = messagesToRegister[index];
		
		// find key
		std::map<MessageType, std::vector<Recipient *> >::iterator it = find(messageType);
		
		// if key is found
		if( it != RecipientTable.end() ){
		
			it->second.push_back(recipient);
			
		} else {
			// protect this...
			std::vector<Recipient *> recipientList;
			recipientList.push_back(recipient);
			RecipientTable.insert(std::pair<MessageType, std::vector<Recipient *> >(messageType,recipientList));
			
		}
		
	}

};

const std::map<MessageType, std::vector<Recipient *> >::iterator MessageDispatcher::find(const MessageType messageType){

	return RecipientTable.find(messageType);

};

void MessageDispatcher::sendMessage(Message &message){

	MessageType messageType = message.getType();
	
	// find key
	std::map<MessageType, std::vector<Recipient *> >::iterator it = find(messageType);
		
	// if key is found
	if( it != RecipientTable.end() ){
	
		std::vector<Recipient *> recipientList = it->second;
		
		for( std::vector<Recipient *>::iterator it = recipientList.begin(); it != recipientList.end(); it++){
		
			(*it)->receiveMessage(message);

		}
	
	}

};