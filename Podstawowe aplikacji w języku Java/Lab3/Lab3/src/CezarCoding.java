public class CezarCoding {
    public static char[] stringToCharArr(String s){
        return s.toCharArray();
    }

    public static String cezarEncode(String s){
        char[] chars = stringToCharArr(s);

        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (Character.isAlphabetic(c)) {
                chars[i]++;
            }
        }
        return String.valueOf(chars);
    }

    public static String cezarDecode(String s){
        char[] chars = stringToCharArr(s);

        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (Character.isAlphabetic(c)) {
                chars[i]--;
            }
        }
        return String.valueOf(chars);
    }

    public static boolean isPalindrome(String s){
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) != s.charAt(s.length() - i - 1)){
                return false;
            }
        }
        return true;
    }


}
