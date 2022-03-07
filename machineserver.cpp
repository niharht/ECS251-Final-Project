

// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>
#include <vector>

// for JsonRPCCPP
#include <iostream>
#include "server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>

// ecs251
#include "Core.h"
#include "VotingMachine.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

class MyVotingMachineServer : public server
{
public:
  MyVotingMachineServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value SendVoterInfo(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);
  virtual Json::Value GetAuthMessage(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& machineId, const std::string& message, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);
  virtual Json::Value GetBallot(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& message, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);
  virtual Json::Value SendVote(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& object_id, const std::string& owner_vsID, const std::string& vote, const std::string& voterInfo);
  virtual Json::Value GetReceipt(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& machineId, const std::string& message, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);

};

MyVotingMachineServer::MyVotingMachineServer(AbstractServerConnector &connector, serverVersion_t type)
  : server(connector, type)
{
  std::cout << "MyVotingMachineServer Object created" << std::endl;
}


VotingMachine *vm1;

//implementation for sendVoterInfo
Json::Value MyVotingMachineServer::SendVoterInfo
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& object_id, 
  const std::string& owner_vsID, const std::string& voterInfo)
{


  std::cout << "calling SendVoterInfo ###Message 1####" << std::endl;
  std::cout << "voterInfo: " << voterInfo << std::endl;

  std::cout << "" << std::endl;


  Json::Value result;
  //std::cout << action << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  if ((class_id != "VotingMachine") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingMachine")
  strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else
  strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001"){
        s = vm1->sendVoterInfo(voterInfo);
        //cout<< "found message: ";
        //cout<< s[0] + " " + s[1] << endl;

      }
      
      std::string space = "";
      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"message\": \"" + s[0] + "\",");
      strJson += ("\"machineID\": \"" + s[1] + "\",");
      strJson += ("\"voterInfo\": \"" + s[2] + "\"}");
    }

  Json::CharReaderBuilder builder;
  Json::CharReader* reader = builder.newCharReader();
  std::string errors;
  bool parsingSuccessful = reader->parse
    (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
  delete reader;

  if (!parsingSuccessful) {
    std::cout << "Failed to parse the JSON, errors:" << std::endl;
    std::cout << s[0] << endl;
    std::cout << errors << std::endl;
    std::cout << strJson << std::endl;
  }

  return result;


}


//voting machine server doesn't use this function. can define as dummy
//NOT USING
Json::Value MyVotingMachineServer::GetAuthMessage
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& machineId, 
  const std::string& message, const std::string& object_id, 
  const std::string& owner_vsID, const std::string& voterInfo)
{

  std::cout << "getting AuthMessage" << std::endl;


  Json::Value result;
  std::cout << action << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  if ((class_id != "VotingMachine") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingMachine")
  strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else
  strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001"){
        //s = vm1->getAuthMessage(arguments);
        cout<< "found message: ";
        cout<< s[0] + " " + s[1] << endl;

      }
      
      std::string space = "";
      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"message\": \"" + s[0] + "\",");
      strJson += ("\"voterInfo\": \"" + s[1] + "\"}");
    }

  Json::CharReaderBuilder builder;
  Json::CharReader* reader = builder.newCharReader();
  std::string errors;
  bool parsingSuccessful = reader->parse
    (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
  delete reader;

  if (!parsingSuccessful) {
    std::cout << "Failed to parse the JSON, errors:" << std::endl;
    std::cout << s[0] << endl;
    std::cout << errors << std::endl;
    std::cout << strJson << std::endl;
  }

  return result;


}

//get ballot implementation
Json::Value MyVotingMachineServer::GetBallot
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& message, 
  const std::string& object_id, const std::string& owner_vsID, 
  const std::string& voterInfo)
{


  std::cout << "calling GetBallot ###Message 3####" << std::endl;

  std::cout << "message: " << message << std::endl;
  std::cout << "voterInfo: " << voterInfo << std::endl;

  std::cout << "" << std::endl;


  Json::Value result;
  //std::cout << action << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  if ((class_id != "VotingMachine") || ((object_id != "00000001")) || ((message != "Authorized")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingMachine")
          strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else if(object_id != "00000001")
          strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
      else if(message != "Authorized")
          strJson += ("\"reason\": \"message " + message + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001")
          s = vm1->getBallot(message, voterInfo);

      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"candidate1\": \"" + s[0]+ "\",");
      strJson += ("\"candidate2\": \"" + s[1]+ "\"}");

    }

  Json::CharReaderBuilder builder;
  Json::CharReader* reader = builder.newCharReader();
  std::string errors;
  bool parsingSuccessful = reader->parse
    (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
  delete reader;

  if (!parsingSuccessful) {
    std::cout << "Failed to parse the JSON, errors:" << std::endl;
    std::cout << errors << std::endl;
  }

  return result;

}



//send vote implementation
Json::Value MyVotingMachineServer::SendVote
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& object_id, 
  const std::string& owner_vsID, const std::string& vote, 
  const std::string& voterInfo)
{


  std::cout << "calling SendVote ###Message 5####" << std::endl;


  std::cout << "voted for : " << vote << std::endl;
  std::cout << "voterInfo: " << voterInfo << std::endl;

  std::cout << "" << std::endl;


  Json::Value result;
  //std::cout << action << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  if ((class_id != "VotingMachine") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingMachine")
          strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else if(object_id != "00000001")
          strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001")
          s = vm1->sendVote(vote, voterInfo);

      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"message\": \"" + s[0] + "\",");
      strJson += ("\"machineID\": \"" + s[1] + "\",");
      strJson += ("\"voterInfo\": \"" + s[2] + "\"}");
    }

  Json::CharReaderBuilder builder;
  Json::CharReader* reader = builder.newCharReader();
  std::string errors;
  bool parsingSuccessful = reader->parse
    (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
  delete reader;

  if (!parsingSuccessful) {
    std::cout << "Failed to parse the JSON, errors:" << std::endl;
    std::cout << errors << std::endl;
  }

  return result;

}


//GetReceipt NOT USED BY THIS CLASS
Json::Value MyVotingMachineServer::GetReceipt
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& machineId, 
  const std::string& message, const std::string& object_id, 
  const std::string& owner_vsID, const std::string& voterInfo)
{


  std::cout << "calling SendVote" << std::endl;


  Json::Value result;
  std::cout << action << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  if ((class_id != "VotingMachine") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingMachine")
          strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else if(object_id != "00000001")
          strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001")
          //s = vm1->sendVote(vote, voterInfo);

      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"message\": \"" + s[0] + "\",");
      strJson += ("\"voterInfo\": \"" + s[1] + "\"}");
    }

  Json::CharReaderBuilder builder;
  Json::CharReader* reader = builder.newCharReader();
  std::string errors;
  bool parsingSuccessful = reader->parse
    (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
  delete reader;

  if (!parsingSuccessful) {
    std::cout << "Failed to parse the JSON, errors:" << std::endl;
    std::cout << errors << std::endl;
  }

  return result;

}





int main() {

  VotingMachine votingMachineOne{"http://169.237.6.102", "1234567890", "VotingMachine", "00000001", 123};

  
  vm1 = (&votingMachineOne);
  

  HttpServer httpserver(8384);
  MyVotingMachineServer s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the another" << endl;
  getchar();

  s.StopListening();
  return 0;
}
