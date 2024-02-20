import java.util.Scanner;

class LibraryItem {
    protected String title;
    protected int itemID;

    public LibraryItem(String title, int itemID) {
        this.title = title;
        this.itemID = itemID;
    }

    public void displayInfo() {
        System.out.println("Title: " + title);
        System.out.println("Item ID: " + itemID);
    }
}

class Book extends LibraryItem {
    private String author;
    private String genre;

    public Book(String title, int itemID, String author, String genre) {
        super(title, itemID);
        this.author = author;
        this.genre = genre;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Author: " + author);
        System.out.println("Genre: " + genre);
    }
}

class DVD extends LibraryItem {
    private String director;
    private int duration;

    public DVD(String title, int itemID, String director, int duration) {
        super(title, itemID);
        this.director = director;
        this.duration = duration;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Director: " + director);
        System.out.println("Duration: " + duration + " minutes");
    }
}

public class Library {
    public static void main(String[] args) {
        // Test the Library Management System
        String title,author,genre,director;
        int id,duration;

        Scanner scn = new Scanner(System.in);

        title = scn.nextLine();
        id = scn.nextInt();
        scn.nextLine();
        author = scn.nextLine();
        genre = scn.nextLine();
        Book myBook = new Book(title, id, author, genre);
        myBook.displayInfo();

        System.out.println();

        title = scn.nextLine();
        id = scn.nextInt();
        scn.nextLine();
        director = scn.nextLine();
        duration = scn.nextInt();
        DVD myDVD = new DVD(title, id, director, duration);
        myDVD.displayInfo();
    }
}
