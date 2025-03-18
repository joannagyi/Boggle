// File name: Boggle.h
// Name: Joanna Yi


#ifndef PROJECT10_BOGGLE_H
#define PROJECT10_BOGGLE_H
#include "Trie.h"

const std::string WORD_FILE = "ospd.txt";
const std::string BOGGLE_BOARD = "boggle-in.txt";
const int BOARD_SIZE = 4;

class Boggle {
private:
  // The actual boggle board is created
  char board[BOARD_SIZE][BOARD_SIZE];

  // The words that are in the dictionary
  Trie validWord;

  // The words that are valid words from the Boggle Board
  Trie gameWords;

  // The words guessed by the user correctly
  Trie userWords;

  // The words that the computer found but the user didn't
  Trie compWords;

  // visited
  // If the character position is already visited then it flags it so that it
  // doesn't repeat
  bool visited[BOARD_SIZE][BOARD_SIZE];

  // validLoc
  // Pre: takes in the row and column positions
  // Checks that the row and coloumn positions are within the Boggle board
  // parameters Post: returns a boolean if the location is valid or not
  bool validLoc(int row, int col);

  // search
  // Pre: takes in the position that the Boggle is starting its search and the
  // word that is being checked to see if it is a word that is valid Searches
  // for valid words on the Boggle Board
  void search(std::string word, int i, int j);

  // solveWord
  // Pre: takes in the userInput string
  // Determines if the word exists
  // Post: returns true or false if the word exists
  bool solveWord(std::string userInput);

  // searchWord
  // Pre: takes in the userInput string and the location
  // searches if the userInput is a word
  // Post: returns true or false if the word is found
  bool searchWord(std::string userInput, int i, int j);

  //  searchUser
  // Pre:takes in the word that the user guessed and the location of the letter
  // Searches for words through backtracking recursive call
  // Returns a boolean of whether the word was found
  bool checkWord(std::string userInput);

  // checkWord
  // Pre: takes in the user guessed word
  // Checks all of the words within the boggle board
  // Returns a boolean to see if the word is a word on the boggle board
  bool searchUser(std::string userInput, int i, int j);

public:
  // Default Constructor
  // Creates a boggle board with each character that takes in the boggle-in.txt
  Boggle();

  // print
  // Prints the found words from the Boggle Board selections of characters
  // Words that are on the Lexicon opsd.txt and passes the requirements for
  // being a valid word
  void print();

  // count
  // Counts the number of valid words found from the Boggle Board
  int count();

  // solve
  // Goes through every character on the board to search for valid words
  void solve();

  // checker
  // Accepts words that is guessed by the user
  // Goes through the requirements of each word to see if it is valid
  void checker();

  // printEC
  // Prints how many valid words the user found and how many the computer found
  void printEC();
};

#endif // PROJECT10_BOGGLE_H
