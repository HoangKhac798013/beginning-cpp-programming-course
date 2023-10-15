#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance): Account(name, balance) {
    std::cout << "Created Checking Account";
}

bool Checking_Account::withdraw(double amount) {
    if(balance > amount + withdraw_fee ) {
        balance -= withdraw_fee;
        Account::withdraw(amount);
        return true;
    }
    else {
        std::cout << "Not enough money in balance";
    }
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}
