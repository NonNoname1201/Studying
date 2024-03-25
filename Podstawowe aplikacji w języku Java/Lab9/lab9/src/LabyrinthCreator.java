import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;

public class LabyrinthCreator {
    public static final int FULLBOARD = 0, TWOEXITS = 1,
            MULTIPLEEXITS = 2, OPENBOARD = 3;
    private int size;
    private int mode;
    public static int num;

    public LabyrinthCreator(int size, int mode) {
        this.size = size;
        this.mode = mode;
    }

    public boolean create(String name) {
        File labyrinth = new File(name);
        try {
            FileWriter fileWriter = new FileWriter(labyrinth);
            fileWriter.append(char2DToString(buildLabyrinth()));
            fileWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return true;
    }

    private char[][] buildLabyrinth() {
        char[][] labyrinth = null;
        switch (mode) {
            case FULLBOARD -> {
                labyrinth = new char[size][size + 1];
                for (int i = 0; i < labyrinth.length; i++) {
                    Arrays.fill(labyrinth[i], ' ');
                }

                for (int i = 0; i < size; i++) {
                    for (int j = 0; j <= size; j++) {
                        if (i == 0 || i == size - 1) labyrinth[i][j] = '#';
                        if (j == 0 || j == size - 1) labyrinth[i][j] = '#';
                        if (j == size) labyrinth[i][j] = '\n';
                    }
                }

                buildwall(labyrinth, 1, 1, size-1, size-1);
            }
            default -> System.out.println("hi");
        }
        System.out.println(char2DToString(labyrinth));
        return labyrinth;
    }

    private char[][] buildwall(char[][] chamber, int x0, int y0, int x1, int y1) {
        int yW = 0;
        int xW = 0;
        if (y1 - y0 > 5) {
            yW = new Random().nextInt(y0+1, y1-1);
            int yWO = new Random().nextInt(x0 + 1, x1 - 1);
            for (int i = x0; i < x1; i++){
                if (i != yWO) chamber[yW][i] = '#';
            }

        }
        if (x1 - x0 > 5) {
            xW = new Random().nextInt(x0 + 1, x1 - 1);
            int xWO = new Random().nextInt(y0 + 1, y1 - 1);
            for (int i = y0; i < y1; i++)
                if (i != xWO) chamber[i][xW] = '#';
        }

        if (y1 - yW > 5) {
            if (x1 - xW > 5) {
                chamber = buildwall(chamber, xW, yW, x1, y1);
            }
            if (xW - x0 > 5) {
                chamber = buildwall(chamber, x0, yW, xW, y1);
            }
        }
        if (yW - y0 > 5) {
            if (x1 - xW > 5) {
                chamber = buildwall(chamber, xW, y0, x1, yW);
            }
            if (xW - x0 > 5) {
                chamber = buildwall(chamber, x0, y0, xW, yW);
            }
        }
        return chamber;
    }

    public static String char2DToString(char[][] a) {
        StringBuilder s = new StringBuilder();
        for (char[] line : a) {
            s.append(line);
        }
        return String.valueOf(s);
    }
}
