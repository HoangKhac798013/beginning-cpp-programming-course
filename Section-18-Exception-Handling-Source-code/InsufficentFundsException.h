#ifndef InsufficentFundsException_H_
#define InsufficentFundsException_H_

class InsufficentFundsException: public std::exception {
public:
    InsufficentFundsException() = default;
    ~InsufficentFundsException() = default;
    std::string virtual what() {
        return "There is not enough money in the back account";
    }
};

#endif 