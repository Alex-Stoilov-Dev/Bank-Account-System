#pragma once
#include <iostream>

class Account
{
  std::string m_OwnerName;
  double m_Balance;
  int m_AccountId;
  std::string m_Pin;

public:
  Account(std::string &name, double balance, std::string pin);
  int getAccountNumber();
  std::string getName();
  double getBalance();
  std::string getPin();
  void display();
};