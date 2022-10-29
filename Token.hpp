
#ifndef EXPRESSIONEVALUATOR_LAB04_TOKEN_HPP
#define EXPRESSIONEVALUATOR_LAB04_TOKEN_HPP

#include <string>

class Token {
public:
    Token() : _isString{ false }, _isCharacter{ false }, _isOEF{ false }, _isEndLine{false}
    , _isSpace{false} {};

    void print();

    // String
    void makeString(std::string str) {
        _keyString = str;
        _isString = true;
    }
    bool isString() { return _isString; }
    std::string getString() { return _keyString; }
    //-----------------------------------
    
    // eof
    bool isEOF() { return _isOEF; }
    void makeEOF() { _isOEF = true; }
    //-----------------------------------

    bool isEndLine() { return _isEndLine; }
    void makeEndLine() { _isEndLine = true; }

    bool isSpace() { return _isSpace; }
    void makeSpace() { _isSpace = true; }

    // Character
    void makeCharacter (char c){
        _character = c;
        _isCharacter = true;
    }
    bool isCharater() { return _isCharacter; }
    char getCharacter() { return _character; }

private:
    std::string _keyString;
    char _character;
    bool _isCharacter , _isOEF, _isString, _isEndLine, _isSpace;
};


#endif //EXPRESSIONEVALUATOR_LAB04_TOKEN_HPP
