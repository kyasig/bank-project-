
#include <iostream>
#include "bank.h"
#include "account.h"
#include <vector>

int main(){
    bankAccount cum("walter", "white", 1342324324	);
	cum.openCheckingSubAcc(5,5,"locked");
	cum.openSavingSubAcc(5);
	/*cum.printt();
	cout << endl;
	cum.deleteSubAcc();
	cum.printt();*/
	//cum.subAccs.at(0)->printBalance();
    
	cum.menu();

	return 0;
}
