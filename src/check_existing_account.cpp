#include "includes/check_existing_account.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

bool check_existing_accounts(Account *acc)
{
  int account_id = acc->get_account_id();
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
    acc->increment();
    return true;
  }
  else if (std::to_string(account_id) < stored_id || std::to_string(account_id) > stored_id)
  {
    account_id = std::stoi(stored_id);
    acc->increment();
    return true;
  }

  return false;
}