import com.sun.source.tree.WhileLoopTree;

import java.util.*;

public class Main {
    public static void wydruk(ArrayList<Auto> autoArrayList){
        for (Auto a:
             autoArrayList) {
            System.out.println(a.toString());
        }
    };

    public static void main(String[] args) {
        ArrayList<Auto> listaAut = new ArrayList<>();
        String parametr = null;

        listaAut.add(new Auto("Camaro", 2020,
                "Chevrolet", new Random().nextInt(1000, 9999)));
        listaAut.add(new Auto("Supra", 2007,
                "Toyota", new Random().nextInt(1000, 9999)));
        listaAut.add(new Auto("M3E46", 2003,
                "BMW", new Random().nextInt(1000, 9999)));
        listaAut.add(new Auto("Logan", 2008,
                "Renault", new Random().nextInt(1000, 9999)));

        Comparator<Auto> autoComparatorModel =
                new Comparator<>() {
                    @Override
                    public int compare(Auto a, Auto b) {
                        return a.getModel().
                                compareToIgnoreCase(b.getModel());
                    }
                };

        Comparator<Auto> autoComparatorRocznik =
                new Comparator<>() {
                    @Override
                    public int compare(Auto a, Auto b) {
                        return a.getRocznik() < b.getRocznik() ? -1 :
                                a.getRocznik() < b.getRocznik() ? 0 : 1;
                    }
                };

        Comparator<Auto> autoComparatorMarka =
                new Comparator<>() {
                    @Override
                    public int compare(Auto a, Auto b) {
                        return a.getMarka().
                                compareToIgnoreCase(b.getMarka());
                    }
                };

        Comparator<Auto> autoComparatorNumRejestr =
                new Comparator<>() {
                    @Override
                    public int compare(Auto a, Auto b) {
                        return a.getNumRejestr() < b.getNumRejestr() ? -1 :
                                a.getNumRejestr() < b.getNumRejestr() ? 0 : 1;
                    }
                };

        while(true){
            boolean b = true;
            System.out.println("Podaj parametr do porownania");
            parametr = new Scanner(System.in).next().toLowerCase();
            switch (parametr){
                case "model":{
                    listaAut.sort(autoComparatorModel);
                    break;
                }
                case "rocznik":{
                    listaAut.sort(autoComparatorRocznik);
                    break;
                }
                case "marka":{
                    listaAut.sort(autoComparatorMarka);
                    break;
                }
                case "numrejestr":{
                    listaAut.sort(autoComparatorNumRejestr);
                    break;
                }
                default:{
                    System.out.println("niepoprawny parametr");
                    b = false;
                }
            }
            if(b){
                wydruk(listaAut);
            }
            System.out.println("Volodymyr Dobrohorskyi");
        }




    }
}