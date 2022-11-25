
#include <iostream>
#include "bank.h"
#include "account.h"
#include <vector>

int main(){
    bankAccount cum;
	cum.openCheckingSubAcc(5,5,"locked");
	cum.openSavingSubAcc(5);
	cum.printt();
	cout << endl;
	cum.deleteSubAcc();
	cum.printt();
	//cum.subAccs.at(0)->printBalance();

	return 0;
}
