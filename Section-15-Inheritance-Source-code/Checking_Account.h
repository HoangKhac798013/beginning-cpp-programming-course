#ifndef _CHECKING_ACCOUNT_
#define _CHECKING_ACCOUNT_
#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
private:
    static constexpr double withdraw_fee = 1.5; 
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
protected:
};

#endif