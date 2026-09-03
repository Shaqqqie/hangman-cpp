#include <iostream>
#include "hangman.hpp"

int main(){
    auto words = import_words("data/words.txt");

    auto word = choose_word(words, random_number(words.size()));
    
    display_hidden_word(word);
    
    return 0;
}