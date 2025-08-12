#include "all_headers.h"
#include <filesystem>

void display(const std::filesystem::path &account_path)
{
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
}