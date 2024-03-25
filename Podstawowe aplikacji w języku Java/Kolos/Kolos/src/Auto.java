public class Auto {
    private String model = null;
    private int rocznik = 0;
    private String marka = null;
    private int numRejestr = 0;

    public Auto(String model, int rocznik, String marka, int numRejestr) {
        this.model = model;
        this.rocznik = rocznik;
        this.marka = marka;
        this.numRejestr = numRejestr;
    }

    public String getModel() {
        return model;
    }

    public int getRocznik() {
        return rocznik;
    }

    public String getMarka() {
        return marka;
    }

    public int getNumRejestr() {
        return numRejestr;
    }

    @Override
    public String toString() {
        return "Auto{" +
                "model='" + model + '\'' +
                ", rocznik=" + rocznik +
                ", marka='" + marka + '\'' +
                ", numRejestr=" + numRejestr +
                '}';
    }
}
