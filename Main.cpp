#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

const int WINDOW_WIDTH = 1020;
const int WINDOW_HEIGHT = 800;

int main()
{
    Game game(WINDOW_WIDTH, WINDOW_HEIGHT);
    game.Start();
    return 0;
}