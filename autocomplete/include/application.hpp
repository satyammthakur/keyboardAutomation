#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "interfaces.hpp"
#include <memory>
#include <string>

class TextPredictionApp {
private:
    std::unique_ptr<ITextProcessor> textProcessor;
    std::unique_ptr<ISuggestionEngine> suggestionEngine;
    std::unique_ptr<IUserInterface> userInterface;
    std::string currentText;
    
    static const std::string SUGGESTION_COMMAND;
    static const std::string QUIT_COMMAND;
    static const std::string SPACE_INPUT;
    
    void handleSpaceInput();
    void handleSuggestionRequest();
    void selectSuggestion(const std::string& suggestion);
    void handleRegularInput(const std::string& input);

public:
    // Dependency Injection through constructor
    TextPredictionApp(std::unique_ptr<ITextProcessor> processor,
                     std::unique_ptr<ISuggestionEngine> engine,
                     std::unique_ptr<IUserInterface> ui);
    
    void run();
};

#endif // APPLICATION_HPP