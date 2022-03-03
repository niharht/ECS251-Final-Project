#include "ShadowVotingOffice.h"


// JSOn RPC part
#include <stdlib.h>
#include "client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

ShadowVotingOffice::ShadowVotingOffice
(std::string arg_host_url, std::string arg_vsID, std::string arg_class_id, std::string arg_object_id) : VotingOffice(arg_host_url, arg_vsID, arg_class_id, arg_object_id)
{
  std::cout << "Shadow Voting Office created" << std::endl;
}


/*
bool ShadowVotingOffice::setAuthMessage(vector<std::string> arg){

	HttpClient httpclient((this->host_url).c_str());
  	client myClient(httpclient, JSONRPC_CLIENT_V2);
  	Json::Value myv;

  	try{

    	std::cout << "calling setAuthMessage" << std::endl;

    	myv = myClient.SetAuthMessage("sendAuthMessage", arg[0] + " " + arg[1], (this->class_id).c_str(),
                           (this->host_url).c_str(), (this->object_id).c_str(), (this->owner_vsID).c_str());

    	cout << myv.toStyledString() << endl;


  	} catch (JsonRpcException &e) {
    	cerr << e.what() << endl;
  	}


  	//return (myv["msg"]).asString();
    //fixme
    return true;

}*/


vector<std::string> ShadowVotingOffice::getAuthMessage(std::string message, std::string machineId, std::string voterInfo){

  vector<std::string> result;

	HttpClient httpclient((this->host_url).c_str());
  	client myClient(httpclient, JSONRPC_CLIENT_V2);
  	Json::Value myv;

  	try{

    	std::cout << "calling getAuthMessage" << std::endl;

    	myv = myClient.GetAuthMessage("GetAuthMessage", (this->class_id).c_str(),
                           (this->host_url).c_str(), machineId,
                           message, (this->object_id).c_str(), 
                           (this->owner_vsID).c_str(), voterInfo);

    	cout << myv.toStyledString() << endl;


  	} catch (JsonRpcException &e) {
    	cerr << e.what() << endl;
  	}


  	result.push_back((myv["message"]).asString());
    result.push_back((myv["voterInfo"]).asString());

    return result;
}


vector<std::string> ShadowVotingOffice::getReceipt(std::string message, std::string machineId, std::string voterInfo){

  vector<std::string> result;

  HttpClient httpclient((this->host_url).c_str());
    client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;

    try{

      std::cout << "calling getReceipt" << std::endl;

      myv = myClient.GetReceipt("GetReceipt", (this->class_id).c_str(),
                           (this->host_url).c_str(), machineId,
                           message, (this->object_id).c_str(), 
                           (this->owner_vsID).c_str(), voterInfo);

      cout << myv.toStyledString() << endl;


    } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }


    result.push_back((myv["message"]).asString());
    result.push_back((myv["voterInfo"]).asString());

    return result;
}


