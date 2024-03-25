import java.util.InputMismatchException;
import java.util.Scanner;

public class Calculator {
    private static double a;
    private static double b;
    private static char action;
    private static double result;

    private static void getData(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Give me a num A: ");
        while(true){
            try{
                a = scanner.nextDouble();
                break;
            }catch (InputMismatchException e){
                System.out.print("Give me a number, not a gibberish!\n> ");
                scanner.next();
            }
        }

        System.out.print("Give me a num B: ");
        while(true){
            try{
                b = scanner.nextDouble();
                break;
            }catch (NumberFormatException e){
                System.out.print("Give me a number, not a gibberish!\n> ");
                scanner.next();
            }
        }

        System.out.print("Give me a function [+, -, /, *]: ");
        while(true){
            action = scanner.next().charAt(0);
            if(action == '+' || action == '-' || action == '/' || action == '*'){
                break;
            }
            else{
                System.out.print("Not an action!\n> ");
            }
        }
    }

    public static void calculator(){
        System.out.println("This is a calculator ver0.1\n");
        while(true){
            getData();
            System.out.println("Solution: " + a + action + b + " = " + calculate(a, b, action));
        }
    }
    public static double calculate(){
        getData();
        switch (action) {
            case '+' -> {
                return a + b;
            }
            case '-' -> {
                return a - b;
            }
            case '*' -> {
                return a * b;
            }
            case '/' -> {
                try {
                    if(b == 0){
                        throw new ArithmeticException();
                    }
                    else{
                        return a / b;
                    }
                } catch (ArithmeticException e) {
                    System.out.println("Can't divide by a zero!");
                    return 0;
                }
            }
            default -> {
                System.out.println("Not an action");
                return 0;
            }
        }
    }

    public static double calculate(double num1, double num2, char c){
        switch (c) {
            case '+' -> {
                return num1 + num2;
            }
            case '-' -> {
                return num1 - num2;
            }
            case '*' -> {
                return num1 * num2;
            }
            case '/' -> {
                try {
                    if(num2 == 0){
                        throw new ArithmeticException();
                    }
                    else{
                        return num1 / num2;
                    }
                } catch (ArithmeticException e) {
                    System.out.println("Can't divide by a zero!");
                    return 0;
                }
            }
            default -> {
                System.out.println("Not an action");
                return 0;
            }
        }
    }
}
