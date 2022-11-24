// 1 euro - 1.0366 dollars
// x euros - 5 dollars

public class Euro implements Currency {

    private float _balance;
    private FakeCantor currencyConverter = new FakeCantor();

    @Override
    public Euro addedCurrency(float value, String currency) {

        return new Euro(_balance + (value / currencyConverter.euroToRate(currency)));
    }

    @Override
    public Euro subtractedCurrency(float value, String currency) {
        float subtractedBalance = _balance - (value / currencyConverter.euroToRate(currency));
        if (subtractedBalance >= 0) {
            return new Euro(subtractedBalance);
        }
        else {
            System.out.println("You can't subtract greater value than your current balance");
            throw new ArithmeticException();
        }
    }

    @Override
    public String abbreviation() {
        return "EUR";
    }

    @Override
    public String symbol() {
        return "€";
    }

    @Override
    public String balance() {
        //return Double.toString(_balance) + " " + symbol();
        return String.format("%.2f %s", _balance, symbol());
    }

    @Override
    public float toDollarExchangeRate() {
        return currencyConverter.euroToRate("USD");
    }

    Euro() {
        this(0);
    }

    Euro(float balance) {
        this._balance = balance;
    }
}
