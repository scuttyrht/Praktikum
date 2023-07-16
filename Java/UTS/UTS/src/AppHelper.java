import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class AppHelper {
    private final int[] table = new int[this.tableSize];
    private final int tableSize = 49;
    private int tableLength = 7;
    private int dotcomCount = 0;
    public ArrayList<String> placeDotComs(int paramInt) {
        ArrayList<String> arrayList = new ArrayList<>();
        String str;
        int[] intArray = new int[paramInt];
        this.dotcomCount++;
        int i = 0, m, n;
        while (i < paramInt) {
            this.table[intArray[i]] = 1;
            m = intArray[i] / this.tableLength;
            n = intArray[i] % this.tableLength;
            str = String.valueOf("abcdefg".charAt(n));
            arrayList.add(str.concat(Integer.toString(m)));
            i++;
        }
        return arrayList;
    }

    public int getChoice(String paramString, int paramInt1, int paramInt2) {
        boolean bool = false;
        int i = -1;
        while (true) {
            if (!bool || i < paramInt1 || i > paramInt2) {
                try {
                    String str = getInput(paramString);
                    i = Integer.parseInt(str);
                    bool = true;
                } catch (Exception e) {
                    System.out.println("Error: " + e);
                }
                continue;
            }
            return i;
        }
    }

    String getInput(String paramString) {
        String str = null;
        System.out.print(paramString + " ");
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            str = bufferedReader.readLine();
            if (str.length() == 0)
                return null;
        } catch (IOException iOException) {
            System.out.println("IOException: " + iOException);
        }
        return str;
    }
}
