import java.util.ArrayList;

public class DotComTestDrive {
    private final String[][] data;
    private int guesses = 0;
    private final AppHelper helper = new AppHelper();
    private ArrayList<DotCom> DotCom;

    public DotComTestDrive() {
        this.data = new String[7][7];
    }

    public void initGame() {
        while (!this.DotCom.isEmpty()) {
            String str = this.helper.getInput("Enter a guess : ");
            checkGuess(str);
        }
        endGame();
    }

    private void inputToArray(String paramString) {
        paramString = paramString.toLowerCase();
        int i = paramString.charAt(0) - 97;
        int j = paramString.charAt(1) - 49;
        this.data[i][j] = paramString;
    }

    private void printArrays() {
        System.out.println(" +--+--+--+--+--+--+--+");
        char c = 'A';
        for (int i = 0; i < 7; i++) {
            System.out.print(c + "|");
            for (int j = 0; j < 7; j++) {
                if (this.data[i][j] == null)
                    this.data[i][j] = "? ";
                System.out.print(this.data[i][j] + "|");
            }
            System.out.println();
            c = (char)(c + 1);
        }
        System.out.println(" +--+--+--+--+--+--+--+");
        System.out.println("  0  1  2  3  4  5  6");
    }

    public void setupGame() {
        DotCom dotCom1 = new DotCom();
        dotCom1.setName("Pets.com");
        DotCom dotCom2 = new DotCom();
        dotCom2.setName("eToys.com");
        DotCom dotCom3 = new DotCom();
        dotCom3.setName("Go2.com");
        this.DotCom.add(dotCom1);
        this.DotCom.add(dotCom2);
        this.DotCom.add(dotCom3);
        System.out.println("Your goal is to sink three dotcoms.");
        System.out.println("Pets.com, eToys.com, Go2.com");
        System.out.println("Try to sink them all in the fewest number of guesses");
        for (DotCom aB : this.DotCom) {
            ArrayList<String> arrayList = this.helper.placeDotComs(3);
            aB.setLocs(arrayList);
        }
        printArrays();
    }

    private void endGame() {
        System.out.println("All DotComs are dead!");
        String str = "";
        if (this.guesses <= 18) {
            str = str + "It only took you " + str + " guesses.";
            str = str + " You got out before your options sank.";
        } else {
            str = str + "Took you long enough. " + str + " guesses.";
            str = str + "Fish are dancing with your options";
        }
        System.out.println(str);
    }

    public static void main(String[] paramArrayOfString) {
        DotComTestDrive game = new DotComTestDrive();
        game.setupGame();
        game.initGame();
    }

    private void checkGuess(String paramString) {
        this.guesses++;
        String str = "miss";
        for (byte b = 0; b < this.DotCom.size(); b++) {
            str = this.DotCom.get(b).checkYourself(paramString);
            if (str.equals("hit"))
                break;
            if (str.equals("kill")) {
                this.DotCom.remove(b);
                break;
            }
        }
        System.out.println(str);
        if (!str.equals("miss")) {
            inputToArray(paramString);
            printArrays();
        }
    }
}
