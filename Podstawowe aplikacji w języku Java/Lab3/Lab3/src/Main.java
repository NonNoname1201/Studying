import java.util.Scanner;

public class Main {
    public static int charInStringCount(char c, String s) {
        int index0 = 0;
        int count = 0;
        while (s.indexOf(c, index0) != -1) {
            index0 = s.indexOf(c, index0) + 1;
            count++;
        }
        return count;
    }

    public static int charSum(String s) {
        int count = 0;
        for (char c :
                s.toCharArray()) {
            if(Character.isLowerCase(c)) {
                count += c;
            }
        }
        return count;
    }


    public static void main(String[] args) {
        /*System.out.print("Hello user!\nGive me a char: ");
        Scanner scanner = new Scanner(System.in);
        char c = scanner.next().charAt(0);

        System.out.print("Give me a string: ");
        String s = scanner.next();

        System.out.println(charInStringCount(c, s));

        System.out.print("Give me a new string: ");
        String s1 = scanner.next();

        System.out.println(charSum(s1) + " - is ASCII sum of all small chars in your string");

        int i = 0;
        while(i < 33 || i > 126){
            System.out.println();
            System.out.print("Gimme an int <33, 126> : ");
            try{
                i = scanner.nextInt();
            }catch (Exception e){
                System.out.println(e);
                System.out.println("Give me a number! Not a garbage chars!");
                scanner.next();
                continue;
            }

            if(i < 33){
                System.out.println("Too small num!");
            }
            if(i > 126){
                System.out.println("Too big num!");
            }
        }
        System.out.println("Your num is transfered to: " + (char)i); */

        System.out.println(CezarCoding.isPalindrome("ABBA"));

        System.out.println(CezarCoding.cezarDecode(CezarCoding.cezarEncode("ABBA")));
        System.out.println(CezarCoding.cezarEncode("ABBA"));

        System.out.println(Binary.decToBin(284));
        System.out.println(Binary.maxZeroLineLength(Binary.decToBin(284)));
    }
}