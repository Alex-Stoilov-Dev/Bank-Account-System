#pragma once
#include <iostream>

class Account
{
private:
  std::string m_OwnerName;
  double m_Balance;
  int m_AccountId = 1;
  std::string m_Pin;

public:
  Account(std::string &name, double balance, std::string pin);
  int getAccountId();
  std::string getName();
  double getBalance();
  std::string getPin();
  void display();
  int get_id();
  void Increment();
};