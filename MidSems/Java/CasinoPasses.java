import java.util.*;
import java.lang.Math;
public class CasinoPasses {
   public static int get_sum(int n){
       int res = 0;
       while (n > 0){
           res += n % 10;
           n /= 10;
       }
       return res;
   }
   public static void main(String[] args) {
       final int MaxN = 100224;
       int n;
       Scanner sc = new Scanner(System.in);
       n = sc.nextInt();
       int a[] = new int[MaxN];
       int cnt[] = new int[3];
       for (int i = 0; i < n; i++){
           a[i] = sc.nextInt();
           a[i] = get_sum(a[i]);
           cnt[a[i] % 3]++;
       }
       System.out.println( cnt[0] / 2 + Math.min(cnt[1], cnt[2]));
   }
}
