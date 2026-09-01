#include <catch2/catch_test_macros.hpp>

#include "hangman.hpp"

TEST_CASE("Letter exists in word")
{
    REQUIRE(contains_letter("apple", 'a'));
}

TEST_CASE("Letter does not exist in word")
{
    REQUIRE(contains_letter("apple", 'z'));
}