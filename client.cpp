
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>
#include <vector>

// for JsonRPCCPP
#include <iostream>
//#include "client.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>

// ecs251
/*
#include "Core.h"
#include "Person.h"
#include "Transaction.h"
#include "Shadow_Flight.h"
#include "Shadow_Person.h"
#include <time.h>
*/

#include "Voter.h"
#include "ShadowVotingMachine.h"
#include "ShadowVotingOffice.h"

using namespace jsonrpc;
using namespace std;


int
main()
{


  Voter voter0{"http://localhost:8386", "1234567890", "Voter", "00000001", "Wu", 0};
  Voter voter1{"http://localhost:8386", "1234567890", "Voter", "00000002", "May", 1};


  ShadowVotingMachine svm1 { "http://localhost:8384", "1234567890", "VotingMachine", "00000001" };

  ShadowVotingOffice svo1 { "http://localhost:8385", "1234567890", "VotingOffice", "00000001" };

  cout << "" << endl;
  cout << "Now trying to vote for authorized voter" << endl;

  cout << "Printing result of sendVoterInfo for authorized voter . ###Message 2####" << endl;
  vector<std::string> msg2 = svm1.sendVoterInfo(voter0.getVoterInfo());

  cout << "" << endl;

  cout << "Printing the result of getAuthMessage. ###Message 3####" << endl;
  vector<std::string> msg3 = svo1.getAuthMessage(msg2[0], msg2[1], msg2[2]);

  if(msg3[0] != "Authorized"){
    cout << "Thanks for trying. You aren't authorized. Goodbye" << endl;
    return 0;
  }

  cout << "" << endl;

  cout << "Printing the result of getBallot ###Message 4###" << endl;
  vector<std::string> msg4 = svm1.getBallot(msg3[0], msg3[1]);

  cout << "" << endl;


  cout << "Printing the result of sendVote ###Message 6####" << endl;
  vector<std::string> msg6 = svm1.sendVote("Candidate A", voter0.getVoterInfo());

  cout << "" << endl;

  cout << "Printing the result of getReceipt ###Message 7####" << endl;
  vector<std::string> msg7 = svo1.getReceipt(msg6[0], msg6[1], msg6[2]);

  cout << "" << endl;



  //unauthorized voter May
  cout << "Now trying to vote for unauthorized voter" << endl;
  cout << "" << endl;

  cout << "Printing result of sendVoterInfo for unauthorized voter. ###Message 2####" << endl;
  msg2 = svm1.sendVoterInfo(voter1.getVoterInfo());

  cout << "" << endl;

  cout << "Printing the result of getAuthMessage for unauthorized voter. ###Message 3####" << endl;
  msg3 = svo1.getAuthMessage(msg2[0], msg2[1], msg2[2]);

  cout << "" << endl;

  if(msg3[0] != "Authorized"){
    cout << "Thanks for trying. You aren't authorized. Goodbye" << endl;
    return 0;
  }



  return 0;
}
