#ifndef _VOTINGMACHINE_H
#define _VOTINGMACHINE_H

#include "Core.h"

#include <iostream>
#include <vector>

using namespace std;


class VotingMachine : public Core{
	private:
		int votingMachineID;
		int candidateA;
		int candidateB;
		
	public:
		VotingMachine(std::string, std::string, std::string, std::string);
		VotingMachine(std::string, std::string, std::string, std::string, int);
		virtual vector<std::string> sendVoterInfo(std::string);
		virtual vector<std::string> getBallot(std::string, std::string);
		virtual vector<std::string> sendVote(std::string, std::string);


};


#endif