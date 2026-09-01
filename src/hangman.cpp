#include "hangman.hpp"

bool contains_letter(const std::string &word, char guess){
    for(char letter: word){
        if(letter == guess){
            return true;
        }
    }
    return false;
}