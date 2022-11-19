#ifndef subaccount_H
#define subaccount_H
#include <iostream>
#include <string>
using namespace std;
static int uniqueNumSav = 1000;
static int uniqueNumChek = 6000;
class subAccount{
    protected:
        unsigned int balance;
        string num; 
    public:
        void deposit();
        void withdraw(unsigned int max);
        string getNum(){return this->num;}
        int getBalance(){return this->balance;}
        virtual void menu() const;
        subAccount();
};
class checkingAccount : public subAccount{
    private:
        int maxCapacity;
        bool locked;
        void deposit();
    public:
        int setMax();
        void toggleLock();
        void menu() const override{
            cout << "sex";
        }
        checkingAccount();
};

int validInput(string input){
    cin >> input;
    while(true){
        try{
            return stoi(input);
        }catch(invalid_argument){
            cout <<"enter a damn integer: ";
            cin >> input;
        }
    }
}

subAccount :: subAccount(){
    this->num = "SAV" + to_string(uniqueNumSav++);
}

checkingAccount :: checkingAccount(){
    this->num = "CHK" + to_string(uniqueNumChek++);
    string maxstr;
    cin >> maxstr;
    this->maxCapacity = validInput(maxstr);
    this->balance = 0;
}

void subAccount::deposit(){
    cout << "enter deposit amount ";
    string input;
    this->balance += validInput(input);
}

void subAccount :: withdraw(unsigned int max){
    cout <<"how much do you wanna withdraw ";
    string input;
    int sub = validInput(input);
    if(max >= sub){
        this->balance -= sub;
    }else{
        cout <<"you dont have that much money to withdraw ";
        }
}

void subAccount :: menu(){
    while (true){
        cout <<"eligable services for " << this->getNum() << endl << "--D Deposit" << endl << "--W withdraw" << endl << "--X exit";
        char input;
        cout <<endl<<"enter response ";
        cin >> input;
        if(input == 'd'){
            this->deposit();
        }
        else if(input == 'w'){
            this->withdraw(this->balance);
        }
        else if(input == 'x'){break;}
        else{cout << "enter one of the options bruh" << endl;}
        }
    }

  
#endif