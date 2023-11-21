package projectawt;

import lmi.MainThread;

public class Main {
//      public static void main(String args[]) {
//          final Frame f = new Frame();
//          f.setContentPane(contentPane);
//          f.setSize(800, 600);
//          //        f.pack(); 
//  
//          Frame controller = new Frame("opener");
//          controller.setDefaultCloseOperation(Frame.EXIT_ON_CLOSE);
//          Action open = new AbstractAction("open/hide second") {
//  
//              @Override
//                  public void actionPerformed(ActionEvent e) {
//                      f.setVisible(!f.isVisible());
//                  }
//  
//          };
//          controller.add(new JButton(open));
//          controller.pack();
//          controller.setVisible(true);
//      }

    public static void main(String args[]) {
        FrameController frameController = new FrameController();

        new Thread(new MainThread(frameController)).start();
    }
}
