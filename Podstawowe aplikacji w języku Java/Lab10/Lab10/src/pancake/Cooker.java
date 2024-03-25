package pancake;

public class Cooker extends Thread {
    private final Machine machine;

    public Cooker(Machine machine) {
        this.machine = machine;
    }

    @Override
    public void run() {
        while (true) {
            try {
                machine.cook();
                Thread.sleep(new java.util.Random().nextInt(1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
