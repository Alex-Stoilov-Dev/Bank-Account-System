#include "includes/login_screen.hpp"
#include "includes/account.hpp"
#include "includes/create_account.hpp"
#include "includes/display.hpp"
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include <string>

void login_to_account()
{

}

void login_screen()
{
  int choice;
  // This is the screen/UI
  std::cout << "###################################################\n"
            << "######## Hello, welcome to our banking app ########\n"
            << "###\t\t\t\t\t\t###\n"
            << "###\t How would you like to continue: \t###\n"
            << "###\t\t\t\t\t\t###\n"
            << "### 1. Log into an existing account \t\t###\n"
            << "### 2. Create a new account \t\t\t###\n"
            << "### 3. Change pin \t\t\t\t###\n"
            << "### 4. Exit \t\t\t\t\t###\n"
            << "###\t\t\t\t\t\t###\n"
            << "###################################################\n";
  std::cin >> choice;
  // This handles the user input for the UI
  switch (choice)
  {
  case 1:
  {
    login_to_account();
    break;
  }
  case 2: // Create new account
  {
    std::shared_ptr<Account> user = create_account();
    user->display_account_dashboard();

    break;
  }
  case 3:
  {
    // Basic change func

    break;
  }
  case 4:
  {
    // The exit Option
    break;
  }
  default:
  {
    break;
  }
  }
}
