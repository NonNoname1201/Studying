package pancake;

public class Roller extends Thread {
    private final Machine machine;

    public Roller(Machine machine) {
        this.machine = machine;
    }

    @Override
    public void run() {
        while (true) {
            try {
                machine.roll();
                Thread.sleep(new java.util.Random().nextInt(1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
