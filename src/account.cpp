#include <iostream>
#include "includes/account.h"

int Account::s_NextAccountId = 1;

Account::Account(std::string &name, double balance, std::string pin) : m_OwnerName(name), m_Balance(balance), m_Pin(pin)
{
  m_AccountId = s_NextAccountId;
  ++s_NextAccountId;
}

int Account::getAccountId()
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
  std::cout << "###################################################\n"
            << "######## C++ Banking Account Systems LTD   ########\n"
            << "###################################################\n"
            << "      Logged in as: " << m_OwnerName << " \n"
            << "      Account ID: " << m_AccountId << "  \n\n"
            << "      Balance: " << m_Balance << " EUR\n"
            << "      Account Options:\n"
            << "        1. Withdraw\n"
            << "        2. Deposit\n"
            << "        3. View Transaction History\n"
            << "        4. Logout\n"
            << "###################################################\n";
}
