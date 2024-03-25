import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int num = 0;
        System.out.print("Podaj ciag znakow: ");
        while(true){
            try{
                num = Integer.parseInt(new Scanner(System.in).nextLine());
                break;
            }catch (NumberFormatException numberFormatException){
                System.out.print("Podaj liczbe calkowita!\n> ");
            }
        }
        System.out.println("Liczba: " + num);
    }
}