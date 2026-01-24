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
  ~Account();
  void save_account() const;
  int get_account_id() const;
  void increment();
  std::string get_name() const;
  double get_balance() const;
  std::string get_pin() const;
  void change_pin();
};