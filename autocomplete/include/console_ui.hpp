#ifndef CONSOLE_UI_HPP
#define CONSOLE_UI_HPP

#include "interfaces.hpp"
#include <vector>
#include <string>

class ConsoleUserInterface : public IUserInterface {
private:
    void clearInputBuffer();

public:
    void displayWelcome() override;
    std::string getUserInput() override;
    void displayCurrentText(const std::string& text) override;
    void displaySuggestions(const std::vector<std::string>& suggestions, const std::string& prefix) override;
    int getSelectedSuggestion(int maxOptions) override;
    void displayFinalText(const std::string& text) override;
    void displayMessage(const std::string& message) override;
};

#endif // CONSOLE_UI_HPP