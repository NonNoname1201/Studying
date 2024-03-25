
public class Main {

    public static void main(String[] args) {

        Store store1 = new Store(1);
        Thread thread1 = new Consumer(store1);
        Thread thread2 = new Factory(store1);

        thread1.start();
        thread2.start();
    }


}