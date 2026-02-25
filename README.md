# 🏦💳 BankVault — C++

A console-based Bank Client Management System built in C++. Manage your clients with ease — add, update, delete, search, list all bank accounts, and perform deposits & withdrawals. All data is stored persistently in a text-based database.

---

## 🎮 App Preview

```
================================================
		Main Menu
================================================
	 [1] Show Client List.
	 [2] Add New Client.
	 [3] Delete Client.
	 [4] Update Client Info.
	 [5] Find Client.
	 [6] Transaction.
	 [7] Exit.
================================================
Choose What Do You Want To Do ? [1 To 7] ?
```

```
================================================
		Transaction Menu Screen
================================================
	 [1] Deposit.
	 [2] Withdraw.
	 [3] Total Balance.
	 [4] Main Menu.
================================================
```

---

## ✨ Features

* 📋 **List all clients** — displays a formatted table with all stored bank accounts
* ➕ **Add new client** — register a new client with account ID, pin, name, phone, and balance
* 🗑️ **Delete client** — search by account ID and permanently remove the record
* ✏️ **Update client info** — modify any client's details while keeping their account ID
* 🔍 **Find client** — look up a client by account ID and view their full details
* 💰 **Deposit** — add funds to any client's account balance
* 💸 **Withdraw** — deduct funds with a balance check to prevent overdraft
* 📊 **Total balances** — view all accounts with a combined total balance
* 💾 **Persistent storage** — all data is saved to and loaded from `clientsData.txt`
* 🚫 **Duplicate prevention** — blocks adding a client with an already-existing account ID

---

## 🛠️ Built With

* **Language:** C++
* **Standard Library:** `iostream`, `fstream`, `vector`, `string`, `iomanip`, `cctype`
* **Concepts used:**
  + Structs (`stClient`)
  + Proper header/source separation (`.h` declarations, `.cpp` definitions)
  + File I/O (read, write, truncate, append)
  + Vector operations (CRUD on in-memory data)
  + String parsing with custom delimiter (`#//#`)
  + Input validation and do-while loops
  + Multi-file compilation

---

## 🚀 Getting Started

### Prerequisites

You need a C++ compiler installed:

* **Windows:** MinGW / MSVC (Visual Studio)
* **Linux/macOS:** `g++` via GCC

### Compile & Run

```bash
# Clone the repository
git clone https://github.com/mohamedfadilitech/BankVault.git
cd BankVault

# Compile all source files
g++ project.cpp clientList.cpp menu.cpp deleteClient.cpp addNewClient.cpp update.cpp transaction.cpp -o BankVault

# Run
./BankVault        # Linux / macOS
BankVault.exe      # Windows
```

> ⚠️ **Note:** `system("cls")` and `system("pause")` are Windows-specific. On Linux/macOS replace `system("cls")` with `system("clear")`.

> ⚠️ **Important:** Make sure `clientsData.txt` is in the **same directory** as the executable when running.

---

## 📁 Project Structure

```
BankVault/
│
├── project.cpp           # Entry point — main menu logic
├── menu.h / menu.cpp     # Menu display and input
├── clientList.h          # Struct definition, file reading, table display
├── clientList.cpp        
├── addNewClient.h        # Add new client logic
├── addNewClient.cpp      
├── deleteClient.h        # Delete + shared utilities (join, removeTheMatch)
├── deleteClient.cpp      
├── update.h              # Update client logic
├── update.cpp            
├── transaction.h         # Deposit, withdraw, total balances
├── transaction.cpp       
├── clientsData.txt       # Persistent client database
└── README.md
```

---

## 🧠 How It Works

Client records are stored in `clientsData.txt` using a custom `#//#` delimiter:

```
A900#//#7827#//#Mohamed Fadili#//#02837162#//#12000.000000
```

On every operation, the file is fully read into a `vector<stClient>`, modified in memory, then written back to disk.

| Field | Example |
|---|---|
| Account ID | A900 |
| Pin Code | 7827 |
| Full Name | Mohamed Fadili |
| Phone | 02837162 |
| Account Balance | 12000.00 |

---

## 🔮 Future Improvements

* Input validation for non-numeric entries
* Encrypted pin code storage
* Login system with pin authentication
* Transaction history log
* Cross-platform clear screen support
* Export client list to CSV
* Replace flat-file storage with SQLite

---

## 👤 Author

* GitHub: [@mohamedfadilitech](https://github.com/mohamedfadilitech)

---

## 📄 License

This project is open source and available under the **MIT License**.