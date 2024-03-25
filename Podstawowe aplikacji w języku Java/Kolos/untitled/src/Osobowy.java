public class Osobowy implements Auto{
    private int iloscMiejsc = 0;

    public Osobowy(int iloscMiejsc){
        this.iloscMiejsc = iloscMiejsc;
    }

    @Override
    public int ileMiejsc() {
        return iloscMiejsc;
    }
}
