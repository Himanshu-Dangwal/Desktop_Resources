#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string type;

public:
    Vehicle(const string &t) : type(t) {}

    virtual void start()
    {
        cout << "Starting the " << type << "..." << endl;
    }
};

class Car : public Vehicle
{
private:
    int kilometers;

public:
    Car(int kilometers) : Vehicle("Car"), kilometers(kilometers) {}

    void start() override
    {
        cout << "Warming up the engine of the Car..." << endl;
        cout << "Total Kilometer travelled till now = " << kilometers << endl;
    }
};

class Truck : public Vehicle
{
private:
    int kilometers;

public:
    Truck(int kilometers) : Vehicle("Truck"), kilometers(kilometers) {}

    void start() override
    {
        cout << "Igniting the engine of the Truck..." << endl;
        cout << "Total Kilometer travelled till now = " << kilometers << endl;
    }
};

class Bicycle : public Vehicle
{
private:
    int kilometers;

public:
    Bicycle(int kilometers) : Vehicle("Bicycle"), kilometers(kilometers) {}

    void start() override
    {
        cout << "Pedaling the Bicycle..." << endl;
        cout << "Total Kilometer travelled till now = " << kilometers << endl;
    }
};

int main()
{
    int carTravelled, truckTravelled, bicycleTravelled;
    cin >> carTravelled >> truckTravelled >> bicycleTravelled;
    Vehicle *fleet[] = {
        new Car(carTravelled),
        new Truck(truckTravelled),
        new Bicycle(bicycleTravelled)};

    for (int i = 0; i < 3; i++)
    {
        fleet[i]->start();
    }

    for (int i = 0; i < 3; i++)
    {
        delete fleet[i];
    }

    return 0;
}
