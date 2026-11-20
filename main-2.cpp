#include <iostream>
using namespace std;

char username[3][20] = {"Lerato", "Thabo", "Amara"};
int accountNumber[3] = {1001001, 1001002, 1001003};
int accountPIN[3] = {1234, 2345, 3456};
double accountBalance[3] = {2500, 1800, 3200};

int currentUser = -1;
int running = 1;

void deposit()
{
    double amount;

    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (amount > 0)
    {
        accountBalance[currentUser] = accountBalance[currentUser] + amount;

        cout << "Deposit successful!" << endl;
        cout << "New balance: R" << accountBalance[currentUser] << endl;
    }
    else
    {
        cout << "Invalid amount!" << endl;
    }
}

void withdraw()
{
    double amount;

    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (amount > 0 && amount <= accountBalance[currentUser])
    {
        accountBalance[currentUser] = accountBalance[currentUser] - amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: R" << accountBalance[currentUser] << endl;
    }
    else
    {
        cout << "Insufficient balance or invalid amount!" << endl;
    }
}

void sendCash()
{
    int receiver;
    int found = -1;
    double amount;

    cout << "Enter receiver account number: ";
    cin >> receiver;

    for (int i = 0; i < 3; i++)
    {
        if (accountNumber[i] == receiver)
        {
            found = i;
        }
    }

    if (found != -1 && found != currentUser)
    {
        cout << "Enter amount to send: R";
        cin >> amount;

        if (amount > 0 && amount <= accountBalance[currentUser])
        {
            accountBalance[currentUser] = accountBalance[currentUser] - amount;
            accountBalance[found] = accountBalance[found] + amount;

            cout << "Cash sent successfully!" << endl;
            cout << "New balance: R" << accountBalance[currentUser] << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
    else
    {
        cout << "Account not found or invalid receiver!" << endl;
    }
}

void checkBalance()
{
    cout << "Username: " << username[currentUser] << endl;
    cout << "Account number: " << accountNumber[currentUser] << endl;
    cout << "Available balance: R" << accountBalance[currentUser] << endl;
}

void exitBanking()
{
    cout << "Thank you for banking with GCC Bank!" << endl;
    running = 0;
}


void menu()
{
    int account, pin;
    int found = -1;

    cout << "========== GCC BANK ==========" << endl;
    cout << "Enter account number: ";
    cin >> account;

    cout << "Enter account PIN: ";
    cin >> pin;

    for (int i = 0; i < 3; i++)
    {
        if (accountNumber[i] == account && accountPIN[i] == pin)
        {
            found = i;
        }
    }

    if (found != -1)
    {
        currentUser = found;

        cout << "Welcome " << username[currentUser] << endl;

        while (running == 1)
        {
            int choice;

            cout << endl;
            cout << "========== GCC BANK MENU ==========" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Send Cash" << endl;
            cout << "4. Check Balance" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    deposit();
                    break;

                case 2:
                    withdraw();
                    break;

                case 3:
                    sendCash();
                    break;

                case 4:
                    checkBalance();
                    break;

                case 5:
                    exitBanking();
                    break;

                default:
                    cout << "Invalid choice!" << endl;
            }
        }
    }
    else
    {
        cout << "Incorrect account number or PIN!" << endl;
    }
}


int main()
{
    menu();

    return 0;
}
