#include "includes/all_headers.h"
#include <filesystem>

void display(const std::filesystem::path &account_path)
{
  // This function takes in the file path of an account
  // And displays the content of that user's
  // Account_Information.txt file

  if (!std::filesystem::exists(account_path))
  {
    std::cerr << "[ERROR]: Account path does not exist\n";
  }

  int choice;

  // Error handling in the case
  std::ifstream account_info(account_path / "Account_Information.txt");
  if (!account_info.is_open() || !account_info.good())
  {
    std::cerr << "[ERROR]: Unable to open file\n";
    std::cout << "Returning to main menu\n";
    login_screen();
  }

  std::string s;
  while (getline(account_info, s))
  {
    std::cout << s << std::endl;
  }
  account_info.close();

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
    login_screen();
  default:
    break;
  }
}