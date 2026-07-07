#include <iostream>
using namespace std;
class JKB
{

    int id;
    string ownerName;
    string dateofBirth;
    double balance;

public:
    JKB(int n, string name, string dob, double d)
    {
        this->balance = d;
        this->dateofBirth = dob;
        this->id = n;
        this->ownerName = name;
    }

    void displayCredentials()
    {
        cout << "ID : " << id << endl;
        cout << "Name : " << ownerName << endl;
        cout << "DOB : " << dateofBirth << endl;
        cout << endl;
    }

    void displayBalance()
    {
        cout << "Current Balance : " << balance << endl;
    }
};

int main()
{
    JKB one(102, "Aryan Sharma", "21-10-2006", 3000);
    JKB two(32, "Rohit Pandey", "11-1-2001", 3400);
    JKB three(124, "Shivam Dube", "2-4-2003", 6000);
    JKB four(14, "Rahul Dravid", "24-5-2002", 4000);
    one.displayCredentials();
    two.displayCredentials();
    three.displayCredentials();
    four.displayCredentials();
}