package ex_2;

public class Main {
    public static void main(String[] args) {
        Logarithm log = new Logarithm(1, 100);
        try {
            System.out.println(log.doubleValue());
        } catch (ArithmeticException e) {
            System.out.println(e);
        }
    }
}