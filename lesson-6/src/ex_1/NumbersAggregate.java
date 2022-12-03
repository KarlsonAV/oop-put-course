package ex_1;

public class NumbersAggregate {
    private int a;
    private int b;

    NumbersAggregate() {
        this(0,0);
    }

    NumbersAggregate(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public int max() {
        return a > b ? a : b;
    }

    public int min() {
        return a < b ? a : b;
    }

    public float avg() {
        return (float) (a + b) / 2;
    }
}
