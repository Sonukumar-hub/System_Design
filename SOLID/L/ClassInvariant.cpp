#include <iostream>
#include <stdexcept>
using namespace std;

//class invarient of a parent class object should not be broken by child class object. // hence child class can either maintain or strengthen the invarient but never narrows it down.

//Invariant : balance cannot be negative

class BankAccount {
protected:
    double balance;

public:
    BankAccount(double b) {
        if (b < 0) {
            throw invalid_argument("Balance can't be negative");
        }

        balance = b;
    }

    virtual void withdraw(double amount) {
        if (balance - amount < 0) {
            throw runtime_error("Insufficient funds");
        }

        balance -= amount;

        cout << "Amount Withdrawn, Remaining balance is " << balance << endl;
    }

    virtual ~BankAccount() = default;
};


// Child class must preserve the invariant:
// balance >= 0

class CheckAccount : public BankAccount {
public:
    CheckAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        if (balance - amount < 0) {
            throw runtime_error("Insufficient funds");
        }

        balance -= amount;

        cout << "Amount Withdrawn from CheckAccount, " << "Remaining balance is " << balance << endl;
    }
};


int main() {
    BankAccount* bankaccount = new BankAccount(100);

    bankaccount->withdraw(100);

    delete bankaccount;

    return 0;
}
