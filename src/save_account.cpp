#include "includes/save_account.h"

void saveAccount(Account *acc)
{
  int accountId = acc->getAccountNumber();
  std::string name = acc->getName();
  double balance = acc->getBalance();
  std::string pin = acc->getPin();

  std::string accountFolder = "/home/alex/Programing/Cpp_Projects/Bank-Account-App/src/user_data/" + name;
  std::string accountFilePath = accountFolder + "/Account_Information.txt";
  std::string pinFilePath = accountFolder + "/pin.txt";
  std::filesystem::create_directories(accountFolder);

  std::ofstream accountFile(accountFilePath);
  std::ofstream pinFile(pinFilePath);
  if (accountFile.is_open() && accountFile.good() && pinFile.is_open() && pinFile.good())
  {
    accountFile << "### Hi " << name << " #############\n"
                << "### Your balance is: " << balance << " EUR ###\n"
                << "### Account ID: " << accountId
                << "\n### Would you like to ###########\n"
                << "1. Withdraw \n"
                << "2. Deposit\n"
                << "3.  View Transaction History"
                << "\n4. Save And Exit";
    pinFile << pin;
    accountFile.close();
    pinFile.close();
  }
  else
  {
    std::cerr << "FAILED TO OPEN FILE: " << accountFilePath << std::endl;
    std::cout << "HINT: directory \"user_data\" might be missing" << std::endl;
  }
}