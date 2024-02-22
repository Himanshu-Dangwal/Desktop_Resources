import java.util.Scanner;

class Integer {
    public int x;

    public Integer increment() {
        Integer i = new Integer();
        i.x = ++x;
        return i;
    }

    public Integer increment(int y) {
        Integer i = new Integer();
        i.x = x++;
        return i;
    }

    public void setValue(int x) {
        this.x = x;
    }
}

public class Overlaoding_Pre_Post {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Integer obj = new Integer();
        int x = scanner.nextInt();
        obj.setValue(x);

        Integer preIncrementResult = obj.increment();
        System.out.println(preIncrementResult.x);

        Integer postIncrementResult = obj.increment(1);
        System.out.println(postIncrementResult.x);

        System.out.println(obj.x);
    }
}
