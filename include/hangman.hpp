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
    int guesses_remaining{6};

public:
    void import_words(const std::string &filename);
    void choose_word( std::size_t random_index);
    static std::size_t random_number(std::size_t words_size);
    void set_hidden_word();
    void display_hidden_word() const;
    bool contains_letter(char) const;
    std::string get_hidden_word() const;
    void add_guessed_letter(char);
    void display_guessed_letters() const;
    void play_game();
    bool input_validation(std::string);
    void reveal_letter(char);
    void display_hangman() const;
};

#endif