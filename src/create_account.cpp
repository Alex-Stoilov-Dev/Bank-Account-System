#include "includes/create_account.h"
#include "includes/account.h"

Account *create_account()
{
  std::string name;
  double balance;
  std::string pin;

  std::cout << "Please enter an Owner Name for the account: ";
  std::cin >> name;

  std::cout << "\nWhat is your account's initial balance?: ";
  std::cin >> balance;

  std::cout << "\nPlese enter your pin: ";
  std::cin >> pin;

  Account *acc = new Account(name, balance, pin);
  return acc;
}