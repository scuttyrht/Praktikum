import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class HistoryReadWrite {
    String str;

    public void logToHistory(String paramString) {
        try {
            FileWriter fileWriter = new FileWriter(this.str, true);
            fileWriter.write(paramString + "\n");
            fileWriter.close();
        } catch (Exception exception) {}
    }

    public HistoryReadWrite(String paramString) {
        this.str = paramString;
    }

    public void printHistory() {
        try {
            File file = new File(this.str);
            Scanner scanner = new Scanner(file);
            System.out.println("====== History ======");
            while (scanner.hasNextLine()) {
                String str = scanner.nextLine();
                System.out.println(str);
            }
            scanner.close();
            System.out.println("=====================");
        } catch (FileNotFoundException fileNotFoundException) {
            System.out.println("Error in opening file.");
            fileNotFoundException.printStackTrace();
        }
    }
}
