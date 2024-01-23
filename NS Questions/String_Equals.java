import java.io.*;
import java.util.*;
class String_Equals {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str1 = scn.next();
        String str2 = scn.next();

        if(str1.equals(str2)){
            System.out.println("True");
        }else{
            System.out.println("False");
        }
    }
}