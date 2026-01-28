#include "includes/login_screen.hpp"
#include <fstream>
#include <filesystem>
#include <memory>

void display(const std::shared_ptr<Account>& account)
{
  account->display_account_dashboard();
  // This function takes in the file path of an account
  // And displays the content of that user's
  // Account_Information.txt file

  int choice;

  // This acts as the menu selection part of the UI
  std::cin >> choice;
  switch (choice)
  {
  case 1:
    // TODO: Add Widthdraw function;
    // withdraw();
    break;
  case 2:
    // TODO: Add Deposite Function;
    // deposit();
  case 3:
    // TODO: Add Transaction History
    // transaction_history();
  case 4:
    account->change_pin();
  case 5:
    login_screen();
  default:
    break;
  }
}
