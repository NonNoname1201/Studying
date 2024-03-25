import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyName extends JPanel{
    private JButton button1;
    private JTextArea textArea1;

    public MyName() {
        this.setSize(200, 300);
        this.add(button1);
        this.add(textArea1);
        button1.addActionListener(e -> setTextArea1("Volodymyr Dobrohroskyi"));
        textArea1.setLineWrap(true);
        textArea1.setColumns(10);
        textArea1.setRows(10);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("My name");
        frame.setPreferredSize(new Dimension(200, 300));
        frame.getContentPane().add(new MyName());
        frame.setVisible(true);
    }
    public void setTextArea1(String s) {
        this.textArea1.append(s);
    }

}
