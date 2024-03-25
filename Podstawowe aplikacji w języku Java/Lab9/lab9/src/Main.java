public class Main {

    public static void main(String[] args) {
        CesarCode.encode("customText.txt", 7);
        CesarCode.decode("Encoded_customText.txt", 7);
        try{
            System.out.println(1/0);
        }catch (ArithmeticException a){
            System.exit(1);
        }finally {
            System.out.println("i'm closed");
        }
    }
}