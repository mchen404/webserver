#ifndef _MessageDispatcher_H_
#define _MessageDispatcher_H_

#include <vector>
#include <map>
#include "datatype.h"
#include "recipient.h"

class MessageDispatcher{

private:

	std::map<MessageID, std::vector<Recipient *> > RecipientTable;
	
	const std::map<MessageID, std::vector<Recipient *> >::iterator find(const MessageID);

	
public:
	
	// Constructor
	MessageDispatcher();
	
	// Deconstructor
	~MessageDispatcher();

	// register for message
	void Register(Recipient *, const MessageID[], const int);
	
	// Send message
	void sendMessage(Message &);
	
};

#endif