
#include <iostream>
#include "bank.h"

int main(){
    cout <<"enter name of bank ";
	string bankname; cin >> bankname;
	cout << "enter address ";
	string addy; cin >> addy;
	cout <<"enter opening time ";
	string open; int intopen = validInput(open);
	cout <<"enter closing time ";
	string close; int intclose = validInput(close);

	bank b(bankname, addy, intopen, intclose);
	b.menu();
    
	cout << "testing thing";
    return 0;
}
