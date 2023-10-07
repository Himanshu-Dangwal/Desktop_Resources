// Explicitly call the parameterised constructor of parent class from the child class constructor
#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    // Parameterized constructor
    Shape(int sides) : numSides(sides) {}

    void printInfo()
    {
        std::cout << "Number of Sides: " << numSides << std::endl;
    }

private:
    int numSides;
};

class Rectangle : public Shape
{
public:
    // Parameterized constructor for Rectangle
    Rectangle(int width, int height) : Shape(4), width(width), height(height) {}

    void printInfo()
    {
        std::cout << "Shape: Rectangle" << std::endl;
        Shape::printInfo(); // Call the base class's printInfo() function
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
    }

private:
    int width;
    int height;
};

int main()
{

    int x, y;
    cin >> x >> y;
    Rectangle myRectangle(x, y);

    std::cout << "Rectangle Information:" << std::endl;
    myRectangle.printInfo();

    return 0;
}
