package ex_1;

public class TelevisionRunner {
    public static void main(String[] args) {
        Television SONY_BRAVIA = new Television(
                "SONY", 53.1, "4K"
        );

        SONY_BRAVIA.showSpecs();
    }
}