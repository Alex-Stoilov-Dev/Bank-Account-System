#include <iostream>

void LoginFunction()
{
  std::cout << "You've logged into your account!"
            << "### Hi --NAME-- #############\n"
            << "### Your balance is: --BALANCE-- EUR###\n"
            << "### Would you like to ##############\n"
            << "1. Withdraw \n"
            << "2. Deposit\n"
            << "3. View Transaction History"
            << "\n4. Save And Exit";
}

void LoginScreen()
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
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    break;
  }
}

int main()
{
  LoginScreen();
}