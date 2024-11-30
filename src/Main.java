import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String formatFrom = ValidInput.validateFormat("What is the number format of your number?", scanner);
        String formatTo = ValidInput.validateFormat("What format do you want the number to be converted to?", scanner);

        String numberIn = ValidInput.validateInput(formatFrom, scanner);

        String output = ValidOutput.calculateOutput(formatFrom, formatTo, numberIn);

        System.out.println(numberIn + " is the same as " + output);

        scanner.close();
    }
}
