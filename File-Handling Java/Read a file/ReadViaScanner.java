import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ReadViaScanner {
    public static void main(String[] args) {
        File file = new File("dummy.txt"); // The file to read

        try {
            Scanner scanner = new Scanner(file);

            // Read the file line by line
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                System.out.println(line);
            }

            // Always close the Scanner
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + e.getMessage());
        }
    }
}
