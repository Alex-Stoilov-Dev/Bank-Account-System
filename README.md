# Bank Account System

This is a C++ application that allows users to:  
- Create bank accounts with balance, name, PIN, and unique IDs.  
- Automatically save accounts to the `user_data` directory.  
- Track the latest account IDs globally in the `user_list` directory.
- Working Login Functionality

---

## Building the App

This project uses **CMake**, and it works on **Linux, macOS, and Windows**. The code is written in C++23 but only requires **C++20 or above**.  

### Cross-Platform Build Instructions

Open a terminal (Linux/macOS) or PowerShell / Command Prompt (Windows) and run:

```bash
# From the project root
cmake -S . -B build         # Configure the project and generate build files
cmake --build build --config Release  # Build the project
```
After building, you can run the executable:

- **Linux/macOS**:
```bash
./build/bank-account-system
```
- **Windows (PowerShell or CMD)**:
```bash
.\build\Release\bank-account-system.exe
```
TODO / Up coming features
-
- Deposit / Withdraw methods.
- Implement transaction history and make it viewable.
- Add Basic File Encryption
