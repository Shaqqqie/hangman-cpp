#include "hangman.hpp"

#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>

std::vector<std::string> import_words(const std::string &filename){
    std::ifstream file{filename};

    if(!file){
        std::cerr << "Could not open file\n";
        return {};
    }

    std::vector<std::string> words{};
    std::string line{};
    while(std::getline(file, line)){
        words.push_back(line);
    }
    return words;
}

std::string choose_word(std::vector<std::string> &words, std::size_t random_index){
    std::string word = words.at(random_index);
    
    return word;
}

std::size_t random_number(std::size_t words_size){
    if(words_size == 0){
        throw std::invalid_argument{"words_size cannot be 0"};
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<std::size_t> distribution(
        0, words_size - 1
    );

    return distribution(generator);
}

bool contains_letter(const std::string &word, char guess){
    for(char letter: word){
        if(letter == guess){
            return true;
        }
    }
    return false;
}

void display_hidden_word(const std::string word){
    for(auto letter: word){
        std::cout << "_" << " ";
    }
}
