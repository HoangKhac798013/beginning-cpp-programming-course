#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException: public std::exception
{
public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}
    std::string virtual what() {
        return "Balance can not be less than 0";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
