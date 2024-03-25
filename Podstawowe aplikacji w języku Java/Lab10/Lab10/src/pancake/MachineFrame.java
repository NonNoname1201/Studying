package pancake;
public class MachineFrame {
    Machine m = new Machine();
    UI ui = new UI(m);
    Cooker c = new Cooker(m);
    Filler f = new Filler(m);
    Roller r = new Roller(m);


    public static void main(String[] args) {
        MachineFrame mf = new MachineFrame();
        mf.ui.start();
        mf.c.start();
        mf.f.start();
        mf.r.start();

    }
}
