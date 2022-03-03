#include "VotingOffice.h"


using namespace std;


VotingOffice::VotingOffice(std::string core_arg_host_url, std::string core_arg_owner_vsID,
               std::string core_arg_class_id, std::string core_arg_object_id) : Core(
  core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id)
{
		cout << "VotingOffice Constructor" << endl;
}

VotingOffice::VotingOffice(std::string core_arg_host_url, std::string core_arg_owner_vsID, std::string core_arg_class_id, std::string core_arg_object_id, std::string votingOfficeName)
	: Core(core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id)
{
		this->votingOfficeName = votingOfficeName;
		this->registeredVoters.insert("0Wu");
}

/*
bool
VotingOffice::setAuthMessage(vector<std::string> args){

	if(args.size() < 2){
		return false;
	}

	std::string voter = args[1];

	if(registeredVoters.count(voter) != 1){
		return false;
	}


	//this->authMessage = arg;
	return true;
}


std::string 
VotingOffice::getAuthMessage(){
	return "";
}

*/

vector<std::string> VotingOffice::getAuthMessage(std::string message, std::string machineId, std::string voterInfo){

	//FIXME: will need to add logic to check if machine Id is registered
	vector<std::string> result;

	if(registeredVoters.count(voterInfo) != 1){
		result.push_back("Not Authorized");
		result.push_back(voterInfo);
		return result;
	}

	result.push_back("Authorized");
	result.push_back(voterInfo);
	return result;

}



vector<std::string> VotingOffice::getReceipt(std::string message, std::string machineId, std::string voterInfo){
	//FIXME: will need to add logic to check if machine Id is registered
	vector<std::string> result;

	if(registeredVoters.count(voterInfo) != 1){
		result.push_back("Not Authorized");
		result.push_back(voterInfo);
		return result;
	}

	result.push_back("Done");
	result.push_back(voterInfo);
	return result;
}





