#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <unordered_map>
#include <memory>

class TrieNode {
private:
    bool isEndOfWord;
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;

public:
    TrieNode();
    
    bool containsKey(char ch) const;
    void put(char ch);
    TrieNode* get(char ch);
    
    void setEnd();
    bool isEnd() const;
    
    const std::unordered_map<char, std::unique_ptr<TrieNode>>& getChildren() const;
};

#endif // TRIE_NODE_HPP