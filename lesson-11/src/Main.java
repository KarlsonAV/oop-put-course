public class Main {
    public static void main(String[] args) {
        Sequence characters = new Characters("Hello World");
        Sequence lowerCased = new LowerCased(characters);
        Sequence substring = new Substring(lowerCased, 6, 11);
        System.out.println(substring.printedSeq()); // prints "world"
    }
}