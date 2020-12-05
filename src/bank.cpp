#include "bank.hpp"

Bank::Bank()
{
    Account account;
    std::ifstream infile;
    infile.open("Bank.data");
    if (!infile)
    {
        std::cout<<"Error in Opening! File Not Found!!"<<std::endl;
        return;
    }
    while (!infile.eof())
    {
        infile >> account;
        accounts.insert(std::pair<long, Account>(account.getAccountNumber(), account));
    }
    Account::setLastAccountNumber(account.getAccountNumber());
    infile.close();
}

Account Bank::openAccount(std::string firstName, std::string lastName, float balance)
{
    std::ofstream outfile;
    Account account(firstName, lastName, balance);
    accounts.insert(std::pair<long, Account>(account.getAccountNumber(), account));
    outfile.open("Bank.data", std::ios::trunc);
    std::map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::balanceEnquiry(long accountNumber)
{
    std::map<long, Account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}

Account Bank::deposit(long accountNumber, float amount)
{
    std::map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.deposit(amount);
    return itr->second;
}

Account Bank::withdraw(long accountNumber, float amount)
{
    std::map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.withdraw(amount);
    return itr->second;
}

bool Bank::closeAccount(long accountNumber)
{
    std::map<long, Account>::iterator itr = accounts.find(accountNumber);
    std::cout << "Account Deleted" << itr->second << std::endl;
    accounts.erase(accountNumber);
}

void Bank::ShowAllAccounts()
{
    std::map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        std::cout << "Account " << itr->first << "\n" << itr->second << std::endl;
    }
}

Bank::~Bank()
{
    std::ofstream outfile;
    outfile.open("Bank.data", std::ios::trunc);

    std::map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
}