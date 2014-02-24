
#include "iptable_byInputIF_rule.h"

iptable_byInputIF_rule::iptable_byInputIF_rule(const string& i_inputInterface)
{
	 rule_buffer.append(" -i "+i_inputInterface);  
}