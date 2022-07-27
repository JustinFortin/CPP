import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Arrays;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class JavaGUI {
    static {
        System.loadLibrary("MyCPPLibrary0"); // Load native library CPPPortion.dll (Windows) or libCPPPortion.so (Unixes)
   
    }
    

        public JavaGUI() {
        JFrame frame = new JFrame("Java/CPP example");
        frame.getContentPane().setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        JTextField textBox = new JTextField(15);
        JButton go = new JButton("Go!");
        c.gridy = 1;
        frame.add(textBox, c);
        c.gridy = 2;
        frame.add(go, c);
        JLabel mean = new JLabel("Mean = ");
        JLabel stdDev = new JLabel("Standard deviation = ");
        JLabel time = new JLabel("Time to compute: ");
        c.gridy = 3;
        frame.add(mean, c);
        c.gridy = 4;
        frame.add(stdDev, c);
        c.gridy = 5;
        frame.add(time, c);
        frame.setSize(400, 300);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            }
        });
        JTextField meanCalc = new JTextField(15);
        meanCalc.setEditable(false);
        c.gridy = 3;
        frame.add(meanCalc, c);
        JTextField stdDevCalc = new JTextField(15);
        stdDevCalc.setEditable(false);
        c.gridy = 4;
        frame.add(stdDevCalc, c);
        JTextField timeCalc = new JTextField(15);
        timeCalc.setEditable(false);
        c.gridy = 5;
        frame.add(timeCalc,c);

        go.addActionListener((ActionEvent ae) -> {
            int textBoxVal;
            String text = textBox.getText().replaceAll(" ", "");
           
            textBoxVal = Integer.parseInt(text);
            int array[] = new int[textBoxVal];
            Random ints = new Random();
            for (int i = 0; i < textBoxVal; i++) {
                array[i] = ints.nextInt(100000);
            }
            long timeBefore = System.currentTimeMillis();
	        calculateMean(array);
            calculateSTDDev(array);
		    long timeAfter = System.currentTimeMillis();

            //System.out.print(Arrays.toString(array));
         
            meanCalc.setText(String.format("%.4f", calculateMean(array)));
            stdDevCalc.setText(String.format("%.4f", calculateSTDDev(array)));
            timeCalc.setText(Long.toString(timeAfter-timeBefore));
        });
        

        frame.setVisible(true);
    }
    public native double calculateSTDDev(int[] numbers);

    public native double calculateMean(int[] numbers);

    public static void main(String[] args) {
        JavaGUI frame = new JavaGUI();
    }
}
