
#include "iptable_rule_basic_data.h"

void iptable_rule_basic_data::print_rule_buffer()
{
	cout<<"basic_rule: "<<basic_rule<<endl;	
	cout<<"target: "<<target<<endl;		
}

iptable_rule_basic_data::iptable_rule_basic_data(const string& i_table, const string& i_command, const string& i_chain, const string& i_target, const int& i_position)
{
	resetData(i_table, i_command, i_chain, i_target, i_position);
}

// building basic command:  /relocated_bin/iptables -t <i_table> -<i_command> <i_chain> <i_position>
void iptable_rule_basic_data::resetData(const string& i_table, const string& i_command, const string& i_chain, const string& i_target, const int& i_position)
{		
	basic_rule.clear();
	target.clear();
	if (i_command.compare("N")==0)
	{
		basic_rule.append("/relocated_bin/iptable -t "+i_table+" -"+i_command+" "+i_chain);
		return;
	}
    if (i_command.compare("I")==0)
	{
		ostringstream convert_position;   // stream used for the conversion
		convert_position << i_position;
		basic_rule.append("/relocated_bin/iptable -t "+i_table+" -"+i_command+" "+i_chain+" "+ convert_position.str());
	}
	else
	{
		basic_rule.append("/relocated_bin/iptable -t "+i_table+" -"+i_command+" "+i_chain);
	}	
	target.append(" -j "+i_target);
}

//--to-destination
void iptable_rule_basic_data::addToDestinationTargetData(const string& i_targetData)
{	
	target.append(" --to-destination "+i_targetData);
}