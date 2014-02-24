
#include "iptable_byProtocol_rule.h"

iptable_byProtocol_rule::iptable_byProtocol_rule(const string& i_protocol)
{
	rule_buffer.append(" -p "+i_protocol);  
}