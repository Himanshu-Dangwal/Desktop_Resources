import java.util.Scanner;

class Shape {
    protected int r;

    public int getArea() {
        return 6 * r * r;
    }

    public void setValue(int r) {
        this.r = r;
    }
}

class Rectangle extends Shape {
    @Override
    public int getArea() {
        return this.r * this.r;
    }
}

public class OveridingArea {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int type = scanner.nextInt();

        if (type == 0) {
            Shape p;
            Rectangle obj = new Rectangle();
            p = obj;

            int r = scanner.nextInt();

            p.setValue(r);
            System.out.println(p.getArea());
        } else {
            Shape p;
            Shape obj = new Shape();
            p = obj;

            int r = scanner.nextInt();

            p.setValue(r);
            System.out.println(p.getArea());
        }
    }
}
