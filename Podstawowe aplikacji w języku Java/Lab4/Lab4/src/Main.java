
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        PrintArr.printArr1D(100);

        PrintArr.printArr2D(new Random().nextInt(10,20));

        Okrag o = new Okrag();
        Okrag o1 = new Okrag(50, 50, 20);

        Relation(o, o1);

        Okrag[] c = createCircleArray(10);
        toString(c);
    }

    public static Okrag[] createCircleArray(int c){
        Okrag[] circles = new Okrag[c];
        for (int i = 0; i < c; i++) {
            circles[i] = new Okrag();
        }
        return circles;
    }

    public static void Relation(Okrag o1, Okrag o2){
        double distance = Math.sqrt(Math.pow(o1.getX() - o2.getX(), 2) + Math.pow(o1.getY() - o2.getY(), 2));
        if(distance < Math.abs(o1.getR() - o2.getR())){
            System.out.println("Pokrywajace!");
        } else if(distance < o1.getR() + o2.getR()){
            System.out.println("Przecinajace!");
        } else if(distance == o1.getR() + o2.getR()) {
            System.out.println("Dotykajace!");
        } else{
            System.out.println("Rozlaczne!");
        }
    }

    public static void toString(Okrag[] circles){
        for (Okrag c:
             circles) {
            System.out.println(c.toString());
        }
    }
}