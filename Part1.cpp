#include <iostream>
#include <string>
using namespace std;

// Global arrays to store account information
int *accountNum;
string *accHolderNames;
double *accountBalances;
string *accountType;

int account_count = 0;
int capacity = 5; 

//to expand peresvious arrays when they get full
void expandArrays() {
    int new_capacity = capacity * 2;

    // Creating new arrays with larger capacity
    int *newaccountNums = new int[new_capacity];
    string *newaccHolderNames = new string[new_capacity];
    double *newAccountBalances = new double[new_capacity];
    string *newaccountType = new string[new_capacity];

    // Copy data from old arrays to new arrays
    for (int i = 0; i < account_count; i++) {
        newaccountNums[i] = accountNum[i];
        newaccHolderNames[i] = accHolderNames[i];
        newAccountBalances[i] = accountBalances[i];
        newaccountType[i] = accountType[i];
    }

    // Deleting previous arrays
    delete[] accountNum;
    delete[] accHolderNames;
    delete[] accountBalances;
    delete[] accountType;

    // Pointing to new arrays
    accountNum = newaccountNums;
    accHolderNames = newaccHolderNames;
    accountBalances = newAccountBalances;
    accountType = newaccountType;

    capacity = new_capacity;
    cout << "Arrays expanded to capacity: " << capacity << endl;
}

// Function to find account index by account number
int findAccountIndex(int acc_number) {
    for (int i = 0; i < account_count; i++) {
        if (accountNum[i] == acc_number) {
            return i;
        }
    }
    return -1; // Account not found
}

// Function to open a new account
void openAccount() {
    if (account_count == capacity) {
        expandArrays(); //capacity increases, so expand arrays to make new accout.
    }
    int acc_number;
    cout << "Enter Account Number: ";
    cin >> acc_number;
    
    // Check if account number already exists
    if (findAccountIndex(acc_number) != -1) {
        cout << "Account number already exists!" << endl;
        return;
    }

    accountNum[account_count] = acc_number;

    cout << "Enter Account Holder Name: ";
    cin.ignore(); 
    getline(cin, accHolderNames[account_count]);

    cout << "Enter Account Type (Savings/Checking): ";
    cin >> accountType[account_count];

    cout << "Enter Initial Balance: ";
    cin >> accountBalances[account_count];

    if (accountBalances[account_count] < 0) {
        cout << "Invalid Input, Try Again!" << endl;
        accountBalances[account_count] = 0;
    }

    account_count++;
    cout << "Account created successfully!" << endl;
}

// Function to deposit funds with amount parameter
void depositFunds(int acc_Number, double amount) {
    int idx = findAccountIndex(acc_Number);
    if (idx == -1) {
        cout << "Account not found!" << endl;
        return;
    }
    
    if (amount <= 0) {
        cout << "Insufficeint Funds! Try Again" << endl;
        return;
    }
    
    accountBalances[idx] += amount;
    cout << "Deposit successful. Updated Balance: $" << accountBalances[idx] << endl;
}

// Overloaded deposit function without amount parameter
void depositFunds(int acc_number) {
    depositFunds(acc_number, 100.0); // Default deposit of $100
}

// Function to withdraw funds with amount parameter
void withdrawFunds(int acc_Number, double amount) {
    int idx = findAccountIndex(acc_Number);
    if (idx == -1) {
        cout << "Account not found!" << endl;
        return;
    }
    
    if (amount <= 0) {
        cout << "Withdrawal amount must be positive!" << endl;
        return;
    }
    
    if (accountBalances[idx] < amount) {
        cout << "Insufficient funds! Current balance: $" << accountBalances[idx] << endl;
        return;
    }
    
    accountBalances[idx] -= amount;
    cout << "Withdrawal successful. Updated Balance: $" << accountBalances[idx] << endl;
}

// Overloaded withdraw function without amount parameter
void withdrawFunds(int acc_number) {
    withdrawFunds(acc_number, 50.0); // Default withdrawal of $50
}

// Function to display all accounts
void displayAllAccounts() {
    if (account_count == 0) {
        cout << "No accounts to display!" << endl;
        return;
    }
    
    cout << "\n================================ ALL ACCOUNTS ================================" << endl;
    cout << "Account Number\tAccount Holder\t\tType\t\tBalance" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < account_count; i++) {
        cout << accountNum[i] << "\t\t" << accHolderNames[i] << "\t\t" 
             << accountType[i] << "\t\t$" << accountBalances[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}

// Function to view account balance
void viewAccountBalance(int acc_Number) {
    int idx = findAccountIndex(acc_Number);
    if (idx == -1) {
        cout << "Account not found!" << endl;
        return;
    }
    
    cout << "Account Holder: " << accHolderNames[idx] << endl;
    cout << "Account Type: " << accountType[idx] << endl;
    cout << "Account Balance: $" << accountBalances[idx] << endl;
}

// Function to initialize the arrays
void initializeArrays() {
    accountNum = new int[capacity];
    accHolderNames = new string[capacity];
    accountBalances = new double[capacity];
    accountType = new string[capacity];
}

int main() {
    // Initialize arrays
    initializeArrays();

    int choice;
    
    cout << "Welcome to Bank Account Management System" << endl;
    
    do {
        cout << "\n1. Open Account\n2. Deposit Funds\n3. Withdraw Funds\n4. Display All Accounts\n5. View Account Balance\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                openAccount();
                break;
            case 2: {
                if (account_count == 0) {
                    cout << "No accounts exist yet!" << endl;
                    break;
                }
                
                int accNumber;
                double amount;
                char option;
                
                cout << "Enter Account Number: ";
                cin >> accNumber;
                
                cout << "Do you want to specify an amount? (y/n): ";
                cin >> option;
                
                if (option == 'y' || option == 'Y') {
                    cout << "Enter amount to deposit: $";
                    cin >> amount;
                    depositFunds(accNumber, amount);
                } else {
                    depositFunds(accNumber);
                }
                break;
            }
            case 3: {
                if (account_count == 0) {
                    cout << "No accounts exist yet!" << endl;
                    break;
                }
                
                int accNumber;
                double amount;
                char option;
                
                cout << "Enter Account Number: ";
                cin >> accNumber;
                
                cout << "Do you want to specify an amount? (y/n): ";
                cin >> option;
                
                if (option == 'y' || option == 'Y') {
                    cout << "Enter amount to withdraw: $";
                    cin >> amount;
                    withdrawFunds(accNumber, amount);
                } else {
                    withdrawFunds(accNumber);
                }
                break;
            }
            case 4:
                displayAllAccounts();
                break;
            case 5: {
                if (account_count == 0) {
                    cout << "No accounts exist yet!" << endl;
                    break;
                }
                
                int accNumber;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                viewAccountBalance(accNumber);
                break;
            }
            case 6:
                cout << "Thank you for using the Bank Account Management System!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    // Clean up dynamically allocated memory
    delete[] accountNum;
    delete[] accHolderNames;
    delete[] accountBalances;
    delete[] accountType;

    return 0;
}
