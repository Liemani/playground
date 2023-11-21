package main;

public class MainRun implements Runnable {
    int critical = 0;

    @Override
    public void run() {
        ++critical;
        System.out.println(critical);
    }
}
