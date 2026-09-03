#ifndef _HANGMAN_
#define _HANGMAN_


#include <string>
#include <vector>
#include <cstddef>

std::vector<std::string> import_words(const std::string &filename);
std::string choose_word(std::vector<std::string> &words, int index);
std::size_t random_number(std::size_t words_size);
bool contains_letter(const std::string &word, char guess);


#endif