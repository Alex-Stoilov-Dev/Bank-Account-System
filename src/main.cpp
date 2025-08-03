#include "includes/account.h"
#include "includes/create_account.h"
#include "includes/save_account.h"

int main()
{
  Account *p_Account = createAccount();
  saveAccount(p_Account);
  p_Account->display();
  delete p_Account;
}
