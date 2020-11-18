/******************************************************
** Program: prog.cpp
** Author: Adilbek Bazarkulov
** Date: 05/20/2020
** Description: This program is a game "Hunt the wumpus", it accepts command
line arguments integer for size of the grid and true/false for using debugg mode,
with debug mode user can see the location of events.
** Input: User's input
** Output: Prints grid, events.
******************************************************/
#include "game.h"

using namespace std;

int main(int argc, char** argv)
{
    bool restart = true;
    Game g1;
    do{
    g1.load_data(atoi(argv[1]), argv[2]);
    g1.restart(restart);
    }while(restart==true);
    
    return 0;
}