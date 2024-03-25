package pancake;

import java.util.Scanner;

public class Machine {
    Pancake currentPancake = new Pancake();
    String order = "chocolate";

    boolean isOrdered = false;
    boolean isCooked = false;
    boolean isFilled = false;
    boolean isRolled = false;
    boolean isReady = true;


    public Machine() {
    }
    //synchronized all methods

    public synchronized void getOrder() {
        if (isReady) {
            System.out.println("Choose your order: \n1. Chocolate\n2. Strawberry\n3. Blueberry");
            switch (new Scanner(System.in).nextInt()) {
                case 1 -> order = "chocolate";
                case 2 -> order = "strawberry";
                case 3 -> order = "blueberry";
                default -> {
                    System.out.println("Invalid order");
                    getOrder();
                }
            }
            isReady = false;
            isOrdered = true;
            currentPancake.flavor = order;
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    public synchronized void cook() {
        if (isOrdered&&!isCooked) {
            System.out.println("Your order is being cooked...");
            currentPancake.isCooked = true;
            isCooked = true;
            notifyAll();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public synchronized void fill() {
        if (isCooked&&!isFilled) {
            System.out.println("Your order is being filled...");
            currentPancake.isFilled = true;
            isFilled = true;
            notifyAll();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public synchronized void roll() {
        if (isFilled&&!isRolled) {
            System.out.println("Your order is being rolled...");
            currentPancake.isRolled = true;
            isRolled = true;
            notifyAll();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public synchronized Pancake dispense() {
        if (isRolled) {
            System.out.println("You order is ready!");
            isOrdered = false;
            isCooked = false;
            isFilled = false;
            isRolled = false;
            notifyAll();
            return currentPancake;
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        return null;
    }

}
