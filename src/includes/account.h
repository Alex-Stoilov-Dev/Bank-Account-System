#pragma once
#include <iostream>

class Account
{
private:
  std::string m_owner_name;
  double m_balance;
  int m_account_id = 1;
  std::string m_pin;

public:
  Account(std::string &name, double balance, std::string pin);
  int get_account_id();
  void increment();
  std::string get_name();
  double get_balance();
  std::string get_pin();
};