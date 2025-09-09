#include "../include/trie_engine.hpp"
#include <algorithm>
#include <cctype>

TrieSuggestionEngine::TrieSuggestionEngine() : root(std::make_unique<TrieNode>()) {}

void TrieSuggestionEngine::dfs(TrieNode* node, std::vector<std::string>& suggestions, std::string& path) {
    if (suggestions.size() >= MAX_SUGGESTIONS) return;
    
    if (node->isEnd()) {
        suggestions.push_back(path);
    }
    
    // Sort children for consistent ordering
    // std::vector<std::pair<char, TrieNode*>> sortedChildren;
    // for (const auto& child : node->getChildren()) {
    //     sortedChildren.emplace_back(child.first, child.second.get());
    // }
    // std::sort(sortedChildren.begin(), sortedChildren.end());
    
    // for (const auto& it : sortedChildren) {
    //     char ch = it.first;
    //     TrieNode* childNode = it.second;
    //     path.push_back(ch);
    //     dfs(childNode, suggestions, path);
    //     path.pop_back();
    // }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        TrieNode* childNode = node->get(ch);
        if (childNode) {
            path.push_back(ch);
            dfs(childNode, suggestions, path);
            path.pop_back();
        }
    }
}

std::string TrieSuggestionEngine::normalizeWord(std::string word) const {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    // Remove non-alphabetic characters
    word.erase(std::remove_if(word.begin(), word.end(), 
               [](char c) { return !std::isalpha(c); }), word.end());
    return word;
}

void TrieSuggestionEngine::addWord(const std::string& word) {
    std::string normalizedWord = normalizeWord(word);
    if (normalizedWord.empty()) return;
    
    TrieNode* current = root.get();
    for (char ch : normalizedWord) {
        current->put(ch);
        current = current->get(ch);
    }
    current->setEnd();
}

std::vector<std::string> TrieSuggestionEngine::getSuggestions(const std::string& prefix) {
    std::string normalizedPrefix = normalizeWord(prefix);
    if (normalizedPrefix.empty()) return {};
    
    TrieNode* current = root.get();
    for (char ch : normalizedPrefix) {
        current = current->get(ch);
        if (!current) return {};
    }
    
    std::vector<std::string> suggestions;
    std::string path = normalizedPrefix;
    dfs(current, suggestions, path);
    return suggestions;
}