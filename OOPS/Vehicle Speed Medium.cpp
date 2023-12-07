#include <iostream>
#include <iomanip>

class Vehicle
{
protected:
    int speed;
    int fuelCapacity;

public:
    Vehicle(int s, int fc) : speed(s), fuelCapacity(fc) {}

    virtual double calculateTravelTime(int distance)
    {
        return static_cast<double>(distance) / speed;
    }
};

class Car : public Vehicle
{
private:
    int numPassengers;

public:
    Car(int s, int fc, int np) : Vehicle(s, fc), numPassengers(np) {}

    double calculateTravelTime(int distance) override
    {

        if (fuelCapacity * speed < distance)
        {
            std::cout << "Not Possible.";
            return 0.0;
        }

        // Adjust travel time based on the number of passengers
        if (numPassengers > 1)
        {
            numPassengers /= 2;
        }

        double time = (double)distance / (double)(speed * numPassengers);
        return time;
    }
};

class Bike : public Vehicle
{
private:
    bool isElectric;

public:
    Bike(int s, int fc, bool elec) : Vehicle(s, fc), isElectric(elec) {}

    double calculateTravelTime(int distance) override
    {
        if (!isElectric && fuelCapacity * speed < distance)
        {
            std::cout << "Not Possible.";
            return 0.0;
        }

        return static_cast<double>(distance) / (isElectric ? 1.2 * speed : speed);
    }
};

int main()
{
    int vehicleType, speed, fuelCapacity, distance;

    std::cin >> vehicleType >> speed >> fuelCapacity;

    std::cout << std::fixed << std::setprecision(2);

    if (vehicleType == 1)
    {
        int numPassengers;
        std::cin >> numPassengers;
        Car car(speed, fuelCapacity, numPassengers);
        std::cin >> distance;
        std::cout << car.calculateTravelTime(distance); // Output handled within the function
    }
    else if (vehicleType == 2)
    {
        bool isElectric;
        std::cin >> isElectric;
        Bike bike(speed, fuelCapacity, isElectric);
        std::cin >> distance;
        std::cout << bike.calculateTravelTime(distance); // Output handled within the function
    }

    return 0;
}
