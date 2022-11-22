
#include <iostream>
#include "bank.h"
#include "subaccount.h"
#include <vector>
using namespace std;
int main()
{
	vector<subAccount*> s;
	//subvec.push_back(new checking((Account());
	s.push_back(new checkingAccount());
	subAccount cum;
	//cum.menu();
    s.at(0)->menu();
	return 0;
}
