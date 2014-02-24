
#include "iptable_chain.h"

/*
Create chains: 

/relocated_bin/iptables -t nat -N NAT_PRE_PROTECTION_RULES
/relocated_bin/iptables -t nat -N NAT_PRE_SCG
/relocated_bin/iptables -t nat -N NAT_PRE_XDMZ
/relocated_bin/iptables -t nat -N NAT_PRE_PORT_FORWARDING
/relocated_bin/iptables -t nat -N NAT_PRE_DMZ
/relocated_bin/iptables -t filter -N FLT_FWD_PROTECTION_RULES 
/relocated_bin/iptables -t filter -N FLT_FWD_FIREWALL
*/
void iptable_chain::createChain(const string& i_table, const string& i_customChainName)
{
	iptable_rule_basic_data my_iptable_rule_basic_data(i_table, "N", i_customChainName);
	my_iptable_rule_basic_data.print_rule_buffer();
}

/*
Add chains references:
Add chain references to table=nat chain=PREROUTING:
/relocated_bin/iptables -t nat -A PREROUTING -j NAT_PRE_PROTECTION_RULES
/relocated_bin/iptables -t nat -A PREROUTING -j NAT_PRE_SCG
/relocated_bin/iptables -t nat -A PREROUTING -j NAT_PRE_XDMZ
/relocated_bin/iptables -t nat -A PREROUTING -j NAT_PRE_PORT_FORWARDING
/relocated_bin/iptables -t nat -A PREROUTING -j NAT_PRE_DMZ

Add chain references to table=filter chain=FORWARD:
/relocated_bin/iptables -t filter -A FORWARD -j FLT_FWD_PROTECTION_RULES
/relocated_bin/iptables -t filter -A FORWARD -j FLT_FWD_FIREWALL
*/
void iptable_chain::addReferenceToChain(const string& i_table, const string& i_defaultChainName, const string& i_customChainName)
{
	iptable_rule_basic_data my_iptable_rule_basic_data(i_table, "A", i_defaultChainName, i_customChainName);
	my_iptable_rule_basic_data.print_rule_buffer();
	make_rule(my_iptable_rule_basic_data);
	print_rule_buffer();
}