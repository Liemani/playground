package main;

class Main {
    public static void main(String args[]) {

        runRunnable(() -> { System.out.println("Hellow, world!"); } );

        Runnable runnable = new MainRun();
        for (int i = 0; i < 10; ++i) {
            runRunnable(runnable);
        }
    }

    static void runRunnable(Runnable runnable) {
        Thread thread = new Thread(runnable);
        thread.start();
    }
}
