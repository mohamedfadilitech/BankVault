# 🏦💳 BankVault — C++

A console-based Bank Client Management System built in C++. Manage your clients with ease — add, update, delete, search, and list all bank accounts stored in a persistent text-based database.

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
	 [6] Exit.
================================================
Choose What Do You Want To Do ? [1 To 6] ? 1

======================================
	 Show Client List Screen
======================================

			 Clients List(7)
=================================================================================================================
| Account Id   | pin code             | Full Name            | Phone                | Account balance
=================================================================================================================
| A151         | 1234                 | Ali Fadi             | 07555552             | 2000
| A152         | 1234                 | Maher Ahmed          | 666666               | 5000
| A900         | 7827                 | Mohamed Fadili       | 02837162             | 12000
...
=================================================================================================================

 Press Any Key To Go Back To The Main Menu .....
```

---

## ✨ Features

* 📋 **List all clients** — displays a formatted table with all stored bank accounts
* ➕ **Add new client** — register a new client with account ID, pin, name, phone, and balance
* 🗑️ **Delete client** — search by account ID and permanently remove the record
* ✏️ **Update client info** — modify any client's details while keeping their account ID
* 🔍 **Find client** — look up a client by account ID and view their full details
* 💾 **Persistent storage** — all data is saved to and loaded from `clientsData.txt`
* 🚫 **Duplicate prevention** — blocks adding a client with an already-existing account ID
* 🔄 **Navigation** — return to the main menu after every action without relaunching

---

## 🛠️ Built With

* **Language:** C++
* **Standard Library:** `iostream`, `fstream`, `vector`, `string`, `iomanip`, `cctype`
* **Concepts used:**
  * Structs (`stClient`)
  * Header file separation (`menu.h`, `clientList.h`, `addNewClient.h`, `deleteClient.h`, `update.h`)
  * File I/O (read, write, truncate)
  * Vector operations (CRUD on in-memory data)
  * String parsing with custom delimiter (`#//#`)
  * Input validation and do-while loops
  * Console system commands (`cls`, `pause`)

---

## 🚀 Getting Started

### Prerequisites

You need a C++ compiler installed:

* **Windows:** MinGW / MSVC
* **Linux/macOS:** `g++` via GCC

### Compile & Run

```bash
# Clone the repository
git clone https://github.com/your-username/bankvault-cpp.git
cd bankvault-cpp

# Compile
g++ project.cpp -o BankVault

# Run
./BankVault        # Linux / macOS
BankVault.exe      # Windows
```

> ⚠️ **Note:** The `system("cls")` and `system("pause")` commands are Windows-specific. On Linux/macOS, replace them with `system("clear")` and a manual pause using `cin.get()`.

---

## 📁 Project Structure

```
bankvault-cpp/
│
├── project.cpp          # Entry point — main menu logic
├── menu.h               # Menu display and input
├── clientList.h         # Struct definition, file reading, table display
├── addNewClient.h       # Add new client logic
├── deleteClient.h       # Delete client logic
├── update.h             # Update client logic
├── clientsData.txt      # Persistent client database
└── README.md            # Project documentation
```

---

## 🧠 How It Works

Client records are stored in `clientsData.txt` using a custom `#//#` delimiter format:

```
A900#//#7827#//#Mohamed Fadili#//#02837162#//#12000.000000
```

On every operation, the file is fully read into a `vector<stClient>`, modified in memory, then written back to disk. This keeps the data consistent across all CRUD operations.

| Field           | Example        |
|-----------------|----------------|
| Account ID      | A900           |
| Pin Code        | 7827           |
| Full Name       | Mohamed Fadili |
| Phone           | 02837162       |
| Account Balance | 12000.00       |

---

## 🔮 Future Improvements

* Input validation for non-numeric balance entries
* Encrypted pin code storage
* Login system with pin authentication
* Transaction history (deposits & withdrawals)
* Cross-platform color and clear screen support
* Export client list to CSV
* Replace flat-file storage with SQLite

---

## 👤 Author

* GitHub: mohamedfadilitech

---

## 📄 License

This project is open source and available under the **MIT License**.
