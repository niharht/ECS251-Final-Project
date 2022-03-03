#include "Voter.h"

using namespace std;


Voter::Voter(std::string core_arg_host_url, std::string core_arg_owner_vsID, std::string core_arg_class_id, std::string core_arg_object_id)
	: Core(core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id)
{
		cout << "Voter Constructor" << endl;
}

Voter::Voter(std::string core_arg_host_url, std::string core_arg_owner_vsID, std::string core_arg_class_id, std::string core_arg_object_id, std::string name, int votingID)
	: Core(core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id)
{
	this->name = name;
	this->votingId = votingID;
}
	


int Voter::getVotingId(){
	return this->votingId;
}

std::string Voter::getName(){
	return this->name;
}

std::string Voter::getVoterInfo(){
	return to_string(this->getVotingId()) + this->getName();
}