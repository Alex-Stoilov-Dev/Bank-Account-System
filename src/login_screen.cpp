#include "includes/login_screen.h"
#include "includes/change_pin.h"

void login_to_account()
{
}

void login_screen()
{
  int choice;

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
  switch (choice)
  {
  case 1:
  {
    login_to_account();
    break;
  }
  case 2:
  {
    Account *new_account = create_account();
    save_account(new_account);
    break;
  }
  case 3:
  {
    change_pin();
    break;
  }
  case 4:
  {
    break;
  }
  default:
  {
    break;
  }
  }
}