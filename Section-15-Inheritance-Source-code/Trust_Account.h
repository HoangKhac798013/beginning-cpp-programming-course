#ifndef _TRUST_ACCOUNT_H_     
#define _TRUST_ACCOUNT_H_  
#include "Savings_Account.h"
#include <string>

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os,const Trust_Account &account);
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_interest_rate);
    bool withdraw(double amount);
    bool deposit(double amount);
private:
    static constexpr const char* def_name = "Unnamed Trust Account" ;
    static constexpr double def_bonus_amount = 50.0 ;
    static constexpr double def_bonus_threshold = 5000.0;
    static constexpr double def_interest_rate = 0.0;
    static constexpr double def_balance = 0;
protected:
};

#endif