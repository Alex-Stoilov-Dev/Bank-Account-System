#include "includes/save_account.h"

namespace fs = std::filesystem;

bool check_existing_accounts(Account *acc)
{
  int account_id = acc->get_id();
  // This function is used to check if account's already exist
  // It makes sure that the account's don't have ID 1
  // Also they don't ovewrite

  fs::path user_list_dir = fs::path(PROJECT_ROOT) / "src" / "user_list";

  fs::path id_file = std::string(PROJECT_ROOT) / user_list_dir / "id.txt";
  std::ifstream read_id_file(id_file);
  std::string stored_id;
  std::getline(read_id_file, stored_id);

  if (std::to_string(account_id) == stored_id)
  {
    acc->Increment();
    return true;
  }

  return false;
}

void save_account(Account *acc)
{
  // Use the get methods to access the variables of our class.
  // Also used to set their values in the file
  check_existing_accounts(acc);
  std::string account_id = std::to_string(acc->getAccountId());
  std::string name = acc->getName();
  double balance = acc->getBalance();
  std::string pin = acc->getPin();

  // We check if the user data and user list directories exist, and if not we create them.
  // Handles the case where the user deleted the folders accidentally or on purpose.
  fs::path user_data_dir = fs::path(PROJECT_ROOT) / "src" / "user_data";
  fs::create_directories(user_data_dir);

  fs::path user_list_dir = fs::path(PROJECT_ROOT) / "src" / "user_list";
  fs::create_directories(user_list_dir);

  // Set up our folders and files to write to
  fs::path account_folder = user_data_dir / account_id; // ID Used as directory name
  fs::path user_list_tracker = user_list_dir;
  fs::path account_data_path = account_folder / "Account_Information.txt"; // Data stored in Acc_info.txt
  fs::path pin_file_path = account_folder / "pin.txt";                     // store the pin separately for ease of access
  fs::path account_id_file_path = account_folder / "id.txt";               // Store the ID Separately
  fs::path global_id_tracker = user_list_tracker / "id.txt";

  /*
    ID is stored in the user's data so they are aware of what their ID is for login functionality.
    Last ID is also stored in a specific file, so future account's can have a refrence to it.
  */

  fs::create_directories(account_folder);

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