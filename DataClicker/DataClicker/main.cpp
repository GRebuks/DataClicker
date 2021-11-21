#include "Game.h"

int main()
{
    Game game;

    while(true){
        //Update
        game.update();
        //Render
        game.render();
    }

    return 0;
}