#ifndef _VOTINGOFFICE_H_
#define _VOTINGOFFICE_H_

#include "Core.h"

#include <iostream>
#include <set>
#include <vector>

using namespace std;


class VotingOffice : public Core{
	private:
		std::string votingOfficeName;
		set<std::string> registeredVoters;
	public:
		VotingOffice(std::string, std::string, std::string, std::string);
		VotingOffice(std::string, std::string, std::string, std::string, std::string);
		virtual vector<std::string> getAuthMessage(std::string, std::string, std::string);
		virtual vector<std::string> getReceipt(std::string, std::string, std::string);
};




#endif