#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void firstMessage() {
    printf("Welcome to the Rock Paper and Scissors game!\n");
    printf("To choose one of the three, enter \"R\", \"P\" or \"S\"\n");
    printf("for Rock Paper and Scissors respectively.\n");
    printf("To quit the game just input \"Q\".\n");
    printf("Let the game begin:\n");
}

char makeGuess() {
    int randomGuessAsInt = (rand() % 3) + 1;
    
    if (randomGuessAsInt == 1)
    {
        return *"R";
    }
    
    if (randomGuessAsInt == 2)
    {
        return *"P";
    }

    if (randomGuessAsInt == 3)
    {
        return *"S";
    }
    
    return *"R";
}

void gameLoop(int currentRound, int playerWon, int compWon) {
    char guess;
    scanf("%c", &guess);
    
    if (guess == *"Q")
    {
        printf("Current scores: Player --> %d --- Computer --> %d\n", playerWon, compWon);
        if (playerWon > compWon)
        {
            printf("You won! Congratulations!\n");
            return;
        }
        
        if (playerWon == compWon)
        {
            printf("It's a draw!");
            return;
        }
        
        printf("You lost! Better luck next time!\n");
        return;
    }
    

    char compGuess = makeGuess();   

    if (guess == *"R" && compGuess == *"R")
    {
        printf("Both played Rock!\n");
        currentRound += 1;
    }
    
    if (guess == *"P" && compGuess == *"P")
    {
        printf("Both played Paper!\n");
        currentRound += 1;
    }

    if (guess == *"S" && compGuess == *"S")
    {
        printf("Both played Scissors!\n");
        currentRound += 1;
    }

    if (guess == *"R" && compGuess == *"P")
    {
        printf("You played Rock. Computer played Paper.\n");
        currentRound += 1;
        compWon += 1;
    }

    if (guess == *"R" && compGuess == *"S")
    {
        printf("You played Rock. Computer played Scissors.\n");
        currentRound += 1;
        playerWon += 1;
    }
    
    if (guess == *"P" && compGuess == *"R")
    {
        printf("You played Paper. Computer played Rock.\n");
        currentRound += 1;
        playerWon += 1;
    }

    if (guess == *"P" && compGuess == *"S")
    {
        printf("You played Paper. Computer played Scissors.\n");
        currentRound += 1;
        compWon += 1;
    }

    if (guess == *"S" && compGuess == *"R")
    {
        printf("You played Scissors. Computer played Rock.\n");
        currentRound += 1;
        compWon += 1;
    }

    if (guess == *"S" && compGuess == *"P")
    {
        printf("You played Scissors. Computer played Paper.\n");
        currentRound += 1;
        playerWon += 1;
    }
    
    gameLoop(currentRound, playerWon, compWon);
}

int main(int argc, char const *argv[])
{
    int currentRound = 0;
    int playerWon = 0;
    int compWon = 0;
    
    srand(time(NULL));

    firstMessage();
    gameLoop(currentRound, playerWon, compWon);
    
    return 0;
}
