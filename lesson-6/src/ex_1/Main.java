package ex_1;

public class Main {
    public static void main(String[] args) {
        NumbersAggregate aggregator = new NumbersAggregate(3, 100);
        System.out.println(aggregator.max());
        System.out.println(aggregator.min());
        System.out.println(aggregator.avg());
    }
}