#include "VotingMachine.h"

using namespace std;

VotingMachine::VotingMachine(std::string core_arg_host_url, std::string core_arg_owner_vsID, std::string core_arg_class_id, std::string core_arg_object_id)
  : Core(core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id)
{
    cout << "VotingMachine Constructor" << endl;
}


VotingMachine::VotingMachine(std::string core_arg_host_url, std::string core_arg_owner_vsID, std::string core_arg_class_id, std::string core_arg_object_id, int votingMachineID)
  : Core(core_arg_host_url, core_arg_owner_vsID, core_arg_class_id, core_arg_object_id)
{

    this->votingMachineID = votingMachineID;
    this->candidateA = 0;
    this->candidateB = 0;
}


vector<std::string> VotingMachine::sendVoterInfo(std::string voterInfo){
    vector<std::string> result;
    result.push_back("requestingAuthorization");
    result.push_back(to_string(this->votingMachineID));
    result.push_back(voterInfo);


    return result;
}


vector<std::string> VotingMachine::getBallot(std::string message, std::string voterInfo){

    vector<std::string> result;

    if(message != "Authorized"){
      result.push_back("Nice try. You aren't authorized!");
      result.push_back(voterInfo);
      return result;
    }


    result.push_back("Candidate A");
    result.push_back("Candidate B");

    return result;

}

vector<std::string> VotingMachine::sendVote(std::string vote, std::string voterInfo){

  vector<std::string> result;

  if(vote == "Candidate A"){
    candidateA++;
  }else if(vote == "Candidate B"){
    candidateB++;
  }

  cout << "Count for candidate A is " << candidateA << endl;
  cout << "Count for candidate B is " << candidateB << endl;

  cout << "" << endl;

  result.push_back("hasVoted");
  result.push_back(to_string(this->votingMachineID));
  result.push_back(voterInfo);

  return result;


}

