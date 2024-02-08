import java.util.Scanner;

class Student {
    private int rollNumber;
    private String name;
    private int age;
    private double marks;

    // Constructor to initialize attributes
    public Student(int rollNumber, String name, int age, double marks) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.age = age;
        this.marks = marks;
    }

    // Method to display student details
    public void displayDetails() {
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Marks: " + marks);
    }
}

class Constructors_Student_Information {
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        int rollNumber = scn.nextInt(); 
        scn.nextLine();
        String name = scn.nextLine();
        int age = scn.nextInt();
        double marks = scn.nextDouble();

        Student student = new Student(rollNumber,name,age,marks);
        student.displayDetails();
    }
}