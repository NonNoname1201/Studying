package pancake;

public class Filler extends Thread {
    private final Machine machine;

    public Filler(Machine machine) {
        this.machine = machine;
    }

    @Override
    public void run() {
        while (true) {
            try {
                machine.fill();
                Thread.sleep(new java.util.Random().nextInt(1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
