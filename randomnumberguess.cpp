#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int guess;

    std::cout << "Guess the number (between 1 and 100): ";

    while (true) {
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(1000, '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number: ";
            continue;
        }

        if (guess < secretNumber) {
            std::cout << "Too low. Try again: ";
        } else if (guess > secretNumber) {
            std::cout << "Too high. Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << std::endl;
            break;
        }
    }

    return 0;
}
