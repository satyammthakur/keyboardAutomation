#ifndef TRIE_ENGINE_HPP
#define TRIE_ENGINE_HPP

#include "interfaces.hpp"
#include "trie_node.hpp"
#include <memory>
#include <vector>
#include <string>

class TrieSuggestionEngine : public ISuggestionEngine {
private:
    std::unique_ptr<TrieNode> root;
    static const int MAX_SUGGESTIONS = 3;
    
    void dfs(TrieNode* node, std::vector<std::string>& suggestions, std::string& path);
    std::string normalizeWord(std::string word) const;

public:
    TrieSuggestionEngine();
    
    void addWord(const std::string& word) override;
    std::vector<std::string> getSuggestions(const std::string& prefix) override;
};

#endif // TRIE_ENGINE_HPP