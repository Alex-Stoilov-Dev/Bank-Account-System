#include "includes/save_account.h"

void saveAccount(Account *acc)
{
  // use the get methods to store data into the file.
  std::string account_id = std::to_string(acc->getAccountId());
  std::string name = acc->getName();
  double balance = acc->getBalance();
  std::string pin = acc->getPin();

  // Set up our folders and files to write to
  std::string account_folder = "/home/alex/Programing/Cpp_Projects/Bank-Account-App/src/user_data/" + account_id;
  std::string account_file_path = account_folder + "/Account_Information.txt";

  std::string pin_file_path = account_folder + "/pin.txt";
  std::string account_id_file_path = account_folder + "/id.txt";
  std::filesystem::create_directories(account_folder);

  std::ofstream account_file(account_file_path);
  std::ofstream pin_file(pin_file_path);
  std::ofstream account_id_file(account_id_file_path);
  if (account_file.is_open() && account_file.good() && pin_file.is_open() && pin_file.good() && account_id_file.is_open() && account_id_file.good())
  {
    account_file << "###################################################\n"
                 << "######## C++ Banking Account Systems LTD   ########\n"
                 << "###################################################\n"
                 << "      Logged in as: " << name << " \n"
                 << "      Account ID: " << account_id << "  \n\n"
                 << "      Balance: " << balance << " EUR\n"
                 << "      Account Options:\n"
                 << "        1. Withdraw\n"
                 << "        2. Deposit\n"
                 << "        3. View Transaction History\n"
                 << "        4. Logout\n"
                 << "###################################################\n";

    /*
            << "###################################################\n"
            << "######## C++ Banking Account Systems LTD   ########\n"
            << "###################################################\n"
            << "      Logged in as: " << name << " \n"
            << "      Account ID: " << account_id << "  \n\n"
            << "      Balance: " << balance << " EUR\n"
            << "      Account Options:\n"
            << "        1. Withdraw\n"
            << "        2. Deposit\n"
            << "        3. View Transaction History\n"
            << "        4. Logout\n"
            << "###################################################\n";
     */
    pin_file << pin;
    account_id_file << account_id;
    account_file.close();
    pin_file.close();
    account_id_file.close();
  }
  else
  {
    std::cerr << "FAILED TO OPEN FILE: " << account_file_path << std::endl;
    std::cout << "HINT: directory \"user_data\" might be missing" << std::endl;
  }
}