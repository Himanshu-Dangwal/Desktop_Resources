import java.util.*;

public class Main {

    public static int solution(int[] arr, int k) {
       
       HashMap<Integer,Integer> m = new HashMap<>();
       
       int sum = 0;
       int count = 0;
       
       m.put(0,1);
       
       for(int i=0;i<arr.length;i++){
           sum += arr[i];
           int rem = sum%k;
           
           if(rem < 0){
               rem += k;
           }
           
           if(m.containsKey(rem) == true){
               count += m.get(rem);
               m.put(rem,m.get(rem)+1);
           }else{
               m.put(rem,1);
           }
       }

        return count;
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }
        int k = scn.nextInt();
        System.out.println(solution(arr, k));
    }

}

