// File name: Trie.cpp
// Name: Joanna Yi


#include "Trie.h"
#include <fstream>
#include <iostream>

// Default constructor
Trie::Trie() : myRoot(' ', false) {}

// insert
// Pre: take in the string word
// Insert the parameter word into the Trie
void Trie::insert(const std::string &word) { myRoot.insert(word); }

// loadFromFile
// Pre: takes in a string of the filename
// Insert all words in the specified file into the Trie. Throws a
// std::invalid_argument exception if the specified file cannot be
// opened.
// Post: took in all words from file into Trie
void Trie::loadFromFile(const std::string &filename) {
  std::ifstream infile;

  infile.open(filename.c_str());
  if (infile.fail()) {
    throw std::invalid_argument("Error opening input data file");
  }

  std::string str;
  while (infile >> str) {
    myRoot.insert(str);
  }

  infile.close();
}

// isWord
// Pre: takes in a string word
// Post: returns true if word is in the Trie, else returns false
bool Trie::isWord(const std::string &word) const { return myRoot.isWord(word); }

// isPrefix
// Pre: take in a string pre
// Post: returns true if pre is a prefix of a word in the Trie, else returns
// false
bool Trie::isPrefix(const std::string &pre) const {
  return myRoot.isPrefix(pre);
}

// print
// Post: print all words in the Trie, one per line. Print in alphabetical order
void Trie::print() const { myRoot.print(""); }

// wordCount
// Post: returns a count all the words in the Trie
size_t Trie::wordCount() const { return myRoot.wordCount(); }
