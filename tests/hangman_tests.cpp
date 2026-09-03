#include <catch2/catch_test_macros.hpp>

#include "hangman.hpp"

TEST_CASE("random_number returns valid index")
{
    const std::size_t words_size{10};

    const std::size_t index{
        random_number(words_size)
    };

    

     REQUIRE(index < words_size);
}
