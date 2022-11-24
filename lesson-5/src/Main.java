public class Main {
  public static void main(String[] args) {
    Euro balance1 = new Euro();
    Euro balance2 = balance1.addedCurrency(11, "USD");
    System.out.println(balance2.balance());
  }
}