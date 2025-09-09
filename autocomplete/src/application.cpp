#include "../include/application.hpp"
#include <utility>

// Static member definitions
const std::string TextPredictionApp::SUGGESTION_COMMAND = "#";
const std::string TextPredictionApp::QUIT_COMMAND = "!";
const std::string TextPredictionApp::SPACE_INPUT = " ";

TextPredictionApp::TextPredictionApp(std::unique_ptr<ITextProcessor> processor,
                                   std::unique_ptr<ISuggestionEngine> engine,
                                   std::unique_ptr<IUserInterface> ui)
    : textProcessor(std::move(processor))
    , suggestionEngine(std::move(engine))
    , userInterface(std::move(ui))
    , currentText("") {}

void TextPredictionApp::handleSpaceInput() {
    auto words = textProcessor->splitIntoWords(currentText);
    if (!words.empty() && !words.back().empty()) {
        suggestionEngine->addWord(words.back());
    }
}

void TextPredictionApp::handleSuggestionRequest() {
    auto words = textProcessor->splitIntoWords(currentText);
    if (words.empty()) {
        userInterface->displayMessage("No text to suggest for.");
        return;
    }
    
    std::string lastWord = words.back();
    auto suggestions = suggestionEngine->getSuggestions(lastWord);
    
    if (suggestions.empty()) {
        userInterface->displayMessage("No suggestions available for '" + lastWord + "'.");
        return;
    }
    
    userInterface->displaySuggestions(suggestions, lastWord);
    int choice = userInterface->getSelectedSuggestion(suggestions.size());
    
    if (choice < 1 || choice > static_cast<int>(suggestions.size())) {
        userInterface->displayMessage("Invalid selection.");
        return;
    }
    
    selectSuggestion(suggestions[choice - 1]);
}

void TextPredictionApp::selectSuggestion(const std::string& suggestion) {
    auto words = textProcessor->splitIntoWords(currentText);
    if (!words.empty()) {
        words.back() = suggestion;
        
        // Rebuild text
        currentText.clear();
        for (size_t i = 0; i < words.size(); ++i) {
            currentText += words[i];
            if (i < words.size() - 1) currentText += " ";
        }
        currentText += " ";
        
        suggestionEngine->addWord(suggestion);
        userInterface->displayMessage("Selected: " + suggestion);
        userInterface->displayCurrentText(currentText);
    }
}

void TextPredictionApp::handleRegularInput(const std::string& input) {
    textProcessor->processInput(currentText, input);
    
    if (input == SPACE_INPUT) {
        handleSpaceInput();
    }
    
    userInterface->displayCurrentText(currentText);
    // userInterface->displayCurrentText(currentText);
}

void TextPredictionApp::run() {
    userInterface->displayWelcome();
    
    while (true) {
        std::string input = userInterface->getUserInput();
        
        if (input == QUIT_COMMAND) {
            break;
        }
        
        if (input == SUGGESTION_COMMAND) {
            handleSuggestionRequest();
        } else {
            handleRegularInput(input);
        }
    }
    
    userInterface->displayFinalText(currentText);
}