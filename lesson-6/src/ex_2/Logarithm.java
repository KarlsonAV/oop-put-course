package ex_2;

public class Logarithm implements Number {

    private double base, argument;

    @Override
    public double doubleValue() throws ArithmeticException{

        if (base <= 0 || base == 1) {
            throw new ArithmeticException("Base of log can't be less or equal to 0, or equal to 1\n");
        }

        if (argument <= 0) {
            throw new ArithmeticException("Argument of log can't be less or equal to 0\n");
        }

        return Math.log(this.argument) / Math.log(this.base);
    }

    public Logarithm(double inputBase, double inputArgument) {
        this.base = inputBase;
        this.argument = inputArgument;
    }
}