#include "hangman.hpp"

#include <fstream>
#include <iostream>

bool contains_letter(const std::string &word, char guess){
    for(char letter: word){
        if(letter == guess){
            return true;
        }
    }
    return false;
}

std::vector<std::string> import_words(const std::string &filename){
    std::ifstream file{filename};

    if(!file){
        std::cerr << "Could not open file\n";
        return {};
    }

    std::vector<std::string> words{};
    std::string line{};
    while(std::getline(file,line)){
        words.push_back(line);
    }
    return words;
}