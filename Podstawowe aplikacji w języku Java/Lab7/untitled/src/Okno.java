
import java.awt.Dimension;
import java.util.Objects;
import java.util.Scanner;
import javax.swing.*;

public class Okno {
    public static void main(String[] args) {
        System.out.print("Choose workflow:\n> 1 - Main program\n> 2 - Reflect\n>> ");

        JFrame frame;
        if(Objects.equals(new Scanner(System.in).next(), "1")){
            frame = new JFrame("Main screen!");
            frame.getContentPane().add(new Panel());
            frame.addWindowListener(new java.awt.event.WindowAdapter() {
                public void windowClosing(java.awt.event.WindowEvent windowEvent) {
                    if (JOptionPane.showConfirmDialog(frame,
                            "Are you sure you want to close this window?", "Close Window?",
                            JOptionPane.YES_NO_OPTION,
                            JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION){
                        Panel.close();
                        System.exit(0);
                    }
                }
            });
        }else{
            frame = new JFrame("Reflect screen!");
            frame.getContentPane().add(new ReflectPanel());
            frame.addWindowListener(new java.awt.event.WindowAdapter() {
                public void windowClosing(java.awt.event.WindowEvent windowEvent) {
                    if (JOptionPane.showConfirmDialog(frame,
                            "Are you sure you want to close this window?", "Close Window?",
                            JOptionPane.YES_NO_OPTION,
                            JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION){
                        System.exit(0);
                    }
                }
            });
        }

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setPreferredSize(new Dimension(800, 600));
        frame.pack();
        frame.setVisible(true);

    }
}