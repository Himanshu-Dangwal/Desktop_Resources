import java.util.*;
import java.io.*;

class Student {
    private String name;
    private double mathScore;
    private double englishScore;
    private double scienceScore;

    // Constructor to initialize the Student object
    public Student(String name, double mathScore, double englishScore, double scienceScore) {
        this.name = name;
        this.mathScore = mathScore;
        this.englishScore = englishScore;
        this.scienceScore = scienceScore;
    }

    // Method to calculate and return the average score
    public double calculateAverage() {
        return (mathScore + englishScore + scienceScore) / 3.0;
    }

    // Method to assign and return the grade based on the average score
    public char calculateGrade() {
        double average = calculateAverage();

        if (average >= 90) {
            return 'A';
        } else if (average >= 70) {
            return 'B';
        } else if (average >= 50) {
            return 'C';
        } else {
            return 'D';
        }
    }

    // Method to display student details, average score, and grade
    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Math Score: " + mathScore);
        System.out.println("English Score: " + englishScore);
        System.out.println("Science Score: " + scienceScore);
        System.out.println("Average Score: " + calculateAverage());
        System.out.println("Grade: " + calculateGrade());
        System.out.println(); // Add a newline for better readability
    }
}

public class Student_Grade_Calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of students
        int numberOfStudents = scanner.nextInt();

        // Consume the newline character
        scanner.nextLine();

        // Create an array to store Student objects
        Student[] students = new Student[numberOfStudents];

        // Input details for each student and create Student objects
        for (int i = 0; i < numberOfStudents; i++) {

            String name = scanner.nextLine();
            double mathScore = scanner.nextDouble();
            double englishScore = scanner.nextDouble();
            double scienceScore = scanner.nextDouble();

            // Consume the newline character
            if(i != numberOfStudents-1)
                  scanner.nextLine();

            // Create Student object using the constructor
            students[i] = new Student(name, mathScore, englishScore, scienceScore);
        }

        // Display details for each student using the displayDetails method

        for (Student student : students) {
            student.displayDetails();
        }

        // Close the scanner
        scanner.close();
    }
}
