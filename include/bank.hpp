#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "account.hpp"

class Bank
{
    private:
        std::map<long, Account> accounts;
    public:
        Bank();
        Account openAccount(std::string firstName, std::string lastName, float balance);
        Account balanceEnquiry(long accountNumber);
        Account deposit(long accountNumber, float amount);
        Account withdraw(long accountNumber ,float amount);
        bool closeAccount(long accountNumber);
        void ShowAllAccounts();
        ~Bank();
};
#endif
