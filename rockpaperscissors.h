#include <string>

class draw
{
    bool correctInput;
    bool playerWin;
    bool cpuWin;

    int rock = 1;
    int paper = 2;
    int scissors = 3;
    int winCount = 0;
    int winStreak = 0;

    int RNG;
    int cpuRNG;
    int playerRNG;

    std::string cpuDraw;
    std::string userDraw;
    std::string userInput;
    std::string lowerInput;
    public:

   
    
    bool retry = false;

    void findRNG();
    void convertRNG();
    void lowInput();
    void pickDraw();
    void compareDraw();
    void attemptAgain();
    void winCheck();
   
    

};