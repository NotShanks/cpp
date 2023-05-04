//Quiz #3 Lesson 12.8
#include <algorithm>
#include <array>
#include <random>
#include <iostream>
#include <vector>
#include <cmath>

using Vector = std::vector<int>;

int randomMultiply(std::mt19937& mt)
{
    std::uniform_int_distribution rd(2, 4);
    return rd(mt);
}

// Use push_back to create a vector.
Vector addToVector(const std::array<int, 10>& squared, int start, int getRandom)
{
    Vector myVector{};
    // Loop through user's starting squared number.
    // Push_back adds the new squared to the vector.
    for (int i{ start - 1 }; i < 10; ++i)
    {
        myVector.push_back(squared[i] * getRandom);
    }

    return myVector;
}


int main()
{
    std::array squared{ 1, 4, 9, 16, 25, 36, 49, 64, 81, 100 };
    int start{};
    int times{};
    int correct{0};
    std::mt19937 mt{ std::random_device{}() };
    int getRandom{ randomMultiply(mt) };

    std::cout << "Start where? ";
    std::cin >> start;

    std::cout << "How many? ";
    std::cin >> times;

    std::cout << "I generated " << times << " numbers." <<
        " Do you know what each number is after multiplying it by " << getRandom << " ?\n";

    // Call addToVector function and the return into myVector.
    Vector myVector{ addToVector(squared, start, getRandom) };

    Vector correctGuesses{};
    bool alreadyGuessed{ false };

    do
    {
        int guess{};
        std::cin >> guess;

        // Looks for the guess in the myVector.
        auto found{ std::find(myVector.begin(), myVector.end(), guess) };

        // Gets the closest number from user's guess.
        auto closest{ std::min_element(myVector.begin(), myVector.end(),
            [guess](const auto& a, const auto& b)
            {
                return std::abs(a - guess < b - guess);
            }
        ) };

        // if guess was found in vector and correct is the same
        if (found != myVector.end())
        {
            // if amount of times is 1 left and assuming user is right next time.
            if (times == 1)
            {
                std::cout << "Nice! You found all numbers, good job!\n";
                break;
            }
            std::cout << "Nice! " << --times << " numbers left\n";
            // Add guess to correctGuesses vector.
            correctGuesses.push_back(guess);
            myVector.erase(found);
        }
        else
        {
            alreadyGuessed = false;
            // Loops through correctGuess Vector.
            for (int i : correctGuesses)
            {
                if (guess == i)
                {
                    std::cout << i << " was already guessed.\n";
                    alreadyGuessed = true;
                    break;
                }
            }

            if (!alreadyGuessed)
            {   
                // If guess is <= 4.
                if (std::abs(*closest - guess) <= 4)
                {
                    std::cout << guess << " is wrong! ";
                    std::cout << "Try " << *closest << " next time.\n";
                    break;
                }
                std::cout << guess << " is wrong\n";
            }
        }

    } while (times > 0);

    return 0;
}
