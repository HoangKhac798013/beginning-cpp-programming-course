#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    try{
    Checking_Account account("Moe", -10.0);
    }
    catch (IllegalBalanceException& ex) {
    ex.what();
    }
    try {
    Savings_Account saving("Joe", 100);
    saving.withdraw(200);
    }
    catch (InsufficentFundsException& ex) {
    ex.what();
    }
    
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

