#include "hangman.hpp"

#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>

std::vector<std::string> Hangman::import_words(const std::string &filename){
    std::ifstream file{filename};

    if(!file){
        std::cerr << "Could not open file\n";
        return {};
    }

    std::string line{};
    while(std::getline(file, line)){
        words.push_back(line);
    }
    return words;
}

std::string Hangman::choose_word( std::size_t random_index){
    return word = words.at(random_index);
}

std::size_t Hangman::random_number(std::size_t words_size){
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

bool Hangman::contains_letter(char guess){
    for(char letter: word){
        if(letter == guess){
            return true;
        }
    }
    return false;
}

void Hangman::display_hidden_word(){
    std::cout << "Hidden word: ";
    for(auto letter: hidden_word){
        std::cout << letter << " ";
    }
    std::cout << "\n";
}

void Hangman::set_hidden_word(){
    for(auto letter: word){
        hidden_word.append("_");
    }
}
std::string Hangman::get_hidden_word(){
    return hidden_word;
}

void Hangman::display_guessed_letters(){
    for(auto letter: guessed_letters){
        std::cout << letter << " ";
    }
    std::cout << "\n";
}

char Hangman::guess(){
    char guess{};
    std::cout << "Letter: ";
    std::cin >> guess;
    return guess;
}

void Hangman::play_game(){
    import_words("data/words.txt");
    choose_word(random_number(words.size()));
    set_hidden_word();

    while(true){
        
        display_hidden_word();
        std::cout << "Guessed letters: ";
        display_guessed_letters();
        std::cout << "Number of guesses: " << number_of_guesses << "\n";

        auto letter = guess();
        if (contains_letter(letter)) {
            reveal_letter(letter);
        }
        else{
            number_of_guesses--;
        }
    }
}

void Hangman::reveal_letter(char letter) { 
    unsigned int index{};
    for (std::size_t i{}; i < word.size(); ++i){
        if(letter == word[i]){
            index = i;
        }
    }
    hidden_word[index] = letter;
}