#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    float x, y;

public:
    // Constructor to initialize coordinates
    Point(float x_coord, float y_coord) : x(x_coord), y(y_coord) {}

    // Friend function declaration
    friend float calculateDistance(const Point &p1, const Point &p2);

    // Function to display point coordinates
    void displayPoint()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Friend function to calculate the distance between two points
float calculateDistance(const Point &p1, const Point &p2)
{
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    float x1, y1, x2, y2;

    // Input coordinates for two points
    cout << "Enter coordinates for the first point (x y): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates for the second point (x y): ";
    cin >> x2 >> y2;

    // Create Point objects
    Point point1(x1, y1);
    Point point2(x2, y2);

    // Display the points
    cout << "Point 1: ";
    point1.displayPoint();
    cout << "Point 2: ";
    point2.displayPoint();

    // Calculate and display the distance
    float distance = calculateDistance(point1, point2);
    cout << "Distance between points: " << distance << endl;

    return 0;
}
