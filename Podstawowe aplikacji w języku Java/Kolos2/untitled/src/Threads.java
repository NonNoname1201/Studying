import static java.lang.Thread.sleep;
public class Threads implements Runnable{
    int nr,counter = 0;
    public Threads(int nr) {
        this.nr = nr;
    }
    @Override
    public void run() {
        while(true){
            counter++;
            System.out.println("Watek: "+nr+" suma: "+counter);
            try {
                sleep(200);
            } catch (InterruptedException ex) {
                System.out.println(ex);
            }
        }
    }

    public static void main(String[] args) {
        for(int i = 1; i <= 5; i++){
            Threads ts = new Threads(i);
            Thread t=new Thread(ts);
            t.start();
        }
    }
}
