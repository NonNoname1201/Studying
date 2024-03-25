import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferInt;
import java.util.Arrays;

import static java.lang.Math.*;

public class Main {

    public static double delta(int x, int y, int max_x, int max_y, int levels, double time){
        double delta = 0;
        double freq;
        double offsetx;
        double offsety;
        for (int i = 0; i < levels; i++) {
            offsetx = (sin(time*i*PI) + sin(time*i*PI*2))/2;
            offsety = (cos(time*i*PI*2) + cos(time*i*PI*3))/2;
            freq = Math.pow(2, i);
            delta = (1+(Math.sin(x*(PI*freq)/max_x + offsetx) * (cos(y*(PI*freq)/max_y + offsety))))/2;
        }
        return Math.pow(delta, 1);
    }
    public static void main(String[] args) {
        //make basic frame and set it to visible
        JFrame frame = new JFrame();
        frame.setSize(1000, 1000);
        frame.setTitle("My First Frame");
       // frame.setResizable(false);
        //frame.setAlwaysOnTop(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //set layout to null
        frame.setLayout(null);
        //create panel
        JPanel panel = new JPanel();
        //set size
        panel.setSize(1000, 1000);
        panel.setPreferredSize(new Dimension(1000, 1000));
        //panel.setBackground(Color.gray);
        panel.setDoubleBuffered(true);
        frame.add(panel);
        frame.setVisible(true);

        //convert pane to array of pixels
        Graphics2D g = (Graphics2D) panel.getGraphics();
        //convert g to buffered image
        BufferedImage img = new BufferedImage(panel.getWidth(), panel.getHeight(), BufferedImage.TYPE_INT_RGB);
        //convert buffered image to array of pixels




        double time=0;
        //delta for each color
        double delta;
        double delta2;
        double delta3;
        double freqx = 10;
        double freqy = 10;

        while (true){
            time+=0.01;
            for (int i = 0; i < panel.getHeight(); i++) {
                for (int j = 0; j < panel.getWidth(); j++) {
                    delta = delta(i, j, 1000, 1000, 2, time);
                    img.setRGB(i,j, new Color((int)(delta*255), (int)(delta*255), (int)(delta*255)).getRGB());
                }
            }
            g.drawImage(img, 0, 0, null);
        }
        //set frame to visible
        //frame.setVisible(true);






    }
}