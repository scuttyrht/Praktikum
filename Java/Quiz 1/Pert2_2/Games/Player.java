package Games;

public class Player {
    int number = 0; // where the guess goes

    public void guess(int from,int to) {
        number = ((int) (Math.random() * to))+from;
        System.out.println("I'm guessing " + number);
    }
    public void guess(){
        guess(0,10);
    }
}
