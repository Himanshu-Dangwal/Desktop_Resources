import java.util.Scanner;

public abstract class Animal {
    String name;
    int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    abstract void makeSound();

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class Dog extends Animal {
    public Dog(String name, int age) {
        super(name, age);
    }

    @Override
    void makeSound() {
        System.out.println("Woof Woof");
    }
}

class Cat extends Animal {
    public Cat(String name, int age) {
        super(name, age);
    }

    @Override
    void makeSound() {
        System.out.println("Meow Meow");
    }
}

public class Animal_Abstraction {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String dogName = scn.nextLine();
        int dogAge = scn.nextInt();

        // Consume the newline character
        scn.nextLine();

        String catName = scn.nextLine();
        int catAge = scn.nextInt();

        Dog myDog = new Dog(dogName, dogAge);
        Cat myCat = new Cat(catName, catAge);

        myDog.displayInfo();
        myDog.makeSound();

        System.out.println();

        myCat.displayInfo();
        myCat.makeSound();
    }
}
