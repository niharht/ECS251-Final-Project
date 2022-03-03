
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


  Voter voter1{"http://localhost:8386", "1234567890", "Voter", "00000001", "Wu", 0};
  Voter voter2{"http://localhost:8386", "1234567890", "Voter", "00000002", "May", 1};


  ShadowVotingMachine svm1 { "http://localhost:8384", "1234567890", "VotingMachine", "00000001" };
  //std::cout << ((Person&) sp1).getVsID() << std::endl;

  ShadowVotingOffice svo1 { "http://localhost:8385", "1234567890", "VotingOffice", "00000001" };


  /*
  // Person, Shadow_Person
  Person *p1_ptr = (Person *) (&sp1);

  Person *p1_ptr = (Person *) ((Shadow_Person *) &sp1);
  void *gen_ptr_1 = (void *) (&sp1);
  void *gen_ptr_2 = (void *) ((Person *) (&sp1));
  */

  
  // Shadow_Person sp2 { "http://localhost:8384", "1234567890", "Person", "00000006" };
  // std::cout << ((Person&) sp2).getVsID() << std::endl;
  // Shadow_Person sp3 { "http://localhost:8385", "1234567890", "Person", "00000006" };
  // std::cout << ((Person&) sp3).getVsID() << std::endl;

  /*

  Shadow_Flight sf3 { "http://localhost:8384", "1234567890", "Flight", "00000003" };
  std::cout << std::to_string(((Flight&) sf3).getDistance()) << std::endl;

  Shadow_Flight sf2 { "http://localhost:8384", "1234567890", "Flight", "00000002" };
  std::cout << std::to_string(sf2.getDistance()) << std::endl;

  Shadow_Flight sf1 { "http://localhost:8384", "1234567890", "Flight", "00000001" };
  std::cout << std::to_string(sf1.getDistance()) << std::endl;

  if (sp1 == sp2) printf("sp1 and sp2 are equal\n");
  if (sp1 == sp3) printf("sp1 and sp3 are equal\n");
  if (sp1 == sp1) printf("sp1 and sp1 are equal\n");
  if (sp2 == sp3) printf("sp2 and sp3 are equal\n");

  if (sf1.Conflict_of_Interest()) printf("sf1 coi\n");
  if (sf2.Conflict_of_Interest()) printf("sf2 coi\n");
  if (sf3.Conflict_of_Interest()) printf("sf3 coi\n");

  */


  //svm1.setVoterInfo(voter1.getInfo());

  vector<std::string> msg2 = svm1.sendVoterInfo(voter1.getVoterInfo());

  cout << "Printing the message 2" << endl;
  cout << msg2[0] << endl;
  cout << msg2[1] << endl;
  cout << msg2[2] << endl;

  vector<std::string> msg3 = svo1.getAuthMessage(msg2[0], msg2[1], msg2[2]);
  cout << "Printing the message 3" << endl;
  cout << msg3[0] << endl;
  cout << msg3[1] << endl;
  //cout << msg1[2] << endl;

  vector<std::string> msg4 = svm1.getBallot(msg3[0], msg3[1]);
  cout << "Printing the message 4" << endl;
  cout << msg4[0] << endl;

  vector<std::string> msg6 = svm1.sendVote("Candidate A", voter1.getVoterInfo());
  cout << "Printing the message 6" << endl;
  cout << msg6[0] << endl;
  cout << msg6[1] << endl;
  cout << msg6[2] << endl;

  vector<std::string> msg7 = svo1.getReceipt(msg6[0], msg6[1], msg6[2]);
  cout << "Printing the message 7" << endl;
  cout << msg7[0] << endl;
  cout << msg7[1] << endl;


  return 0;
}
