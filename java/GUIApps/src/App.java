import java.awt.Dimension;
import java.awt.Rectangle;
import java.util.Date;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.ImageIcon;

// Quick note: for this app readability and clarity wasn't the focus

public class App {
    public static void main(String[] args) throws Exception {
        InnerApp app = new InnerApp();
        app.setBounds(50,50,400,400);
        app.setVisible(true);
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

class InnerApp extends JFrame {
    Thread th1;
    Thread th2;
    Thread th3;
    Thread th4;

    int x = 0;
    Date d = new Date();
    JLabel label = new JLabel();
    JLabel icon;

    final int ballSpeed = 10;
    int ix =0;
    int iy =0;
    boolean goingRight = true;
    boolean goingDown = true;

    public InnerApp(){
        this.setTitle("my test");
        this.setLayout(null);

        label.setHorizontalAlignment(JLabel.CENTER);
        label.setVerticalAlignment(JLabel.CENTER);

        label.setText(d.toString());

        Dimension size = label.getPreferredSize();
        label.setBounds(x,50,size.width, size.height);
        
        // created image by adding an icon to a label
        ImageIcon image = new ImageIcon(
            getClass().getResource("/assets/snowball.png")
            );
        icon = new JLabel(image);
        icon.setHorizontalAlignment(JLabel.CENTER);
        icon.setVerticalAlignment(JLabel.CENTER);
        size = icon.getPreferredSize();
        icon.setBounds(x,50,size.width, size.height);

        this.add(label);
        this.add(icon);

        // these are all the threads used by this app
        // all of them are called using method references

        th1 = new Thread(this::updateDate);
        th2 = new Thread(this::updatePosition);
        th3 = new Thread(this::updateBall);
        th4 = new Thread(this::refreshBuffer);
        
        th1.start();
        th2.start();
        th3.start();
        th4.start();
    }

    private void refreshBuffer(){
        // used because otherwise linux refuses to update the image frequently enough otherwise
        while (true) {
            this.getToolkit().sync();
            try {
                Thread.sleep(10);   
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void updatePosition(){
        // updates the Marque position
        // we use the width to calculate the wrap around position
        while (true){
            Dimension size = label.getPreferredSize();
            x+=5;
            if (x>this.getBounds().width){
                x=-(int)size.getWidth();
            }
            label.setBounds(x,50,size.width, size.height);
            try {
                Thread.sleep(100);   
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void updateBall(){
        // 4 blocks updateing 4 directions
        // necessary because these blocks also check collision with border
        while (true) {
            Rectangle windowBounds = this.getContentPane().getBounds();
            Dimension size = icon.getPreferredSize();
            if (goingDown){
                iy+=ballSpeed;
                if (iy+size.height>windowBounds.height){
                    iy = windowBounds.height-size.height;
                    goingDown = false;
                }
            }else {
                iy-=ballSpeed;
                if (iy<0){
                    iy = 0;
                    goingDown = true;
                }
            }

            if (goingRight){
                ix+=ballSpeed;
                if (ix+size.width>windowBounds.width){
                    ix = windowBounds.width-size.width;
                    goingRight = false;
                }
            }else {
                ix-=ballSpeed;
                if (ix<0){
                    ix = 0;
                    goingRight = true;
                }
            }
            
            // actually update element position
            icon.setBounds(ix,iy,size.width, size.height);

            try {
                Thread.sleep(50);   
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void updateDate(){
        while (true){
            d = new Date();
            label.setText(d.toString());
            try {
                Thread.sleep(1000);   
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}