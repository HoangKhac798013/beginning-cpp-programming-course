#include "Trust_Account.h"

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

Trust_Account::Trust_Account(std::string name, double balance, double int_rate):
Savings_Account{name, balance, int_rate} {
    if(balance > 5000) {
        this->balance += 50;
    }
}

bool Trust_Account::withdraw(double amount) {
    static int count = 0;
    if(amount < 0.2*balance && count < 3) {
        std::cout << "Withdraw success" << std::endl;
        Savings_Account::withdraw(amount);
        count++;
        return true;
    }
    else if( amount > 0.2*balance) {
        std::cout << "Withdraw unsuccessful" << std::endl;
        std::cout << "Larger than 20% of the balance" << std::endl;
        return false;
    }
    else if( count >= 3) {
        std::cout << "More than 3 times a year" << std::endl;
        return false;
    }
    return false;
}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000) {
        balance += 50;
    }
    Savings_Account::deposit(amount);
}