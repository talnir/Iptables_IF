// iptable_IF.cpp : Defines the entry point for the application.

#include "iptable_IF.h"
#include "iptable_rule_basic_data.h"
#include "iptable_chain.h"
#include "iptable_byInputIF_And_byProtocol_rule.h"

void iptable_IF::IPT_p_init_chains_per_policy()
{
	iptable_chain my_iptable_chain;
	my_iptable_chain.createChain("nat", "NAT_PRE_PROTECTION_RULES");
	my_iptable_chain.addReferenceToChain("nat", "PREROUTING", "NAT_PRE_PROTECTION_RULES");
}

/*	NAT_PRE_DMZ:
/relocated_bin/iptables -t nat -A NAT_PRE_DMZ -p icmp -i usb0 -j ACCEPT
/relocated_bin/iptables -t nat -A NAT_PRE_DMZ -p tcp --dport 80 -i usb0 -j ACCEPT
/relocated_bin/iptables -t nat -A NAT_PRE_DMZ -p tcp --dport 22 -i usb0 -j ACCEPT
/relocated_bin/iptables -t nat -A NAT_PRE_DMZ -p all -i usb0 -j DNAT --to-destination DMZ_IP
*/
void iptable_IF::IPT_p_Add_DMZ_rule(const string& i_DmzIP, bool i_PingToDmz, bool i_WebToDmz, bool i_SshToDmz)
{
	if (false==i_PingToDmz)
	{
		iptable_rule_basic_data my_iptable_rule_basic_data("nat", "A", "NAT_PRE_DMZ", "ACCEPT");
		iptable_byInputIF_And_byProtocol_rule my_iptable_byInputIF_And_byProtocol_rule("icmp", "usb0");		
		my_iptable_byInputIF_And_byProtocol_rule.make_rule(my_iptable_rule_basic_data);
        my_iptable_byInputIF_And_byProtocol_rule.print_rule_buffer();
	}

	if (false==i_WebToDmz)
	{
		iptable_rule_basic_data my_iptable_rule_basic_data("nat", "A", "NAT_PRE_DMZ", "ACCEPT");
		iptable_byInputIF_And_byProtocol_rule my_iptable_byInputIF_And_byProtocol_rule("tcp", "usb0");		
		my_iptable_byInputIF_And_byProtocol_rule.ByDport(my_iptable_rule_basic_data, 80);		
        my_iptable_byInputIF_And_byProtocol_rule.print_rule_buffer();
	} 

	if (false==i_SshToDmz)
	{
		iptable_rule_basic_data my_iptable_rule_basic_data("nat", "A", "NAT_PRE_DMZ", "ACCEPT");
		iptable_byInputIF_And_byProtocol_rule my_iptable_byInputIF_And_byProtocol_rule("tcp", "usb0");		
		my_iptable_byInputIF_And_byProtocol_rule.ByDport(my_iptable_rule_basic_data, 22);		
        my_iptable_byInputIF_And_byProtocol_rule.print_rule_buffer();
	}

	// command: /relocated_bin/iptables -t nat -A NAT_PRE_DMZ -p all -i usb0 -j DNAT --to-destination DMZ_IP
	iptable_rule_basic_data my_iptable_rule_basic_data("nat", "A", "NAT_PRE_DMZ", "DNAT");
	iptable_byInputIF_And_byProtocol_rule my_iptable_byInputIF_And_byProtocol_rule("all", "usb0");	
	my_iptable_byInputIF_And_byProtocol_rule.ToTargetIp(my_iptable_rule_basic_data, i_DmzIP);	
	my_iptable_byInputIF_And_byProtocol_rule.print_rule_buffer();
}
