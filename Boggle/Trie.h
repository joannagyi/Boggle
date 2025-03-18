// File name: Trie.h
// Name: Joanna Yi


#ifndef PROJECT9_TRIE_H
#define PROJECT9_TRIE_H
#include "TrieNode.h"

class Trie {
private:
  TrieNode myRoot;

public:
  // Default constructor
  Trie();

  // insert
  // Pre: take in the string word
  // Insert the parameter word into the Trie
  void insert(const std::string &word);

  // loadFromFile
  // Pre: takes in a string of the filename
  // Insert all words in the specified file into the Trie. Throws a
  // std::invalid_argument exception if the specified file cannot be
  // opened.
  // Post: took in all words from file into Trie
  void loadFromFile(const std::string &filename);

  // isWord
  // Pre: takes in a string word
  // Post: returns true if word is in the Trie, else returns false
  bool isWord(const std::string &word) const;

  // isPrefix
  // Pre: take in a string pre
  // Post: returns true if pre is a prefix of a word in the Trie, else returns
  // false
  bool isPrefix(const std::string &pre) const;

  // print
  // Post: print all words in the Trie, one per line. Print in alphabetical
  // order
  void print() const;

  // wordCount
  // Post: returns a count all the words in the Trie
  size_t wordCount() const;
};

#endif // PROJECT9_TRIE_H
