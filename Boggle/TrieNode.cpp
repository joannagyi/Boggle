// File name: TrieNode.cpp
// Name: Joanna Yi


#include "TrieNode.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// Constructor.
// Pre: takes a character for the node, and a bool indicating whether it
// represents the end of a word. Post: each character node is created
TrieNode::TrieNode(char c, bool b) : letter(c), word(b), hold() {}

// Copy Constructor
// Pre: parameter object, rhs, exists
// Post: node is created to be a copy of the parameter node
TrieNode::TrieNode(const TrieNode &rhs) : letter(rhs.letter), word(rhs.word) {
  for (size_t i = 0; i < ALPHA; ++i) {
    if (rhs.hold[i] != nullptr) {
      hold[i] = new TrieNode(*rhs.hold[i]);
    } else {
      hold[i] = nullptr;
    }
  }
}

// Class Deconstructor
// pre: the node exists
// post: the node is destroyed
TrieNode::~TrieNode() {
  for (size_t i = 0; i < ALPHA; ++i) {
    delete hold[i];
    hold[i] = nullptr;
  }
}

// Assignment operator
// Assigns a node to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const TrieNode &TrieNode::operator=(const TrieNode &rhs) {
  if (this != &rhs) {
    TrieNode tmp(rhs);
    std::swap(this->letter, tmp.letter);
    std::swap(this->word, tmp.word);

    for (size_t i = 0; i < ALPHA; ++i) {
      std::swap(this->hold[i], tmp.hold[i]);
    }
  }

  return *this;
}

// insert
// Pre: insert str starting with the given TrieNode
// Post: create new TrieNodes as needed and set the boolean flag on the last
// node to true.
void TrieNode::insert(const std::string &str) {
  if (str.length() == 0) {
    word = true;
  } else {
    size_t index = str[0] - 'a';
    if (hold[index] == nullptr) {
      hold[index] = new TrieNode(str[0], str.length() == 1);
    }
    hold[index]->insert(str.substr(1));
  }
}

// isWord
// Pre: takes in a string str parameter
// Post: returns true if str is in the sub-Trie starting at the given TrieNode,
// else returns false
bool TrieNode::isWord(const std::string &str) const {
  if (str.length() == 0) {
    return word;
  }

  size_t index = str[0] - 'a';
  if (hold[index] == nullptr) {
    return false;
  }
  return hold[index]->isWord(str.substr(1));
}

// isPrefix
// Pre: takes in a string pre parameter
// Post: returns true if pre is a prefix of a word in the sub-Trie starting at
// the given TrieNode, else returns false
bool TrieNode::isPrefix(const std::string &pre) const {
  if (pre.length() == 0) {
    return true;
  }

  size_t index = pre[0] - 'a';
  if (hold[index] == nullptr) {
    return false;
  }
  return hold[index]->isPrefix(pre.substr(1));
}

// print
// Pre: takes in a string str parameter
// Post: Prints all words starting at the given TrieNode. The parameter
// string str stores the letters of all previous TrieNode objects up to
// the node currently being processed.
void TrieNode::print(const std::string &str) const {
  std::string tempStr = str;
  if (letter != ' ') {
    tempStr = tempStr + letter;
  }

  if (word) {
    std::cout << tempStr << std::endl;
  }

  for (size_t i = 0; i < ALPHA; ++i) {
    if (hold[i] != nullptr) {
      hold[i]->print(tempStr);
    }
  }
}

// wordCount
// Post: returns a count all the nodes in the sub-Trie that end a word.
size_t TrieNode::wordCount() const {
  int counter = 0;

  if (word) {
    ++counter;
  }

  for (size_t i = 0; i < ALPHA; ++i) {
    if (hold[i] != nullptr) {
      counter += hold[i]->wordCount();
    }
  }

  return counter;
}
