import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class HashMapQuestion {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        HashMap<Character,Integer> mp = new HashMap<>();

        //Insertion
        for(int i=0;i<5;i++){
            int value;
            char key;

            key = scn.next().charAt(0);
            value = scn.nextInt();

            mp.put(key,value);

        }

         //Size
         System.out.println(mp.size());

         // Check if map contains key : 'a', if yes then get value corrosponding to 'a'
         if(mp.containsKey('a')){
            System.out.println("a is present");
            Integer value = mp.get('a');
            System.out.println(value);
         }

         // Check if map contains value : 3
         if(mp.containsValue(3)){
            System.out.println("Yes");
         }


         // Get default value corrosponding to a key that is not present
         Integer defaultValue = mp.getOrDefault('f',6);
         System.out.println("Default value is " + defaultValue);

        //Iterate (Method : 1)

        for (Map.Entry<Character,Integer> mapElement : mp.entrySet()) {
            Character key = mapElement.getKey();
            Integer value = mapElement.getValue();
 
            System.out.println(key + " : " + value);
        }


        //Iterate (Method : 2)

        mp.forEach((key, value) -> System.out.println(key + " : " + value));

        //Clear
        mp.clear();

        // isEmpty()
        if(mp.isEmpty()){
            System.out.println("Map is empty");
        }
    }
}
