#ifndef account_H
#define account_H
#include "subaccount.h"
#include <vector>
#include <algorithm>
//using namespace std;
static int uniqueNumm = 1000;
class bankAccount{
    private:
        string uniqueNum;
        string name[2];
        int ssn;
       // vector <subAccount *> subAccs;
    public:
        vector <subAccount *> subAccs;
        void openSavingSubAcc(unsigned int initBal){
            this->subAccs.push_back(new subAccount(initBal));
            }
        void openCheckingSubAcc(unsigned int bal, int initMax, string initState){
            this->subAccs.push_back(new checkingAccount());
            }
        void deleteSubAcc();
        void modifySubAcc(string num);
       // void detailDisplay();
       // void briefDisplay();
        void menu();
        void getSize(){std::cout << this->subAccs.size();}
        bankAccount(){
            this-> uniqueNum = "";
            //this-> name = {};
            this-> ssn = 0;
        }
        bankAccount(string firstName, string lastName, int ssn);
};

////helpers //////////////////////////////////////////////////////////////////////////

bool balanceComp(subAccount *s, subAccount *s2){
    return s->getBalance()  > s2->getBalance();
}

subAccount* searchSubAcc(string num, vector<subAccount*> vec){
    for (auto i : vec){
        if(i->getNum() == num){
            return i;
        }
    }
    return nullptr;
}
///////////////////////////////////////////////////////////////////////////
bankAccount :: bankAccount(string firstName, string lastName, int ssn){
    this->name[0] = firstName;
    this->name[1] = lastName;
    this->ssn = ssn;
    this->uniqueNum = "BNK" + to_string(uniqueNumm++);
}
void bankAccount :: deleteSubAcc(){
    auto bruh = this->subAccs.front();
    delete bruh;
    this->subAccs.erase(this->subAccs.begin(), this->subAccs.begin()+1);
}

void bankAccount :: modifySubAcc(string num){
    searchSubAcc(num, this->subAccs)->menu();
}

void bankAccount :: menu(){
    while (true){
        cout << "options for " <<this->uniqueNum << "\nS -- open saving acc\nC -- open checking acc\nM -- modify subAcc\nC -- close a sub account\nD -- detail info\nB -- brief info\nX -- exit";
        //lol
        cout << endl <<"enter response: ";
        char input;
        cin >> input; 
        if(tolower(input) == 'x'){
             return; 
        }
        else if(tolower(input) == 's'){
            cout << "enter initial balance: ";
            string bal;
            this->subAccs.push_back(new subAccount(validInput(bal)));
        }
        else if(tolower(input) == 'c'){
            cout << "enter initial balance: ";
            string bal; int vbal = validInput(bal);
            cout << "enter initial max: ";
            string max; int vmax = validInput(max);
            cout << "enter initial balanc, max, and state: ";
            string state; cin >> state;
            this->subAccs.push_back(new checkingAccount(vbal,vmax,state));
        }
        else if(tolower(input) == 'm'){
            cout << "enter name of account";
            string acc;
            cin >> acc;
            this->modifySubAcc(acc);
        }
        
    }
}

#endif