#ifndef _HANGMAN_
#define _HANGMAN_


#include <string>
#include <vector>
#include <cstddef>

class Hangman{
private:
    std::vector<std::string> words;
    std::string word;
    std::string hidden_word;
    std::vector<char> guessed_letters;
    int number_of_guesses;

public:
    Hangman()
        :number_of_guesses{6}{
    }
    
    std::vector<std::string> import_words(const std::string &filename);
    std::string choose_word( std::size_t random_index);
    static std::size_t random_number(std::size_t words_size);
    void display_hidden_word();
    bool contains_letter(char guess);
    std::string get_hidden_word();
    void display_guessed_letters();
    void play_game();
};



#endif