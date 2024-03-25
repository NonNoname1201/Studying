package pancake;

public class Pancake {
    Boolean isCooked = false;
    Boolean isFilled = false;
    Boolean isRolled = false;
    String flavor = "";

    @Override
    public String toString() {
        return "Pancake: " + flavor;
    }
}
