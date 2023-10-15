#include <iostream>
#include "Account_Util.h"

// Displays Trust Account objects in a  vector of Trust Account objects 
void display(const std::vector<Account *> accounts) {
    std::cout << "\n=== Generic Accounts=====================================" << std::endl;
    for (const auto acc: accounts) 
        std::cout << *acc << std::endl;
}

// Deposits supplied amount to each Trust Account object in the vector
void deposit(std::vector<Account* > accounts, double amount) {
    std::cout << "\n=== Depositing to Generic Accounts===========================" << std::endl;
    for (auto acc:accounts)  {
        if (acc->deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

// Withdraw supplied amount from each Trust Account object in the vector
void withdraw(std::vector<Account*> accounts, double amount) {
    std::cout << "\n=== Withdrawing from Generic Accounts=======================" << std::endl;
    for (auto acc:accounts)  {
        if (acc->withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
    } 
}