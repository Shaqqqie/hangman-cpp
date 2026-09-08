#include <catch2/catch_test_macros.hpp>

#include "hangman.hpp"

TEST_CASE("Hangman imports words from a file")
{
    Hangman game;

    auto words = game.import_words("data/words_test.txt");

    REQUIRE_FALSE(words.empty());
    REQUIRE(words.at(0) == "apple");
    REQUIRE(words.at(1) == "banana");
}

TEST_CASE("random_number returns an index inside the valid range")
{
    
    constexpr int number_of_trials{100};
    constexpr std::size_t words_size{10};

    for (int i{0}; i < 100; ++i)
    {
        const auto result = Hangman::random_number(words_size);

        REQUIRE(result < words_size);
    }
}

TEST_CASE("choose_word returns the word at the given index")
{
    Hangman game;

    std::vector<std::string> words{
        "apple",
        "banana",
        "orange"
    };

    REQUIRE(game.choose_word(0) == "apple");
    REQUIRE(game.choose_word(1) == "banana");
    REQUIRE(game.choose_word(2) == "orange");
}

TEST_CASE("contains_letter detects letters in the chosen word")
{
    Hangman game;

    std::vector<std::string> words{
        "apple"
    };

    game.choose_word( 0);

    REQUIRE(game.contains_letter('a'));
    REQUIRE(game.contains_letter('p'));
    REQUIRE_FALSE(game.contains_letter('z'));
}

TEST_CASE("hidden_word displays '_' for every letter in chosen word")
{
    Hangman game;

    std::vector<std::string> words{
        "apple"
    };

    game.choose_word(0);
    game.display_hidden_word();

    REQUIRE(game.get_hidden_word() == "_____");
}

