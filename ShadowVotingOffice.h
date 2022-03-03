#ifndef _SHADOWVOTINGOFFICE_H_
#define _SHADOWVOTINGOFFICE_H_

#include "VotingOffice.h"

using namespace std;

class ShadowVotingOffice: public VotingOffice
{
	public:
		ShadowVotingOffice(std::string, std::string, std::string, std::string);
		virtual vector<std::string> getAuthMessage(std::string, std::string, std::string);
		virtual vector<std::string> getReceipt(std::string, std::string, std::string);
};



#endif