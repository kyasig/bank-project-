#ifndef bank_H
#define bank_H
#include "account.h"
using namespace std;
class bank {
    private:
        string name;
        string address;
        int workingHours[2];
        vector <bankAccount *> accs;
    public:
        int getSubAccs();
        int getSavingSubAccs();
        int getCheckingSubAccs();
        void displayAccs();
        void modifyAcc(string id);
        void menu();
        bank(){
            name ="";
            address = "";
        };
        bank(string name, string address, int open, int close);
};
int summ(char c){
    int sum = 0;
    for(auto i : this->accs){
        for(auto x : i->subAccs){
            if(x->getNum()[0] == c){sum +=1;}
        }
    }
    return sum; 
}
/////////////////////////////////////////////////////////////////// 
bank :: bank(string name, string address, int open, int close){
    this->name = name;
    this->address = address;
    workingHours[0] = open;
    workingHours[1] = close;
}
int bank :: getSubAccs(){
    int sum = 0;
    for(i : this->accs){
        sum += 1 + i->getSubs();
    }
    return sum;
}
int bank :: getSavingSubAccs(){
    return summ('S');
}
int bank :: getCheckingSubAccs(){
    return sums('C');
}
void bank:: displayAccs(){
    for(auto i: this->accs){
        i->detailDisplay();
    }
}
void modifyAcc(string id){
   int i = searchAcc(id, this->accs);
   this->accs.at(i)->menu();
}
void bank:: menu(){}

#endif
