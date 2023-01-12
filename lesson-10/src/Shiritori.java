import java.util.ArrayList;

public class Shiritori {
    ArrayList<String> words = new ArrayList<String>(); // Create an ArrayList object
    int wordsSize = 0;
    boolean game_over = false;

    void play(String word) {
        if (words.isEmpty()) {
            words.add(word);
            wordsSize++;
            printWords();
        }

        else if (game_over) {
            System.out.println("Game is over!");
        }

        else {
            if (words.contains(word)) {
                game_over = true;
                System.out.println("Game over!\n" + word + " has already been used");
                return;
            }

            String prevWord = words.get(wordsSize - 1);
            if (prevWord.charAt(prevWord.length() - 1) == word.charAt(0)) {
                words.add(word);
                wordsSize++;

                printWords();
            }

            else {
                game_over = true;
                System.out.println("Game over!\n" + word + " doesn't start with " + prevWord.substring(prevWord.length()-1));
            }
        }
    }

    void restart() {
        words.clear();
        wordsSize = 0;
        game_over = false;
        System.out.println("Game is restarted so you can play");
    }

    void printWords() {
        System.out.println(words);
    }
}
