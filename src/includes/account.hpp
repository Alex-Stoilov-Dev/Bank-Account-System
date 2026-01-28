#pragma once
#include <iostream>

class Account
{
private:
  int m_user_id;
  void set_user_id();
  std::string m_username;
  double m_balance;
  std::string m_pin;
  std::string m_account_dashboard = std::format(
                              "###################################################\n"
                              "######## C++ Banking Account Systems LTD   ########\n"
                              "###################################################\n"
                              "      Logged in as:  {}  \n"
                              "      Balance:  {}  EUR\n"
                              "      Account Options:\n"
                              "        1. Withdraw\n"
                              "        2. Deposit\n"
                              "        3. View Transaction History\n"
                              "        4. Change pin\n"
                              "        5. Logout\n"
                              "###################################################\n", m_username, m_balance);
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
  void widthdraw();
  void deposit();
  void display_account_dashboard() const;
};
