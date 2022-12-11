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
        string getNum(){return this->num;} 
        void genericMenu(char input);
        virtual void menu();
        unsigned int getBalance(){return this->balance;}
        subAccount(){this->num = ""; this->balance = 0;}
        subAccount(unsigned int bal);
        virtual void printInfo();
};
class checkingAccount : public subAccount{
    private:
        int maxCapacity;
        bool locked;
    public:
        void deposit(int amount);
        void withdraw(int amount) override;
        void setMax(int amount){this->maxCapacity = amount;}
        int getMax(){return this->maxCapacity;}
        void toggleLock();
        void menu()override;
        void printInfo() override;
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
            cout <<"enter an integer: ";
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
    switch(tolower(input)){
        case 'd':{
            cout << "enter deposit amount ";
            string input;
            this->deposit(validInput(input));
            cout <<"current balance is " << this->balance << endl;
            break;
        }
        case 'w':{
            cout <<"how much do you wanna withdraw ";
            string input;
            this ->withdraw(validInput(input));  
            cout <<"current balance is " << this->balance << endl;
            break;        
        }default:{
            cout <<" enter one of the options bruh";
        }
    }

}
void subAccount :: menu(){
    while (true){
        cout <<"\neligable services for " << this->getNum() <<"\n--D Deposit\n--W withdraw\n--X exit";
        cout <<"\nenter response: ";
        char input;
        cin >> input;
        switch(tolower(input)){
            case 'x':{
                return;
            }
            default: {
                genericMenu(input);
            }
        }
    }
}
void subAccount::printInfo(){
    cout <<"\n name: " << this->getNum();
    cout << "\n balance: " << this->getBalance()<<endl;
}
/////////////////////checking account functions//////////////////////////////////////////////////////////////////////
checkingAccount :: checkingAccount(int bal, int initMax, string initState){
        this->num = "CHK" + to_string(uniqueNumChek++);
        this->balance = bal;
        this->maxCapacity = initMax;
        initState = "l"? this->locked = true : this->locked = false;
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
    if(this->locked){cout << "\naccount is locked\n"; return;}
    subAccount :: deposit(amount);
}
void checkingAccount::toggleLock(){
    string lockStatus;
    this->locked = !this->locked;
    this->locked? lockStatus = "locked" : lockStatus = "unlocked";
    cout << "\nthis account has been " << lockStatus << endl;
}
void checkingAccount::printInfo(){
    cout <<"\n name: " << this->getNum();
    cout << "\n balance: " << this->getBalance();
    string lockStatus;
    this->locked? lockStatus = "locked" : lockStatus = "unlocked";
    cout << "\n this account is: " << lockStatus;
    cout <<"\n this account's max capacity is: " << this->getMax()<<endl;
}
void checkingAccount :: menu(){
    while(true){
        cout <<"\neligable services for " << this->getNum() << "\n--D Deposit\n--W withdraw\n--C max capacity\n";
        cout <<"--T toggle account lock status\n--X exit"; 
        cout << endl <<"\nenter response ";
        char input;
        cin >> input; 
        switch(tolower(input)){
            case 'x':{
                return;
            }
            case 'c':{
                cout << "enter max ";
                string inp;
                setMax(validInput(inp));
                break;
            }
            case 't':{
                this->toggleLock();
                break;
            }
            default:{
                subAccount::genericMenu(input);
            }
        }
    }
}
  
#endif