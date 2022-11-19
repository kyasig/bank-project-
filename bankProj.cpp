
#include <iostream>
#include "bank.h"
#include "subaccount.h"
#include <vector>
using namespace std;
int main()
{
	subAccount sub1;
    checkingAccount *sub2;
	//sub2.deposit(440);
	//sub2.withdraw(20);
	//sub1.menu();
	vector<subAccount *> subvec;
	//subvec.push_back(new checkingAccount());
	subvec.push_back(new subAccount());
	subvec.push_back(new checkingAccount());
	//subvec.at(0)->menu();
	subvec.at(1)->menu();
	//cout << sub1.getBalance();
}
