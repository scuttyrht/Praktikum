package Movies;

public class Movie {
    String title;
    String genre;
    int rating;

    public Movie(){
        this("No title","No genre",0);
    }
    public Movie(String title, String genre, int rating){
        this.title=title;
        this.genre=genre;
        this.rating=rating;
    }
    public void playIt() {
        System.out.println("Playing the movie");
        System.out.println("Title: "+title+", Genre: "+genre+", Rating: "+rating);
    }
}
