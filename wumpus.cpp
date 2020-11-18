/******************************************
* Filename: wumpus.cpp
* Description: implementation file for wumpus class
* Input: header
* Output: default constructor, getters, setters
******************************************/
#include "wumpus.h"

using namespace std;

Wumpus::Wumpus()
{
    message = "You smell terrible stench";
    encounter = "Room with Wumpus, Wumpus killed you";
    name = "W";
}
string Wumpus::get_message()
{
    return message;
}
string Wumpus::get_encounter()
{
    return encounter;
}
string Wumpus::get_name()
{
    return name;
}
Wumpus::~Wumpus(){}