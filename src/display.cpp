#include "includes/all_headers.h"
#include <filesystem>

void display(const std::filesystem::path &account_path)
{
  int choice;
  std::ifstream account_info(account_path / "Account_Information.txt");
  if (!account_info.is_open())
  {
    std::cerr << "[ERROR]: Unable to open file";
    std::cout << "Returning to main menu";
    login_screen();
  }
  std::string s;

  while (getline(account_info, s))
  {
    std::cout << s << std::endl;
  }

  account_info.close();

  std::cin >> choice;

  switch (choice)
  {
  case 1:
    // withdraw();
    break;
  case 2:
    // deposit();
  case 3:
    // transaction_history();
  case 4:
    login_screen();
  default:
    break;
  }
}