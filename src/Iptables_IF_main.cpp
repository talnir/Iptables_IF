//============================================================================
// Name        : Iptables_IF.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "iptable_IF.h"

int main ()
{
  string mystr;

  iptable_IF my_iptable_IF;
  my_iptable_IF.IPT_p_init_chains_per_policy();
  my_iptable_IF.IPT_p_Add_DMZ_rule("10.1.1.121", false, false,false); /* instead of bool it will be enum*/

  getline (cin, mystr);
  return 0;
}
