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
    friend void swapValues(A &objectA, B &objectB);
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
    friend void swapValues(A &objectA, B &objectB);
};
void swapValues(class A &objectA, class B &objectB)
{
    int temp = objectA.a;
    objectA.a = objectB.b;
    objectB.b = temp;
}

int main()
{
    A objA(2);
    B objB(4);
    cout << "Before Swapping : " << endl;
    objA.displayValue();
    objB.displayValue();
    swapValues(objA, objB);
    cout << "After Swapping" << endl;
    objA.displayValue();
    objB.displayValue();
}