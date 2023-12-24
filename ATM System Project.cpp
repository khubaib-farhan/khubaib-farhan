#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Account {
private:
    int accountNumber;
    float balance;  

public:
    Account(int number, float b) : accountNumber(number), balance(b) {}

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(float amount) {
        if (amount >= 100) {
            balance += amount;
        } else {
            cout << "Minimum Deposit Amount is $100!" << endl;
        }
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds in Current Account!" << endl;
        }
    }

    float getBalance() {
        return balance;
    }

    void display() {
        cout << "Account Type: Current" << endl;
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Balance: $" << getBalance() << endl;
    }
};

class SavingsAccount {
private:
    Account account;
    float savingBalance;
    float savingPercentage;

public:
    SavingsAccount(int number, float b)
        : account(number, b), savingPercentage(20.0 / 100.0) {
        savingBalance = account.getBalance() * savingPercentage;
    }

    float getSavingBalance() {
        return savingBalance;
    }

    void withdraw(float amount) {
        if (amount <= savingBalance) {
            savingBalance -= amount;
        } else {
            cout << "Insufficient funds in Savings Account!" << endl;
        }
    }

    void deposit(float amount) {
        savingBalance += amount;
        account.deposit(amount);
    }

    void display() {
        cout << "Account Type: Savings" << endl;
        cout << "Account Number: " << account.getAccountNumber() << endl;
        cout << "Balance: $" << getSavingBalance() << endl;
    }
};

class Bank {
private:
    string bankName;
    Account account;
    SavingsAccount savingsAccount;

public:
    Bank(const string& name, int number, float balance)
        : bankName(name), account(number, balance), savingsAccount(number, balance) {}

    void displayAccounts() {
        account.display();
        savingsAccount.display();
    }

    void withdrawFromSavingsAccount(float amount) {
        account.withdraw(amount);
        savingsAccount.withdraw(amount);
    }

    void depositToSavingsAccount(float amount) {
        account.deposit(amount);
        savingsAccount.deposit(amount);
    }

    void withdrawFromCurrentAccount(float amount) {
        account.withdraw(amount);
    }

    void depositToCurrentAccount(float amount) {
        account.deposit(amount);
    }

    const string& getBankName() {
        return bankName;
    }
};

class Person {
private:
    string name;
    string password;
    Bank* bank;

public:
    Person(const string& n, const string& pw, Bank* b) : name(n), password(pw), bank(b) {}

    const string& getName() {
        return name;
    }

    void displayAccounts() {
        cout << "Accounts for " << name << " in " << bank->getBankName() << ":" << endl;
        bank->displayAccounts();
    }

    void withdrawFromSavingsAccount(float amount) {
        cout << name << " is withdrawing $" << amount << " from savings account." << endl;
        bank->withdrawFromSavingsAccount(amount);
    }

    void depositToSavingsAccount(float amount) {
        cout << name << " is depositing $" << amount << " to savings account." << endl;
        bank->depositToSavingsAccount(amount);
    }

    void withdrawFromCurrentAccount(float amount) {
        cout << name << " is withdrawing $" << amount << " from current account." << endl;
        bank->withdrawFromCurrentAccount(amount);
    }

    void depositToCurrentAccount(float amount) {
        cout << name << " is depositing $" << amount << " to current account." << endl;
        bank->depositToCurrentAccount(amount);
    }

    bool authenticate() {
        string userName;
        string userPassword;
        int attempts = 3;

        while (attempts > 0) {
            cout << "Enter your name: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> userPassword;

            if (userName == name && userPassword == password) {
                cout << "Authentication successful!" << endl;
                return true;
            } else {
                cout << "Incorrect name or password entered. Please try again." << endl;
                attempts--;
            }
        }

        cout << "Too many incorrect attempts. Exiting." << endl;
        return false;
    }
};

float getValidAmount() {
    float amount;
    while (!(cin >> amount) || cin.peek() != '\n') {
        cout << "Invalid amount. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return amount;
}

int getValidBankChoice() {
    int bankChoice;
    while (!(cin >> bankChoice) || (bankChoice != 1 && bankChoice != 2)) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return bankChoice;
}

int main() {
    Bank* hblBank = new Bank[5]{
        Bank("HBL Bank", 123, 2000.0),
        Bank("HBL Bank", 223, 3000.0),
        Bank("HBL Bank", 323, 4000.0),
        Bank("HBL Bank", 423, 5000.0),
        Bank("HBL Bank", 523, 6000.0)
    };

    Bank* alliedBank = new Bank[5]{
        Bank("Allied Bank", 156, 1000.0),
        Bank("Allied Bank", 256, 2000.0),
        Bank("Allied Bank", 356, 3000.0),
        Bank("Allied Bank", 456, 4000.0),
        Bank("Allied Bank", 556, 5000.0)
    };

    int bankChoice;

    cout << "Choose the bank:" << endl;
    cout << "1. HBL Bank" << endl;
    cout << "2. Allied Bank" << endl;
    cout << "Choice: ";
    bankChoice = getValidBankChoice();

    Bank* selectedBank;

    switch (bankChoice) {
        case 1:
            selectedBank = &hblBank[1];
            break;
        case 2:
            selectedBank = &alliedBank[1];
            break;
        default:
            cout << "Invalid bank choice. Exiting." << endl;
            delete[] hblBank;
            delete[] alliedBank;
            return 0;
    }

    Person* person = new Person[5]{
        Person("Ali", "pass1", selectedBank),
        Person("usman", "pass2", selectedBank),
        Person("hamza", "pass3", selectedBank),
        Person("Ahmed", "pass4", selectedBank),
        Person("farhan", "pass5", selectedBank)
    };

    if (!person[1].authenticate()) {
        delete[] person;
        delete[] hblBank;
        delete[] alliedBank;
        return 0;
    }

    person[1].displayAccounts();

    int transactionType;
    cout << "Choose the transaction type:" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "Choice: ";
    transactionType = getValidBankChoice();

    int accountType;
    cout << "Choose the account type:" << endl;
    cout << "1. Current Account" << endl;
    cout << "2. Savings Account" << endl;
    cout << "Choice: ";
    accountType = getValidBankChoice();

    float amount;
    cout << "Enter the amount: $";
    amount = getValidAmount();

    switch (transactionType) {
        case 1:  // Deposit
            if (accountType == 1) {
                person[1].depositToCurrentAccount(amount);
            } else if (accountType == 2) {
                person[1].depositToSavingsAccount(amount);
            } else {
                cout << "Invalid account type. Exiting." << endl;
                delete[] person;
                delete[] hblBank;
                delete[] alliedBank;
                return 0;
            }
            break;
        case 2:  // Withdraw
            if (accountType == 1) {
                person[1].withdrawFromCurrentAccount(amount);
            } else if (accountType == 2) {
                person[1].withdrawFromSavingsAccount(amount);
            } else {
                cout << "Invalid account type. Exiting." << endl;
                delete[] person;
                delete[] hblBank;
                delete[] alliedBank;
                return 0;
            }
            break;
        default:
            cout << "Invalid transaction type. Exiting." << endl;
            delete[] person;
            delete[] hblBank;
            delete[] alliedBank;
            return 0;
    }

    cout << endl;
    person[1].displayAccounts();

    delete[] person;
    delete[] hblBank;
    delete[] alliedBank;

    return 0;
}

