#include <iostream>
using namespace std;
class BankAcc
{

    int id;
    string name;
    double balance;

public:
    BankAcc(int x, string y, double z)
    {
        id = x;
        name = y;
        balance = z;
    }

    void returnBalance()
    {
        cout << "Balance : " << balance << endl;
    }

    void info()
    {
        cout << "Account ID : " << id << endl;
        cout << "Account Holder Name : " << name << endl;
    }
};

int main()
{
    BankAcc Cs1(192, "Walter", 550000);
    BankAcc Cs2(836, "Skyler", 3000);
    Cs1.info();
    Cs1.returnBalance();
}