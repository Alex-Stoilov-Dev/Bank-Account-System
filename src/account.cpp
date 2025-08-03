#include <iostream>
#include "includes/account.h"

Account::Account(std::string &name, double balance, std::string pin) : m_OwnerName(name), m_Balance(balance), m_Pin(pin)
{
  m_AccountId++;
}

int Account::getAccountNumber()
{
  return Account::m_AccountId;
}
std::string Account::getName()
{
  return m_OwnerName;
}
double Account::getBalance()
{
  return m_Balance;
}
std::string Account::getPin()
{
  return m_Pin;
}
void Account::display()
{
  std::cout << "### Hi " << m_OwnerName << "#############\n"
            << "### #Your balance is : " << m_Balance << "EUR###\n"
            << "### Would you like to ##############\n"
            << "1. Withdraw \n"
            << "2. Deposit\n"
            << "3.View Transaction History"
            << "\n4. Save And Exit";
}
