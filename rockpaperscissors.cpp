#include "rockpaperscissors.h"
#include "time.h"
#include <cstdlib>
#include <iostream> 






void draw::findRNG()
//CPU generates a random number that is used to determine their draw.
{
    srand(time(NULL));
    cpuRNG = rand() % 3 + 1;
}

void draw::convertRNG()
//Puts the CPU's draw into a string.
{
    if(cpuRNG == 1)
        cpuDraw = "rock";
    if(cpuRNG == 2)
        cpuDraw = "paper";
    if(cpuRNG == 3)
        cpuDraw = "scissors";
}

void draw::lowInput()
    //Lower's the user's input for easy computation.
    {
        for(int i = 0; i < userInput.length(); i++)
        {
            lowerInput += userInput[i];
        }
        userInput = lowerInput;
        lowerInput = "";
    }

void draw::pickDraw()
{
    correctInput = false;
    do{
    std::cout << "Will you use rock, paper, or scissors? \n";
    std::cin >> userInput;


    if(userInput == "rock")
        correctInput = true;
    if(userInput == "paper")
        correctInput = true;   
    if(userInput == "scissors")
        correctInput = true;


    if(correctInput != true)
        std::cout << "Please enter a correct input. \n";
    }while(correctInput == false);
}



void draw::compareDraw()
//Compares the draws of the CPU and player.
{
    std::cout << "CPU played " << cpuDraw << "!\n";
    _sleep(500);
    userDraw = userInput;
    if(userDraw == cpuDraw)
        {std::cout << "It's a draw! \n"; 
        playerWin = false;
        _sleep(500);
        }
    if(userDraw == "rock" && cpuDraw == "scissors")
        {
        std::cout << "Rock wins! \n";
        _sleep(500);
        playerWin = true;
        }
    if(userDraw == "rock" && cpuDraw == "paper")
        {
            std::cout << "Paper wins! \n";
            _sleep(500);
            playerWin = false;
        }
    if(userDraw == "paper" && cpuDraw == "rock")
        {
            std::cout << "Paper wins! \n";
            _sleep(500);
            playerWin = true;
        }
    if(userDraw == "paper" && cpuDraw == "scissors")
        {
            std::cout << "Scissors wins! \n";
            _sleep(500);
            playerWin = false;
        }   
    if(userDraw == "scissors" && cpuDraw == "rock")
        {
            std::cout << "Rock wins! \n";
            _sleep(500);
            playerWin = false;
        }
    if(userDraw == "scissors" && cpuDraw == "paper")
        {
            std::cout << "Scissors wins! \n";
            _sleep(500);
            playerWin = true;
        }
    winCheck();
}


void draw::attemptAgain()
{
    std::cout << "Would you like to play again? \n";
    correctInput = false;
    do{
    std::cin >> userInput;
    lowInput();
    
    if(userInput == "yes")
    {
        playerWin = false;
        retry = true;
        correctInput = true;
    }
    if(userInput == "no")
    {
        retry = false;
        correctInput = true;
    }
    if(correctInput == false)
        std::cout << "Please enter yes or no. \n";
    }while(correctInput == false);
}

void draw::winCheck()
{
    if(playerWin == true)
    {
        winCount++;
        winStreak++;
    }else
    {
        winStreak = 0;
    }
    
    if(winCount > 1 && winStreak > 1)
    {
    std::cout << "You've won " << winCount << " times and \n";
    std::cout << "you're on a " << winStreak << " win streak! \n";
    }else if(winCount > 1)
        std::cout << "You've won " << winCount << " times! \n";

}


draw game;