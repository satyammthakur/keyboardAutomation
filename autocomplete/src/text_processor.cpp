#include "../include/text_processor.hpp"
#include <sstream>

std::vector<std::string> TextProcessor::splitIntoWords(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    std::vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

std::string TextProcessor::processInput(std::string& currentText, const std::string& input) {
    currentText += input;
    return currentText;
}