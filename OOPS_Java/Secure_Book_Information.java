import java.io.*;
import java.util.*;
class Book {
    private String title;
    private String author;
    private int publicationYear;
    private boolean isAvailable;

    public Book(String title, String author, int publicationYear) {
        this.title = title;
        this.author = author;
        this.publicationYear = publicationYear;
        this.isAvailable = true;
    }

    public void displayDetails() {
        System.out.println("Book Details Initially:");
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Publication Year: " + publicationYear);
        System.out.println("Availability: " + (isAvailable ? "Available" : "Not Available"));
        System.out.println(); // Add a newline for better readability
    }

    public void borrowBook() {
        System.out.println("Borrowing the Book:");
        if (isAvailable) {
            isAvailable = false;
            System.out.println("Book borrowed successfully.");
        } else {
            System.out.println("Book is not available for borrowing.");
        }
    }

    public void returnBook() {
        System.out.println("Returning the Book:");
        if(isAvailable == true){
            System.out.println("Haven't borrowed any book.");
        }else{
            isAvailable = true;
            System.out.println("Book returned successfully.");
        }
    }
}

public class Secure_Book_Information {
    public static void main(String[] args) {
        // Sample usage of the Book class
        Scanner scn = new Scanner(System.in);

        String title = scn.nextLine();

        String author = scn.nextLine();
        int year = scn.nextInt();
        Book myBook = new Book(title,author,year);

        int borrow = scn.nextInt();
        myBook.displayDetails();

        if(borrow == 1){
            myBook.borrowBook();
            myBook.returnBook();
        }else{
            myBook.returnBook();
            myBook.borrowBook();
        }
            
    }
}
