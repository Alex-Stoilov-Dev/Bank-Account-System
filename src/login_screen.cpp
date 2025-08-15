#include "includes/all_headers.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdlib>

void login_to_account()
{
  // We make sure that the program knows what path to use to find the user's data
  const std::string base_path = "Bank-Account-App/src/user_data";

  std::string id, pin;

  std::cout << "Account ID: ";
  std::cin >> id;
  std::cout << "\nAccount Pin: ";
  std::cin >> pin;

  // We use the base path + the ID of the account
  // The ID is also the name of the folder
  std::filesystem::path account_path = std::filesystem::path(base_path) / id;
  if (!std::filesystem::exists(account_path) || !std::filesystem::is_directory(account_path))
  {
    login_screen(); // Returns to the main menu if there are any issues.
  }

  // Create a path to our pin.txt for authentication.
  std::filesystem::path pin_file = account_path / "pin.txt";
  if (!std::filesystem::exists(pin_file))
  {
    std::cout << "PIN file missing. \n Please create reach out to admins to resolve the issue.\n\n";
    login_screen();
    // Handles the case where the pin.txt file has been deleted
  }

  std::ifstream file(pin_file);
  std::string stored_pin;
  std::getline(file, stored_pin);

  if (pin == stored_pin)
  {
    std::cout << "Login Successful!\n";
    display(account_path); // Calls the display function, with our account path everything is correct
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
  case 2:
  {
    // This calls our create function, and passes the pointer
    // To save account.
    Account *new_account = create_account(); // Pointer deleted in save_account.cpp
    save_account(new_account);
    break;
  }
  case 3:
  {
    // Basic change func
    change_pin();
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