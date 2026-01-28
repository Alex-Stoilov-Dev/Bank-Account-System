#include "includes/login_screen.hpp"
#include <fstream>
#include <filesystem>

void display()
{
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
    login_screen();
  default:
    break;
  }
}