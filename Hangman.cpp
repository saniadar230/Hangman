#include "Hangman.h"

Hangman::Hangman(string name) : Game(name) 
{    
}

void Hangman::play()
{
    gameWon = false;

    // Gameplay Rules
    cout << "Welcome to Hangman!" << endl;
    cout << "Here are the rules of the game:" << endl;
    cout << "1. The computer will select a secret word, and you have to guess it." << endl;
    cout << "2. You can guess one letter at a time." << endl;
    cout << "3. For each incorrect guess, a part of the hangman figure will be drawn." << endl;
    cout << "4. You have a limited number of incorrect guesses (6)." << endl;
    cout << "5. If you guess the word before the hangman is fully drawn, you win!" << endl;
    cout << "6. If the hangman is fully drawn before you guess the word, you lose." << endl;
    cout << "7. Letters that have already been guessed cannot be guessed again." << endl;
    cout << "8. Have fun and good luck!" << endl;
    cout << endl;

    // Available word list
    string words[] = {
        "elephant", "giraffe", "kangaroo", "dolphin", "flamingo", "octopus", "penguin", "armadillo",
        "pineapple", "avocado", "blueberry", "cinnamon", "croissant", "pomegranate", "watermelon", "sushi",
        "volcano", "mountain", "glacier", "tornado", "savannah", "rainforest", "desert", "waterfall",
        "umbrella", "telescope", "keyboard", "lighthouse", "binoculars", "microscope", "backpack", "earphones",
        "brilliant", "mysterious", "courageous", "delightful", "adventurous", "vivacious", "spontaneous", "meticulous",
        "jupiter", "satellite", "quarantine", "strategy", "symphony", "mosaic", "labyrinth", "horizon"
    };

    // Calculating the size of words list to select random index
    int size = sizeof(words) / sizeof(words[0]);

    // Selecting random word from the list
    srand(time(0));
    int randomIndex = rand() % size;
    string randomWord = words[randomIndex];



    int IncorrectGuesses = 0;


    string guessedRN = "";

    for (int i = 0; i < randomWord.length(); i++)
    {
        guessedRN += "_";
    }


    do {
        cout << hangman_state[IncorrectGuesses] << endl << endl;

        for (int i = 0; i < randomWord.length(); i++)
        {
            cout << guessedRN[i] << " ";
        }

        cout << endl << endl;

        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        bool isWrong = true;

        for (int i = 0; i < randomWord.length(); i++)
        {
            if (guess == randomWord[i])
            {
                guessedRN[i] = guess;
                isWrong = false;
            }

        }

        if (isWrong == true) {
            IncorrectGuesses++;
        }

        if (IncorrectGuesses == 6)
        {
            cout << "You killed Hangman!" << endl;
            cout << hangman_state[IncorrectGuesses] << endl << endl;
            break;
        }
    } while (guessedRN != randomWord);

    cout << endl;

    if (guessedRN == randomWord)
    {
        cout << "You have won! The correct word was " << randomWord << "." << endl;
        gameWon = true;
    }

}