#include <mysql/mysql.h>
#include <string>
#include <iostream>
#include "includes/db_manager.hpp"
#include "includes/account.hpp"


// std::string &name, double balance, std::string pin) : m_owner_name(name), m_balance(balance), m_pin(pin)
Account::Account(std::string &name, double balance, std::string pin) : m_username(name), m_balance(balance), m_pin(pin){}

std::string Account::get_name () const
{
  return m_username;
}
double Account::get_balance() const
{
  return m_balance;
}
std::string Account::get_pin() const
{
  return m_pin;
}

Account::~Account(){}

void Account::change_pin(){

  std::string pin;

  std::cout << "\nPlese enter your new pin 6 digit pin: ";
  std::cin >> pin;
  // Forces the PIN to be 6 digits
  while (pin.length() < 6 || pin.length() > 6)
  {
    std::cout << "Please enter a 6 digit pin: ";
    std::cin >> pin;
  }

  m_pin = pin;

  save_account();

}

void Account::save_account() const { // This function will save any changes made to an account

  dbManager DB{};

  DB.create_db();

  const char* query;

  MYSQL *DB_conn = DB.mysql_connection_setup();
  MYSQL_RES *result;

  std::string query_str = std::format(
    "UPDATE users SET username = '{}', pin_hashed = MD5('{}'), balance = '{}' WHERE username = '{}'"
    ,this->m_username, this->m_pin, this->m_balance, this->m_username); // SQL QUERY IS WRITTEN HERE

  query = query_str.c_str();

  result = DB.execute_sql_query(DB_conn, query);
  if (result != nullptr) {
    mysql_free_result(result);
    result = nullptr;
  }
  mysql_close(DB_conn);

}

void Account::widthdraw() {

}

void Account::deposit() {

}

void Account::set_user_id(){

  dbManager DB{};

  DB.create_db();

  const char* query;

  MYSQL *DB_conn = DB.mysql_connection_setup();

  std::string query_str = std::format("SELECT id FROM users WHERE username={};", this->m_username);

  query = query_str.c_str();

  MYSQL_RES *result = DB.execute_sql_query(DB_conn, query);

  std::string fetched_info;

  if(result){
    MYSQL_ROW row;

    if((row = mysql_fetch_row(result)))
    {
      if (row[0]){
        fetched_info = row[0];
      }
    }
  }
  std::cout << fetched_info;
}

void Account::display_account_dashboard() const {
  std::cout << m_account_dashboard;
}
