import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Update {
    public static void main(String[] args) {
        File fs = new File("dummy.txt");

        // Try to create the file if it does not exist
        try {
            if (!fs.exists()) {
                fs.createNewFile();
            }

            // Check if the file is writable
            if (fs.canWrite()) {
                // Use FileWriter to write to the file
                FileWriter fw = new FileWriter(fs);
                BufferedWriter bw = new BufferedWriter(fw);

                // Write a string to the file
                bw.write("Hello, this is a test string!");

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
