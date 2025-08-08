#include "../include/trie_node.hpp"

TrieNode::TrieNode() : isEndOfWord(false) {}

bool TrieNode::containsKey(char ch) const {
    return children.find(ch) != children.end();
}

void TrieNode::put(char ch) {
    if (!containsKey(ch)) {
        children[ch] = std::make_unique<TrieNode>();
    }
}

TrieNode* TrieNode::get(char ch) {
    return containsKey(ch) ? children[ch].get() : nullptr;
}

void TrieNode::setEnd() {
    isEndOfWord = true;
}

bool TrieNode::isEnd() const {
    return isEndOfWord;
}

const std::unordered_map<char, std::unique_ptr<TrieNode>>& TrieNode::getChildren() const {
    return children;
}