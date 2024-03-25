package zad5_2;

public interface Basic {
    public abstract void eat();
    public abstract void drink();

    public default int ileLat() {
        return 0;
    }

    public default String character() {
        return "null";
    }
}
