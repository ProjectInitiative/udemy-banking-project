#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>
#include <fstream>


#define MIN_BALANCE 500;
class InsufficientFunds{};

class Account
{
    private:
        long acocuntNumber;
        std::string firstName;
        std::string lastName;
        float balance;
        static long NextAccountNumber;
    public:
        Account() {};
        Account(std::string firstName, std::string lastName, float balance);
        long getAccountNumber();
        std::string getFirstName();
        std::string getLastName();
        float getBalance();
        void deposit(float amount);
        void withdraw(float amount);
        static void setLastAccountNumber(long accountNumber);
        static void getLastAccoundNumber();
        friend std::ofstream & operator<<(std::ofstream &ofs, Account &account);
        friend std::ifstream & operator>>(std::ifstream &ifs, Account &account);
        friend std::ostream & operator>>(std::ostream &os, Account &account);
};
#endif
