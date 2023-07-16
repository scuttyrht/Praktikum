import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] s) {
        int i = 0;
        SimpleDotCom simpleDotCom = new SimpleDotCom();
        while (true) {
            System.out.print("Enter cell coordinate [(Char)(Num)]: ");
            String input = null;
            try {
                BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                input = reader.readLine();
                if (input.length() == 0) input = null;
            } catch (IOException iOException) {
                System.out.println("IOException: " + iOException);
            }
            String check = simpleDotCom.checkYourself(input);
            i++;
            if (check != null && check.equals("kill")) {
                System.out.println("You took " + i + " guesses");
                break;
            }
        }
    }
}
