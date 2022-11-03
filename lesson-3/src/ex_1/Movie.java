package ex_1;


public class Movie {
    private String name;
    private Actor[] actors;
    private String[] genres;
    private Rating[] ratings;


    Movie() {
        this("", new Actor[] {}, new String[] {}, new Rating[] {});
    }

    Movie(String name, Actor[] actors, String[] genres, Rating[] ratings) {
        this.name = name;
        this.actors = actors;
        this.genres = genres;
        this.ratings = ratings;
    }

    public void printInfo() {
        System.out.println("Movie name: " + this.name);
        System.out.println("Movie Cast: " + this.actors);
        System.out.println("Movie Genre: " + this.genres);
        System.out.println("Movie Ratings: " + this.ratings);
    }
}
