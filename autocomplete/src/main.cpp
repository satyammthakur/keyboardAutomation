#include "../include/application.hpp"
#include "../include/trie_engine.hpp"
#include "../include/text_processor.hpp"
#include "../include/console_ui.hpp"
#include <iostream>
#include <memory>
#include <exception>

int main() {
    try {
        // Dependency injection - easy to swap implementations
        auto textProcessor = std::make_unique<TextProcessor>();
        auto suggestionEngine = std::make_unique<TrieSuggestionEngine>();
        auto userInterface = std::make_unique<ConsoleUserInterface>();
        
        TextPredictionApp app(std::move(textProcessor), 
                            std::move(suggestionEngine), 
                            std::move(userInterface));
        
        app.run();
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}