package projectawt;

import java.awt.Component;
import java.awt.Button;
import java.awt.Label;
import java.awt.TextField;

import java.awt.event.KeyListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelListener;
import java.awt.event.MouseMotionListener;

import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;

public class Frame extends java.awt.Frame implements KeyListener, MouseListener, MouseWheelListener, MouseMotionListener {
    Frame() {
        this.setTitle("[frame.title]");
        this.setSize(190,110);
        this.setVisible(true);
        this.setResizable(false);
        this.setLayout(null);
        addLiestener(this);

        Label label = new Label("[label.text]");
        label.setBounds(10, 40, 80, 30);
        addLiestener(label);
        this.add(label);

        TextField textField = new TextField();
        textField.setBounds(10, 70, 80, 30);
        addLiestener(textField);
        this.add(textField);

        Button button = new Button("Submit");
        button.setBounds(100, 70, 80, 30);
        addLiestener(button);
        this.add(button);
    }

    private void addLiestener(Component component) {
        component.addKeyListener(this);
        component.addMouseListener(this);
        component.addMouseWheelListener(this);
        component.addMouseMotionListener(this);
    }

    // interface KeyListener
    @Override
    public void keyPressed(KeyEvent keyEvent) {
        System.out.println("[keyPressed()]");
        lmi.Debug.debugDescribe(keyEvent.toString());
//          System.out.println(String.format("%04x", (int) keyEvent.getKeyChar()));
    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
        System.out.println("[keyReleased()]");
        lmi.Debug.debugDescribe(keyEvent.toString());
        System.out.println(String.format("%04x", (int) keyEvent.getKeyChar()));
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {
        System.out.println("[keyTyped()]");
        lmi.Debug.debugDescribe(keyEvent.toString());
        System.out.println(String.format("%04x", (int) keyEvent.getKeyChar()));
    }

    // interface MouseListener
    @Override
    public void mouseClicked(MouseEvent mouseEvent) {
        System.out.println("[mouseClicked()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }

    @Override
    public void mouseEntered(MouseEvent mouseEvent) {
        System.out.println("[mouseEntered()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }

    @Override
    public void mouseExited(MouseEvent mouseEvent) {
        System.out.println("[mouseExited()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }

    @Override
    public void mousePressed(MouseEvent mouseEvent) {
        System.out.println("[mousePressed()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }

    @Override
    public void mouseReleased(MouseEvent mouseEvent) {
        System.out.println("[mouseReleased()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }

    // interface MouseWheelListener
    @Override
    public void mouseWheelMoved(MouseWheelEvent mouseWheelEvent) {
        System.out.println("[mouseWheelMoved()]");
        lmi.Debug.debugDescribe(mouseWheelEvent.toString());
    }

    // interface MouseMotionListener
    @Override
    public void mouseDragged(MouseEvent mouseEvent) {
        System.out.println("[mouseDragged()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }

    @Override
    public void mouseMoved(MouseEvent mouseEvent) {
        System.out.println("[mouseMoved()]");
        lmi.Debug.debugDescribe(mouseEvent.toString());
    }
}
