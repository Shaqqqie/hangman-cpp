#include <iostream>
#include "hangman.hpp"

int main(){
    std::vector<std::string> words = import_words("data/words.txt");

    std::string word = choose_word(words, random_number(words.size()));
    
    for(auto letter: word){
        std::cout << letter <<" ";
    }
    return 0;
}