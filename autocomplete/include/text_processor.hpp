#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include "interfaces.hpp"
#include <vector>
#include <string>

class TextProcessor : public ITextProcessor {
public:
    std::vector<std::string> splitIntoWords(const std::string& text) override;
    std::string processInput(std::string& currentText, const std::string& input) override;
};

#endif // TEXT_PROCESSOR_HPP