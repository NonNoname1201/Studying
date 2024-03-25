import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.Scanner;

public class setProcessing {


    private static void printSorted(ArrayList<Integer> arrayList){
        arrayList.sort(null);
        System.out.print("Your array: ");
        for (int i:
                arrayList) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    private static int getIntFromUser(){
        Scanner scanner = new Scanner(System.in);
        int num;
        while(true){
            try {
                System.out.print("> ");
                num = scanner.nextInt();
                break;
            } catch (InputMismatchException e) {
                System.out.println("Not a number");
                scanner.next();
            }
        }
        return num;
    }

    public static void basic() {
        int sum = 0;
        int product = 1;
        int num;
        ArrayList<Integer> arrayList = new ArrayList<>();
        System.out.println("Give me a num:");
        while (sum < 250 && product < 3000000) {
            num = getIntFromUser();
            arrayList.add(num);
            sum += num;
            product *= num;
            System.out.println("Sum = " + sum);
            System.out.println("Product = " + product);
        }
        printSorted(arrayList);
    }

    public static void sumCorrection(){
        int sum = 0;
        int num;
        ArrayList<Integer> arrayList = new ArrayList<>();
        System.out.println("Give me a num:");
        while (sum != 64){
            num = getIntFromUser();
            arrayList.add(num);
            sum += num;
            printSorted(arrayList);
            if(sum > 64){
                System.out.println("Sum is exceeded. Removing " + arrayList.get(arrayList.size()-1));
                sum -= arrayList.get(arrayList.size()-1);
                arrayList.remove(arrayList.size()-1);
                printSorted(arrayList);
            }
            System.out.println("Sum = " + sum);
        }
    }

    public static void productCorrection(){
        int product = 1;
        int num;
        ArrayList<Integer> arrayList = new ArrayList<>();
        System.out.println("Give me a num:");
        while (product != 256){
            num = getIntFromUser();
            arrayList.add(num);
            product *= num;
            printSorted(arrayList);
            if(product > 256){
                System.out.println("Product is exceeded. Removing " + arrayList.get(arrayList.size()-1));
                product /= arrayList.get(arrayList.size()-1);
                arrayList.remove(arrayList.size()-1);
                printSorted(arrayList);
            }
            System.out.println("Product = " + product);
        }
    }
}
