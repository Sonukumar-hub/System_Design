#include<iostream>
#include<vector>
#include <stdexcept>
using namespace  std;

class Account{
public:
    virtual void deposite(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};



class SavingAccount : public Account{
private:
    double balance;

public:
    SavingAccount(){
        balance = 0;
    }

    void deposite(double amount){
        balance += amount;
        cout << "Deposited:" << amount << "in saving account. New Balance:" << balance << endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << "Withdrawn: " << "from saving account. New balance: " << balance << endl;
        }else{
            cout << "Insufficient funds in Saving Account!\n";
        }
    }
};



class CurrentAccount : public Account{
    private:
    double balance;

public:
    CurrentAccount(){
        balance = 0;
    }

    void deposite(double amount){
        balance += amount;
        cout << "Deposited:" << amount << "in current account. New Balance:" << balance << endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << "Withdrawn: " << "from current account. New balance: " << balance << endl;
        }else{
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};


class FixedTermAccount : public Account{
private:
    double balance;
public:
    FixedTermAccount(){
        balance = 0;
    }

    void deposite(double amount){
        balance += amount;
        cout << "Deposited:" << amount << " in fixed term account. New balance: " << balance << endl;
    }

    void withdraw(double amount){
        balance += amount;
        throw logic_error("Withdrawal not allowed in Fixed Trem Account");
    }
};

class BankClient{
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void processTransactions(){
        for(Account* acc : accounts){
            acc->deposite(1000); //all account allow deposite

            //checking account type explicitely

            if(typeid(*acc) == typeid(FixedTermAccount)){
                cout << "Skipping Withdrawl to Fixed term Account.\n";
            }else{
                try{
                    acc->withdraw(500);
                }catch(const logic_error & e){
                    cout << "Exception: " << e.what() << endl;
                }
            }
        }
    }
};


int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();

    return 0;
}