# Bank System

A C++ banking application that integrates multiple banking systems into one unified application.

The project provides different interfaces for bank users and bank clients, allowing them to manage clients, perform banking transactions, access ATM services, and exchange currencies.

---

## Systems

The application contains three main systems:

### 1. Bank Management System

The Bank Management System is designed for bank users to manage clients and perform banking operations.

#### Client Management

* Add Client
* Update Client
* Find Client
* Delete Client
* List Clients

#### Transactions

* Deposit
* Withdraw
* Total Balances
* Transaction History

#### Other Features

* User Management
* Permissions
* Login System
* Communication System
* Messages Box

---

### 2. ATM System

The ATM System is designed for bank clients to access their accounts and perform common banking operations.

#### ATM Operations

* Client Authentication
* Check Account Balance
* Deposit
* Withdraw
* Quick Withdraw
* Other ATM operations

Unlike the Bank Management System, the ATM is used directly by the **bank client** rather than a bank user.

---

### 3. Currency Exchange System

The Currency Exchange System provides currency-related operations within the same banking application.

#### Currency Operations

* Manage Currencies
* Find Currency
* View Currency Information
* Currency Conversion
* Exchange Rate Calculations

The system supports converting an amount from one currency to another using the available exchange rates.

---

## Application Structure

The application starts with a main menu that allows the user to select the required system:

```text
Bank System
│
└── Main Menu
    │
    ├── Bank Management System
    │   ├── Client Management
    │   │   ├── Add Client
    │   │   ├── Update Client
    │   │   ├── Find Client
    │   │   └── Delete Client
    │   │
    │   └── Transactions
    │       ├── Deposit
    │       ├── Withdraw
    │       ├── Total Balances
    │       └── Transaction History
    │
    ├── ATM System
    │   ├── Client Authentication
    │   ├── Check Balance
    │   ├── Deposit
    │   ├── Withdraw
    │   └── Quick Withdraw
    │
    └── Currency Exchange System
        ├── Currency Management
        ├── Find Currency
        └── Currency Conversion
```

---

## Users and Clients

The application distinguishes between the two main types of people interacting with the system.

### Bank User

The bank user works with the **Bank Management System** and can manage clients and perform administrative banking operations.

### Bank Client

The bank client uses the **ATM System** to access their own account and perform banking operations.

```text
Bank User
    ↓
Bank Management System
    ↓
Manage Clients & Banking Operations


Bank Client
    ↓
ATM System
    ↓
Access Account & Perform ATM Operations
```

---

## Main Features

* Client management
* User management
* Authentication and login
* Permissions
* Deposits and withdrawals
* Quick withdrawal
* Balance inquiry
* Transaction history
* Communication between users
* Messages box
* Currency management
* Currency conversion
* File-based data storage

---

## Technologies

* C++
* Object-Oriented Programming (OOP)
* File Handling
* Data Structures
* Templates
* Exception Handling
* Git & GitHub

---

## Project Goals

This project was developed as a practical application of C++ and Object-Oriented Programming concepts.

The project focuses on:

* Applying OOP concepts in a real-world style application
* Designing reusable and maintainable classes
* Separating business logic from user interface logic
* Working with files for persistent data storage
* Building multiple systems that work together within one application
* Continuously extending an existing system with new features

---

## Project Evolution

The project started as a Bank Management System and was gradually expanded by integrating additional systems and features.

```text
Bank Management System
        │
        ├── ATM System
        │
        └── Currency Exchange System
                ↓
           Bank System
```

The result is a unified banking application containing multiple systems that serve different purposes while working with the same overall banking environment.

---

## Author

**Mohammed Mahmoud Rajab Agha**
