#include <iostream>
#include "hangman.hpp"

int main(){
    std::string word{"apple"};

    if(contains_letter(word, 'a')){
        std::cout << "Correct guess!\n";
    }
    return 0;
}