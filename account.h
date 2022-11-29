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
        //vector <subAccount *> subAccs;
    public:
        vector <subAccount *> subAccs;
        void openSavingSubAcc(unsigned int initBal){
            this->subAccs.push_back(new subAccount(initBal));
            }
        void openCheckingSubAcc(unsigned int bal, int initMax, string initState){
            this->subAccs.push_back(new checkingAccount());
            }
        void deleteSubAcc(string id);
        void modifySubAcc(string num);
        void detailDisplay();
        int getSubs(){return this->subAccs.size();}
        void menu();
        string getNum(){return this->uniqueNum;}
        void getSize(){std::cout << this->subAccs.size();}
        int getBalance(){
            int sum = 0;
            for(auto i : subAccs){
                sum += i->getBalance();
            }
            return sum;
        }
        bankAccount(){
            this-> uniqueNum = "";
            //this-> name = {};
            this-> ssn = 0;
        }
        bankAccount(string firstName, string lastName, int ssn);
};

////helpers //////////////////////////////////////////////////////////////////////////
template <typename t>
int searchAcc(string num, vector<t*> vec){ //returns the index of desired subaccount
    for (int i = 0; i < vec.size(); i++){
        if(vec.at(i)->getNum() == num){
            return i;
        }
    }
    return -1;
}
template <typename t>
void bankSorter(vector <t *> &vec){ //chose insertion sort due to low expected amount of data
    int i = 0;
    int j = 0;
    t *temp;
    for(i = 1; i < vec.size(); i++){
        j = i;
        while(j > 0 && vec.at(j)->getBalance() < vec.at(j-1)->getBalance()){
            temp = vec.at(j);
            vec.at(j) = vec.at(j-1);
            vec.at(j-1) = temp;
            j--;
        }
    }
}

///////////////////////////////////////////////////////////////////////////
bankAccount :: bankAccount(string firstName, string lastName, int ssn){
    this->name[0] = firstName;
    this->name[1] = lastName;
    this->ssn = ssn;
    this->uniqueNum = "BNK" + to_string(uniqueNumm++);
}
void bankAccount :: deleteSubAcc(string id){
    int i = searchAcc(id, this->subAccs);
    auto itr = this->subAccs.begin() + i;
    if(i != -1){
        delete this->subAccs.at(i);
        this->subAccs.erase(itr);
    }else{
        cout << "subacc dont exist";
    }
}

void bankAccount :: modifySubAcc(string num){
    this->subAccs.at(searchAcc(num, this->subAccs))->menu();
}

void bankAccount :: detailDisplay(){
    bankSorter(this->subAccs);
    for(auto i : this->subAccs){
        cout << i->getNum() << " -- " << i->getBalance();
        cout << endl;
    }
} 
    
void bankAccount :: menu(){
    while (true){
        cout << "options for " <<this->uniqueNum << "\nS -- open saving acc\nC -- open checking acc\nM -- modify subAcc\nE -- close a sub account\nD -- detail info\nB -- brief info\nX -- exit";
        //lol
        cout << endl <<"enter response: ";
        char input;
        cin >> input; 
        switch(tolower(input)){
            case 'x':{
                return;
            }
            case 's':{
                cout << "enter initial balance: ";
                string bal;
                subAccount* newAcc = new subAccount(validInput(bal));
                int sum = 0;;
                for(auto x : this->subAccs){
                  if(x->getNum()[0] == 'S'){sum +=1;}
                }
                if (sum == 0){newAcc->deposit(100);}
                this->subAccs.push_back(newAcc); break;
            }
            case'c':{
                cout << "enter initial balance: ";
                string bal; int vbal = validInput(bal);
                cout << "enter initial max: ";
                string max; int vmax = validInput(max);
                cout << "enter \"l\" if you want locked account: ";
                string state; cin >> state;
                this->subAccs.push_back(new checkingAccount(vbal,vmax,state)); break;
            }
            case 'm':{
                cout << "enter name of account";
                string acc;
                cin >> acc;
                this->modifySubAcc(acc); break;
            }
            case 'e':{
                cout << "enter name of account";
                string acc;
                cin >> acc; 
                this->deleteSubAcc(acc);
            }   
            case 'd':{
                this->detailDisplay();
            }
            case 'b':{
                int sum =0;
                for(auto i : this->subAccs){sum +=i->getBalance();}
                cout <<"aggregated balance of " << this->uniqueNum << "with " <<this->subAccs.size() <<" subaccounts is " << sum << endl;
            }
            default:{
                cout <<"enter one of the options bruh";
            }
        }
    }
}

#endif