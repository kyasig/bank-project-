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
        void briefDisplay();
        void modifyAcc(string id);
        void deleteAcc(string id);
        int getAggSum(){
            int sum = 0;
            for(auto i : this->accs){
             sum += i->getBalance();
             }
            return sum;
        }
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
void bank::briefDisplay(){
    bankSorter(this->accs);
    cout <<"\n Bank name: " << this->name;
    cout <<"\n Bank address: " << this->address;
    cout <<"\n Bank working hours: " <<this->workingHours[0] <<"am  to " << this->workingHours[1] << "pm";
    cout <<"\n Bank aggregate sum:" <<getAggSum();
    cout <<"\n consists of " << this->accs.size() <<" bank accounts\n";
}
void bank:: displayAccs(){
    this->briefDisplay();
    cout << endl;
    for(auto i : this->accs){
        cout << " Bank Account number: " << i->getNum();
        cout << "\n Account holder: " << i->getName();
        cout << "\n Account holder ssn: " << i->getSSn();
        cout <<"\n Aggregated balance: " << i->getBalance();
        cout <<"\n Consists of " << i->getSubs() << " sub accounts\n";
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
        cout << "acc dont exist ";
    }
}
void bank:: menu(){
    while (true){
        cout << "\neligable services for " << this->name << "\nA -- # of accounts \nS -- number of saving accounts\nH -- number of checking accounts";
        cout<<"\nO -- open bank account\nC -- close bank account\nM -- modify bank acc\nD -- detailed banks accs\nB -- brief accounts\nX -- exit";
        cout << endl << "enter response: ";
        char resp;
        cin >> resp;
        switch(tolower(resp)){
            case 'x':
                return;
            case 'a':{
                cout << endl << this->name << " has " << this->accs.size() << " accounts\n";
                break;
            }
            case 's':{
                cout << endl << this->name << " has " << this-> getSavingSubAccs() << " saving sub accs\n";
                break;
            }
            case 'h':{
                cout << endl << this->name << " has " << this-> getCheckingSubAccs() << " checking sub accs\n";
                break;
            }
            case 'o':{
                cout <<"enter first name ";
                string name; cin >> name;
                cout <<"enter last name ";
                string name2; cin >> name2;
                cout <<"enter ssn ";
                string ssn; int intssn = validInput(ssn);
                this->accs.push_back(new bankAccount(name, name2,intssn));
                cout <<"\na new bank account " << this->accs.back()->getNum() <<" was created!\n"; break;
                break;
            }
            case 'c':{
                cout << "enter name of account: ";
                string acc;
                cin >> acc; 
                this->deleteAcc(acc);
                break;
            }
            case 'm':{
                cout << "enter name of account: ";
                string acc;
                cin >> acc;
                //this->accs.at(searchAcc(acc, this->accs))->menu();   
                if(searchAcc(acc, this->accs) != -1){
                    this->accs.at(searchAcc(acc, this->accs))->menu();
                }else{
                    cout <<"try again ";
                }
                break;
            }
            case 'd':{
             this->displayAccs();
             break;
            }
            case 'b':{
                this->briefDisplay();
                break;
            }
            default:
                cout << "try again " << endl;
        }
    }
}

#endif
