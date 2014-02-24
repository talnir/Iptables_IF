#ifndef IPTABLE_RULE_H
#define IPTABLE_RULE_H

// iptable_IF.cpp : Defines the entry point for the application.
#include "iptable_rule_basic_data.h"

/*
 * class name: iptable_rule
 */
class iptable_rule
{
	public:				
		void print_rule_buffer();
		void make_rule(iptable_rule_basic_data& i_iptable_rule_basic_data);
		void ToTargetIp(iptable_rule_basic_data& i_iptable_rule_basic_data, const string& targetIp);
		void ByDport(iptable_rule_basic_data& i_iptable_rule_basic_data, const int& i_dport);

	protected:		
		string rule_buffer;		
};

#endif /* IPTABLE_RULE_H */