#ifndef account_H
#define account_H
#include "subaccount.h"
#include <vector>
#include <algorithm>
//using namespace std;
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
        void printt(){
            for(auto i : this->subAccs){
                cout << i->getNum() << " ";
            }
        }
};

////helpers //////////////////////////////////////////////////////////////////////////

bool balanceComp(subAccount *s, subAccount *s2){
    return s->getBalance()  > s2->getBalance();
}

subAccount* searchSubAcc(string num, vector<subAccount*> vec){
    for (auto i : vec){
        if(i->getNum().compare(num) == 0){
            return i;
        }
    }
    return nullptr;
}
///////////////////////////////////////////////////////////////////////////
void bankAccount :: deleteSubAcc(){
    auto bruh = this->subAccs.front();
    delete bruh;
    this->subAccs.erase(this->subAccs.begin(), this->subAccs.begin()+1);
}


#endif