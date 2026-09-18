#include <iostream>
#include <stdexcept>
using namespace std;

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

    // History constraint:
    // Withdraw should be allowed.
    virtual void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("Withdrawal amount can't be negative");
        }

        if (balance - amount < 0) {
            throw runtime_error("Insufficient funds");
        }

        balance -= amount;

        cout << "Amount withdrawn. Remaining balance is "
             << balance << endl;
    }

    virtual ~BankAccount() = default;
};


class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(double b) : BankAccount(b) {}

    // LSP BREAK!
    // Parent allows withdrawal, but child completely
    // changes that behavior.
    void withdraw(double amount) override {
        throw runtime_error(
            "Withdraw not allowed in Fixed Deposit"
        );
    }
};


int main() {

    BankAccount* bankAccount = new BankAccount(100);

    bankAccount->withdraw(100);

    delete bankAccount;

    return 0;
}