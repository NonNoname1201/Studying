import javax.swing.JPanel;
import java.awt.*;
import java.io.*;

public class ReflectPanel extends JPanel {
    int x = 0, y = 0;
    ReflectPanel(){
        this.setBackground(Color.black);
    }
    @Override
    protected void paintComponent(Graphics g){
        super.paintComponent(g);
        g.setColor(new Color(200, 100, 100));

        BufferedReader bufferedReader = null;
        try {

            String data;
            bufferedReader = new BufferedReader(new FileReader("bounces.log"));
            while((data = bufferedReader.readLine()) != null){
                String[] dataArr = data.split(" ");
                x = Integer.parseInt(dataArr[2].replace(',', ' ').trim());
                y = Integer.parseInt(dataArr[3].replace(',', ' ').trim());

                g.drawLine(x-2, y-2, x+2, y+2);
                g.drawLine(x+2, y-2, x-2, y+2);
            }

            bufferedReader.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

}
