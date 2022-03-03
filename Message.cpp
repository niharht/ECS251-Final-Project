#include "Message.h"


Message::Message(std::string arg_host_url, std::string arg_owner_vsID,
			 std::string arg_class_id, std::string arg_object_id){
  
  	//transaction_count++;
  	std::cout << "Message Constructor" << std::endl;

  	this.host_url = arg_host_url;
  	this.owner_vsID = arg_owner_vsID;
  	this.class_id = arg_class_id;
  	this.object_id = arg_object_id;
}