#ifndef _MessageDispatcher_H_
#define _MessageDispatcher_H_

#include <vector>
#include <map>
#include "datatype.h"
#include "recipient.h"

class MessageDispatcher{

private:

	std::map<MessageType, std::vector<Recipient *> > RecipientTable;
	
	const std::map<MessageType, std::vector<Recipient *> >::iterator find(const MessageType);

	
public:
	
	// Constructor
	MessageDispatcher();
	
	// Deconstructor
	~MessageDispatcher();

	// register for message
	void Register(Recipient *, const MessageType[]);
	
	// Send message
	/* template<class T>
	void SendMessage(MessageType, T){}; */
	void sendMessage(Message &);
	
};

#endif