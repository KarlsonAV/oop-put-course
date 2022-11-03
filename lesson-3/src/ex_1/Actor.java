package ex_1;

public class Actor {
    private String name;
    private String surname;
    private Integer age;
    private Movie[] movies;

    Actor() {
        this("", "", 0, new Movie[] {});
    }

    Actor(String name, String surname, Integer age, Movie[] movies) {
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.movies = movies;
    }

    public void printInfo() {
        System.out.println("Name: " + name + ", Surname: " + surname + ", Age: " + age + ", Movies: " + movies);
    }
}
