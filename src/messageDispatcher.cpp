#include "messageDispatcher.h"

MessageDispatcher::MessageDispatcher(){
	
};

MessageDispatcher::~MessageDispatcher(){

};

void MessageDispatcher::Register(Recipient * recipient, const MessageID messagesToRegister[], const int numOfMessages){
	
	
	for(int index = 0; index < numOfMessages; index++){
		
		// message type
		const MessageID messageID = messagesToRegister[index];
		
		// find key
		const std::map<MessageID, std::vector<Recipient *> >::iterator it = find(messageID);
		
		// if key is found
		if( it != RecipientTable.end() ){
		
			it->second.push_back(recipient);
			
		} else {
			// protect this...
			std::vector<Recipient *> recipientList;
			recipientList.push_back(recipient);
			RecipientTable.insert(std::pair<MessageID, std::vector<Recipient *> >(messageID,recipientList));
			
		}
		
	}

};

const std::map<MessageID, std::vector<Recipient *> >::iterator MessageDispatcher::find(const MessageID messageID){

	return RecipientTable.find(messageID);

};

void MessageDispatcher::sendMessage(Message &message){

	MessageID messageID = message.getID();
	
	// find key
	std::map<MessageID, std::vector<Recipient *> >::iterator it = find(messageID);
		
	// if key is found
	if( it != RecipientTable.end() ){
	
		std::vector<Recipient *> recipientList = it->second;
		
		for( std::vector<Recipient *>::iterator it = recipientList.begin(); it != recipientList.end(); it++){
		
			(*it)->receiveMessage(message);

		}
	
	}

};