import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class ValidInput {

    static List<String> validInputs = Arrays.asList("0", "1", "2");

    public static String validateFormat(String question, Scanner scanner) {
        while (true) {
            try {
                System.out.println(question);
                System.out.println("[decimal|hex|binary] [0|1|2]");

                String formatFrom = scanner.nextLine();
                if (!validInputs.contains(formatFrom))
                    throw new Exception();
                else
                    return formatFrom;
            } catch (Exception e) {
                System.out.println("Please enter a number between 0 and 2.");
            }

        }
    }

    public static String validateInput(String formatFrom, Scanner scanner) {
        while (true) {
            try {
                System.out.println("Please enter your number.");
                String numberIn = scanner.nextLine();

                Pattern decPat = Pattern.compile("^[0-9]+$");
                Pattern hexPat = Pattern.compile("^[0-9A-F]+$", Pattern.CASE_INSENSITIVE);
                Pattern binPat = Pattern.compile("^[01]+$");

                Boolean decMatch = decPat.matcher(numberIn).matches();
                Boolean hexMatch = hexPat.matcher(numberIn).matches();
                Boolean binMatch = binPat.matcher(numberIn).matches();

                if (formatFrom.equals("0") && decMatch) {
                    return numberIn;
                }
                if (formatFrom.equals("1") && hexMatch) {
                    return numberIn;
                }
                if (formatFrom.equals("2") && binMatch) {
                    return numberIn;
                }

                throw new Exception();
            } catch (Exception e) {
                System.out.println("Please enter a valid number from your chosen number format.");
            }
        }
    }
}
