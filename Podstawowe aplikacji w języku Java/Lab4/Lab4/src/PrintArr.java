import java.util.Random;

public class PrintArr {
    public static void printArr1D(int size){
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            if(i % 10 == 0 && i > 0){
                System.out.println();
            }
            System.out.printf("%02d, ", random.nextInt(0,100));
        }
        System.out.println();
    }

    public static void printArr2D(int size){
        Random random = new Random();
        int num = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(i == j || i + j == size-1){
                    if(random.nextBoolean()){
                        num = 1;
                    }
                    else{
                        num = -1;
                    }
                }
                else{
                    num = random.nextInt(-20, 20);
                }
                System.out.printf("%3d,", num);
            }
            System.out.println();
        }
    }
}
