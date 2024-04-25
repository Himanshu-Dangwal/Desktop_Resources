import java.io.*;

class Create {
    public static void main(String args[]){
        File fs =  new File("dummy.txt");
        // System.out.println(fs.canWrite());

        if(!fs.exists()){
            try{
                fs.createNewFile();
            }catch(IOException e){
                System.out.println("IO Exception" + e);
            }
        }

        System.out.println(fs.canWrite());

    }
}

