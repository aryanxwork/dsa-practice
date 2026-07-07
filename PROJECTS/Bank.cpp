#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std; //  Bank Management System
// PAPPU BANK OF INDIA

// ----------- COLOR UTILITIES -----------
void Green() { cout << "\033[1;32m"; }
void Red() { cout << "\033[1;31m"; }
void Yellow() { cout << "\033[1;33m"; }
void Blue() { cout << "\033[1;34m"; }
void reset() { cout << "\033[0m"; }

// ----------- UI HELPERS -----------
void line()
{
    cout << "==================================================" << endl;
}
void smallLine()
{
    cout << "--------------------------------------------------" << endl;
}
void pause()
{
    cout << "\nPress Enter to continue...";
    cin.get();
    system("cls");
}

// ----------- BANK CLASS -----------
class Bank
{
private:
    string bankName = "PBOI";
    int bankIFSCcode;
    string accountHolderName;
    string accountNumber;
    double balance;
    string accountPassword;
    string email;
    string phoneNumber;
    string adhaarNumber;
    vector<string> transactions;

public:
    void savetoFile();
    void loadFromFile();
    void mainMenu();
    void createAccount();
    void loginAccount();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    void displayAccountDetails();
    void transactionHistory();
};

// ----------- FILE HANDLING -----------
void Bank::savetoFile()
{
    ofstream file(accountNumber + ".txt");
    if (file.is_open())
    {
        file << accountHolderName << endl
             << accountNumber << endl
             << accountPassword << endl
             << adhaarNumber << endl
             << email << endl
             << phoneNumber << endl
             << balance << endl;

        for (auto transaction : transactions)
            file << transaction << endl;

        file.close();
    }
}

void Bank::loadFromFile()
{
    ifstream file(accountNumber + ".txt");
    if (file.is_open())
    {
        getline(file, accountHolderName);
        getline(file, accountNumber);
        getline(file, accountPassword);
        getline(file, adhaarNumber);
        getline(file, email);
        getline(file, phoneNumber);
        file >> balance;
        file.ignore();

        transactions.clear();
        string transaction;
        while (getline(file, transaction))
            transactions.push_back(transaction);

        file.close();
    }
}

