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
        int getSavingSubAccs(); // used for the $100 initial balance
        int getCheckingSubAccs();
        void displayAccs();
        void modifyAcc(string id);
        void deleteAcc(string id);
        void menu();
        bank(){
            name ="";
            address = "";
        };
        bank(string name, string address, int open, int close);
};
int summ(char c, vector <bankAccount *> vec){
    int sum = 0;
    for(auto i : vec){
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
    for(auto i : this->accs){
        sum += 1 + i->getSubs();
    }
    return sum;
}

int bank :: getSavingSubAccs(){
    return summ('S', this->accs);
}
int bank :: getCheckingSubAccs(){
    return summ('C', this->accs);
}
void bank:: displayAccs(){
    for(auto i: this->accs){
        i->detailDisplay();
    }
}
void bank :: modifyAcc(string id){
   int i = searchAcc(id, this->accs);
   this->accs.at(i)->menu();
}
void bank ::deleteAcc(string id){
    int i = searchAcc(id, this->accs);
    auto itr = this->accs.begin() + i;
    if(i != -1){
        delete this->accs.at(i);
        this->accs.erase(itr);
    }else{
        cout << "acc dont exist";
    }
}
void bank:: menu(){
    while (true){
        cout << "eligable services for " << this->name << "\nA -- # of accounts \nS -- number of saving accounts\nH -- number of checking accounts";
        cout<<"\nO -- open bank account\nC -- close bank account\nM -- modify bank acc\nD -- detailed banks accs\nB -- brief accounts\nX -- exit";
        cout << endl << "enter response ";
        char resp;
        cin >> resp;
        switch(tolower(resp)){
            case 'x':
                return;
            case 'a':{
                cout << this->name << " has " << this->accs.size() << " accounts" << endl;
                break;
            }
            case 's':{
                cout << this->name << "has " << this-> getSavingSubAccs() << " saving sub accs";
                break;
            }
            case 'h':{
                cout << this->name << "has " << this-> getCheckingSubAccs() << " checking sub accs";
                break;
            }
            case 'o':{
                cout <<"enter first name ";
                string name; cin >> name;
                cout <<"enter last name ";
                string name2; cin >> name2;
                cout <<"enter ssn";
                string ssn; int intssn = validInput(ssn);
                this->accs.push_back(new bankAccount(name, name2,intssn));
                break;
            }
            case 'c':{
                cout << "enter name of account";
                string acc;
                cin >> acc; 
                this->deleteAcc(acc);
                break;
            }
            case 'm':{
                cout << "enter name of account";
                string acc;
                cin >> acc;
                //this->accs.at(searchAcc(acc, this->accs))->menu();   
                if(searchAcc(acc, this->accs) != -1){
                    this->accs.at(searchAcc(acc, this->accs))->menu();
                }else{
                    cout <<"try again";
                }
            }
            case 'd':{
             this->displayAccs();
            }
            case 'b':{
                bankSorter(this->accs);
                for(auto i : this-> accs){
                    cout << i->getNum() << " -- ";
                }
            }
            default:
                cout << "fuck you";
        }
    }
}

#endif
