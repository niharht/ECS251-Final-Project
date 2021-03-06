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



vector<std::string> VotingOffice::getAuthMessage(std::string message, std::string machineId, std::string voterInfo){

	//In the future: will need to add logic to check if machine Id is registered
	vector<std::string> result;

	if(registeredVoters.count(voterInfo) != 1){
		result.push_back("Not Authorized");
		result.push_back(voterInfo);
		std::cout << voterInfo << " is not authorized to vote " << std::endl;
		return result;
	}

	result.push_back("Authorized");
	result.push_back(voterInfo);
	return result;

}



vector<std::string> VotingOffice::getReceipt(std::string message, std::string machineId, std::string voterInfo){
	
	//In the future: will need to add logic to check if machine Id is registered
	vector<std::string> result;

	if(message != "hasVoted"){
		result.push_back("Hasn't Voted");
		result.push_back(voterInfo);
		return result;
	}

	if(registeredVoters.count(voterInfo) != 1){
		result.push_back("Not Authorized");
		result.push_back(voterInfo);
		return result;
	}

	result.push_back("Done");
	result.push_back(voterInfo);
	return result;
}





