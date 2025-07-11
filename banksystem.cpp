#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    void createAccount() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
        } else {
            balance -= amount;
            cout << "Amount Withdrawn Successfully. New Balance: " << balance << endl;
        }
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    BankAccount account;
    int choice;
    double amount;

    cout << "=== Welcome to Bank Management System ===" << endl;

    account.createAccount();

    do {
        cout << "\n1. Display Account\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                account.displayAccount();
                break;
            case 2:
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                if (cin.fail() || amount <= 0) {
                    cout << "Invalid amount.\n";
                    clearInputBuffer();
                } else {
                    account.deposit(amount);
                }
                break;
            case 3:
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                if (cin.fail() || amount <= 0) {
                    cout << "Invalid amount.\n";
                    clearInputBuffer();
                } else {
                    account.withdraw(amount);
                }
                break;
            case 4:
                cout << "Thank you! Exiting..." << endl;
                break;
            default:
                cout << "Invalid Choice. Try Again." << endl;
        }
    } while (choice != 4);

    return 0;
}
