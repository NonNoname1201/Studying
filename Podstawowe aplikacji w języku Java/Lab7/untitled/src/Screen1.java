import javax.swing.*;

public class Screen1 extends JFrame{
    private JPanel panel1;
    private JButton ConsoleButton;
    private JTextArea textArea;
    private JTextField textField1;
    private JRadioButton toConsoleRadioButton;
    private JRadioButton toFileRadioButton;
    private JTextPane fileNameTextPane;

    public Screen1() {
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.add(panel1);
        this.pack();
        this.setVisible(true);
        ConsoleButton.addActionListener(e -> System.out.println(textArea.getText()));
    }


}
