#include <iostream>
#include "includes/account.h"

Account::Account(std::string &name, double balance, std::string pin) : m_owner_name(name), m_balance(balance), m_pin(pin)
{
}

int Account::get_account_id()
{
  return Account::m_account_id;
}
void Account::increment()
{
  Account::m_account_id++;
};
std::string Account::get_name()
{
  return m_owner_name;
}
double Account::get_balance()
{
  return m_balance;
}
std::string Account::get_pin()
{
  return m_pin;
}
