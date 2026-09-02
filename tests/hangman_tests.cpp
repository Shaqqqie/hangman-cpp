#include <catch2/catch_test_macros.hpp>

#include "hangman.hpp"

TEST_CASE("import_words reads the expected words")
{
    std::vector<std::string> expected{
        "elephant",
        "keyboard",
        "mountain",
        "bicycle",
        "pancake",
        "dolphin",
        "castle",
        "thunder",
        "pumpkin",
        "diamond"
    };

     REQUIRE(import_words("data/words.txt") == expected);
}
