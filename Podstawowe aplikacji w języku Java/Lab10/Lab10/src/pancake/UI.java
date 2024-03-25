package pancake;

public class UI extends Thread {
    private final Machine machine;

    public UI(Machine machine) {
        this.machine = machine;
    }

    @Override
    public void run() {
        while (true) {
            machine.getOrder();
            if (machine.isRolled && machine.isFilled && machine.isCooked) {
                Pancake pancake = machine.dispense();
                System.out.println(pancake.toString());
                System.out.println();

                machine.isReady = true;
            }
        }
    }
}
