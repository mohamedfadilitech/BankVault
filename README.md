# 🏦💳 BankVault — C++

A console-based Bank Management System built in C++. Manage clients and system users with a full authentication system, role-based permissions, and persistent file storage — all without any external libraries or frameworks.

---

## 🚀 What's New in V2

V1 was a client management system. V2 is a full banking backend with:

- 🔐 **Login system** — username & password authentication
- 👥 **User management** — add, delete, update, and list system users
- 🛡️ **Bitwise permission system** — fine-grained access control per user
- 🚫 **Access denied screen** — blocked operations show a clear denial message
- 🔄 **Logout & re-login** — session management without restarting the program

---

## 🎮 App Preview

```
======================================
	 Login Screen
======================================
Enter The userName :
Enter The password :
```

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
	 [7] Manage Users.
	 [8] Logout.
================================================
```

```
================================================
		Manage Users
================================================
	 [1] List Users.
	 [2] Add New User.
	 [3] Delete User.
	 [4] Update User Info.
	 [5] Find User.
	 [6] Main Menu.
================================================
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

### 🔐 Authentication
* **Login screen** — verifies credentials against `users.txt` before granting access
* **Session loop** — logout returns to login screen instead of closing the program
* **Invalid credentials handling** — keeps prompting until a valid login is entered

### 🛡️ Permission System
* **Bitwise permissions** — each permission is a bit flag stored as a single integer
* **Per-user access control** — every user has a custom set of allowed operations
* **Admin mode** — permissions value of `-1` grants full access to everything
* **Dynamic menu** — options are hidden if the user doesn't have permission for them
* **Access denied screen** — shown when a user attempts a blocked operation

### 👤 Client Management
* 📋 **List all clients** — formatted table with all stored bank accounts
* ➕ **Add new client** — register with account ID, pin, name, phone, and balance
* 🗑️ **Delete client** — search by account ID and permanently remove the record
* ✏️ **Update client info** — modify any client's details while keeping their account ID
* 🔍 **Find client** — look up a client by account ID and view their full details
* 🚫 **Duplicate prevention** — blocks adding a client with an already-existing account ID

### 👥 User Management
* 📋 **List all users** — displays all system users with their permission values
* ➕ **Add new user** — register a new user and assign permissions interactively
* 🗑️ **Delete user** — remove a system user by username
* ✏️ **Update user** — modify password and permissions for any user
* 🔍 **Find user** — look up a user by username

### 💰 Transactions
* **Deposit** — add funds to any client's account balance
* **Withdraw** — deduct funds with a balance check to prevent overdraft
* **Total balances** — view all accounts with a combined total balance

### 💾 Storage
* All client data saved to and loaded from `clientsData.txt`
* All user data saved to and loaded from `users.txt`
* Custom `#//#` delimiter for record parsing

---

## 🛡️ How Permissions Work

Each permission is a power of 2 (bit flag). A user's total permissions value is the sum of all granted permissions:

| Permission | Value |
|---|---|
| Show Client List | 1 |
| Add New Client | 2 |
| Delete Client | 4 |
| Update Client | 8 |
| Find Client | 16 |
| Transactions | 32 |
| Manage Users | 64 |
| Admin (All) | -1 |

**Example:** A user with permissions `= 19` has access to:
- Show Client List `(1)`
- Add New Client `(2)`
- Find Client `(16)`

This is stored in `users.txt` as a single integer:
```
ahmed#//#1234#//#19
```

---

## 🧠 How It Works

### Client records — `clientsData.txt`
```
A900#//#7827#//#Mohamed Fadili#//#02837162#//#12000.000000
```

### User records — `users.txt`
```
Admin#//#1234#//#-1
ahmed#//#pass123#//#19
```

On every operation, the file is fully read into a vector, modified in memory, then written back to disk.

---

## 🛠️ Built With

* **Language:** C++
* **Standard Library:** `iostream`, `fstream`, `vector`, `string`, `iomanip`, `cctype`
* **Concepts used:**
  + Multi-file architecture (`.h` declarations, `.cpp` definitions)
  + Structs (`stClient`, `stUser`)
  + File I/O (read, write, truncate, append)
  + Bitwise operators for permission checking
  + Vector CRUD operations
  + String parsing with custom delimiter
  + Output parameters for multi-value returns
  + Input validation with do-while loops
  + Session management with logout loop

---

## 🚀 Getting Started

### Prerequisites

* **Windows:** MSVC (Visual Studio)
* **Linux/macOS:** `g++` via GCC

### Option 1 — Visual Studio (Recommended ⭐)

1. Download [Visual Studio Community](https://visualstudio.microsoft.com/) — free
2. During install, select **"Desktop development with C++"**
3. Open Visual Studio → **Create a new project** → **Empty Project (C++)**
4. Add all `.h`, `.cpp`, `clientsData.txt`, and `users.txt` files via **Project → Add Existing Item**
5. Press `Ctrl + F5` to compile and run

### Option 2 — g++ via Terminal

```bash
# Clone the repository
git clone https://github.com/mohamedfadilitech/BankVault.git
cd BankVault

# Compile all source files
g++ project.cpp clientList.cpp menu.cpp deleteClient.cpp addNewClient.cpp \
    update.cpp transaction.cpp login.cpp addUser.cpp deleteUser.cpp \
    updateUser.cpp usersList.cpp manageUsers.cpp -o BankVault

# Run
./BankVault        # Linux / macOS
BankVault.exe      # Windows CMD
```

> ⚠️ Make sure `clientsData.txt` and `users.txt` are in the **same directory** as the executable.

---

## 📁 Project Structure

```
BankVault/
│
├── project.cpp           # Entry point — login flow and main menu dispatch
├── menu.h / menu.cpp     # Menu display, permission-aware rendering
│
├── clientList.h/.cpp     # stClient struct, file reading, table display
├── addNewClient.h/.cpp   # Add new client logic
├── deleteClient.h/.cpp   # Delete client + shared utilities (join, removeTheMatch)
├── update.h/.cpp         # Update client logic
├── updateClient.h/.cpp   # Update client screen
├── transaction.h/.cpp    # Deposit, withdraw, total balances
│
├── login.h/.cpp          # stUser struct, authentication, FileToStUser
├── addUser.h/.cpp        # Add new user + permission assignment
├── deleteUser.h/.cpp     # Delete user logic
├── updateUser.h/.cpp     # Update user logic
├── usersList.h/.cpp      # List all users
├── manageUsers.h/.cpp    # Manage users menu and dispatch
│
├── clientsData.txt       # Persistent client database
├── users.txt             # Persistent user database
└── README.md
```

---

## 🔮 Future Improvements

* Password encryption (XOR / Caesar cipher)
* Input validation for non-numeric entries
* Transaction history log per client
* Export client list to CSV
* Replace flat-file storage with SQLite
* Cross-platform clear screen support

---

## 📌 Versions

| Version | Description |
|---|---|
| V1 | Client management — add, delete, update, find, list, transactions |
| V2 | Added login system, user management, and bitwise permission control |

---

## 👤 Author

* GitHub: [@mohamedfadilitech](https://github.com/mohamedfadilitech)

---

## 📄 License

This project is open source and available under the **MIT License**.