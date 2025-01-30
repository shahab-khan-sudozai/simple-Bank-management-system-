#include <iostream>
#include <unordered_map>

using namespace std;

class Bank {
private:
    unordered_map<int, double> accounts; // Account Number -> Balance
    int nextAccountNumber = 1001;

public:
    int createAccount() {
        accounts[nextAccountNumber] = 0.0;
        cout << "Account created! Your account number is: " << nextAccountNumber << endl;
        return nextAccountNumber++;
    }

    void deposit(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber] += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << ".\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdraw(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            if (accounts[accountNumber] >= amount) {
                accounts[accountNumber] -= amount;
                cout << "Withdrew $" << amount << " from account " << accountNumber << ".\n";
            } else {
                cout << "Insufficient balance.\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    void checkBalance(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account " << accountNumber << " balance: $" << accounts[accountNumber] << endl;
        } else {
            cout << "Account not found.\n";
        }
    }
};

int main() {
    Bank bank;
    int choice, accNum;
    double amount;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                accNum = bank.createAccount();
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount: ";
                cin >> amount;
                bank.deposit(accNum, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount: ";
                cin >> amount;
                bank.withdraw(accNum, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accNum;
                bank.checkBalance(accNum);
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
