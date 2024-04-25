import java.io.*;

public class Read {
    public static void main(String[] args) {
        File fs = new File("dummy.txt");

        try{
            FileReader fr = new FileReader(fs);
            BufferedReader br = new BufferedReader(fr);

            String line;
            // Read the file line by line
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            // Always close the BufferedReader
            br.close();
        }catch(Exception e){
            System.out.println("Exception " + e);
        }
        

    }    
}
