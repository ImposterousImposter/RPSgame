#include "rockpaperscissors.cpp"

int main()
{
    do{
    game.findRNG();
    game.convertRNG();
    game.lowInput();
    game.pickDraw();
    game.compareDraw();
    game.attemptAgain();
    }while(game.retry == true);
}