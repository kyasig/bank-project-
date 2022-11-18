#ifndef subaccount_H
#define subaccount_H
#include <string>
static int uniqueNumSav = 1000;
static int uniqueNumChek = 6000;
class subAccount{
    protected:
        int balance;
        string num; 
    public:
        virtual void deposit(int num){this->balance += num;};
        void withdraw(int num){this->balance -= num;}
        string getNum(){return this->num;}
        int getBalance(){return this->balance;}
        virtual void menu();
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
        checkingAccount();
};

subAccount :: subAccount(){
    this->num = "SAV" + std::to_string(uniqueNumSav++);
}
checkingAccount :: checkingAccount(){
    this->num = "CHK" + std::to_string(uniqueNumChek++);
    this->balance = 0;
}

void subAccount :: menu(){
    std::cout <<"eligable services for " << this->getNum() << endl << "--D Deposit" << endl << "--W withdraw" << endl << "--X exit";
    string input;
    while (true){
        cin >> input;
        switch (input){
            case "d": this->deposit(1);
            break;
            case "w": this->withdraw(1);
            break;
            case "x": return;
            break;
        }
    }
}

#endif