#ifndef IPTABLE_IF_H
#define IPTABLE_IF_H


#include "iptable_IF.h"
#include "iptable_rule_basic_data.h"
#include "iptable_chain.h"
#include "iptable_byInputIF_And_byProtocol_rule.h"
/*
 * class name: iptable_IF
 */
class iptable_IF
{
	public:
		void IPT_p_init_chains_per_policy();
		void IPT_p_Add_DMZ_rule(const string& i_DmzIP, bool i_PingToDmz,  bool i_WebToDmz, bool i_SshToDmz);
};

#endif /* IPTABLE_IF_H */