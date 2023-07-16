package main;

import java.util.Scanner;
import java.util.Random;

class Guess {
    Random rand = new Random();
    int[] locationCells;
    int numOfHits = 0;
    int gDogLoc, bDogLoc;

    public void setLocationCells(int[] locs) {
        locationCells = locs;
        gDogLoc = rand.nextInt(locs.length);
        bDogLoc = rand.nextInt(locs.length);
    }
    public String checkYourself(String stringGuess) {
        int guess = Integer.parseInt(stringGuess);
        String result = "miss";
        int gDogSize = rand.nextInt(100) + 1, bDogSize = rand.nextInt(100) + 1;
        Dog goodDog = new Dog("GoodDog", gDogSize), badDog = new Dog("BadDog", bDogSize);
        for (int cell : locationCells) {
            if (guess == cell) {
                result = "hit";
                numOfHits++;
                break;
            }
        }
        if (numOfHits == locationCells.length) {
            result = "kill";
        }
        return result;
    }
}

class Dog {
    int size;
    String name;
    void bark(int numOfBarks) {
        String barkType;
        if (size > 60) barkType = "Woof ";
        else if (size > 14) barkType = "Ruff ";
        else barkType = "Yeet ";

        for (int i = 0; i < numOfBarks; i++) {
            System.out.print(barkType);
        } System.out.println();
    }

    public Dog(String name, int size) {
        this.name = name;
        this.size = size;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner rd = new Scanner(System.in);
        Guess g = new Guess();
        Random randLocAmt = new Random();
        int locAmt = randLocAmt.nextInt(6) + 5, maxLocRange = locAmt - 1;
        int[] locs = new int[locAmt];
        g.setLocationCells(locs);
        for (int i = 0; i < locs.length; i++) {
            locs[i] = i;
        }

        System.out.println("There are 1 GoodDog and 1 BadDog in " + locAmt + " Location cells (0 to " + maxLocRange + ")" +
                "\nGuess their locations!");

        String userGuess, result;

        do {
            System.out.print("Enter a number: ");
            userGuess = rd.nextLine();
            result = g.checkYourself(userGuess);
            System.out.println(result);
        } while (!result.equals("kill"));
    }
}
