#include "../include/console_ui.hpp"
#include <iostream>
#include <limits>

void ConsoleUserInterface::clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleUserInterface::displayWelcome() {
    std::cout << "=== Smart Text Prediction System ===" << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "  - Type normally to input text" << std::endl;
    std::cout << "  - Type '#' to get suggestions" << std::endl;
    std::cout << "  - Type '!' to quit" << std::endl;
    std::cout << "=====================================" << std::endl;
}

std::string ConsoleUserInterface::getUserInput() {
    std::string input;
    std::cout << "Enter command/text: ";
    std::getline(std::cin, input);
    return input;
}

void ConsoleUserInterface::displayCurrentText(const std::string& text) {
    std::cout << "Current text: \"" << text << "\"" << std::endl;
}

void ConsoleUserInterface::displaySuggestions(const std::vector<std::string>& suggestions, const std::string& prefix) {
    std::cout << "\nSuggestions for '" << prefix << "':" << std::endl;
    for (size_t i = 0; i < suggestions.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << suggestions[i] << std::endl;
    }
}

int ConsoleUserInterface::getSelectedSuggestion(int maxOptions) {
    int choice;
    std::cout << "Select suggestion (1-" << maxOptions << "): ";
    std::cin >> choice;
    clearInputBuffer();
    return choice; 
}

void ConsoleUserInterface::displayFinalText(const std::string& text) {
    std::cout << "\nFinal text: \"" << text << "\"" << std::endl;
}

void ConsoleUserInterface::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}