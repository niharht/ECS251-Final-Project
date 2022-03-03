#include "ShadowVotingMachine.h"


// JSOn RPC part
#include <stdlib.h>
#include "client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

ShadowVotingMachine::ShadowVotingMachine(std::string arg_host_url, std::string arg_vsID, std::string arg_class_id, std::string arg_object_id)
  : VotingMachine(arg_host_url, arg_vsID, arg_class_id, arg_object_id)
{
  std::cout << "Shadow Voting Machine created" << std::endl;
}

/*
void ShadowVotingOffice::setAuthMessage(string msg){

	HttpClient httpclient((this->host_url).c_str());
  	client myClient(httpclient, JSONRPC_CLIENT_V2);
  	Json::Value myv;

  	try{

    	std::cout << "calling setAuthMessage" << std::endl;

    	myv = myClient.setAuthMessage("setAuthMessage", "This is a Voting Office JSON string!", (this->class_id).c_str(),
                           (this->host_url).c_str(), (this->object_id).c_str(), (this->owner_vsID).c_str());

    	cout << myv.toStyledString() << endl;


  	} catch (JsonRpcException &e) {
    	cerr << e.what() << endl;
  	}


  	//return (myv["msg"]).asString();

}*/

//implementing sendVoterInfo
vector<std::string> ShadowVotingMachine::sendVoterInfo(std::string voterInfo){

  vector<std::string> result; 

  HttpClient httpclient((this->host_url).c_str());
    client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;

    try{

      std::cout << "calling sendVoterInfo" << std::endl;

      myv = myClient.SendVoterInfo("sendVoterInfo", (this->class_id).c_str(),
                           (this->host_url).c_str(), (this->object_id).c_str(), 
                           (this->owner_vsID).c_str(), voterInfo);

      cout << myv.toStyledString() << endl;


    } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }

    result.push_back((myv["message"]).asString());
    result.push_back((myv["machineID"].asString()));
    result.push_back((myv["voterInfo"].asString()));
    return result;




}

//implementing getBallot
vector<std::string> ShadowVotingMachine::getBallot(std::string message, std::string voterInfo){

  vector<std::string> result; 

  HttpClient httpclient((this->host_url).c_str());
    client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;

    try{

      std::cout << "calling getBallot" << std::endl;

      myv = myClient.GetBallot("GetBallot", (this->class_id).c_str(),
                           (this->host_url).c_str(), message,
                           (this->object_id).c_str(), 
                           (this->owner_vsID).c_str(), voterInfo);

      cout << myv.toStyledString() << endl;


    } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }

    result.push_back((myv["candidate1"]).asString());
    return result;

}



//implementing getBallot
vector<std::string> ShadowVotingMachine::sendVote(std::string vote, std::string voterInfo){

  vector<std::string> result; 

  HttpClient httpclient((this->host_url).c_str());
    client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;

    try{

      std::cout << "calling sendVote" << std::endl;

      myv = myClient.SendVote("SendVote", (this->class_id).c_str(),
                           (this->host_url).c_str(),
                           (this->object_id).c_str(), 
                           (this->owner_vsID).c_str(), 
                           vote, voterInfo);

      cout << myv.toStyledString() << endl;


    } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }

    result.push_back((myv["message"]).asString());
    result.push_back((myv["machineID"]).asString());
    result.push_back((myv["voterInfo"]).asString());
    return result;




}
