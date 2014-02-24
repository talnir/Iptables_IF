#ifndef IPTABLE_BYINPUTIF_AND_BYPROTOCOL_RULE_H
#define IPTABLE_BYINPUTIF_AND_BYPROTOCOL_RULE_H

#include "iptable_byProtocol_rule.h"
#include "iptable_byInputIF_rule.h"

/*
 * class name: iptable_byInputIF_And_byProtocol_rule
 */
class iptable_byInputIF_And_byProtocol_rule : public iptable_byProtocol_rule, iptable_byInputIF_rule
{
	public:
		iptable_byInputIF_And_byProtocol_rule(string i_protocol, string i_inputInterface):iptable_byProtocol_rule(i_protocol), iptable_byInputIF_rule(i_inputInterface) {}		
		void resetData(const string& i_protocol, const string& i_inputInterface) {rule_buffer.clear(); rule_buffer.append(" -p "+i_protocol); rule_buffer.append(" -i "+i_inputInterface);}
};

#endif /* IPTABLE_BYINPUTIF_AND_BYPROTOCOL_RULE_H */