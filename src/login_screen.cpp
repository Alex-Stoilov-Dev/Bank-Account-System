#include "includes/all_headers.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdlib>

void login_to_account()
{
  const std::string base_path = "/home/alex/Programing/Cpp_Projects/Bank-Account-App/src/user_data";
  std::string id, pin;
  std::cout << "Account ID: ";
  std::cin >> id;
  std::cout << "\nAccount Pin: ";
  std::cin >> pin;

  std::filesystem::path account_path = std::filesystem::path(base_path) / id;
  if (!std::filesystem::exists(account_path) || !std::filesystem::is_directory(account_path))
  {
    system("pwd");
    std::cout << "Account not found. \nReturning to main menu...\n\n";
    login_screen();
  }

  std::filesystem::path pin_file = account_path / "pin.txt";
  if (!std::filesystem::exists(pin_file))
  {
    std::cout << "PIN file missing. \n Please create reach out to admins to resolve the issue.\n\n";
    login_screen();
  }
  std::ifstream file(pin_file);
  std::string stored_pin;
  std::getline(file, stored_pin);

  if (pin == stored_pin)
  {
    std::cout << "Login Successful!\n";
    display(account_path);
  }
  else
  {
    std::cout << "Invalid PIN. \nReturning to main menu...\n\n";
    login_screen();
  }
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