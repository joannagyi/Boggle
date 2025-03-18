// File name: BoggleDriver.cpp
// Name: Joanna Yi


#include "Boggle.h"
#include <iostream>

int main() {
  std::cout << "Let's play the Boggle Game." << std::endl;

  Boggle game;

  game.checker();
  game.solve();
  game.printEC();

  std::cout << "This is the non-extra credit program results." << std::endl;

  std::cout << "The computer found the following words: " << std::endl;
  std::cout << "============" << std::endl;

  game.print();

  std::cout << "============" << std::endl;
  std::cout << "The computer found " << game.count() << " words." << std::endl;

  return 0;
}