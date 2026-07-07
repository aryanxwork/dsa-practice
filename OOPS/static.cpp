#include <iostream>
using namespace std;
class Student
{

    int rollNo;
    string name;
    static int count;

public:
    Student(int r)
    {
        rollNo = r;
        count++;
    }
    static int getCount()
    {
        return count;
    }
    void setName(string n)
    {
        name = n;
    }
    void displayName()
    {
        cout << "Name : " << name << endl;
    }
};

int Student::count = 0;

int main()
{
    Student s1(2);
    Student s6(3);
    Student s5(4);
    Student s2(5);
    cout << Student::getCount() << endl;
    Student *ptr = &s1;
    ptr->setName("Aryan");
    ptr->displayName();
}