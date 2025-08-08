#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <vector>
#include <string>

// Interface for text processing operations
class ITextProcessor {
public:
    virtual ~ITextProcessor() = default;
    virtual std::vector<std::string> splitIntoWords(const std::string& text) = 0;
    virtual std::string processInput(std::string& currentText, const std::string& input) = 0;
};

// Interface for suggestion engine
class ISuggestionEngine {
public:
    virtual ~ISuggestionEngine() = default;
    virtual void addWord(const std::string& word) = 0;
    virtual std::vector<std::string> getSuggestions(const std::string& prefix) = 0;
};

// Interface for user interaction
class IUserInterface {
public:
    virtual ~IUserInterface() = default;
    virtual void displayWelcome() = 0;
    virtual std::string getUserInput() = 0;
    virtual void displayCurrentText(const std::string& text) = 0;
    virtual void displaySuggestions(const std::vector<std::string>& suggestions, const std::string& prefix) = 0;
    virtual int getSelectedSuggestion(int maxOptions) = 0;
    virtual void displayFinalText(const std::string& text) = 0;
    virtual void displayMessage(const std::string& message) = 0;
};

#endif // INTERFACES_HPP