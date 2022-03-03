

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
#include "VotingOffice.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

class MyOfficeServer : public server
{
public:
  MyOfficeServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value SendVoterInfo(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);
  virtual Json::Value GetAuthMessage(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& machineId, const std::string& message, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);
  virtual Json::Value GetBallot(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& message, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);
  virtual Json::Value SendVote(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& object_id, const std::string& owner_vsID, const std::string& vote, const std::string& voterInfo);
  virtual Json::Value GetReceipt(const std::string& action, const std::string& class_id, const std::string& host_url, const std::string& machineId, const std::string& message, const std::string& object_id, const std::string& owner_vsID, const std::string& voterInfo);

private:
  vector<std::string> parseString(std::string arg);
};

MyOfficeServer::MyOfficeServer(AbstractServerConnector &connector, serverVersion_t type)
  : server(connector, type)
{
  std::cout << "MyOfficeServer Object created" << std::endl;
}


VotingOffice *vo1;


vector<std::string> MyOfficeServer::parseString(std::string arg){

    vector<std::string> result;
    std::stringstream ss(arg);
    std::string word;
    while (ss >> word) {
        //cout << word << endl;
      result.push_back(word);
    }

    return result;
}

/*
Json::Value MyOfficeServer::GetAuthMessage
(const std::string& action, const std::string& arguments, 
 const std::string& class_id, const std::string& host_url, 
 const std::string& object_id, const std::string& owner_vsID)
{

  std::cout << "getting AuthMessage" << std::endl;


  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;
  std::string strJson;

  string s = "";
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
      //if (object_id == "00000001")
          //s = vm1->getAuthMessage();

      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"message\": " + s + "}");
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

Json::Value MyOfficeServer::SetAuthMessage
(const std::string& action, const std::string& arguments, 
 const std::string& class_id, const std::string& host_url, 
 const std::string& object_id, const std::string& owner_vsID)
{


  std::cout << "setting AuthMessage" << std::endl;


  Json::Value result;
  std::cout << action << " " << arguments << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  bool b;


  //parse the arguments and add as vector to pass to setAuthMessage
  s = parseString(arguments);

  if ((class_id != "VotingOffice") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingOffice")
  strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else
  strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001")
          b = vo1->setAuthMessage(s);

      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"result\": " + to_string(b) + "}");
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
*/


//implementation for sendVoterInfo
//not used by this class
Json::Value MyOfficeServer::SendVoterInfo
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& object_id, 
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
        //s = vm1->SendVoterInfo(voterInfo);
        cout<< "found message: ";
        cout<< s[0] + " " + s[1] << endl;

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


//implementation for GetAuthMessage
Json::Value MyOfficeServer::GetAuthMessage
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
  if ((class_id != "VotingOffice") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingOffice")
          strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else
          strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001"){
        s = vo1->getAuthMessage(message, machineId, voterInfo);
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
//not used by this class
Json::Value MyOfficeServer::GetBallot
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& message, 
  const std::string& object_id, const std::string& owner_vsID, 
  const std::string& voterInfo)
{


  std::cout << "calling GetBallot" << std::endl;


  Json::Value result;
  std::cout << action << " " << owner_vsID << std::endl;
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
          //s = vm1->getBallot();

      strJson += "{\"status\" : \"successful\", ";
      strJson += ("\"candidate1\": " + s[0]+ "}");
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
//not used by this class
Json::Value MyOfficeServer::SendVote
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& object_id, 
  const std::string& owner_vsID, const std::string& vote, 
  const std::string& voterInfo)
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


//implementation of GetReceipt
Json::Value MyOfficeServer::GetReceipt
(const std::string& action, const std::string& class_id, 
  const std::string& host_url, const std::string& machineId, 
  const std::string& message, const std::string& object_id, 
  const std::string& owner_vsID, const std::string& voterInfo)
{


  std::cout << "calling GetReceipt" << std::endl;


  Json::Value result;
  std::cout << action << " " << owner_vsID << std::endl;
  std::string strJson;

  vector<std::string> s;
  if ((class_id != "VotingOffice") || ((object_id != "00000001")))
    {
      strJson += "{\"status\" : \"failed\", ";
      if (class_id != "VotingOffice")
          strJson += ("\"reason\": \"class " + class_id + " unknown\"}");
      else if(object_id != "00000001")
          strJson += ("\"reason\": \"object " + object_id + " unknown\"}");
    }
  else
    {
      if (object_id == "00000001")
          s = vo1->getReceipt(message, machineId, voterInfo);

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

  VotingOffice votingOfficeOne{"http://169.237.6.102", "1234567890", "VotingOffice", "00000001",
                                  "Yolo County"};

  
  vo1 = (&votingOfficeOne);
  

  HttpServer httpserver(8385);
  MyOfficeServer s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the another" << endl;
  getchar();

  s.StopListening();
  return 0;
}
