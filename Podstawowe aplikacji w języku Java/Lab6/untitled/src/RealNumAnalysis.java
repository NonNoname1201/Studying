import java.util.InputMismatchException;
import java.util.Scanner;

public class RealNumAnalysis {
    private static double origin;
    private static int wholePart;
    private static double rationalPart;

    private static void getData(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Give me a num: ");
        while(true){
            try{
                origin = scanner.nextDouble();
                break;
            } catch (InputMismatchException e){
                System.out.print("Give me a num, not a gibberish!\n> ");
                scanner.next();
            }
        }
    }

    private static void split(){
        wholePart = (int) Math.floor(origin);
        rationalPart = origin - wholePart;
    }

    public static void process(){
        getData();
        split();
        System.out.println("Yur number consist of:\nWhole part: " + wholePart + "\nRational part: " + rationalPart);
    }

    public static void process(double num){
        origin = num;
        split();
        System.out.println("Yur number consist of:\nWhole part: " + wholePart + "\nRational part: " + rationalPart);
    }
}
