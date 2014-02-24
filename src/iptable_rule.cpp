
#include "iptable_rule.h"

void iptable_rule::print_rule_buffer()
{
	cout<<rule_buffer<<endl;	
}

void iptable_rule::make_rule(iptable_rule_basic_data& i_iptable_rule_basic_data)
{
	rule_buffer.insert(0, i_iptable_rule_basic_data.getBasicRule());
	rule_buffer.append(" "+i_iptable_rule_basic_data.gettarget());
}

void iptable_rule::ToTargetIp(iptable_rule_basic_data& i_iptable_rule_basic_data, const string& targetIp)
{
	i_iptable_rule_basic_data.addToDestinationTargetData(targetIp);
	make_rule(i_iptable_rule_basic_data);
}

void iptable_rule::ByDport(iptable_rule_basic_data& i_iptable_rule_basic_data, const int& i_dport)
{
	ostringstream convert_dport;   // stream used for the conversion

	convert_dport << i_dport;
	rule_buffer.append(" --dport "+convert_dport.str());
	make_rule(i_iptable_rule_basic_data);
}
