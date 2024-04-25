import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Append {
    public static void main(String[] args) {
        File fs = new File("dummy.txt");

        try {
            // The second parameter 'true' in FileWriter constructor is for enabling append mode
            FileWriter fw = new FileWriter(fs, true);
            BufferedWriter bw = new BufferedWriter(fw);

            // Check if the file is writable
            if (fs.canWrite()) {
                // Write a string to the file
                bw.write("Hello, this is a test string!");
                // Optionally add a new line if appending multiple times
                bw.newLine();

                // Always close the BufferedWriter to flush the changes to the file
                bw.close();
            } else {
                System.out.println("Cannot write to the file.");
            }
        } catch (IOException e) {
            System.out.println("IO Exception: " + e.getMessage());
        }
    }
}
