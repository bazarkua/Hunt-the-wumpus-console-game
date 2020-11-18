/******************************************
* Filename: pit.cpp
* Description: implementation file for pit class
* Input: header
* Output: default constructor, getters, setters
******************************************/
#include "pit.h"

using namespace std;

Pit::Pit()
{
    message = "You feel a breeze";
    encounter = "You fell in pit and died";
    name = "Pit";
}

string Pit::get_message()
{
    return message;
}
string Pit::get_name()
{
    return name;
}
string Pit::get_encounter()
{
    return encounter;
}

Pit::~Pit(){}