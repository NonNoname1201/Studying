import com.sun.jdi.ThreadReference;

import java.util.Random;

public class WatekTest implements Runnable {
    int nr;
    int counter = 0;
    Random r = new Random();
    WatekTest(int nr){
        this.nr = nr;
    }

    public static void main(String[] args) {
        int amount = 10;
        Random r = new Random();
//        WatekTest wt1 = new WatekTest(1);
//        Thread t1 = new Thread(wt1);
//        t1.start();
//
//        WatekTest wt2 = new WatekTest(2);
//        Thread t2 = new Thread(wt2);
//        t2.start();
        Thread[] wTab = new Thread[amount];
        for (int i = 0; i < amount; i++) {
            wTab[i] = new Thread(new WatekTest(i));
            wTab[i].setPriority(i+1);
            wTab[i].start();
        }
    }

    @Override
    public void run() {
        while(true){
            counter ++;
            System.out.println("Thread no." + nr + " drawn " + counter);
//            try{
//                Thread.sleep(1);
//            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
//            }
        }
    }
}