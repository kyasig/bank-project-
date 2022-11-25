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
        virtual void deposit(int amount){this->balance += amount;};
        virtual void withdraw(int amount){this->balance -= amount;};
        string getNum(){return this->num;} //idk why this is here
        void printBalance(){cout << "current balance is " <<  this->balance << endl;}
        void genericMenu(char input);
        virtual void menu();
        unsigned int getBalance(){return this->balance;}
        subAccount(){this->num = "SAV" + to_string(uniqueNumSav++); this->balance = 0;}
        subAccount(unsigned int bal);
};
class checkingAccount : public subAccount{
    private:
        int maxCapacity;
        bool locked;
    public:
        void deposit(int amount);
        void withdraw(int amount) override;
        void setMax(int amount){this->maxCapacity = amount;};
        void toggleLock();
        void menu()override;
        void printt(){cout << "cum"<<endl;}
        checkingAccount(){
            this->num = "CHK" + to_string(uniqueNumChek++);
            this->balance = 0;
            this->locked = false;
            this->maxCapacity = 0;
        }
        checkingAccount(int bal, int initMax, string initState);
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

/// subaccount stuff/////////////////////////////////////////////////////////////////////////////////////////////////
subAccount :: subAccount(unsigned int bal){
    this->num = "SAV" + to_string(uniqueNumSav++);
    this->balance = bal;
    }
void subAccount::genericMenu(char input){
     if(tolower(input) == 'd'){
        cout << "enter deposit amount ";
        string input;
        this->deposit(validInput(input));
      }
      else if(tolower(input) == 'w'){
         cout <<"how much do you wanna withdraw ";
         string input;
         this ->withdraw(validInput(input));
    }
    else{cout << "enter one of the options bruh" << endl;}
        this->printBalance();
}
void subAccount :: menu(){
    while (true){
        cout <<"eligable services for " << this->getNum() << endl << "--D Deposit" << endl  << "--W withdraw" << endl << "--X exit";

        cout <<"enter response: ";
        char input;
        cin >> input;
        if(tolower(input) == 'x'){
            return;
        }else{
         genericMenu(input);
        }
    }
}
/////////////////////checking account functions//////////////////////////////////////////////////////////////////////
checkingAccount :: checkingAccount(int bal, int initMax, string initState){
        this->num = "CHK" + to_string(uniqueNumChek++);
        this->balance = bal;
        this->maxCapacity = initMax;
        initState = "locked"? this->locked = true : this->locked = false;
        }
void checkingAccount::withdraw(int amount ){
    if(this->locked){cout << "account is locked" << endl; return;}
    if(amount > this->maxCapacity){
        cout << "you are trying to withdraw more than the max";
        return;
    }
    subAccount :: withdraw(amount);
}
void checkingAccount :: deposit(int amount ){
    if(this->locked){cout << "account is locked" << endl; return;}
    subAccount :: deposit(amount);
}
void checkingAccount::toggleLock(){
    string lockStatus;
    this->locked = !this->locked;
    this->locked? lockStatus = "locked" : lockStatus = "unlocked";
    cout << "this account has been " << lockStatus << endl;
}
void checkingAccount :: menu(){
    while(true){
        cout <<"eligable services for " << this->getNum() << endl<< "--D Deposit" << endl << "--W withdraw" << endl << "--C max capacity"
         << endl << "--T toggle account lock status" << endl << "--X exit"; 
        cout << endl <<"enter response ";
        char input;
        cin >> input; 
        if(input == 'x'){
        return;
        }
        else if(tolower(input) == 'c'){
            cout << "enter max ";
            string inp;
            setMax(validInput(inp));
        }
        else if(tolower(input) == 't'){
            toggleLock();
        }
        else{
            subAccount::genericMenu(input);
        }
    }
}
  
#endif