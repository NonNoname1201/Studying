public class Store {
    private int myNum;
    private static int[] buffer = new int[10];
    private static int count = 5;

    public Store(int myNum) {
        this.myNum = myNum;
    }

    public int getMyNum() {
        return myNum;
    }

    public int getCount() {
        return count;
    }


    public synchronized void produce() throws InterruptedException {
        while (count > buffer.length - 2) {
            wait();
        }
        buffer[count++] = 1;
        notifyAll();
    }

    public synchronized void consume() throws InterruptedException {
        while (count < 2) {
            wait();
        }
        buffer[--count] = 0;
        notifyAll();
    }
}
