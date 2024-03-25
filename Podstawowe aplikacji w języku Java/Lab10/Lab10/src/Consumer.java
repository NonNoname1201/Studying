import static java.lang.Thread.sleep;

public class Consumer extends Thread {
    private Store s;

    public Consumer(Store s){
        this.s = s;
    }
    @Override
    public void run() {
        while(true){
            try {
                s.consume();
                System.out.println("Konsument -> " + s.getCount());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public int getStoreNum() {
        return s.getMyNum();
    }
}
