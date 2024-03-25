public class Binary {
    public static String decToBin(int i){
        return Integer.toBinaryString(i);
    }

    public static int maxZeroLineLength(String s){
        int counter = -1;
        int maxCounter = 0;
        char[] chars = s.toCharArray();

        for (char c:
             chars) {
            if(c == '1') {
                maxCounter = Math.max(counter, maxCounter);
                counter = 0;
            } else if (counter != -1) {
                counter++;
            }
        }

        return maxCounter;
    }
}
