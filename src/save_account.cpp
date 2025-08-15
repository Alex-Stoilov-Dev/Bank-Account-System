#include "includes/save_account.h"

void save_account(Account *acc)
{
  // Use the get methods to access the variables of our class.
  // Also used to set their values in the file
  std::string account_id = std::to_string(acc->getAccountId());
  std::string name = acc->getName();
  double balance = acc->getBalance();
  std::string pin = acc->getPin();

  // We check if the user data and user list directories exist, and if not we create them.
  // Handles the case where the user deleted the folders accidentally or on purpose.
  if (!std::filesystem::exists("Bank-Account-App/src/user_data/"))
  {
    std::filesystem::create_directories("Bank-Account-App/src/user_data/");
  }
  if (!std::filesystem::exists("Bank-Account-App/src/user_data/"))
  {
    std::filesystem::create_directories("Bank-Account-App/src/user_data/");
  }

  // Set up our folders and files to write to
  std::string account_folder = "Bank-Account-App/src/user_data/" + account_id; // ID Used as directory name
  std::string user_list_tracker = "Bank-Account-App/src/user_list/";
  std::string account_data_path = account_folder + "/Account_Information.txt"; // Data stored in Acc_info.txt
  std::string pin_file_path = account_folder + "/pin.txt";                     // store the pin separately for ease of access
  std::string account_id_file_path = account_folder + "/id.txt";               // Store the ID Separately
  std::string global_id_tracker = user_list_tracker + "/id.txt";

  /*
    ID is stored in the user's data so they are aware of what their ID is for login functionality.
    Last ID is also stored in a specific file, so future account's can have a refrence to it.
  */

  std::filesystem::create_directories(account_folder);

  // Make sure we have access to all of our files
  std::ofstream account_file(account_data_path);
  std::ofstream pin_file(pin_file_path);
  std::ofstream account_id_file(account_id_file_path);
  std::ofstream id_tracker(global_id_tracker);
  if (account_file.is_open() &&
      account_file.good() &&
      pin_file.is_open() &&
      pin_file.good() &&
      account_id_file.is_open() &&
      account_id_file.good() &&
      id_tracker.is_open() &&
      id_tracker.good()
      // Validation checks
  )
  {
    // This is the screen the users sees when logging in;
    account_file
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
    pin_file << pin;
    account_id_file << account_id;
    id_tracker << account_id;

    // Close the files
    account_file.close();
    pin_file.close();
    account_id_file.close();
    id_tracker.close();
  }
  else
  {
    std::cerr << "FAILED TO OPEN FILE: " << account_data_path << std::endl;
    std::cout << "HINT: directory \"user_data\" might be missing" << std::endl;
  }
  delete acc;
}