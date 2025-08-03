#include "includes/account.h"
#include "includes/create_account.h"
#include "includes/save_account.h"
/*
class Account
{
  std::string m_OwnerName;
  double m_Balance;
  int m_AccountId = 1;
  std::string m_Pin;

public:
  Account(std::string &name, double balance, std::string pin) : m_OwnerName(name), m_Balance(balance), m_Pin(pin)
  {
    m_AccountId++;
  }
  int getAccountNumber()
  {
    return m_AccountId;
  }
  std::string getName()
  {
    return m_OwnerName;
  }
  double getBalance()
  {
    return m_Balance;
  }
  std::string getPin()
  {
    return m_Pin;
  }
  void display()
  {
    std::cout << "### Hi " << m_OwnerName << "#############\n"
              << "### #Your balance is : " << m_Balance << "EUR###\n"
              << "### Would you like to ##############\n"
              << "1. Withdraw \n"
              << "2. Deposit\n"
              << "3.View Transaction History"
              << "\n4. Save And Exit";
  }
};

void saveAccount(Account *acc)
{
  int accountId = acc->getAccountNumber();
  std::string name = acc->getName();
  double balance = acc->getBalance();
  std::string pin = acc->getPin();

  std::string accountFolder = "/home/alex/Programing/Cpp_Projects/Bank-Account-App/src/user_data/" + name;
  std::string accountFilePath = accountFolder + "/Account_Information.txt";

  std::filesystem::create_directories(accountFolder);

  std::ofstream accountFile(accountFilePath);
  if (accountFile.is_open())
  {
    accountFile << "### Hi " << name << " #############\n"
                << "### Your balance is: " << balance << " EUR ###\n"
                << "### Account ID: " << accountId
                << "\n### Would you like to ###########\n"
                << "1. Withdraw \n"
                << "2. Deposit\n"
                << "3.  View Transaction History"
                << "\n4. Save And Exit"
                << "\nYour Pin: " + pin;
    accountFile.close();
  }
  else
  {
    std::cerr << "FAILED TO OPEN FILE: " << accountFilePath << std::endl;
  }
}

Account *createAccount()
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
*/
int main()
{
  Account *p_Account = createAccount();
  saveAccount(p_Account);
  p_Account->display();
  delete p_Account;
}
