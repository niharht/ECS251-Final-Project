#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iostream>

using namespace std;


class Message{
	private:
		static unsigned message_count;
		unsigned inst msg_type;
		string msg_description;
		unsigned int msg_status;


	public:
		Message(string, string, string, string);
		//Message(unsigned int);
		//Message(string, string, string, string, unsigned int, string, IP_Address&);

		std::string host_url;
  		std::string owner_vsID;
  		std::string class_id;
  		std::string object_id;


		void setMessage(void *);
		void *getMessage();



};

class AuthMessage: public Message{

}





#endif /*MESSAGE.H*/