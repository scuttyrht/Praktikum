import java.util.ArrayList;

public class Main {
    private GameHelper helper = new GameHelper();
    private ArrayList<DotCom> dotComsList = new ArrayList<>();
    private int guesses = 0;
    private String[][] data = new String[7][7];

    private void setUpGame() {
        DotCom[] dotCom = new DotCom[3];
        for (int i = 0; i < 3; i++) dotCom[i] = new DotCom();
        dotCom[0].setName("Pets.com");
        dotCom[1].setName("eToys.com");
        dotCom[2].setName("Go2.com");
        this.dotComsList.add(dotCom[0]);
        this.dotComsList.add(dotCom[1]);
        this.dotComsList.add(dotCom[2]);
        System.out.println("Your goal is to sink three dotcoms:");
        System.out.println("Pets.com, eToys.com, and Go2.com");
        System.out.println("Try to sink them all in the fewest number of guesses");
        for (DotCom dC : this.dotComsList) {
            ArrayList<String> arrayList = this.helper.placeDotCom(3);
            dC.setLocs(arrayList);
        }
        printArrays();
    }

    private void stringToArrayLoc(String paramString) {
        paramString = paramString.toLowerCase();
        int i = paramString.charAt(0) - 97;
        int j = paramString.charAt(1) - 49;
        this.data[i][j] = paramString;
    }

    private void printArrays() {
        System.out.println(" +--+--+--+--+--+--+--+");
        char c = 'A';
        for (byte b = 0; b < 7; b++) {
            System.out.print(c + "|");
            for (byte b1 = 0; b1 < 7; b1++) {
                if (this.data[b][b1] == null)
                    this.data[b][b1] = "? ";
                System.out.print(this.data[b][b1] + "|");
            }
            System.out.println();
            c = (char)(c + 1);
        }
        System.out.println(" +--+--+--+--+--+--+--+");
        System.out.println("  1  2  3  4  5  6  7");
    }

    private void gameInit() {
        while (!this.dotComsList.isEmpty()) {
            String str = this.helper.getUserInput("Enter a guess : ");
            checkGuess(str);
        }
        endGame();
    }

    private void checkGuess(String guess) {
        this.guesses++;
        String str = "miss";
        for (byte b = 0; b < this.dotComsList.size(); b++) {
            str = this.dotComsList.get(b).checkYourself(guess);
            if (str.equals("hit"))
                break;
            if (str.equals("kill")) {
                this.dotComsList.remove(b);
                break;
            }
        }
        System.out.println(str);
        if (str != "miss") {
            stringToArrayLoc(guess);
            printArrays();
        }
    }

    private void endGame() {
        System.out.println("All Dot Coms are dead! Your stock is now worthless.");
        if (this.guesses <= 18) {
            System.out.println("It only took you " + this.guesses + " guesses.");
            System.out.println(" You got out before your options sank.");
        } else {
            System.out.println("Took you long enough. " + this.guesses + " guesses.");
            System.out.println("Fish are dancing with your options");
        }
    }

    public static void main(String[] paramArrayOfString) {
        Main m = new Main();
        m.setUpGame();
        m.gameInit();
    }
}
