import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

public class Main {
    public static void main(String[] args) {

        Integer[] arr = new Integer[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new Random().nextInt(0,100);
        }
        Arrays.sort(arr, (i, j) -> i - j);

//        Arrays.sort(arr, new Comparator<Integer>() {
//            @Override
//            public int compare(Integer i, Integer j) {
//                return i-j;
//            }
//        });
    }
}