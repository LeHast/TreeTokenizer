//
// Created by Ali A. Kooshesh on 3/9/22.
//

#include <iostream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(const std::string &inputFile): inputFileName{inputFile} {
    inputStream.open(inputFile, std::ios::in);
}


bool Tokenizer::isCharacter(char c)
{
    return c == ':' || c == ' ';
}

/*  Gets a character from the input file to add the to the token
*  
*   @return the token added.
*/
Token Tokenizer::getToken() {
    if(!inputStream.is_open()) {
        std::cout << "Input stream in Tokenizer::getToken is not open. Terminating...\n";
        exit(4);
    }

    char c;
    inputStream >> c >> std::noskipws;
    // EOF
    if (inputStream.eof()) {
        Token token;
        token.makeEOF();
        inputStream.close();
        return token;
    }

    if (c == '\n') {
        Token token;
        token.makeEndLine();
        return token;
    }

    while(c == '\t')
        inputStream >> c >> std::noskipws;

    while (isspace(c)) {
        inputStream >> c >> std::noskipws;
        if (c == '\n') {
            Token token;
            token.makeEndLine();
            return token;
        }
    }

    if (c == ':') {
        Token token;
        token.makeCharacter(':');
        return token;
    }

    else {
        std::string str;
        while (!isspace(c)) {
            str += c;           
            if (inputStream.peek() == ':' || inputStream.peek() == ' ' || inputStream.peek() == '\n')
                break;
            inputStream >> c >> std::noskipws;
        }
        Token token;
        token.makeString(str);
        return token;
    }

}