/******************************************
* Filename: game.h
* Description: header file for game.cpp
* Input: 
* Output: Prototypes for default constructor, getters, setters, functions
******************************************/
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "room.h"
#include "event.h"
#include "gold.h"
#include "wumpus.h"
#include "pit.h"
#include "room.h"
#include "bat.h"

class Game
{
    private:
    int size;
    int player_x, player_y, wumpus_x, wumpus_y;
    int arrows;
    bool wumpus;
    bool gold;
    bool wumpus_near;
    bool alive;
    
    string mode;
    string pos1,pos2,pos3;
    string arrow1, arrow2;
    
    vector<vector<Room> > grid;
    
    public:
    Game(int,string);
    ~Game();
    Game();
    
    bool get_wumpus();
    void load_data(int,string);
    void print_grid();
    void print_grid_debugg();

    void pop_event(int);
    void set_grid();
    void move_player(char);
    void gameplay(string);
    void print_event();
    void encounter();
    //void remove(int, int);
    void bat_move();
    void wumpus_move();
    void shoot_arrow(string);
    void print_status();
    void restart(bool&);
};

#endif