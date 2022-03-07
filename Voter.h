#ifndef _VOTER_H
#define _VOTER_H


#include "Core.h"
#include <iostream>
using namespace std;


class Voter : public Core{
	private:
		int voterId;
		std::string name;

	public:
		Voter(std::string, std::string, std::string, std::string);
		Voter(std::string, std::string, std::string, std::string, std::string, int);
		int getVoterId();
		std::string getName();
		std::string getVoterInfo();



};







#endif /*_VOTER_H*/
