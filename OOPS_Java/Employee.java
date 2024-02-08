// public class Example {
//     private int value;
    
//     public Example() {
//         this.value = 42;
//     }
    
//     public void displayValue() {
//         System.out.println("Value: " + value);
//     }
    
//     public static void main(String[] args) {
//         Example obj = new Example();
//         obj.displayValue();
//     }
// }

public class Employee {
    private String name;
    private int employeeId;

    public Employee(String name, int employeeId) {
        this.name = name;
        this.employeeId = employeeId;
    }

    public Employee(String name) {
        this(name, 0);
    }

    public void displayInfo() {
        System.out.println("Name: " + name + ", Employee ID: " + employeeId);
    }

    public static void main(String[] args) {
        Employee emp1 = new Employee("John", 123);
        Employee emp2 = new Employee("Alice");

        emp1.displayInfo();
        emp2.displayInfo();
    }
}
