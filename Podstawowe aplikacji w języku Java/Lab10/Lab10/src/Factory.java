public class Factory extends Thread {
    private final Store s;

    public Factory(Store s) {
        this.s = s;
    }

    @Override
    public void run() {
        while (true) {
            try {
                s.produce();
                System.out.println("Producent -> " + s.getCount());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public int getStoreNum() {
        return s.getMyNum();
    }
}
