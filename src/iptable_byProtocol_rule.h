#ifndef IPTABLE_BYPROTOCOL_RULE_H
#define IPTABLE_BYPROTOCOL_RULE_H

#include "iptable_rule.h"

/*
 * class name: iptable_byProtocol_rule
 */
class iptable_byProtocol_rule : virtual public iptable_rule
{
	public:
		iptable_byProtocol_rule(const string& i_protocol);
};

#endif /* IPTABLE_BYPROTOCOL_RULE_H */