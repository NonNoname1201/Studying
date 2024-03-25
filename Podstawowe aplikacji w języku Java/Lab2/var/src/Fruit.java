public class Fruit {
    private String name;

    private double acidity;
    private double sweetness;
    private int ageInDays;
    private double mass;


    public String getName() {
        return name;
    }

    public double getAcidity() {
        return acidity;
    }

    public double getSweetness() {
        return sweetness;
    }

    public int getAgeInDays() {
        return ageInDays;
    }

    public double getMass() {
        return mass;
    }

    Fruit(){
        this.setName("Apple");
        this.setAcidity(1.0);
        this.setSweetness(1.0);
        this.setAgeInDays(0);
        this.setMass(0.1);
    }
    public void setName(String name) {
        this.name = name;
    }

    public void setAcidity(double acidity) {
        this.acidity = acidity;
    }

    public void setSweetness(double sweetness) {
        this.sweetness = sweetness;
    }

    public void setAgeInDays(int ageInDays) {
        this.ageInDays = ageInDays;
    }

    public void setMass(double mass) {
        this.mass = mass;
    }

    Fruit(String name, double acidity, double sweetness, int ageInDays, double mass){
        this.setName(name);
        this.setAcidity(acidity);
        this.setSweetness(sweetness);
        this.setAgeInDays(ageInDays);
        this.setMass(mass);

    }
}
