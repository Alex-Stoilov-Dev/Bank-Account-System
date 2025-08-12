#include "includes/all_headers.h"

Account *create_account()
{
  std::string name;
  double balance;
  std::string pin;

  std::cout << "Please enter an Owner Name for the account (A-z): ";
  std::cin >> name;
  if (name == " " || name == "")
  {
    std::cout << "Please enter a valid Owner name: ";
    std::cin >> name;
  }

  std::cout << "\nWhat is your account's initial balance?: ";
  std::cin >> balance;
  if (balance < 0)
  {
    std::cout << "You cannot create an account without initial balance.";
    std::cout << "\nPlease enter a valid initial balance: ";
    std::cin >> balance;
  }

  std::cout << "\nPlese enter your pin 6 digit pin): ";
  std::cin >> pin;
  if (pin.length() < 6 || pin.length() > 6)
  {
    std::cout << "Please enter a 6 digit pin: ";
    std::cin >> pin;
  }

  Account *acc = new Account(name, balance, pin);
  return acc;
}