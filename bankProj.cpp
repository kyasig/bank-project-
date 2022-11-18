
#include <iostream>
#include "bank.h"
#include "subaccount.h"
using namespace std;
int main()
{
	subAccount sub1;
    checkingAccount sub2;

	sub1.deposit(69);
	//sub2.deposit(440);
	//sub2.withdraw(20);
	
	sub1.menu();
}
