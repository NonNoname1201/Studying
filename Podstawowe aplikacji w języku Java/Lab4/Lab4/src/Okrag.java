import java.util.Random;

public class Okrag {

    private int x, y, r;
    Okrag(){
        Random random = new Random();
        x = random.nextInt(5, 95);
        y = random.nextInt(5, 95);
        r = random.nextInt(1, 5);
    }
    Okrag(int r){
        Random random = new Random();
        x = random.nextInt(5, 95);
        y = random.nextInt(5, 95);
        this.r = r;
    }
    Okrag(int x, int y){
        Random random = new Random();
        this.x = x;
        this.y = y;
        r = random.nextInt(1, 5);
    }
    Okrag(int x, int y, int r){
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getR() {
        return r;
    }

    public String toString(){
        return "X: " + this.x + "|Y: " + this.y + "|R: " + this.r;
    }
}
