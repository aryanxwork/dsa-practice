#include <iostream>
using namespace std;
class Rectangle
{

    int length;
    int breadth;

public:
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int x)
    {
        length = x;
        breadth = x;
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    ~Rectangle()
    {
        cout << "Destructor called" << endl;
    }
    void displayArea()
    {
        cout << "Area = " << length * breadth << endl;
    }
};

int main()
{
    Rectangle r1;
    Rectangle r2(5);
    Rectangle r3(6, 5);
    r1.displayArea();
    r2.displayArea();
    r3.displayArea();

    Rectangle arr[3] = {Rectangle(), Rectangle(3), Rectangle(7, 10)};
    for (int i = 0; i < 3; i++)
    {
        arr[i].displayArea();
    }
}