
#include <iostream>
#include <iomanip>
#include "Token.hpp"

/* Print the character into the token.
*/
void Token::print() {
    // Character
    if (isCharater()) {
        std::cout << getCharacter() << std::endl;
    }
    // String
    else if (isString()) {
        std::cout << getString() << std::endl;
    }
    else if (isSpace()) {
        std::cout << "-" << std::endl;
    }
    else if (isEndLine()) {
        std::cout << "endline" << std::endl;
    }
    else {
        std::cout << "Unknown token." << std::endl;
    }

}