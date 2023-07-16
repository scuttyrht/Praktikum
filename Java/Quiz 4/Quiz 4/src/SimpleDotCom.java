class SimpleDotCom {
    int hits = 0, gDogs = 0, bDogs = 0;
    private Dog[][] locs = new Dog[7][7];

    public SimpleDotCom() {
        setDogs();
        printCells();
    }

    private void setDogs() {
        int i = (int)(Math.random() * 10.0D);
        if (i < 6)
            i += 5;
        for (byte j = 0; j < i; j++) {
            int k = (int)(Math.random() * 2.0D);
            placeDog(k);
            if (k == 1) {
                this.gDogs++;
            } else {
                this.bDogs++;
            }
        }
        System.out.println("There are " + this.gDogs + " GoodDogs and " + this.bDogs + " BadDogs in 49 cells");
        System.out.println("Guess their locations!");
    }

    private void placeDog(int type) {
        while (true) {
            int i = (int)(Math.random() * 7.0D);
            int j = (int)(Math.random() * 7.0D);
            if (this.locs[i][j] == null) {
                String str = "BadDog";
                if (type == 1)
                    str = "GoodDog";
                this.locs[i][j] = new Dog((int)(Math.random() * 100.0D), str);
                return;
            }
        }
    }

    public String checkYourself(String input) {
        if (input == null || input.length() > 2)
            return null;
        input = input.toLowerCase();
        int i = input.charAt(0) - 97;
        int j = input.charAt(1) - 49;
        Dog dog = null;
        try {
            dog = this.locs[i][j];
        } catch (Exception ignored) {}
        String str = "miss";
        if (dog != null && dog.getHitStatus()) {
            str = "hit";
            this.hits++;
            System.out.println(dog);
            this.locs[i][j].setHitStatus(true);
            printCells();
        }
        if (this.hits >= this.bDogs + this.gDogs)
            str = "kill";
        System.out.println(str);
        return str;
    }

    private void printCells() {
        System.out.println(" +---+---+---+---+---+---+---+");
        char c = 'A';
        for (byte i = 0; i < 7; i++) {
            System.out.print(c + "|");
            for (byte j = 0; j < 7; j++) {
                if (this.locs[i][j] == null || !this.locs[i][j].getHitStatus()) {
                    System.out.print(" ? |");
                } else if (this.locs[i][j].getName() == "GoodDog") {
                    System.out.print("GDg|");
                } else if (this.locs[i][j].getName() == "BadDog") {
                    System.out.print("BDg|");
                }
            }
            System.out.println();
            c = (char)(c + 1);
        }
        System.out.println(" +---+---+---+---+---+---+---+");
        System.out.println("   1   2   3   4   5   6   7");
    }
}
