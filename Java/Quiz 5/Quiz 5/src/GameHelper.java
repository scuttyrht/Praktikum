import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class GameHelper {
    private int gridLength = 7;
    private int gridSize = 49;
    private int[] grid = new int[this.gridSize];
    private int comCount = 0;

    public String getUserInput(String s) {
        String str = null;
        System.out.print(s + " ");
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            str = bufferedReader.readLine();
            if (str.length() == 0)
                return null;
        } catch (IOException iOException) {
            System.out.println("IOException: " + iOException);
        }
        assert str != null;
        return str.toLowerCase();
    }

    public ArrayList<String> placeDotCom(int paramInt) {
        ArrayList<String> arrayList = new ArrayList<>();
        String str;
        int[] arrayOfInt = new int[paramInt];
        byte bi = 0;
        int i = 0, j = 1;
        boolean bool = false;
        this.comCount++;
        if (this.comCount % 2 == 1) j = this.gridLength;
        while (true) {
            if (((!bool ? 1 : 0)) != 0 && bi < this.gridLength) {
                i = (int)(Math.random() * this.gridSize);
                byte bj = 0;
                bool = true;
                while (bool && bj < paramInt) {
                    if (this.grid[i] == 0) {
                        arrayOfInt[bj++] = i;
                        i += j;
                        if (i >= this.gridSize) bool = false;
                        if (bj > 0 && i % this.gridLength == 0) bool = false;
                        continue;
                    }
                    bool = false;
                }
                continue;
            }
        break;
        }
        byte bk = 0;
        int k = 0;
        int m = 0;
        while (bk < paramInt) {
            this.grid[arrayOfInt[bk]] = 1;
            k = arrayOfInt[bk] / this.gridLength;
            m = arrayOfInt[bk] % this.gridLength;
            str = String.valueOf("abcdefg".charAt(m));
            arrayList.add(str.concat(Integer.toString(k)));
            bk++;
        }
        return arrayList;
    }
}
