import java.util.*;
import java.io.*;

class Car {
    private String model;
    private String color;
    private int year;

    // Constructor to initialize the Car object
    public Car(String model, String color, int year) {
        this.model = model;
        this.color = color;
        this.year = year;
    }

    // Method to display car details
    public void displayDetails() {
        System.out.println("Model: " + model);
        System.out.println("Color: " + color);
        System.out.println("Year: " + year);
        System.out.println(); 
    }
}

public class Car_Information_System {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        // Read the number of cars
      
        int numberOfCars = scn.nextInt();

        // Consume the newline character
        scn.nextLine();

        // Create an array to store Car objects
        Car[] cars = new Car[numberOfCars];

        // Input details for each car and create Car objects
        for (int i = 0; i < numberOfCars; i++) {


            String model = scn.nextLine();
            String color = scn.nextLine();
            int year = scn.nextInt();

            if(i != numberOfCars-1)
                scn.nextLine();
            // Create Car object using the constructor
            cars[i] = new Car(model, color, year);
        }

        // Display details for each car using the displayDetails method

        for (Car car : cars) {
            car.displayDetails();
        }


    }
}
