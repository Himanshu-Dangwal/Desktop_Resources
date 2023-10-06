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

class Triangle : public Shape
{
public:
    // Parameterized constructor for Triangle
    Triangle(int base, int height) : Shape(3), base(base), height(height) {}

    void printInfo()
    {
        std::cout << "Shape: Triangle" << std::endl;
        Shape::printInfo(); // Call the base class's printInfo() function
        std::cout << "Base: " << base << std::endl;
        std::cout << "Height: " << height << std::endl;
    }

private:
    int base;
    int height;
};

int main()
{

    int x, y, a, b;
    cin >> x >> y >> a >> b;
    Rectangle myRectangle(x, y);
    Triangle myTriangle(a, b);

    std::cout << "Rectangle Information:" << std::endl;
    myRectangle.printInfo();

    std::cout << "\nTriangle Information:" << std::endl;
    myTriangle.printInfo();

    return 0;
}