// ----------- MAIN ACCOUNT MENU -----------
void Bank::mainMenu()
{
    int choice;
    do
    {
        Blue();
        line();
        cout << "        WELCOME TO " << bankName << " - ACCOUNT MENU" << endl;
        line();
        reset();

        cout << " 1. Deposit Money" << endl;
        cout << " 2. Withdraw Money" << endl;
        cout << " 3. Check Balance" << endl;
        cout << " 4. Display Account Details" << endl;
        cout << " 5. Transaction History" << endl;
        cout << " 6. Logout" << endl;
        smallLine();
        cout << " Enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice)
        {
        case 1:
            depositMoney();
            break;
        case 2:
            withdrawMoney();
            break;
        case 3:
            checkBalance();
            break;
        case 4:
            displayAccountDetails();
            break;
        case 5:
            transactionHistory();
            break;
        case 6:
            cout << "Logging out..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
        pause();
    } while (choice != 6);
}

// ----------- CREATE ACCOUNT -----------
void Bank::createAccount()
{
    Green();
    line();
    cout << "            CREATE NEW ACCOUNT" << endl;
    line();
    reset();

    cout << " Account Holder Name : ";
    getline(cin, accountHolderName);
    cout << " Email ID            : ";
    getline(cin, email);
    cout << " Phone Number        : ";
    getline(cin, phoneNumber);
    cout << " Aadhaar Number      : ";
    getline(cin, adhaarNumber);
    cout << " Set Password        : ";
    getline(cin, accountPassword);

    balance = 500.0;

    ifstream file("PBOI.txt");
    if (!file)
    {
        ofstream init("PBOI.txt");
        init << 1000;
        init.close();
        bankIFSCcode = 1000;
    }
    else
    {
        file >> bankIFSCcode;
        file.close();
    }

    ofstream output("PBOI.txt");
    output << bankIFSCcode + 1;
    output.close();

    accountNumber = "PBOI" + to_string(bankIFSCcode);
    transactions.push_back("Account created with initial deposit of Rs.500");

    Yellow();
    smallLine();
    cout << " Account Created Successfully!" << endl;
    cout << " Account Number : " << accountNumber << endl;
    cout << " Password       : " << accountPassword << endl;
    cout << " Minimum Balance: Rs.500" << endl;
    smallLine();
    reset();

    savetoFile();
}

// ----------- LOGIN -----------
void Bank::loginAccount()
{
    string enteredAccountNumber;
    string enteredPassword;

    Blue();
    line();
    cout << "              ACCOUNT LOGIN" << endl;
    line();
    reset();

    cout << " Enter Account Number : ";
    getline(cin, enteredAccountNumber);

    ifstream file(enteredAccountNumber + ".txt");
    if (!file)
    {
        Red();
        cout << " Account not found!" << endl;
        reset();
        pause();
        return;
    }
    file.close();

    accountNumber = enteredAccountNumber;
    loadFromFile();

    cout << " Enter Password       : ";
    getline(cin, enteredPassword);

    if (enteredPassword == accountPassword)
    {
        Green();
        cout << " Login Successful!" << endl;
        reset();
        pause();
        mainMenu();
    }
    else
    {
        Red();
        cout << " Incorrect Password!" << endl;
        reset();
        pause();
    }
}

// ----------- TRANSACTIONS -----------
void Bank::depositMoney()
{
    double amount;
    cout << " Enter amount to deposit: Rs.";
    cin >> amount;
    cin.ignore();

    if (amount > 0)
    {
        balance += amount;
        transactions.push_back("Deposited Rs." + to_string(amount));
        savetoFile();
        Green();
        cout << " Deposit Successful!" << endl;
        reset();
    }
}

void Bank::withdrawMoney()
{
    double amount;
    cout << " Enter amount to withdraw: Rs.";
    cin >> amount;
    cin.ignore();

    if (amount > 0 && balance - amount >= 500.0)
    {
        balance -= amount;
        transactions.push_back("Withdrew Rs." + to_string(amount));
        savetoFile();
        Green();
        cout << " Withdrawal Successful!" << endl;
        reset();
    }
    else
    {
        Red();
        cout << " Insufficient balance!" << endl;
        reset();
    }
}

void Bank::checkBalance()
{
    Yellow();
    smallLine();
    cout << " Current Balance : Rs." << balance << endl;
    smallLine();
    reset();
}

void Bank::displayAccountDetails()
{
    Blue();
    line();
    cout << "              ACCOUNT DETAILS" << endl;
    line();
    reset();

    cout << " Name           : " << accountHolderName << endl;
    cout << " Account Number : " << accountNumber << endl;
    cout << " Email          : " << email << endl;
    cout << " Phone          : " << phoneNumber << endl;
    cout << " Aadhaar        : " << adhaarNumber << endl;
    cout << " Balance        : Rs." << balance << endl;
}

void Bank::transactionHistory()
{
    Yellow();
    line();
    cout << "           TRANSACTION HISTORY" << endl;
    line();
    reset();

    for (auto t : transactions)
        cout << " - " << t << endl;
}

// ----------- MAIN FUNCTION -----------
int main()
{
    Bank bank;
    int choice;

    do
    {
        Blue();
        line();
        cout << "        PAPPU BANK OF INDIA" << endl;
        line();
        reset();

        cout << " 1. Create New Account" << endl;
        cout << " 2. Login to Existing Account" << endl;
        cout << " 3. Exit" << endl;
        smallLine();
        cout << " Enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice)
        {
        case 1:
            bank.createAccount();
            pause();
            break;
        case 2:
            bank.loginAccount();
            break;
        case 3:
            cout << " Thank you for banking with us!" << endl;
            break;
        default:
            cout << " Invalid choice." << endl;
            pause();
        }
    } while (choice != 3);

    return 0;
}
