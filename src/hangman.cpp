#include "hangman.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>

void Hangman::import_words(const std::string &filename)
{
    std::ifstream file{filename};

    if (!file)
    {
        std::cerr << "Could not open file\n";
    }

    std::string line{};
    while (std::getline(file, line))
    {
        words.push_back(line);
    }
}

void Hangman::choose_word(std::size_t random_index)
{
    word = words.at(random_index);
}

std::size_t Hangman::random_number(std::size_t words_size)
{
    if (words_size == 0)
    {
        throw std::invalid_argument{"words_size cannot be 0"};
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<std::size_t> distribution(
        0, words_size - 1);

    return distribution(generator);
}

bool Hangman::contains_letter(char guess) const
{
    for (char letter : word)
    {
        if (letter == guess)
        {
            return true;
        }
    }
    return false;
}

void Hangman::display_hidden_word() const
{
    std::cout << "\nHidden word: ";
    for (char letter : hidden_word)
    {
        std::cout << letter << " ";
    }
    std::cout << "\n";
}

void Hangman::set_hidden_word()
{
    hidden_word.assign(word.size(), '_');
}

std::string Hangman::get_hidden_word() const
{
    return hidden_word;
}

void Hangman::display_guessed_letters() const
{
    std::cout << "Guessed letters: ";
    for (char letter : guessed_letters)
    {
        std::cout << letter << " ";
    }
    std::cout << "\n";
}

bool Hangman::input_validation(std::string guess)
{
    if (guess.empty())
    {
        std::cout << "\nNo input.\n";
        return false;
    }
    else
    {
        for (char letter : guess)
        {
            if (!std::isalpha(static_cast<unsigned char>(letter)))
            {
                std::cout << "\nInvalid input.\n";
                return false;
            }
        }

        for (char &letter : guess)
        {
            letter = static_cast<char>(
                std::tolower(static_cast<unsigned char>(letter))
            );
        }
    }
    return true;
}

void Hangman::play_game()
{
    import_words("data/words.txt");
    choose_word(random_number(words.size()));
    set_hidden_word();

    while (true)
    {
        display_hangman();
        display_hidden_word();
        display_guessed_letters();
        std::cout << "Guesses remaining: " << guesses_remaining << "\n";

        std::string guess{};
        std::cout << "Guess: ";
        std::cin >> guess;

        if (input_validation(guess))
        {
            if (guess.size() > 1 )
            {
                if(guess == word){
                    std::cout << "You won!\n";
                    std::cout << "The word was " << word << "\n";
                    break;
                }
                else{
                    std::cout << guess << " was not the word...\n";
                    guesses_remaining--;
                }
            }
            else if (guess.size() == 1)
            {
                char letter{guess[0]};
                add_guessed_letter(letter);
                if (contains_letter(letter))
                {
                    reveal_letter(letter);
                }
                else
                {
                    guesses_remaining--;
                }
            }
        }
        
        if (guesses_remaining == 0)
        {
            display_hangman();
            std::cout << "\n";
            std::cout << "Game over!\n";
            std::cout << "The word was: " << word << std::endl;
            break;
        }
        else if (hidden_word == word)
        {
            std::cout << "Game Won!\n";
            break;
        }
    }
}

void Hangman::reveal_letter(char letter)
{
    for (std::size_t i{}; i < word.size(); ++i)
    {
        if (letter == word[i])
        {
            hidden_word[i] = letter;
        }
    }
}

void Hangman::add_guessed_letter(char letter)
{
    guessed_letters.push_back(letter);
}

void Hangman::display_hangman() const
{
    int wrong_guesses{6 - guesses_remaining};
    
    if(wrong_guesses == 0)
    {
        std::cout << "\n";
        std::cout << " ----------" << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |          " << "\n";
        std::cout << " |          " << "\n";
        std::cout << " |          " << "\n";
        std::cout << "/__\\       " << "\n";
    }
    else if(wrong_guesses == 1)
    {
        std::cout << "\n";
        std::cout << " ---------- " << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |        o " << "\n";
        std::cout << " |          " << "\n";
        std::cout << " |          " << "\n";
        std::cout << "/__\\       " << "\n";
    }
    else if(wrong_guesses == 2)
    {
        std::cout << "\n";
        std::cout << " ----------" << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |        o  " << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |          " << "\n";
        std::cout << "/__\\       " << "\n";
    }
    else if(wrong_guesses == 3)
    {
        std::cout << "\n";
        std::cout << " ----------" << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |        o  " << "\n";
        std::cout << " |        |  " << "\n";
        std::cout << " |         \\ " << "\n";
        std::cout << "/__\\       " << "\n";
    }
    else if(wrong_guesses == 4)
    {
        std::cout << "\n";
        std::cout << " ----------" << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |        o  " << "\n";
        std::cout << " |        |  " << "\n";
        std::cout << " |       / \\ " << "\n";
        std::cout << "/__\\       " << "\n";
    }
    else if(wrong_guesses == 5)
    {
        std::cout << "\n";
        std::cout << " ----------" << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |      \\ o  " << "\n";
        std::cout << " |        |  " << "\n";
        std::cout << " |       / \\ " << "\n";
        std::cout << "/__\\       " << "\n";
    }
    else if(wrong_guesses == 6)
    {
        std::cout << "\n";
        std::cout << " ----------" << "\n";
        std::cout << " |        | " << "\n";
        std::cout << " |      \\ o /  " << "\n";
        std::cout << " |        |  " << "\n";
        std::cout << " |       / \\ " << "\n";
        std::cout << "/__\\       " << "\n";
    }
}