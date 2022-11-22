
#include <iostream>
#include "bank.h"
#include "subaccount.h"
#include <vector>
using namespace std;
int main()
{
	vector<subAccount*> s;
	s.push_back(new subAccount());
	s.push_back(new checkingAccount());
    s.at(0)->menu();
	s.at(1)->menu();
	return 0;
}
