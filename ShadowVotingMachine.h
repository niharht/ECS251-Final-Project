#ifndef _SHADOWVOTINGMACHINE_H_
#define _SHADOWVOTINGMACHINE_H_

#include "VotingMachine.h"
#include <vector>

using namespace std;

class ShadowVotingMachine: public VotingMachine
{
	private:
	public:
		ShadowVotingMachine(std::string, std::string, std::string, std::string);
		virtual vector<std::string> sendVoterInfo(std::string);
		virtual vector<std::string> getBallot(std::string, std::string);
		virtual vector<std::string> sendVote(std::string, std::string);
};



#endif