// File name: TrieNode.h
// Name: Joanna Yi


#ifndef PROJECT9_TRIENODE_H
#define PROJECT9_TRIENODE_H
#include <string>

const int ALPHA = 26;

class TrieNode {
private:
  char letter;
  bool word;

  TrieNode *hold[26];

public:
  // Post: each character node is created
  TrieNode(char c, bool b);

  // Copy Constructor
  // Pre: parameter object, rhs, exists
  // Post: node is created to be a copy of the parameter node
  TrieNode(const TrieNode &rhs);

  // Class Deconstructor
  // pre: the node exists
  // post: the node is destroyed
  ~TrieNode();

  // Assignment operator
  // Assigns a node to another
  // pre: both class objects exist
  // post: this class object gets assigned a copy of the parameter class object
  const TrieNode &operator=(const TrieNode &rhs);

  // insert
  // Pre: insert str starting with the given TrieNode
  // Post: create new TrieNodes as needed and set the boolean flag on the last
  // node to true.
  void insert(const std::string &str);

  // isWord
  // Pre: takes in a string str parameter
  // Post: returns true if str is in the sub-Trie starting at the given
  // TrieNode, else returns false
  bool isWord(const std::string &str) const;

  // isPrefix
  // Pre: takes in a string pre parameter
  // Post: returns true if pre is a prefix of a word in the sub-Trie starting at
  // the given TrieNode, else returns false
  bool isPrefix(const std::string &pre) const;

  // print
  // Pre: takes in a string str parameter
  // Post: Prints all words starting at the given TrieNode. The parameter
  // string str stores the letters of all previous TrieNode objects up to
  // the node currently being processed.
  void print(const std::string &str) const;

  // wordCount
  // Post: returns a count all the nodes in the sub-Trie that end a word.
  size_t wordCount() const;
};

#endif // PROJECT9_TRIENODE_H
