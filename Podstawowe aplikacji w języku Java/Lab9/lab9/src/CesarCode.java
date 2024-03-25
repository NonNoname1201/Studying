import java.io.*;
import java.util.ArrayList;

public class CesarCode {
    public static void encode(String fileName, int constant){
        try{
            ArrayList<Character> arrayList = new ArrayList<>();
            String s;
            BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName));
            while ((s = bufferedReader.readLine()) != null){
                for (char c: s.toCharArray()) {
                    arrayList.add((char)(c + constant));
                }
                arrayList.add('\n');
            }
            bufferedReader.close();

            String newFile = "Encoded_" + fileName;
            FileWriter fileWriter = new FileWriter(newFile);
            for (int i = 0; i < arrayList.size(); i++) {
                fileWriter.write(arrayList.get(i));
            }

            fileWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    public static void decode(String fileName, int constant){
        try{
            ArrayList<Character> arrayList = new ArrayList<>();
            String s;
            BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName));
            while ((s = bufferedReader.readLine()) != null){
                for (char c: s.toCharArray()) {
                    arrayList.add((char)(c - constant));
                }
            }
            bufferedReader.close();

            String newFile = "Decoded_" + fileName;
            FileWriter fileWriter = new FileWriter(newFile);
            for (int i = 0; i < arrayList.size(); i++) {
                fileWriter.write(arrayList.get(i));
            }

            fileWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
