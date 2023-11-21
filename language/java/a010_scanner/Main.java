import java.util.Scanner;

public class Main {
    public static void main(String args[]) {

        while (true) {
            boolean booleanValue;

            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter a boolean value: ");

            try {
                booleanValue = scanner.nextBoolean();
            }
            catch (Exception e) {
                e.printStackTrace();
                continue;
            }

            System.out.print("Entered boolean: ");
            System.out.println(booleanValue);

//              System.out.print("Enter a line(\'q\' to exit): ");
//              String line = scanner.nextLine();
//  
//              if (line.contentEquals("q"))
//                  break;
//  
//              System.out.print("Entered line: ");
//              System.out.println(line);
        }
    }
}
