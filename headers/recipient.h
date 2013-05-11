#ifndef _RECIPIENT_H_
#define _RECIPIENT_H_

#include "datatype.h"

class Recipient{

public:	
	virtual void receiveMessage(Message &message) = 0;
 
};

#endif