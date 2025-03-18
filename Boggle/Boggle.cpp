// File name: Boggle.cpp
// Name: Joanna Yi


#include "Boggle.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

// Default Constructor
Boggle::Boggle() {
  // Builds a lexicon of acceptable words from "ospd.txt"
  validWord.loadFromFile(WORD_FILE);

  for (int j = 0; j < BOARD_SIZE; ++j) {
    for (int p = 0; p < BOARD_SIZE; ++p) {
      visited[j][p] = false;
    }
  }

  // Reads in a Boggle Board Configuration
  std::ifstream infile;

  infile.open(BOGGLE_BOARD);
  if (infile.fail()) {
    throw std::invalid_argument("Error opening input data file");
  }

  // Reading the characters into the board
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (!(infile >> board[i][j])) {
        throw std::invalid_argument("Error taking in the character.");
      }
      std::cout << board[i][j];
      if (j == 3) {
        std::cout << std::endl;
      }
    }
  }

  infile.close();
}

// solve
// Goes through every character on the board to search for valid words
void Boggle::solve() {

  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      search("", i, j);
    }
  }
}

// search
// Pre: takes in the position that the Boggle is starting its search and the
// word that is being checked to see if it is a word that is valid Searches for
// valid words on the Boggle Board
void Boggle::search(std::string word, int i, int j) {

  // If the location is not a valid location then it should not go through the
  // steps below
  if (!(validLoc(i, j))) {
    return;
  }

  // If the coordinate has already been visited than it should not go through
  // the steps below
  if (visited[i][j]) {
    return;
  }

  // Add the word with the new character
  std::string newWord = word + board[i][j];
  if (newWord.length() >= 4 && validWord.isWord(newWord)) {
    if (!(userWords.isWord(newWord)) && !(gameWords.isWord(newWord))) {
      compWords.insert(newWord);
    }

    if (!gameWords.isWord(newWord)) {
      gameWords.insert(newWord);
    }
  }

  if (validWord.isPrefix(newWord)) {
    visited[i][j] = true;
    // Goes through all 8 adjacent positions of the letter
    for (int k = -1; k <= 1; ++k) {
      int row;
      row = i + k;
      for (int l = -1; l <= 1; ++l) {
        int col;
        col = j + l;
        search(newWord, row, col);
      }
    }
    visited[i][j] = false;
  }
}

// valid Loc
// Pre: takes in the row and column positions
// Checks that the row and coloumn positions are within the Boggle board
// parameters Post: returns a boolean if the location is valid or not
bool Boggle::validLoc(int row, int col) {
  if (row >= 0 && row <= 3) {
    if (col >= 0 && col <= 3) {
      return true;
    }
  }
  return false;
}

// print
// Prints the found words from the Boggle Board selections of characters
// Words that are on the Lexicon opsd.txt and passes the requirements for being
// a valid word
void Boggle::print() { gameWords.print(); }

// count
// Counts the number of valid words found from the Boggle Board
int Boggle::count() { return gameWords.wordCount(); }

// checker
// Accepts words that is guessed by the user
// Goes through the requirements of each word to see if it is valid
void Boggle::checker() {
  std::string userInput;
  while (true) {
    std::cout << "Enter the word:";
    std::cin >> userInput;
    if (userInput == "Q" || userInput == "q") {
      break;
    }

    if (userInput.length() < 4) {
      std::cout << "Not a valid word. The length should be 4 or greater."
                << std::endl;
      continue;
    }

    if (userWords.isWord(userInput)) {
      std::cout << "You already found this word." << std::endl;
      continue;
    }

    if (!(validWord.isWord(userInput))) {
      std::cout << "This word is not a legal word." << std::endl;
      continue;
    }

    if (!(solveWord(userInput))) {
      std::cout << "This word is not a valid word on the Boggle Board."
                << std::endl;
      continue;
    }

    if (checkWord(userInput)) {
      std::cout << "You found a word!" << std::endl;
      userWords.insert(userInput);
    }
  }
}

// printEC
// Prints how many valid words the user found and how many the computer found
void Boggle::printEC() {
  std::cout << "You have found these words." << std::endl;
  userWords.print();
  std::cout << "You have found " << userWords.wordCount() << " words."
            << std::endl;

  std::cout << "The computer found the rest of the words." << std::endl;
  compWords.print();
  std::cout << "The computer has found " << compWords.wordCount() << " words."
            << std::endl;
  std::cout << std::endl;
}

// solveWord
// Pre:takes in the userInput string Determines if the word exists Post: returns
// true or false if the word exists
bool Boggle::solveWord(std::string userInput) {

  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (searchWord(userInput, i, j)) {
        return true;
      }
    }
  }
  return false;
}

// searchWord
// Pre:takes in the userInput string and the location searches if the userInput is a
// word Post: returns true or false if the word is found
bool Boggle::searchWord(std::string userInput, int i, int j) {

  if (userInput.length() == 0) {
    return true;
  }
  // If the location is not a valid location then it should not go through the
  // steps below
  if (!(validLoc(i, j))) {
    return false;
  }

  // If the coordinate has already been visited than it should not go through
  // the steps below
  if (visited[i][j]) {
    return false;
  }

  if (userInput[0] != board[i][j]) {
    return false;
  }

  visited[i][j] = true;
  // Goes through all 8 adjacent positions of the letter
  for (int k = -1; k <= 1; ++k) {
    int row;
    row = i + k;
    for (int l = -1; l <= 1; ++l) {
      int col;
      col = j + l;
      if (searchWord(userInput.substr(1, userInput.size() - 1), row, col)) {
        visited[i][j] = false;
        return true;
      }
    }
  }
  visited[i][j] = false;
  return false;
}

// searchUser
// Pre:takes in the word that the user guessed and the location of the letter
// Searches for words through backtracking recursive call
// Returns a boolean of whether the word was found
bool Boggle::searchUser(std::string userInput, int i, int j) {
  if (!(validLoc(i, j))) {
    return false;
  }
  if (userInput.size() == 0) {
    return true;
  }
  if (visited[i][j]) {
    return false;
  }
  visited[i][j] = true;
  for (int k = -1; k <= 1; ++k) {
    int row;
    row = i + k;
    for (int l = -1; l <= 1; ++l) {
      int col;
      col = j + l;
      if (searchUser(userInput.substr(1, userInput.length() - 1), row, col)) {
        visited[i][j] = false;
        return true;
      }
    }
  }
  return false;
}

// checkWord
// Pre: takes in the user guessed word
// Checks all of the words within the boggle board
// Returns a boolean to see if the word is a word on the boggle board
bool Boggle::checkWord(std::string userInput) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (searchUser(userInput, i, j)) {
        return true;
      }
    }
  }
  return false;
}
