#ifndef IPTABLE_BYINPUTIF_RULE_H
#define IPTABLE_BYINPUTIF_RULE_H

#include "iptable_rule.h"

/*
 * class name: iptable_byInputIF_rule
 */
class iptable_byInputIF_rule : virtual public iptable_rule
{
	public:
		iptable_byInputIF_rule(const string& i_inputInterface);
};

#endif /* IPTABLE_BYINPUTIF_RULE_H */