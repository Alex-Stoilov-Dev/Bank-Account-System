# Bank Account System

This is a C++ application that allows users to:
- Create Bank Accounts, with balance, name, PINs, and unique IDs.
- The program Automatically saves the account to the "User_Data" directory.
  
# Building The App
For the build, we are using cmake. After forking the repo, you can build it like so:
```
cd build/
cmake --build .
```
This code is writen in C++23, but it only require's C++17 and above.
# Todo
We still need to add more functionality, like:
  1. Login with account number’s & PIN
  2. Deposit / Withdraw Methods
  3. Implement transaction history, and make it viewable.
  4. Save and Load data from the filesystem:
     - Currently only saves data
