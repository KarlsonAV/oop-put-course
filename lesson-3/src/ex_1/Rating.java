package ex_1;

public class Rating {
    private String criticName;
    private double score;

    Rating() {
        this("", 0);
    }

    Rating(String criticName, double score) {
        this.criticName = criticName;
        this.score = score;
    }

    public void print() {
        System.out.println("Critic Name: " + criticName + ", Score: " + score);
    }

}
