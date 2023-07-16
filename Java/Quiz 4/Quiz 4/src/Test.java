import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test {
    public static void main(String[] args) throws IOException {
    String input = null;
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    input = reader.readLine();
    input = input.toLowerCase();
    int i = input.charAt(0) - 97;
    int j = input.charAt(1) - 49;
    System.out.println(i + " " + j);
    }
}
