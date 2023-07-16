public class Main {
    public int printMenu() {
        System.out.println("====================================");
        System.out.println("   Ujian Tengah Semester PBO 2023   ");
        System.out.println("   Nama: Zakirio Hugoraazaq Wasis   ");
        System.out.println("   NIM : 2207411039                 ");
        System.out.println("====================================");
        System.out.println("  [1] Tampilkan History             ");
        System.out.println("  [2] Tebak Posisi                  ");
        System.out.println("  [3] Hitung Usia                   ");
        System.out.println("  [4] Keluar                        ");
        System.out.println("====================================");
        AppHelper helper = new AppHelper();
        return helper.getChoice(" Pilihan : ", 1, 4);
    }

    public static void main(String[] args) {
        Main main = new Main();
        HistoryReadWrite historyRW = new HistoryReadWrite("UTS-log.txt");
        historyRW.logToHistory(DateTime.getCurrentDateTime() + " : Start program");
        boolean loop = true;
        while (loop) {
            DotComTestDrive game;
            int choice = main.printMenu();
            historyRW.logToHistory(DateTime.getCurrentDateTime() + " : Menu " + DateTime.getCurrentDateTime() + " selected");
            switch (choice) {
                case 1:
                    historyRW.printHistory();
                case 2:
                    game = new DotComTestDrive();
                    game.setupGame();
                    historyRW.logToHistory(DateTime.getCurrentDateTime() + " : " + DateTime.getCurrentDateTime());
                case 3:
                    DateTime.countAge();
                    historyRW.logToHistory(DateTime.getCurrentDateTime() + " : " + DateTime.getCurrentDateTime());
                case 4:
                    historyRW.logToHistory(DateTime.getCurrentDateTime() + " : End program");
                    System.out.println("End Program");
                    loop = false;
            }
        }
    }
}
