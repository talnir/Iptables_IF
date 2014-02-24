#ifndef IPTABLE_CHAIN_H
#define IPTABLE_CHAIN_H

#include "iptable_rule.h"

/*
 * class name: iptable_chain
 */
class iptable_chain : virtual public iptable_rule
{
	public:
		//void iptable_chain(const string& i_DmzIP, bool i_PingToDmz,  bool i_WebToDmz, bool i_SshToDmz);
		void createChain(const string& i_table, const string& i_customChainName);
		void addReferenceToChain(const string& i_table, const string& i_defaultChainName, const string& i_customChainName);
};

#endif /* IPTABLE_CHAIN_H */