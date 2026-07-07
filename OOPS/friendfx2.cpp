#include <iostream>
using namespace std;
class B;
class A
{
    int a;

public:
    A(int a)
    {
        this->a = a;
    }
    void displayValue()
    {
        cout << "Value : " << a << endl;
        cout << endl;
    }
    friend void addValues(A &objectA, B &objectB);
};
class B
{
    int b;

public:
    B(int b)
    {
        this->b = b;
    }
    void displayValue()
    {
        cout << "Value : " << b << endl;
        cout << endl;
    }
    friend void addValues(A &objectA, B &objectB);
};
void addValues(class A &objectA, class B &objectB)
{
    int temp = objectA.a + objectB.b;
    cout << "Sum : " << temp << endl;
}

int main()
{
    A objA(2);
    B objB(4);
    cout << "Before Adding : " << endl;
    objA.displayValue();
    objB.displayValue();
    addValues(objA, objB);
}