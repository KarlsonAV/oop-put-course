import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        String action;
        String word;
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));

        System.out.println("Welcome to Shiritori game!");
        Shiritori my_shiritori = new Shiritori();
        System.out.printf("Choose action:\n1 - play\n2 - restart\n");
        while (true) {

            try {
                action = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            if (action.equals("1")) {
                System.out.println("Enter word!:");
                try {
                    word = reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                my_shiritori.play(word);
            }

            else if (action.equals("2")) {
                my_shiritori.restart();
            }

            else {
                System.out.println("Wrong input! Try again");
            }
        }
    }
}