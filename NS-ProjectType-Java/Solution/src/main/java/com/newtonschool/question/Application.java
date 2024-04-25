package com.newtonschool.question;

import java.io.InputStream;
import java.util.Scanner;

public class Application {
    public static void main(String[] args) {
        readFromFile("dummy.txt");
    }

    public static void readFromFile(String fileName) {
        // Load file from resources folder using classloader
        InputStream inputStream = Application.class.getClassLoader().getResourceAsStream(fileName);
        if (inputStream == null) {
            System.out.println("File not found: " + fileName);
            return;
        }

        try (Scanner scanner = new Scanner(inputStream)) {
            while (scanner.hasNextLine()) {
                String data = scanner.nextLine();
                System.out.println(data);
            }
        } catch (Exception e) {
            System.out.println("An error has occurred.");
            e.printStackTrace();
        }
    }
}
