import java.util.InputMismatchException;
import java.util.Scanner;

public class DigitSquaring {
    private static int num;

    private static void getData(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Give me a number from <99, 999>\n> ");
        while(true){
            try{
                num = scanner.nextInt();
                if(num < 99 || num > 999){
                    throw new ArithmeticException();
                }
                break;
            }catch (ArithmeticException arithmeticException){
                System.out.print("Number is out of bounds! <99, 999>\n> ");
            }catch (InputMismatchException inputMismatchException){
                System.out.print("Give me a whole number, not a gibberish!\n> ");
                scanner.next();
            }
        }
    }

    public static int squareDigitSum(int number){
        int result = 0;
        String s = Integer.toString(number);
        for (char c:
             s.toCharArray()) {
            result += Math.pow(c - '0', 2);
        }
        return result;
    }

    public static void process(){
        getData();
        System.out.println("Number " + num + " converts to -> " + squareDigitSum(num));
    }
}
