/******************************************
* Filename: gold.cpp
* Description: implementation file for gold class
* Input: header
* Output: default constructor, getters, setters
******************************************/
#include "gold.h"

using namespace std;

Gold::Gold()
{
    message = "You see a glimmer nearby";
    encounter = "LUCKY YOU! NOW YOU HAVE GOLD!";
    name = "G";
}
string Gold::get_message()
{
    return message;
}
string Gold::get_encounter()
{
    return encounter;
}
string Gold::get_name()
{
    return name;
}
Gold::~Gold(){}