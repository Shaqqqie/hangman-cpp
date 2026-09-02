#pragma once

#include <string>
#include <vector>

bool contains_letter(const std::string &word, char guess);
std::vector<std::string> import_words(const std::string &filename);