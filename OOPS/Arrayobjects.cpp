#include <iostream>
using namespace std;
class Rectangle
{
    int length;
    int breadth;

public:
    Rectangle() {}
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    void setParameters(int l, int b)
    {
        length = l;
        breadth = b;
    }
    void calculateArea()
    {
        cout << "Area = " << length * breadth << endl;
    }
};
int main()
{
    Rectangle r(20, 15);
    r.calculateArea();
    Rectangle arr[3] = {Rectangle(10, 12), Rectangle(5, 8), Rectangle(9, 10)};
    for (int i = 0; i < 3; i++)
    {
        arr[i].calculateArea();
    }

    int n = 3;
    Rectangle *ptr = new Rectangle[n];
    ptr[0].setParameters(20, 3);
    ptr[1].setParameters(8, 20);
    ptr[2].setParameters(4, 5);
    for (int i = 0; i < 3; i++)
    {
        ptr[i].calculateArea();
    }
    delete[] ptr;
}