#include "includes/account.hpp"
#include <iostream>
#include <mysql/mysql.h>
#include "includes/db_manager.hpp"

void create_account()
{
  dbManager DB{};

  MYSQL *DB_conn = DB.mysql_connection_setup();;
  MYSQL_RES *result;

  const char *query;

  std::string name;
  double balance;
  std::string pin;

  std::cout << "Please enter an Owner Name for the account (A-z): ";
  std::cin >> name;
  if (name == " " || name == "")
  {
    std::cout << "Please enter a valid Owner name: ";
    std::cin >> name;
  }

  std::cout << "\nWhat is your account's initial balance?: ";
  std::cin >> balance;
  if (balance < 0)
  {
    std::cout << "You cannot create an account without initial balance.";
    std::cout << "\nPlease enter a valid initial balance: ";
    std::cin >> balance;
  }

  std::cout << "\nPlese enter your pin 6 digit pin: ";
  std::cin >> pin;
  // Forces the PIN to be 6 digits
  if (pin.length() < 6 || pin.length() > 6)
  {
    std::cout << "Please enter a 6 digit pin: ";
    std::cin >> pin;
  }

  Account new_user(name,balance,pin);


  mysql_stmt_init(DB_conn);

  std::string query_str = std::format(
      "INSERT INTO users(username, pin_hashed, balance) VALUES ('{}', MD5('{}'), '{}')",
      name, pin, balance
  );
  
  query = query_str.c_str();

  result = DB.execute_sql_query(DB_conn, query);
  if (result != nullptr) {
    mysql_free_result(result);
    result = nullptr;
  }
  mysql_close(DB_conn);
}
