import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Panel extends JPanel {
    private ArrayList<Kula> listaKul;
    private int size = 20;
    private Timer timer;
    private final int DELAY = 33;

    //dla 30fps -> 1s/30 = 0,033s
    public Panel() {
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);
        addMouseListener(new Event());
        addMouseWheelListener(new MouseWheelListener() {
            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                System.out.println(size);
                size += e.getWheelRotation();
            }
        });
        timer = new Timer(DELAY, new Event());
        timer.start();
    }

    public static void close() {
        Kula.close();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (Kula k : listaKul) {
            g.setColor(k.color);
            g.drawOval(k.x, k.y, k.size, k.size);
        }
        g.setColor(Color.YELLOW);
        g.drawString(Integer.toString(listaKul.size()), 40, 40);
    }

    private class Event implements MouseListener,
            ActionListener {
        @Override
        public void mouseClicked(MouseEvent e) {
        }

        @Override
        public void mousePressed(MouseEvent e) {
            listaKul.add(new Kula(e.getX(), e.getY(), size));
            repaint();
        }

        @Override
        public void mouseReleased(MouseEvent e) {
        }

        @Override
        public void mouseEntered(MouseEvent e) {
        }

        @Override
        public void mouseExited(MouseEvent e) {
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            for (Kula k1 : listaKul) {
                for (Kula k2 : listaKul) {
                    double dist = Math.sqrt(Math.pow(k1.x - k2.x, 2) + Math.pow(k1.y - k2.y, 2));
                    if (dist < (double) (k1.size + k2.size) / 2 && dist != 0) {
                        Kula.bounce(k1, k2);
                    }
                }
                k1.update();
            }
            repaint();
        }
    }

    private class Kula {

        private static FileWriter fileWriter = null;
        public int x, y, size, xspeed = 0, yspeed = 0;
        public Color color;
        private final int MAX_SPEED = 5;

        public Kula(int x, int y, int size) {
            if (fileWriter == null) {
                File logFile = new File("bounces.log");
                try {
                    fileWriter = new FileWriter(logFile);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            this.x = x;
            this.y = y;
            this.size = size;
            color = new Color((float) Math.random(), (float)
                    Math.random(), (float) Math.random());
            while (xspeed == 0) {
                xspeed = (int) Math.ceil((Math.random() * MAX_SPEED * 2 -
                        MAX_SPEED));
            }
            while (yspeed == 0) {
                yspeed = (int) Math.ceil((Math.random() * MAX_SPEED * 2 -
                        MAX_SPEED));
            }
        }

        public void update() {
            x += xspeed;
            y += yspeed;
            if (x < 0) {
                xspeed = -xspeed;
                x = 0;
            }
            if (x > getWidth()) {
                xspeed = -xspeed;
                x = getWidth();
            }
            if (y < 0) {
                yspeed = -yspeed;
                y = 0;
            }
            if (y > getHeight()) {
                yspeed = -yspeed;
                y = getHeight();
            }
        }

        public static void bounce(Kula k1, Kula k2) {
//            double theta = Math.atan((double) (k2.y - k1.y) / (k2.x - k1.x)) + Math.PI / 2;
//            double theta1 = Math.atan((double) (k2.size * Math.sin(theta)) /
//                    (k1.size + k2.size * Math.cos(theta)));
//            double theta2 = (Math.PI - theta1) / 2; //TODO check angle
//
//            double absoluteSpeed1 = Math.sqrt(Math.pow(k1.xspeed, 2) + Math.pow(k1.yspeed, 2));
//            double absoluteSpeed2 = Math.sqrt(Math.pow(k2.xspeed, 2) + Math.pow(k2.yspeed, 2));
//            double part1 = absoluteSpeed1 * Math.cos(theta1 - theta) * (k1.size - k2.size)
//                    + 2 * k2.size * absoluteSpeed2 * Math.cos(theta2 - theta);
//            double part2 = k1.size + k2.size;
//            double part3 = absoluteSpeed1 * Math.sin(theta1 - theta) * Math.cos(theta + Math.PI / 2);
//
//            k1.xspeed = (int) Math.ceil(((part1 / part2) * Math.cos(theta) + part3));
//            part3 = absoluteSpeed1 * Math.sin(theta1 - theta) * Math.sin(theta + Math.PI / 2);
//            k1.yspeed = (int) Math.ceil(((part1 / part2) * Math.sin(theta) + part3));
//
//            part1 = absoluteSpeed2 * Math.cos(theta1 - theta) * (k2.size - k1.size)
//                    + 2 * k1.size * absoluteSpeed1 * Math.cos(theta1 - theta);
//            part3 = absoluteSpeed2 * Math.sin(theta2 - theta) * Math.cos(theta + Math.PI / 2);
//
//            k2.xspeed = (int) Math.ceil(((part1 / part2) * Math.cos(theta) + part3));
//            part3 = absoluteSpeed2 * Math.sin(theta2 - theta) * Math.sin(theta + Math.PI / 2);
//            k2.yspeed = (int) Math.ceil(((part1 / part2) * Math.sin(theta) + part3));
            k1.xspeed = -k1.xspeed;
            k1.yspeed = -k1.yspeed;
            k2.xspeed = -k2.xspeed;
            k2.yspeed = -k2.yspeed;

            String log = "Bounce at: " + (k1.x  + k1.size/2 + (k2.x - k1.x)/2) + ", " + (k1.y + k1.size/2 + (k2.y - k1.y)/2) + ", "
                    + "k1(" + k1.x + ", " + k1.y + ") | k2(" + k2.x + ", " + k2.y + ")\n";
            try {
                fileWriter.append(log);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public static void close() {
            try {
                fileWriter.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
