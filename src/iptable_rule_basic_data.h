#ifndef IPTABLE_RULE_BASIC_DATA_H
#define IPTABLE_RULE_BASIC_DATA_H


#include <iostream>
#include <string>
#include <sstream>      // std::stringstream
using namespace std;
 
/*
 * class name: iptable_rule_basic_data
 */
class iptable_rule_basic_data
{
	public:		
		iptable_rule_basic_data(const string& i_table, const string& i_command, const string& i_chain, const string& i_target="ACCEPT", const int& i_position=1);
		void print_rule_buffer();
		void resetData(const string& i_table, const string& i_command, const string& i_chain, const string& i_target="ACCEPT", const int& i_position=1);
		string& getBasicRule() {return basic_rule;}
		string& gettarget() {return target;}		
		void addToDestinationTargetData(const string& i_targetData);		

	protected:		
		string basic_rule;
		string target;
};

#endif /* IPTABLE_RULE_BASIC_DATA_H */