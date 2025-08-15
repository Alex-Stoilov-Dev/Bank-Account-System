#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "account.h"

bool check_existing_accounts(Account *acc);
void save_account(Account *acc);