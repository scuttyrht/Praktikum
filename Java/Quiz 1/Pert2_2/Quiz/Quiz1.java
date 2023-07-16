package Quiz;

import Dogs.*;
import Games.*;
import Movies.*;

public class Quiz1{
    public static void main(String[] args) {
        printLine(); DogTestDrive.main(null);
        printLine(); MovieTestDrive.main(null);
        printLine(); GameLauncher.main(null);
        printLine(); 
    }

    public static void printLine(){
        System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    }
}
