#include "account.hpp"

Account::Account(std::string firstName, std::string lastName, float balance)
{
    NextAccountNumber++;
    accountNumber = NextAccountNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->balance = balance;
}

long Account::getAccountNumber()
{
    return accountNumber;
}

std::string Account::getFirstName()
{
    return firstName;
}

std::string Account::getLastName()
{
    return lastName;
}

float Account::getBalance()
{
    return balance;
}

void Account::deposit(float amount)
{
    balance += amount;
}

bool Account::withdraw(float amount)
{
    if (balance - amount < MIN_BALANCE)        
    {
        throw InsufficientFunds();
        return false;
    }
    balance -= amount;
    return true;
}

void Account::setLastAccountNumber(long accountNumber)
{
    NextAccountNumber = accountNumber;
}

long Account::getLastAccountNumber()
{
    return NextAccountNumber;
}


std::ofstream & operator<<(std::ofstream &ofs, Account &account)
{
    ofs<<account.accountNumber<<std::endl;
    ofs<<account.firstName<<std::endl;
    ofs<<account.lastName<<std::endl;
    ofs<<account.balance<<std::endl;
    return ofs;
}
std::ifstream & operator>>(std::ifstream &ifs, Account &account)
{
    ifs>>account.accountNumber;
    ifs>>account.firstName;
    ifs>>account.lastName;
    ifs>>account.balance;
    return ifs;
}
std::ostream & operator<<(std::ostream &os, Account &account)
{
    os<<"First Name:"<<account.getFirstName()<<std::endl;
    os<<"Last Name:"<<account.getLastName()<<std::endl;
    os<<"Account Number:"<<account.getAccountNumber()<<std::endl;
    os<<"Balance:"<<account.getBalance()<<std::endl;
    return os;
}