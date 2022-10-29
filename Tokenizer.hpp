
#ifndef EXPRESSIONEVALUATOR_LAB04_TOKENIZER_HPP
#define EXPRESSIONEVALUATOR_LAB04_TOKENIZER_HPP
#include <string>
#include <fstream>

#include "Token.hpp"

class Tokenizer {
public:
    explicit Tokenizer(const std::string &inputFile);

    Token getToken();

private:
    std::string inputFileName;
    std::fstream inputStream;

    static bool isCharacter(char c);
};


#endif //EXPRESSIONEVALUATOR_LAB04_TOKENIZER_HPP
