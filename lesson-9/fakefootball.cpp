#include <iostream>
#include <stdexcept>

class Game {
 public:
  virtual int result() = 0;
};

class FakeFootballGame : public Game {
 public:
  int result() override {
    return 123;
  }
};

int main() {
  FakeFootballGame game;
  try {
    int score = game.result();
    if (score != 123) {
      throw std::runtime_error("Error: fake score returned");
    }
    std::cout << score << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
